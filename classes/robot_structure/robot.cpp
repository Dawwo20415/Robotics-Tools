#include "robot.h"

void Robot::cycleJoints (const std::function<void(Joint*)>& function) {
    for (int i = 0; i < pm_joints.size(); i++) {
        function(pm_joints[i]);
    }
}

void Robot::cycleJoints (const std::function<void(Joint*,int)>& function) {
    for (int i = 0; i < pm_joints.size(); i++) {
        function(pm_joints[i],i);
    }
}

void Robot::setPosition(std::vector<Transform> transformsList) {
    cycleJoints([&transformsList](Joint* j, int i){
        j->setPosition(transformsList[i]);
    });
}

Matrix Robot::getHomogenousMatrix() {
    //First link transformation matrix
    Matrix homogenous_matrix = pm_source_link.displacementMatrix();

    //Cycle trough all the joints and associated links
    cycleJoints( [&homogenous_matrix](Joint* j) mutable {
        homogenous_matrix *= j->getHomogenousTransformationMatrix();
        homogenous_matrix *= j->displacementMatrix();
    });

    return homogenous_matrix;
}

Vectorn Robot::getEndEffector () {

    //First link transformation matrix
    Matrix homogenous_matrix = pm_source_link.displacementMatrix();
    homogenous_matrix.println();

    //Cycle trough all the joints and associated links
    cycleJoints( [&homogenous_matrix](Joint* j) mutable {
        homogenous_matrix *= j->getHomogenousTransformationMatrix();
        homogenous_matrix.println();
        homogenous_matrix *= j->displacementMatrix();
        homogenous_matrix.println();
    });

    //Calculate actual position
    Matrix current_position = homogenous_matrix * Matrix({0,0,0,1}, VERTICAL);

    //from [x,y,z,1] to [x,y,z]
    pm_endeffector = Matrix::toVector(current_position);
    Vectorn::toCoordinates(pm_endeffector);

    homogenous_matrix.columnDetatch(1, END_TO_BEGIN);
    homogenous_matrix.rowDetatch(1, END_TO_BEGIN);

    Matrix rotated_normal = homogenous_matrix * Matrix({0,1,0}, VERTICAL);
    Vectorn new_normal = Matrix::toVector(rotated_normal);
    new_normal.println();

    return pm_endeffector;
}

Matrix Robot::getJacobian() {
    Matrix jacobian ({{0},{0},{1},{0},{0},{0}});
    Matrix homogenous_matrix = pm_source_link.displacementMatrix();

    cycleJoints( [this, &jacobian, &homogenous_matrix](Joint* j) mutable {
        j->getJacobianSection(jacobian, homogenous_matrix, pm_endeffector);
        homogenous_matrix *= j->getHomogenousTransformationMatrix();
        homogenous_matrix *= j->displacementMatrix();
    });

    jacobian.columnDetatch(1, BEGIN_TO_END);

    return jacobian;
}

Vectorn Robot::getConfigurationSpace() {
    Vectorn tmp(1);

    cycleJoints( [&tmp](Joint* j) mutable {
        tmp.append(j->getConfigurationSpace());
    });

    tmp.detatch(1, BEGIN_TO_END);

    return tmp;
}

bool Robot::inverseKinematic (Transform objective) {
    //Jacobian inverse technique
    //link https://en.wikipedia.org/wiki/Inverse_kinematics
    //Next step is to calculate the moonrooe pseudo inverse of the jacobian
    //link https://en.wikipedia.org/wiki/Moore%E2%80%93Penrose_inverse

    //With that we have a vector from origin to end effector

    //With the vector we can calculate the 3 total angles that the sum of the joints need to end up having

    //Then divide the angle in how many joints can have an effect on this angle

    //How do we get how each joint effects the angle?

    //the vector of the end effector is just the sum of the vector of each joint + link

    //That vector is determined by the vector link with the applied rotation

    return true;
}

void Robot::printStatus() {

    cycleJoints([](Joint* j, int i){
        std::cout << "Joint #" << i << " Status ";
        j->printStatus();
        std::cout << std::endl;

        std::cout << "Joint #" << i << " Vector ";
        j->printVector();
        std::cout << std::endl; 
    });
}

Matrix Robot::jacobianSteps() {
    Matrix rotation (Matrix::identityMatrix(4));
    Matrix jacobian (6,1);

    for (int i = 0; i < pm_joints.size(); i++) {
        std::cout << "For Joint i:" << i+1 << " R 0 to " << i << " Displacement d end - d" << i <<std::endl;
        std::cout << "R 0|" << i << std::endl;
        if (i > 0)
            rotation *= pm_joints[i-1]->getHomogenousTransformationMatrix();
        
        rotation.println();

        std::cout << "d 0|" << i << std::endl;
        if (i > 0) 
            rotation *= pm_joints[i-1]->displacementMatrix();
        
        rotation.println();

        Vectorn displacement(3);
        Vectorn d0i(3);

        for (int j = 0; j < 3; j++) {
            d0i[j] = rotation(j,3);
        }

        displacement = pm_endeffector - d0i;
        std::cout << "Displacement vector:" << std::endl;
        displacement.println();

        Vectorn Z(3);

        if (i == 0) {
            for (int j = 0; j < 3; j++) {
                Z[j] = rotation(j,2);
                jacobian(j+3,0) = rotation(j,2);
            }
            Vectorn result = Z * displacement;
            for (int j = 0; j < 3; j++) {
                jacobian(j,0) = result[j];
            }
        } else {
            Matrix jPiece(6,1);

            for (int j = 0; j < 3; j++) {
                Z[j] = rotation(j,2);
                jPiece(j+3,0) = rotation(j,2);
            }
            Vectorn result = Z * displacement;
            for (int j = 0; j < 3; j++) {
                jPiece(j,0) = result[j];
            }
            jacobian.rowAppend(jPiece);
        }

        jacobian.println();
    
    }

    return Matrix::identityMatrix(4);
    
}
