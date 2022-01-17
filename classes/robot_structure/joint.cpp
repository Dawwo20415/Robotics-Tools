#include "joint.h"

#pragma region Constructors

RevoluteJoint::RevoluteJoint(float length) {    
    pm_length = length;
    position = {5,0,0};

}

Matrix RevoluteJoint::getRotationMatrix(float yaw, float pitch, float roll) {
    Matrix yaw_matrix   ({{cos(yaw), -sin(yaw), 0},
                          {sin(yaw),  cos(yaw), 0},
                          {    0   ,    0     , 1}});

    Matrix pitch_matrix ({{ cos(pitch), 0, sin(pitch)},
                          {    0      , 1,     0     },
                          {-sin(pitch), 0, cos(pitch)}});

    Matrix roll_matrix  ({{    1  ,     0    ,     0     },
                          {    0  , cos(roll), -sin(roll)},
                          {    0  , sin(roll),  cos(roll)}});

    return yaw_matrix * pitch_matrix * roll_matrix;
}

Vectorn RevoluteJoint::rotate(float yaw, float pitch, float roll) {

    Matrix newposition = getRotationMatrix(yaw, pitch, roll) * Matrix(position, VERTICAL);

    Vectorn posvector(3);

    for (int i = 0; i < 3; i++) {
        posvector[i] = newposition(i,0);
    }

    return posvector;
}

AbsoluteJoint::AbsoluteJoint(float length) {    
    pm_length = length;
    position = {5,0,0};

}

Matrix AbsoluteJoint::getRotationMatrix(float yaw, float pitch, float roll, Vectorn translation) {
    Matrix yaw_matrix   ({{cos(yaw), -sin(yaw), 0},
                          {sin(yaw),  cos(yaw), 0},
                          {    0   ,    0     , 1}});

    Matrix pitch_matrix ({{ cos(pitch), 0, sin(pitch)},
                          {    0      , 1,     0     },
                          {-sin(pitch), 0, cos(pitch)}});

    Matrix roll_matrix  ({{    1  ,     0    ,     0     },
                          {    0  , cos(roll), -sin(roll)},
                          {    0  , sin(roll),  cos(roll)}});

    Matrix rotation = yaw_matrix * pitch_matrix * roll_matrix;

    rotation.columnAppend({{0,0,0}});

    rotation.rowAppend(Matrix(translation, VERTICAL));

    return rotation;
}

Vectorn AbsoluteJoint::rototranslate(float yaw, float pitch, float roll, Vectorn translation) {

    Vectorn homogenous(4);
    Vectorn h_translation(4);

    for (int i = 0; i < 3; i++) {
        homogenous[i] = position[i];
        h_translation[i] = translation[i];
    }

    homogenous[3] = 1;
    h_translation[3] = 1;

    Matrix newposition = getRotationMatrix(yaw, pitch, roll, h_translation) * Matrix(homogenous, VERTICAL);

    Vectorn posvector(3);

    for (int i = 0; i < 3; i++) {
        posvector[i] = newposition(i,0);
    }

    return posvector;
}

#pragma endregion