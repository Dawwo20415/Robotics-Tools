
#include <iostream>
#include "classes/robot_structure/robot.h"

int main()
{
    std::map<Joint, Transform> components { { RevoluteJoint(Link({0,1,0})), Transform({0,0,0},{M_PI / 2, 0, 0}) },
                                            { RevoluteJoint(Link({0,1,0})), Transform({0,0,0},{M_PI / 2, 0, 0}) }};

    std::map<Joint, Joint> comp ( RevoluteJoint(Link({1,0,0})), RevoluteJoint(Link({1,0,0})) ,
                                  RevoluteJoint(Link({1,0,0})), RevoluteJoint(Link({1,0,0})));                           

    UnidirectionalPrismaticJoint joint(Link(Vectorn({5,5,5})), UnidirectionalPrismaticJoint::X);

    Transform transform({1,1,1},{0,M_PI / 2,0});

    joint.rototransform(transform).println();

    return 1;
}