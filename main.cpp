
#include <iostream>
#include "classes/robot_structure/robot.h"

//Name  -  Axis
//Roll  -   X
//Pitch -   Y
//Yaw   -   Z

//All the actions to affect the Joints
std::vector<Transform> getActions() {

    return {Transform({0,0,0},{M_PI_2,M_PI_2,M_PI_2}),
            Transform({0,0,0},{M_PI_4,M_PI_4,M_PI_4})};

}

int main()
{
    //Declaration of all components
    UnidirectionalRevoluteJoint  joint1(Link({0,1,0}), Transform({0,0,0},{M_PI,M_PI,M_PI}), Transform({0,0,0},{0,0,0}), UnidirectionalRevoluteJoint::Pitch);
    UnidirectionalRevoluteJoint  joint2(Link({0,sqrt(2),0}), Transform({0,0,0},{M_PI,M_PI,M_PI}), Transform({0,0,0},{0,0,0}), UnidirectionalRevoluteJoint::Yaw);
    RevoluteJoint  joint3(Link({sqrt(2),0,0}), Transform({0,0,0},{M_PI,M_PI,M_PI}), Transform({0,0,0},{0,0,0}));

    std::vector<Joint*> tmp;

    #pragma region Filling the List
    tmp.push_back(&joint1);
    tmp.push_back(&joint2);
    //tmp.push_back(&joint3);
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
    std::cout << std::endl;

    return 1;
}