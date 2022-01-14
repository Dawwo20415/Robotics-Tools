
#include <iostream>
#include "classes/algebric_backend/vectorn.h"
#include "classes/algebric_backend/matrix.h"
#include <vector>

int main()
{
    
    Matrix mat4({{7,2,3},
                 {0,5,1},
                 {6,7,9}});

    std::cout << "Final Result = " << mat4.determinant() << std::endl;

    return 1;

}