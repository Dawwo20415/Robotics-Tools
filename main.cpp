
#include <iostream>
#include "classes/robot_structure/robot.h"

int main()
{
    AbsoluteJoint joint(5);

    Vectorn vec = joint.rototranslate(M_PI / 2, 0, 0, {1,1,2});

    vec.println();

    return 1;
}