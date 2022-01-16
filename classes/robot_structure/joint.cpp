#include "joint.h"

#pragma region Constructors

RevoluteJoint::RevoluteJoint(float length) {    
    pm_length = length;
    position = {0,length};

}

Matrix RevoluteJoint::getRotationMatrix(float angle) {
    return Matrix( {{ cos(angle), sin(angle)},
                    {-sin(angle), cos(angle)}} );
}

Vectorn RevoluteJoint::rotate(float angle) {
    Matrix newposition(2,1);

    newposition = getRotationMatrix(angle) * Matrix(position, VERTICAL);

    Vectorn posvector(2);

    for (int i = 0; i < 2; i++) {
        posvector[i] = newposition(i,0);
    }

    return posvector;
}

#pragma endregion