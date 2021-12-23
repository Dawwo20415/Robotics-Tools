
#include <iostream>
#include "classes/algebric_backend/vectorn.h"
#include <vector>

int main()
{
    //Need to completely remake both classes without Templates


    Vectorn vec1({1,2,3,4,5,6,7,8,9});
    Vectorn vec2({2,3,4,5});

    std::cout << vec1[5] << std::endl;

    return 1;

}