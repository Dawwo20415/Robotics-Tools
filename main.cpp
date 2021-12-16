/*
launch code g++:
clear && g++ main.cpp -o main.out && ./main.out
debug compile
clear && g++ main.cpp ./robot/backend/* -g -o main.out
*/


#include <iostream>
#include "classes/algebric_backend/vectorn.h"
/*
#include <memory>
#include "dependencies/backend/vector3.h"

using namespace std;
*/
int main()
{
    //Need to completely remake both classes without Templates

    std::cout << "Hello World" << std::endl;

    Vectorn hello(5);

    return 1;

}