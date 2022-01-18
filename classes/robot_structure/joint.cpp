#include "joint.h"

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

    Matrix yaw_matrix   ({{cos(tr.yaw()), -sin(tr.yaw()), 0, 0},
                          {sin(tr.yaw()),  cos(tr.yaw()), 0, 0},
                          {      0      ,        0      , 1, 0},
                          {      0      ,        0      , 0, 1}});

    Matrix pitch_matrix ({{ cos(tr.pitch()), 0, sin(tr.pitch()),0},
                          {        0       , 1,       0        ,0},
                          {-sin(tr.pitch()), 0, cos(tr.pitch()),0},
                          {        0       , 0,       0        ,1}});

    Matrix roll_matrix  ({{1,        0      ,         0      ,0},
                          {0, cos(tr.roll()), -sin(tr.roll()),0},
                          {0, sin(tr.roll()),  cos(tr.roll()),0},
                          {0,        0      ,         0      ,1}});

    Matrix rotation = yaw_matrix * pitch_matrix * roll_matrix;

    return rotation;
}

Vectorn RevoluteJoint::rototransform(Transform tr) {

    Matrix newposition = getHomogenousTransformationMatrix(tr) * Matrix(pm_transform.position + pm_link.link_end, VERTICAL);

    for (int i = 0; i < 3; i++) {
        pm_joint_effector[i] = newposition(i,0);
    }

    return pm_joint_effector;
}

Matrix UnidirectionalRevoluteJoint::getHomogenousTransformationMatrix(Transform tr) {

    Matrix rotation(3,3);

    switch (m_axis) {
        case Yaw:
            rotation = {{cos(tr.yaw()), -sin(tr.yaw()), 0},
                        {sin(tr.yaw()),  cos(tr.yaw()), 0},
                        {      0      ,       0       , 1}};
            break;
        
        case Pitch:
            rotation = {{ cos(tr.pitch()), 0, sin(tr.pitch())},
                        {        0       , 1,        0       },
                        {-sin(tr.pitch()), 0, cos(tr.pitch())}};
            break;
        
        case Roll:
            rotation = {{ 1,       0       ,        0       },
                        { 0, cos(tr.roll()), -sin(tr.roll())},
                        { 0, sin(tr.roll()),  cos(tr.roll())}};
            break;
    }

    return rotation;
}

Vectorn UnidirectionalRevoluteJoint::rototransform(Transform tr) {

    Matrix newposition = getHomogenousTransformationMatrix(tr) * Matrix(pm_transform.position + pm_link.link_end, VERTICAL);

    for (int i = 0; i < 3; i++) {
        pm_joint_effector[i] = newposition(i,0);
    }

    return pm_joint_effector;
}

#pragma endregion

#pragma region Prismatic Joint

Matrix PrismaticJoint::getHomogenousTransformationMatrix(Transform tr) {

    Matrix rotation ( Matrix::identityMatrix(3) );

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

Matrix UnidirectionalPrismaticJoint::getHomogenousTransformationMatrix(Transform tr) {

    Matrix rotation ( Matrix::identityMatrix(3) );

    switch (m_axis) {
        case X:
            rotation.rowAppend(Matrix({tr.x(),0,0}, VERTICAL));
            break;
        
        case Y:
            rotation.rowAppend(Matrix({0,tr.y(),0}, VERTICAL));
            break;

        case Z:
            rotation.rowAppend(Matrix({0,0,tr.z()}, VERTICAL));
            break;
    }

    rotation.columnAppend({{0,0,0,1}});

    return rotation;
}

Vectorn UnidirectionalPrismaticJoint::rototransform(Transform tr) {

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

Matrix Joint::linkMatrix() {
    Matrix translation ( Matrix::identityMatrix(3) );

    translation.rowAppend(Matrix(pm_link.link_end, VERTICAL));

    translation.columnAppend({{0,0,0,1}});

    return translation;
}