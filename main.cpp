#include <iostream>

#include "./robot/robot.h"
#include "./robot/robot.cpp"

using namespace std;

int main()
{
    robot rob;
    rob.num = 5;
    rob.prnt();
    rob.func1(3);
    rob.prnt();

    return 0;
}

