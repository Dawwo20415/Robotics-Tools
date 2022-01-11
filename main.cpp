
#include <iostream>
#include "classes/algebric_backend/vectorn.h"
#include "classes/algebric_backend/matrix.h"
#include <vector>

int main()
{
    //Need to completely remake both classes without Templates
    Matrix mat1({{1,2,3},
                 {4,5,6},
                 {7,8,9}});

    Matrix mat2(3,3);

    mat1.Println();
    mat2.Println();

    mat2 = mat1;

    Matrix mat3({{9,8,7},
                 {6,5,4},
                 {3,2,1}});

    mat1 = mat3;

    mat1(0,0) = 0;
    mat2(2,2) = 0;
    mat3(1,1) = 0;

    return 1;

}