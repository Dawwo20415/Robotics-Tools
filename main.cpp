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

    std::vector<float> vec({1,2,3,4,5});

    Vectorn vec0(20);
    Vectorn vec1({1,2,3,4,5,6,7,8,9});

    Vectorn vec2(vec1);
    Vectorn vec3(2,vec1);
    Vectorn vec4(2,6,vec1);

    Vectorn vec5(vec);
    Vectorn vec6(2,vec);

    std::cout << vec0[0] << std::endl;

    return 1;

}