#ifndef JOINT_CLASS
#define JOINT_CLASS

#include <iostream>
#include <list>
#include <iterator>
#include <vector>

//PARENT CLASS for joints
class Joint {

    protected:
        //name of the joint
        std::string name;
        //symbol classificator of the joint
        char symbol;
        //Origin of the joint relative to the joint itself
        std::vector<float> origin;
        //Position of the end effector relative to the joint
        std::vector<float> endeffector;

    public:
        //Constructors
        Joint();
        //Prints to console the relative position of the endeffector relative
        //to the joint
        virtual void GetRelativePos();
        //Destructor
        ~Joint();
};

#endif

#ifndef P_JOINT_CLASS
#define P_JOINT_CLASS
//SUBCLASS Prismatic_Joint
//linear joint that moves on 1 axis without rotation
class Prismatic_Joint : public Joint {

    private:
        //length of the travellable axis by the joint measured in relative
        //position with the origin of the joint as <0,0,0>
        float range;
        //Value from 0.0 to 1.0 that determines how much along the axis the joint is
        float progress;

    public:
        //Constructors
        Prismatic_Joint(std::string n, char c, std::vector<float> o, float r);
        Prismatic_Joint(std::string n, char c, std::vector<float> o, float r, float p);
        //Functions
        virtual void GetRelativePos();
        //Destructor
        ~Prismatic_Joint();

};

#endif
