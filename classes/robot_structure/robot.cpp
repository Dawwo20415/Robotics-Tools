#include "robot.h"

Vectorn Robot::homogenousToCoordinates (Matrix homogenous) {
    Vectorn tmp(3);

    for (int i = 0; i < 3; i++) {
        tmp[i] = homogenous(i,0);
    }

    return tmp;
}

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
    pm_endeffector = homogenousToCoordinates(current_position);

    return pm_endeffector;

}

bool Robot::inverseKinematic (Transform objective) {
    //extract position from the transform

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
        std::cout << "Joint #" << i << " ";
        pm_joints[i]->printStatus();
        std::cout << std::endl; 
    }
}