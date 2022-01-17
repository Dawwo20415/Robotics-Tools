
#include <iostream>
#include "classes/robot_structure/robot.h"

int main()
{
    AbsoluteJoint joint(Link(Vectorn({5,0,0})));

    Transform transform({1,0,0},{0,M_PI / 2,0});

    joint.rototransform(transform).println();

    return 1;
}