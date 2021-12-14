#include "robot.h"

Robot::Robot() {
    name = "Unnamed";
}

Robot::Robot(std::string n) {
    name = n;
}

Robot::Robot(std::string n, std::list <Joint> j) {
    name = n;
    joints = j;
}

int Robot::func1 (int n) {
    return n;
}

void Robot::prnt () {
    printf("This is the current value %s \n", name.c_str());
}
