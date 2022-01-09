
#include <iostream>
#include "classes/algebric_backend/vectorn.h"
#include "classes/algebric_backend/matrix.h"
#include <vector>

int main()
{
    //Need to completely remake both classes without Templates
    float fl = 4;
    Matrix mat(3,3);
    float fl1 = mat(2,2);
    float fl2 = mat(0,0);

    return 1;

}