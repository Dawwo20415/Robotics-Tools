
#include <iostream>
#include "classes/robot_structure/robot.h"

int main()
{
    RevoluteJoint joint(5);

    Vectorn vec = joint.rotate(M_PI / 2);
    vec.println();

    return 1;

}