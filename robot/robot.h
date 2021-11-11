#ifndef ROBOT_CLASS
#define ROBOT_CLASS

#include <iostream>

#include "robot.cpp"

class robot {

    public:
        int num;
        int func1(int n);
        void prnt() {
            printf("rob value: %d\n", num);
        };

};

#endif