
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

    Matrix mat4({{0,2,2},
                 {1,4,3},
                 {2,3,5}});

    if (mat4.isSymmetric())
        std::cout << "is symmetric" << std::endl;


    return 1;

}