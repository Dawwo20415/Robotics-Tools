#include "matrix.h"

#pragma region Exception_Handlers

void Matrix::constructorPreconditions(const int row, const int column) const {
    try {
        if (
        //Conditions
        row > pm_matrix.max_size()    || 
        column > pm_matrix.max_size() ||
        row <= 0 || column <= 0
        ) {
            //Exception
            throw std::out_of_range(
                "In creation of Matrix: passed parameter row:" +
                std::to_string(row) + " column:" + std::to_string(column) +
                " out of range for std::vector<float>"); //Out of scope dimension
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
}

void Matrix::operatorPreconditions(const int row, const int column) const {
    try {
        if (
        //Conditions
        row > pm_row_dim || 
        column > pm_column_dim ||
        row < 0 || column < 0
        ) {
            //Exception
            throw std::out_of_range(
                "In access of Matrix: passed parameter row:" +
                std::to_string(row) + " column:" + std::to_string(column) +
                " out of range"); //Out of scope dimension
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
}

#pragma endregion

#pragma region Constructors

Matrix::Matrix(unsigned int row, unsigned int column) {

    //Preconditions
    constructorPreconditions(row, column);

    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Row " << pm_row_dim 
                << " | Column " << pm_column_dim
                << " | Index "  << index << " |" << std::endl;
    #endif

    //Constructor
    pm_column_dim = column;
    pm_row_dim = row;

    for (int i = 0; i < column; i++) {
        pm_matrix.push_back(std::move(Vectorn(row)));
    }

}

#pragma endregion

#pragma region Operators

//Selection operators
float& Matrix::operator()(int row, int column) {
    operatorPreconditions(row,column);
    
    return (pm_matrix[column])[row];
}

const float& Matrix::operator()(int row, int column) const{
    operatorPreconditions(row,column);
    
    return (pm_matrix[column])[row];
}

#pragma endregion

#if DEBUG
unsigned int Vectorn::counter = 0;
#endif