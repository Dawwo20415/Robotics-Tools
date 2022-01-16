#ifndef ROBOT_CLASS
#define ROBOT_CLASS

#include "joint.h"
#include <list>

class Robot {

    private:

        std::list<RevoluteJoint> pm_joints; 

    public:

        //Constructors ----------------------------------------
            Robot();
            Robot(std::list<RevoluteJoint> list);

        //Functions -------------------------------------------
            //Vectorn getEndEffector();
            //Vectorn redefineJoints();


};

#endif
