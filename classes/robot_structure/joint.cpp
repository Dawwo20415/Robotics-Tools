#include "joint.h"
/*
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

*/

#pragma region Absolute Joint

Matrix AbsoluteJoint::getHomogenousTransformationMatrix(Transform tr) {

    Matrix yaw_matrix   ({{cos(tr.yaw()), -sin(tr.yaw()), 0},
                          {sin(tr.yaw()),  cos(tr.yaw()), 0},
                          {    0   ,    0     , 1}});

    Matrix pitch_matrix ({{ cos(tr.pitch()), 0, sin(tr.pitch())},
                          {    0      , 1,     0     },
                          {-sin(tr.pitch()), 0, cos(tr.pitch())}});

    Matrix roll_matrix  ({{    1  ,     0    ,     0     },
                          {    0  , cos(tr.roll()), -sin(tr.roll())},
                          {    0  , sin(tr.roll()),  cos(tr.roll())}});

    Matrix rotation = yaw_matrix * pitch_matrix * roll_matrix;

    rotation.rowAppend(Matrix(tr.position, VERTICAL));

    rotation.columnAppend({{0,0,0,1}});

    return rotation;
}

Vectorn AbsoluteJoint::rototransform(Transform tr) {

    Vectorn homogenous(4);

    for (int i = 0; i < 3; i++) {
        homogenous[i] = pm_transform.position[i] + pm_link.link_end[i];
    }

    homogenous[3] = 1;

    Matrix newposition = getHomogenousTransformationMatrix(tr) * Matrix(homogenous, VERTICAL);

    for (int i = 0; i < 3; i++) {
        pm_joint_effector[i] = newposition(i,0);
    }

    return pm_joint_effector;
}

#pragma endregion

#pragma region Revolute Joint

Matrix RevoluteJoint::getHomogenousTransformationMatrix(Transform tr) {

    Matrix yaw_matrix   ({{cos(tr.yaw()), -sin(tr.yaw()), 0},
                          {sin(tr.yaw()),  cos(tr.yaw()), 0},
                          {    0   ,    0     , 1}});

    Matrix pitch_matrix ({{ cos(tr.pitch()), 0, sin(tr.pitch())},
                          {    0      , 1,     0     },
                          {-sin(tr.pitch()), 0, cos(tr.pitch())}});

    Matrix roll_matrix  ({{    1  ,     0    ,     0     },
                          {    0  , cos(tr.roll()), -sin(tr.roll())},
                          {    0  , sin(tr.roll()),  cos(tr.roll())}});

    Matrix rotation = yaw_matrix * pitch_matrix * roll_matrix;

    rotation.rowAppend(Matrix(tr.position, VERTICAL));

    rotation.columnAppend({{0,0,0,1}});

    return rotation;
}

Vectorn RevoluteJoint::rototransform(Transform tr) {

    Vectorn homogenous(4);

    for (int i = 0; i < 3; i++) {
        homogenous[i] = pm_transform.position[i] + pm_link.link_end[i];
    }

    homogenous[3] = 1;

    Matrix newposition = getHomogenousTransformationMatrix(tr) * Matrix(homogenous, VERTICAL);

    for (int i = 0; i < 3; i++) {
        pm_joint_effector[i] = newposition(i,0);
    }

    return pm_joint_effector;
}

#pragma endregion

#pragma region Prismatic Joint

Matrix PrismaticJoint::getHomogenousTransformationMatrix(Transform tr) {

    Matrix yaw_matrix   ({{cos(tr.yaw()), -sin(tr.yaw()), 0},
                          {sin(tr.yaw()),  cos(tr.yaw()), 0},
                          {    0   ,    0     , 1}});

    Matrix pitch_matrix ({{ cos(tr.pitch()), 0, sin(tr.pitch())},
                          {    0      , 1,     0     },
                          {-sin(tr.pitch()), 0, cos(tr.pitch())}});

    Matrix roll_matrix  ({{    1  ,     0    ,     0     },
                          {    0  , cos(tr.roll()), -sin(tr.roll())},
                          {    0  , sin(tr.roll()),  cos(tr.roll())}});

    Matrix rotation = roll_matrix * pitch_matrix * yaw_matrix;

    rotation.rowAppend(Matrix(tr.position, VERTICAL));

    rotation.columnAppend({{0,0,0,1}});

    return rotation;
}

Vectorn PrismaticJoint::rototransform(Transform tr) {

    Vectorn homogenous(4);

    for (int i = 0; i < 3; i++) {
        homogenous[i] = pm_transform.position[i] + pm_link.link_end[i];
    }

    homogenous[3] = 1;

    Matrix newposition = getHomogenousTransformationMatrix(tr) * Matrix(homogenous, VERTICAL);

    for (int i = 0; i < 3; i++) {
        pm_joint_effector[i] = newposition(i,0);
    }

    return pm_joint_effector;
}

#pragma endregion