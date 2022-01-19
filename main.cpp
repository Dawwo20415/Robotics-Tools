
#include <iostream>
#include "classes/robot_structure/robot.h"

//Name  -  Axis
//Roll  -   X
//Pitch -   Y
//Yaw   -   Z

int main()
{
    //Joints
    RevoluteJoint prism1(Link({0,2,0}));
    RevoluteJoint prism2(Link({0,1,0}));

    std::vector<Joint*> components = { &prism1, &prism2 };

    std::vector<Transform> actions ({ {Transform({0,0,0},{M_PI/2,0,0})},
                                      {Transform({0,0,0},{M_PI/2,0,0})}});
    
    Robot bot(components, actions, {0,1,0});

    bot.getEndEffector().println();

    return 1;
}