#include "robot.h"

/*
Vectorn Robot::getEndEffector () {

    Matrix transformation_matrix(Matrix::identityMatrix(4));
    Matrix current_position(4,1);

    Vectorn homogenous_position(Vectorn::unitVector(4));

    std::cout << "-------------------------------------------- | FIRST POSITION VECTOR" << std::endl;
    
    for (int i = 0; i < 3; i++) {
        homogenous_position[i] = 0 pm_starting_position[i];
    }

    homogenous_position.println();

    for (int i = 0; i < pm_joints.size(); i++) {

        std::cout << "-------------------------------------------- | CURRENT TRANSFORMATION MATRIX" << std::endl;

        transformation_matrix *= pm_joints[i]->getHomogenousTransformationMatrix(pm_transforms[i]);
        transformation_matrix.println();

        current_position = transformation_matrix * Matrix(homogenous_position, VERTICAL);

        std::cout << "-------------------------------------------- | CURRENT POSITION VECTOR" << std::endl;

        current_position.getRotated().println();

        transformation_matrix *= pm_joints[i]->linkMatrix();

    }

    transformation_matrix.println();

    std::cout << "-------------------------------------------- | CURRENT TRANSFORMATION MATRIX" << std::endl;

    Matrix result = transformation_matrix * Matrix(homogenous_position, VERTICAL);

    for (int i = 0; i < 3; i++) {
        pm_endeffector[i] += result(i,0);
    }

    return pm_endeffector;
}
*/

Vectorn Robot::getEndEffector () {

    //First link transformation matrix
    Matrix homogenous_matrix (Matrix::identityMatrix(3));
    homogenous_matrix.rowAppend(Matrix(pm_starting_position, VERTICAL));
    homogenous_matrix.columnAppend({{0,0,0,1}});

    //Cycle trough all the joints and associated links
    for (int i = 0; i < pm_joints.size(); i++) {
        homogenous_matrix *= pm_joints[i]->getHomogenousTransformationMatrix(pm_transforms[i]);
        homogenous_matrix *= pm_joints[i]->linkMatrix();
    }

    //Calculate actual position
    Matrix current_position = homogenous_matrix * Matrix({0,0,0,1}, VERTICAL);

    for (int i = 0; i < 3; i++) {
        pm_endeffector[i] = current_position(i,0);
    }

    return pm_endeffector;

}