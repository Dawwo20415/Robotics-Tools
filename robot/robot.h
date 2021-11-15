#ifndef ROBOT_CLASS
#define ROBOT_CLASS

#include <iostream>
#include <list>
#include <iterator>
#include "joints/joints.cpp"

class Robot {

    private:
        std::string name;
        std::list <Joint> joints;

    public:
        Robot();
        Robot(std::string n);
        Robot(std::string n, std::list <Joint> j);
        int func1(int n);
        void prnt();

};

#endif