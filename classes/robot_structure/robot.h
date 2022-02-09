#ifndef ROBOT_CLASS
#define ROBOT_CLASS

#include "joint.h"
#include <list>
#include <map>
#include <functional>

class Robot {

    private:

        std::vector<Joint*> pm_joints;
        Link pm_source_link;
        Vectorn pm_endeffector;

        void cycleJoints(const std::function<void(Joint*)>& function);
        void cycleJoints(const std::function<void(Joint*,int)>& function);

    public:

        //Constructors ----------------------------------------
            Robot() : pm_joints({}), 
                      pm_source_link({0,0,0}), 
                      pm_endeffector(Vectorn::nullVector(3)) {};
            Robot(std::vector<Joint*> joint_list, Link position) 
                    : pm_joints(joint_list),
                        pm_source_link(position), 
                        pm_endeffector(Vectorn::nullVector(3)) {};

        //Functions -------------------------------------------
            
            void setPosition(std::vector<Transform> transformsList);
            Matrix getHomogenousMatrix();
            Vectorn getEndEffector();
            Matrix getJacobian();
            Matrix jacobianSteps();
            Vectorn getConfigurationSpace();
            //Vectorn redefineJoints();
            //Returns wether or not the objective is reachable
            bool inverseKinematic(Transform objective);
            //Prints the status of all the joints that are part of the chain
            void printStatus();


};

#endif
