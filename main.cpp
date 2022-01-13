
#include <iostream>
#include "classes/algebric_backend/vectorn.h"
#include "classes/algebric_backend/matrix.h"
#include <vector>

int main()
{
    //Need to completely remake both classes without Templates
    

    Matrix mat4({{-2,2,-1},
                 {6,-6,7},
                 {3,-8,4}});

    mat4.println();

    mat4.determinant();


    return 1;

}