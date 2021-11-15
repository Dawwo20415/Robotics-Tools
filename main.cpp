//launch code g++:
//g++ main.cpp -o main.out && ./main.out

#include <iostream>

#include "./robot/robot.cpp"

using namespace std;

int main()
{
    Prismatic_Joint j1 ("Prismatic 1", 'p', {0,0,0}, 5.0f, 1.0f);
    Robot rob("Robot2", {j1});
    rob.prnt();
    rob.func1(3);
    rob.prnt();

    return 0;
}



