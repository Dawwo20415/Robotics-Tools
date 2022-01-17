#ifndef ROBOT_CLASS
#define ROBOT_CLASS

#include "joint.h"
#include <list>
#include <map>

class Robot {

    private:

        std::map<Joint, Transform> pm_joints;
        Vectorn pm_starting_position;
        Vectorn pm_endeffector;

    public:

        //Constructors ----------------------------------------
            Robot() : pm_joints({}), 
                      pm_starting_position({0,0,0}), 
                      pm_endeffector(Vectorn::nullVector(3)) {};
            Robot(std::map<Joint, Transform> pairs, Vectorn position) : pm_joints(pairs),
                                                                        pm_starting_position(position), 
                                                                        pm_endeffector(Vectorn::nullVector(3)) {};

        //Functions -------------------------------------------
            Vectorn getEndEffector();
            //Vectorn redefineJoints();


};

#endif
