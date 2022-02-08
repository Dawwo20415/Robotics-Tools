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
    Matrix homogenous_matrix = pm_source_link.link_matrix();

    //Cycle trough all the joints and associated links
    cycleJoints( [&homogenous_matrix](Joint* j) mutable {
        homogenous_matrix *= j->getHomogenousTransformationMatrix();
        homogenous_matrix *= j->linkMatrix();
    });

    return homogenous_matrix;
}

Vectorn Robot::getEndEffector () {

    //First link transformation matrix
    Matrix homogenous_matrix = pm_source_link.link_matrix();

    //Cycle trough all the joints and associated links
    cycleJoints( [&homogenous_matrix](Joint* j) mutable {
        homogenous_matrix *= j->getHomogenousTransformationMatrix();
        homogenous_matrix *= j->linkMatrix();
    });

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

    cycleJoints( [this, &jacobian, &homogenous_matrix](Joint* j) mutable {
        j->getJacobianSection(jacobian, homogenous_matrix, pm_endeffector);
        homogenous_matrix *= j->getHomogenousTransformationMatrix();
        homogenous_matrix *= j->linkMatrix();
    });

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