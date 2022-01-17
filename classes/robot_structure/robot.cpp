#include "robot.h"

Vectorn Robot::getEndEffector () {
    Vectorn current_position = pm_starting_position;

    for (int i = 0; i < pm_joints.size(); i++) {
        current_position = pm_joints[i].rototransform(pm_transforms[i]);
    }

    return current_position;
}