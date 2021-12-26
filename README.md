# Robotics-Tools
Tools used for the "Introduction to Robotics" Class at Unitn, comprehensive of all formulas and instruction for jointed robotic arms, and maybe more...?
This software has been made for the group project necessary to pass the class. This project is to be implemented in ROS, using simulation software. 

## Structure of the project

This project is divided in 3 sections:
 - The Mathematical Structures (VectorN, Matrix);
 - The Robot Assembler (Robot, Joints);
 - The Main (main.cpp);

VectorN and Matrix allow for the easy creation and usage of Mathematical NxM matrixes, with useful methods and structured for them to be used as if operation were being written on paper. These form the base of the Robot Structures, these allow the user to create any number of **robotic arms** and freely define the joints they are composed of. As the previous Structures the usage is made to be intuitive with both english named functions that describe what is happening and direct operators for those that already know what's up. All the construction and action of the robot is to be done in the ''main.cpp'' file. (One day I may rework this to have robot declaration and construction done all at runtime with the possibility of saving configurations in specified files but for now it is out of the scope of this project)

## Available joints

 - Prismatic joint [to be made]
 - Revolute joint [to be made]

## Build and implementation instructions

To be written when software will be completed
