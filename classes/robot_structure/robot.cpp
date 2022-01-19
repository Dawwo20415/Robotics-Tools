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