
#include <iostream>
#include "classes/algebric_backend/vectorn.h"
#include "classes/algebric_backend/matrix.h"
#include <vector>

int main()
{
    //Need to completely remake both classes without Templates
    Matrix mat1({{1,2,3,4,5,6,7},
                 {5,6,7,8,9,1,2},
                 {9,1,2,3,4,5,6},
                 {7,8,9,1,2,3,4},
                 {6,7,8,9,9,0,1}});

    mat1.Println();

    return 1;

}