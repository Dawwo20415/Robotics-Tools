
#include <iostream>
#include "classes/robot_structure/robot.h"

//Name  -  Axis
//Roll  -   X
//Pitch -   Y
//Yaw   -   Z

//All the actions to affect the Joints
std::vector<Transform> getActions() {

    return {Transform({0,0,0},{M_PI/2,0,0}),
            Transform({0,1,0},{0,0,0})};

}

int main()
{
    //Declaration of all components
    RevoluteJoint  prism1(Link({0,1,0}));
    PrismaticJoint prism2(Link({0,1,0}));

    std::vector<Joint*> tmp;

    #pragma region Filling the List
    tmp.push_back(&prism1);
    tmp.push_back(&prism2);
    #pragma endregion
    
    Robot bot(tmp, getActions(), Link({0,1,0}));

    bot.getEndEffector().println();

    return 1;
}