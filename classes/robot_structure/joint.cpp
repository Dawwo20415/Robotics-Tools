#include "joint.h"

#pragma region Revolute Joint

bool RevoluteJoint::setPosition(Transform tr) {
    if (!applyTransform(tr))
        return false;
    
    pm_current_tr = tr;
    return true;
}

bool UnidirectionalRevoluteJoint::setPosition(Transform tr) {
    if (!applyTransform(tr))
        return false;
    
    pm_current_tr = tr;
    return true;
}

Matrix RevoluteJoint::getHomogenousTransformationMatrix() {

    Matrix yaw_matrix   ({{cos(pm_current_tr.yaw()), -sin(pm_current_tr.yaw()), 0, 0},
                          {sin(pm_current_tr.yaw()),  cos(pm_current_tr.yaw()), 0, 0},
                          {      0      ,        0      , 1, 0},
                          {      0      ,        0      , 0, 1}});

    Matrix pitch_matrix ({{ cos(pm_current_tr.pitch()), 0, sin(pm_current_tr.pitch()),0},
                          {        0       , 1,       0        ,0},
                          {-sin(pm_current_tr.pitch()), 0, cos(pm_current_tr.pitch()),0},
                          {        0       , 0,       0        ,1}});

    Matrix roll_matrix  ({{1,        0      ,         0      ,0},
                          {0, cos(pm_current_tr.roll()), -sin(pm_current_tr.roll()),0},
                          {0, sin(pm_current_tr.roll()),  cos(pm_current_tr.roll()),0},
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

Matrix UnidirectionalRevoluteJoint::getHomogenousTransformationMatrix() {

    Matrix rotation(3,3);

    switch (m_axis) {
        case Yaw:
            rotation = {{cos(pm_current_tr.yaw()), -sin(pm_current_tr.yaw()), 0},
                        {sin(pm_current_tr.yaw()),  cos(pm_current_tr.yaw()), 0},
                        {      0      ,       0       , 1}};
            break;
        
        case Pitch:
            rotation = {{ cos(pm_current_tr.pitch()), 0, sin(pm_current_tr.pitch())},
                        {        0       , 1,        0       },
                        {-sin(pm_current_tr.pitch()), 0, cos(pm_current_tr.pitch())}};
            break;
        
        case Roll:
            rotation = {{ 1,       0       ,        0       },
                        { 0, cos(pm_current_tr.roll()), -sin(pm_current_tr.roll())},
                        { 0, sin(pm_current_tr.roll()),  cos(pm_current_tr.roll())}};
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

Matrix RevoluteJoint::getHomogenousTransformationMatrixSteps (Transform tr, int step) {
    if (!applyTransform(tr)) return Matrix::identityMatrix(4);

    Matrix rotation(4,4);

    pm_current_tr = tr;

    switch (step) {
        case 0:
            rotation = Matrix({{1,        0      ,         0      ,0},
                               {0, cos(tr.roll()), -sin(tr.roll()),0},
                               {0, sin(tr.roll()),  cos(tr.roll()),0},
                               {0,        0      ,         0      ,1}});
            break;
        case 1:
            rotation = Matrix({{ cos(tr.pitch()), 0, sin(tr.pitch()),0},
                               {        0       , 1,       0        ,0},
                               {-sin(tr.pitch()), 0, cos(tr.pitch()),0},
                               {        0       , 0,       0        ,1}});
            break;
        case 2:
            rotation = Matrix({{cos(tr.yaw()), -sin(tr.yaw()), 0, 0},
                               {sin(tr.yaw()),  cos(tr.yaw()), 0, 0},
                               {      0      ,        0      , 1, 0},
                               {      0      ,        0      , 0, 1}});
            break;
    }

    return rotation;

}

Matrix RevoluteJoint::getJacobianSection(Matrix& jacobian, const Matrix& homogenous, const Vectorn& endEffector) {
    Matrix tmp(6,1);
    Vectorn upper(3);
    Vectorn precedentPosition(3);

    for (int i = 0; i < 3; i++) {
        upper[i] = homogenous(i,2);
        tmp(i+3,0) = homogenous(i,2);
        precedentPosition[i] = homogenous(i,3);
    }

    upper *= (endEffector - precedentPosition);

    for (int i = 0; i < 3; i++) {
        tmp(i,0) = upper[i];
    }

    return tmp;
}

Matrix UnidirectionalRevoluteJoint::getJacobianSection(Matrix& jacobian, const Matrix& homogenous, const Vectorn& endEffector) {
    Matrix tmp(6,1);
    Vectorn upper(3);
    Vectorn precedentPosition(3);

    for (int i = 0; i < 3; i++) {
        upper[i] = homogenous(i,2);
        tmp(i+3,0) = homogenous(i,2);
        precedentPosition[i] = homogenous(i,3);
    }

    upper *= (endEffector - precedentPosition);

    for (int i = 0; i < 3; i++) {
        tmp(i,0) = upper[i];
    }

    return tmp;
}

Vectorn RevoluteJoint::getConfigurationSpace() {
    return Vectorn( {pm_current_tr.roll(), pm_current_tr.pitch(), pm_current_tr.yaw()} );
}

Vectorn UnidirectionalRevoluteJoint::getConfigurationSpace() {
    switch (m_axis)
    {
    case Roll:
        return Vectorn( {pm_current_tr.roll()} );
        break;
    case Pitch:
        return Vectorn( {pm_current_tr.pitch()} );
        break;
    case Yaw:
        return Vectorn( {pm_current_tr.yaw()} );
        break;
    }

    return Vectorn::unitVector(1);
}

#pragma endregion

#pragma region Prismatic Joint

bool PrismaticJoint::setPosition(Transform tr) {
    if (!applyTransform(tr))
        return false;
    
    pm_current_tr = tr;
    return true;
}

bool UnidirectionalPrismaticJoint::setPosition(Transform tr) {
    if (!applyTransform(tr))
        return false;
    
    pm_current_tr = tr;
    return true;
}

Matrix PrismaticJoint::getHomogenousTransformationMatrix() {

    Matrix rotation ( Matrix::identityMatrix(3) );

    rotation.rowAppend(Matrix(pm_current_tr.position, VERTICAL));

    rotation.columnAppend({{0,0,0,1}});

    return rotation;
}

bool PrismaticJoint::applyTransform(Transform tr) {

    if (tr.x() < pm_lower_limit.x() || tr.x() > pm_upper_limit.x()) return false;
    if (tr.y() < pm_lower_limit.y() || tr.y() > pm_upper_limit.y()) return false;
    if (tr.z() < pm_lower_limit.z() || tr.z() > pm_upper_limit.z()) return false;

    return true;
}

Matrix UnidirectionalPrismaticJoint::getHomogenousTransformationMatrix() {
    Matrix rotation ( Matrix::identityMatrix(3) );

    switch (m_axis) {
        case X:
            rotation.rowAppend(Matrix({pm_current_tr.x(),0,0}, VERTICAL));
            break;
        
        case Y:
            rotation.rowAppend(Matrix({0,pm_current_tr.y(),0}, VERTICAL));
            break;

        case Z:
            rotation.rowAppend(Matrix({0,0,pm_current_tr.z()}, VERTICAL));
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

Matrix PrismaticJoint::getHomogenousTransformationMatrixSteps (Transform tr, int step) {
    if (!applyTransform(tr)) return Matrix::identityMatrix(4);

    Matrix rotation ( Matrix::identityMatrix(3) );

    pm_current_tr = tr;

    switch (step) {
        case 0:
            rotation.rowAppend(Matrix({tr.x(),0,0}, VERTICAL));
            break;
        case 1:
            rotation.rowAppend(Matrix({0,tr.y(),0}, VERTICAL));
            break;
        case 2:
            rotation.rowAppend(Matrix({0,0,tr.z()}, VERTICAL));
            break;
    }

    rotation.columnAppend({{0,0,0,1}});

    return rotation;

}

Matrix PrismaticJoint::getJacobianSection(Matrix& jacobian, const Matrix& homogenous, const Vectorn& endEffector) {
    Matrix tmp(6,1);

    for (int i = 0; i < 3; i++) {
        tmp(i,0) = homogenous(i,2);
    }



    return tmp;
}

Matrix UnidirectionalPrismaticJoint::getJacobianSection(Matrix& jacobian, const Matrix& homogenous, const Vectorn& endEffector) {
    Matrix tmp(6,1);

    for (int i = 0; i < 3; i++) {
        tmp(i,0) = homogenous(i,2);
    }

    return tmp;
}

Vectorn PrismaticJoint::getConfigurationSpace() {
    return Vectorn( {pm_current_tr.x(), pm_current_tr.y(), pm_current_tr.z()} );
}

Vectorn UnidirectionalPrismaticJoint::getConfigurationSpace() {
    switch (m_axis)
    {
    case X:
        return Vectorn( {pm_current_tr.x()} );
        break;
    case Y:
        return Vectorn( {pm_current_tr.y()} );
        break;
    case Z:
        return Vectorn( {pm_current_tr.z()} );
        break;
    }
    return Vectorn::unitVector(1);
}

#pragma endregion

Matrix Joint::linkMatrix() {
    return pm_link.link_matrix();
}

void Joint::printStatus() {
    std::cout << pm_current_tr.getString(); 
}

Vectorn Joint::jointVector() {
    Vectorn tmp (pm_link.link_end);
    Vectorn::toHomogenous(tmp);

    Matrix mat = getHomogenousTransformationMatrix() * Matrix(tmp, VERTICAL);

    tmp = Matrix::toVector(mat);

    Vectorn::toCoordinates(tmp);

    return tmp;

}

void Joint::printVector() {
    jointVector().print();
}

Matrix Joint::getJacobianSection(Matrix& jacobian, const Matrix& homogenous, const Vectorn& endEffector) {
    return Matrix(6,1);
}