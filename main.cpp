
#include <iostream>
#include "classes/algebric_backend/vectorn.h"
#include "classes/algebric_backend/matrix.h"
#include <vector>

int main()
{
    
    Matrix mat4({{7,2,3},
                 {0,0,1},
                 {0,0,9}});

    mat4.inverse().println();


    return 1;

}