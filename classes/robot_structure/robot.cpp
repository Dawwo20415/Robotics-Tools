#include "robot.h"

Vectorn Robot::getEndEffector () {
    Vectorn current_position = pm_starting_position;

    for (auto joint : pm_joints) {
        current_position = joint.first.rototransform(joint.second);
    }

    return current_position;
}