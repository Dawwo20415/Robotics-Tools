
#include <iostream>
#include "classes/algebric_backend/vectorn.h"
#include "classes/algebric_backend/matrix.h"
#include <vector>

int main()
{
    //Need to completely remake both classes without Templates
    Matrix mat1({{1,2,3,4},
                 {5,6,7,8},
                 {9,10,11,12}});

    Matrix mat2(1,1,2,3, mat1);

    return 1;

}