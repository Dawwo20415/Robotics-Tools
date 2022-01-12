
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

    mat1 = mat1 * 2;

    mat1.Println();


    return 1;

}