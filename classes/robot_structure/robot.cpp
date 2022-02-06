#include "robot.h"

Vectorn Robot::getEndEffector () {

    //First link transformation matrix
    Matrix homogenous_matrix = pm_source_link.link_matrix();

    //Cycle trough all the joints and associated links
    for (int i = 0; i < pm_joints.size(); i++) {
        homogenous_matrix *= pm_joints[i]->getHomogenousTransformationMatrix(pm_transforms[i]);
        homogenous_matrix *= pm_joints[i]->linkMatrix();
    }

    //Calculate actual position
    Matrix current_position = homogenous_matrix * Matrix({0,0,0,1}, VERTICAL);

    //from [x,y,z,1] to [x,y,z]
    pm_endeffector = Matrix::toVector(current_position);
    Vectorn::toCoordinates(pm_endeffector);

    return pm_endeffector;
}

Matrix Robot::getJacobian() {
    Matrix jacobian ({{0},{0},{1},{0},{0},{0}});
    Matrix homogenous_matrix = pm_source_link.link_matrix();

    for (int i = 0; i < pm_joints.size(); i++) {

        jacobian.rowAppend(pm_joints[i]->getJacobianSection(homogenous_matrix, pm_endeffector));

        homogenous_matrix *= pm_joints[i]->getHomogenousTransformationMatrix(pm_transforms[i]);
        homogenous_matrix *= pm_joints[i]->linkMatrix();

    }

    return jacobian;
}

bool Robot::inverseKinematic (Transform objective) {
    //extract position from the transform

    //Take the angles necessary to be reached by sum of all others
    Vectorn angles(3);

    float magnitude = sqrt(pow(objective.x(),2) + pow(objective.y(),2) + pow(objective.z(),2));

    //roll
    angles[0] = atan2(sqrt(pow(objective.y(),2) + pow(objective.z(),2)), objective.x());

    //pitch
    angles[1] = acos(objective.y() / magnitude);

    //yaw
    angles[2] = acos(objective.z() / magnitude);

    angles *= (180 / M_PI);

    angles.println();

    //With that we have a vector from origin to end effector

    //With the vector we can calculate the 3 total angles that the sum of the joints need to end up having

    //Then divide the angle in how many joints can have an effect on this angle

    //How do we get how each joint effects the angle?

    //the vector of the end effector is just the sum of the vector of each joint + link

    //That vector is determined by the vector link with the applied rotation

    return true;
}

void Robot::printStatus() {
    for (int i = 0; i < pm_joints.size(); i++) {
        std::cout << "Joint #" << i << " Status ";
        pm_joints[i]->printStatus();
        std::cout << std::endl;

        std::cout << "Joint #" << i << " Vector ";
        pm_joints[i]->printVector();
        std::cout << std::endl; 
    }
}