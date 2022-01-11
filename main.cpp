
#include <iostream>
#include "classes/algebric_backend/vectorn.h"
#include "classes/algebric_backend/matrix.h"
#include <vector>

int main()
{
    //Need to completely remake both classes without Templates
    Matrix mat1({{1,1,1},
                 {1,1,1},
                 {1,1,1}});

    Matrix mat3({{2,2,2},
                 {3,3,3},
                 {4,4,4}});

    Matrix mat2(3,3);

    mat2 = mat3 - mat1;

    mat2.Println();

    return 1;

}