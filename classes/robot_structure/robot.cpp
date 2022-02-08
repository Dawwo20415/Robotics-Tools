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

Vectorn Robot::getConfigurationSpace() {
    Vectorn tmp(1);

    tmp = pm_joints[0]->getConfigurationSpace();

    for (int i = 1; i < pm_joints.size(); i++) {
        tmp.append(pm_joints[i]->getConfigurationSpace());
    }

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
    for (int i = 0; i < pm_joints.size(); i++) {
        std::cout << "Joint #" << i << " Status ";
        pm_joints[i]->printStatus();
        std::cout << std::endl;

        std::cout << "Joint #" << i << " Vector ";
        pm_joints[i]->printVector();
        std::cout << std::endl; 
    }
}