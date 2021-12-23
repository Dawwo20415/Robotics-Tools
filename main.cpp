/*
launch code g++:
clear && g++ main.cpp -o main.out && ./main.out
debug compile
clear && g++ main.cpp ./robot/backend/* -g -o main.out
*/


#include <iostream>
#include "classes/algebric_backend/vectorn.h"
#include <vector>
/*
#include <memory>
#include "dependencies/backend/vector3.h"

using namespace std;
*/
int main()
{
    //Need to completely remake both classes without Templates


    Vectorn vec1({1,2,3,4,5,6,7,8,9});
    Vectorn vec2({2,3,4,5});

    vec2 = vec2 + vec2;

    std::cout << vec1[5] << std::endl;

    return 1;

}