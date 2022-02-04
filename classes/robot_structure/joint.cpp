#include "joint.h"

#pragma region Absolute Joint

Matrix AbsoluteJoint::getHomogenousTransformationMatrix(Transform tr) {

    if (!applyTransform(tr)) return Matrix::identityMatrix(4);

    pm_current_tr = tr;

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

bool AbsoluteJoint::applyTransform(Transform tr) {

    if (tr.x() < pm_lower_limit.x() || tr.x() > pm_upper_limit.x()) return false;
    if (tr.y() < pm_lower_limit.y() || tr.y() > pm_upper_limit.y()) return false;
    if (tr.z() < pm_lower_limit.z() || tr.z() > pm_upper_limit.z()) return false;
    if (tr.yaw() < pm_lower_limit.yaw() || tr.yaw() > pm_upper_limit.yaw()) return false;
    if (tr.roll() < pm_lower_limit.roll() || tr.roll() > pm_upper_limit.roll()) return false;
    if (tr.pitch() < pm_lower_limit.pitch() || tr.pitch() > pm_upper_limit.pitch()) return false;

    return true;
}

#pragma endregion

#pragma region Revolute Joint

Matrix RevoluteJoint::getHomogenousTransformationMatrix(Transform tr) {

    if (!applyTransform(tr)) return Matrix::identityMatrix(4);

    pm_current_tr = tr;

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

bool RevoluteJoint::applyTransform(Transform tr) {

    if (tr.yaw() < pm_lower_limit.yaw() || tr.yaw() > pm_upper_limit.yaw()) return false;
    if (tr.roll() < pm_lower_limit.roll() || tr.roll() > pm_upper_limit.roll()) return false;
    if (tr.pitch() < pm_lower_limit.pitch() || tr.pitch() > pm_upper_limit.pitch()) return false;

    return true;
}

Matrix UnidirectionalRevoluteJoint::getHomogenousTransformationMatrix(Transform tr) {

    if (!applyTransform(tr)) return Matrix::identityMatrix(4);

    pm_current_tr = tr;

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

bool UnidirectionalRevoluteJoint::applyTransform(Transform tr) {
    
    switch (m_axis) {
    case Yaw:
        if (tr.yaw() < pm_lower_limit.yaw() || tr.yaw() > pm_upper_limit.yaw()) return false;
        break;
    case Pitch:
        if (tr.pitch() < pm_lower_limit.pitch() || tr.pitch() > pm_upper_limit.pitch()) return false;
        break;
    case Roll:
        if (tr.roll() < pm_lower_limit.roll() || tr.roll() > pm_upper_limit.roll()) return false;
        break;
    }

    return true;
}

#pragma endregion

#pragma region Prismatic Joint

Matrix PrismaticJoint::getHomogenousTransformationMatrix(Transform tr) {

    if (!applyTransform(tr)) return Matrix::identityMatrix(4);

    pm_current_tr = tr;

    Matrix rotation ( Matrix::identityMatrix(3) );

    rotation.rowAppend(Matrix(tr.position, VERTICAL));

    rotation.columnAppend({{0,0,0,1}});

    return rotation;
}

bool PrismaticJoint::applyTransform(Transform tr) {

    if (tr.x() < pm_lower_limit.x() || tr.x() > pm_upper_limit.x()) return false;
    if (tr.y() < pm_lower_limit.y() || tr.y() > pm_upper_limit.y()) return false;
    if (tr.z() < pm_lower_limit.z() || tr.z() > pm_upper_limit.z()) return false;

    return true;
}

Matrix UnidirectionalPrismaticJoint::getHomogenousTransformationMatrix(Transform tr) {

    if (!applyTransform(tr)) return Matrix::identityMatrix(4);

    pm_current_tr = tr;

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

bool UnidirectionalPrismaticJoint::applyTransform(Transform tr) {
    
    switch (m_axis) {
    case X:
        if (tr.x() < pm_lower_limit.x() || tr.x() > pm_upper_limit.x()) return false;
        break;
    case Y:
        if (tr.y() < pm_lower_limit.y() || tr.y() > pm_upper_limit.y()) return false;
        break;
    case Z:
        if (tr.z() < pm_lower_limit.z() || tr.z() > pm_upper_limit.z()) return false;
        break;
    }
    
    return true;
}

#pragma endregion

Matrix Joint::linkMatrix() {
    return pm_link.link_matrix();
}