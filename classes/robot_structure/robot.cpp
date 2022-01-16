#include "robot.h"

#pragma region Constructor

Robot::Robot() {
    pm_joints = {};
}

Robot::Robot(std::list<RevoluteJoint> list) {
    pm_joints = list;
}

#pragma endregion