
#include <iostream>
#include "classes/robot_structure/robot.h"

//Name  -  Axis
//Roll  -   X
//Pitch -   Y
//Yaw   -   Z

/*
* TO DO LIST FOR WHEN COMING BACK:
* - Check if the jacobian calculation is correct, 
    it would seem to be correct but I have no counterparts to compare it with
* - Make function to generate the pseudoinverse of the Jacobian with SVD
* - Use the inverse jacobian to iteratively do the inverse kinematic
* - The robot simulation software doesn't provide parsed data from the sensors, therefore
    sensors data will need to be partsed and probably a camera controller will need to be made, I have no idea if it needs to be attached 
    to the robotic arm, but for now it seems that we can use both cameras and lasers;
* - Probably will need to make a class called "Robot Controller" that will determin how the robot will act and decide in what position it should be in
    for instance determine path and interpolation of positions, handle sensor input and implement the object finding behaviour
*/

//All the actions to affect the Joints
std::vector<Transform> getActions() {

    return {Transform({0,0,0},{M_PI_2,M_PI_2,M_PI_2}),
            Transform({0,0,0},{M_PI_4,M_PI_4,M_PI_4})};

}

int main()
{
    //Declaration of all components
    UnidirectionalRevoluteJoint  joint1(Link({0,1,0}), Transform({0,0,0},{M_PI,M_PI,M_PI}), Transform({0,0,0},{0,0,0}), UnidirectionalRevoluteJoint::Pitch);
    UnidirectionalRevoluteJoint  joint2(Link({1,0,0}), Transform({0,0,0},{M_PI,M_PI,M_PI}), Transform({0,0,0},{0,0,0}), UnidirectionalRevoluteJoint::Yaw);
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
    bot.jacobianSteps();
    std::cout << std::endl;

    std::cout << "JACOBIAN OLD:" << std::endl;
    bot.getJacobian().println();
    std::cout << std::endl;

    std::cout << "CONFIGURATION SPACE:" << std::endl;
    bot.getConfigurationSpace().println();
    std::cout << std::endl;

    return 1;
}