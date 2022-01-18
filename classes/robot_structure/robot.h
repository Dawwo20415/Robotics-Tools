#ifndef ROBOT_CLASS
#define ROBOT_CLASS

#include "joint.h"
#include <list>
#include <map>

class Robot {

    private:

        std::vector<Joint*> pm_joints;
        std::vector<Transform> pm_transforms;
        Vectorn pm_starting_position;
        Vectorn pm_endeffector;

    public:

        //Constructors ----------------------------------------
            Robot() : pm_joints({}), 
                      pm_starting_position({0,0,0}), 
                      pm_endeffector(Vectorn::nullVector(3)) {};
            Robot(std::vector<Joint*> joint_list, std::vector<Transform> transform_list, Vectorn position) 
                    : pm_joints(joint_list),
                        pm_transforms(transform_list),
                        pm_starting_position(position), 
                        pm_endeffector(Vectorn::nullVector(3)) {};

        //Functions -------------------------------------------
            Vectorn getEndEffector();
            //Vectorn redefineJoints();


};

#endif
