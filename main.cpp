
#include <iostream>
#include "classes/robot_structure/robot.h"

//Name  -  Axis
//Roll  -   X
//Pitch -   Y
//Yaw   -   Z

//All the actions to affect the Joints
std::vector<Transform> getActions() {

    return {Transform({0,0,0},{0,0,M_PI_2 / 3}),
            Transform({0,0,0},{0,0,M_PI_2 / 3}),
            Transform({0,0,0},{0,0,M_PI_2 / 3})};

}

int main()
{
    //Declaration of all components
    RevoluteJoint  joint1(Link({sqrt(2),0,0}), Transform({0,0,0},{M_PI,M_PI,M_PI}), Transform({0,0,0},{0,0,0}));
    RevoluteJoint  joint2(Link({1,0,0}), Transform({0,0,0},{M_PI,M_PI,M_PI}), Transform({0,0,0},{0,0,0}));
    RevoluteJoint  joint3(Link({sqrt(2),0,0}), Transform({0,0,0},{M_PI,M_PI,M_PI}), Transform({0,0,0},{0,0,0}));

    std::vector<Joint*> tmp;

    #pragma region Filling the List
    tmp.push_back(&joint1);
    tmp.push_back(&joint2);
    tmp.push_back(&joint3);
    #pragma endregion
    
    Robot bot(tmp, Link({0,0,0}));

    bot.setPosition(getActions());

    std::cout << "END EFFECTOR:" << std::endl;
    bot.getEndEffector().println();
    std::cout << std::endl;

    std::cout << "HOMOGENOUS MATRIX:" << std::endl;
    bot.getHomogenousMatrix().println();
    std::cout << std::endl;

    std::cout << "STATUS:" << std::endl;
    bot.printStatus();
    std::cout << std::endl;

    std::cout << "JACOBIAN:" << std::endl;
    bot.getJacobian().println();
    std::cout << std::endl;

    std::cout << "CONFIGURATION SPACE:" << std::endl;
    bot.getConfigurationSpace().println();

    return 1;
}