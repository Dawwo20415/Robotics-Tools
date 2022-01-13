
#include <iostream>
#include "classes/algebric_backend/vectorn.h"
#include "classes/algebric_backend/matrix.h"
#include <vector>

int main()
{
    //Need to completely remake both classes without Templates
    Matrix mat1({{1,1,1,1},
                 {1,1,1,1},
                 {1,1,1,1}});

    Matrix mat2({{2,2,2},
                 {3,3,3},
                 {4,4,4},
                 {5,5,5}});

    Matrix mat3(3,4);

    mat2.rotate();
    mat2.println();


    return 1;

}