
#include <iostream>
#include "classes/robot_structure/robot.h"

//Name  -  Axis
//Roll  -   X
//Pitch -   Y
//Yaw   -   Z

//All the actions to affect the Joints
std::vector<Transform> getActions() {

    return {Transform({0,0,0},{0,0,M_PI / 6}),
            Transform({0,0,0},{0,0,M_PI / 6}),
            Transform({0,0,0},{0,0,M_PI / 6})};

}

int main()
{
    //Declaration of all components
    RevoluteJoint  prism1(Link({(float)sqrt(5),0,0}), Transform({0,0,0},{M_PI,M_PI,M_PI}), Transform({0,0,0},{0,0,0}));
    RevoluteJoint  prism2(Link({(float)sqrt(5),0,0}), Transform({0,0,0},{M_PI,M_PI,M_PI}), Transform({0,0,0},{0,0,0}));
    RevoluteJoint  prism3(Link({(float)sqrt(5),0,0}), Transform({0,0,0},{M_PI,M_PI,M_PI}), Transform({0,0,0},{0,0,0}));

    std::vector<Joint*> tmp;

    #pragma region Filling the List
    tmp.push_back(&prism1);
    tmp.push_back(&prism2);
    tmp.push_back(&prism3);
    #pragma endregion
    
    Robot bot(tmp, getActions(), Link({0,0,0}));

    bot.getEndEffector().println();

    std::cout << std::endl;

    //bot.printStatus();

    bot.getJacobian().println();

    return 1;
}