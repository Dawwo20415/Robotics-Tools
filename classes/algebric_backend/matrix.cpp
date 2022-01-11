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

void Matrix::constructorPreconditions(const int row, const int column, const int otherRow, const int otherColumn) const {
    try {
        if (
        //Conditions
        row > otherRow   || 
        column > otherColumn ||
        row <= 0 || column <= 0
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

void Matrix::constructorPreconditions(const int row1, const int row2, const int column1, const int column2, const int otherRow, const int otherColumn) const {
    try {
        if (
        //Conditions
        row1 < 0 ||
        column1 < 0 ||
        row2 - row1 + 1 <= 0 ||
        column2 - column1 + 1 <= 0 ||
        row2 - row1 + 1 > otherRow   || 
        column2 - column1 + 1 > otherColumn
        ) {
            //Exception
            throw std::out_of_range(
                "In access of Matrix: passed parameter row:" +
                std::to_string(row2 - row1) + " column:" + std::to_string(column2 - column1) +
                " out of range"); //Out of scope dimension
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
}

void Matrix::constructorPreconditions(const std::initializer_list<std::initializer_list<float>>& other) const {
    try {
        int row = other.begin()->size();
        int column = other.size();

        for (auto element : other) {
            if (row != element.size()) {
                throw std::invalid_argument("In creation of Matrix: passed initializer list with rows of uneven size");
            }
        }

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

Matrix::Matrix(const Matrix& other) {
    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Row " << pm_row_dim 
                << " | Column " << pm_column_dim
                << " | Index "  << index << " |" << std::endl;
    #endif

    //Constructor
    pm_column_dim = other.pm_column_dim;
    pm_row_dim = other.pm_row_dim;
    pm_matrix = other.pm_matrix;
}

Matrix::Matrix(unsigned int n_rows, unsigned int n_columns, const Matrix& other) {
    //Preconditions
    constructorPreconditions(n_rows, n_columns, other.pm_row_dim, other.pm_column_dim);
    
    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Row " << pm_row_dim 
                << " | Column " << pm_column_dim
                << " | Index "  << index << " |" << std::endl;
    #endif

    //Constructor
    pm_column_dim = n_columns;
    pm_row_dim = n_rows;

    for (int c = 0; c < n_rows; c++) {
        Vectorn tmp(n_columns);
        for (int r = 0; r < n_columns; r++) {
            tmp[r] = other(r,c);
        }
        pm_matrix.push_back(tmp);
    }
}

Matrix::Matrix(unsigned int row1, unsigned int column1, unsigned int row2, unsigned int column2, const Matrix& other) {
    //Preconditions
    constructorPreconditions(row1, row2, column1, column2, other.pm_row_dim, other.pm_column_dim);
    
    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Row " << pm_row_dim 
                << " | Column " << pm_column_dim
                << " | Index "  << index << " |" << std::endl;
    #endif

    //Constructor
    pm_column_dim = column2 - column1 + 1;
    pm_row_dim = row2 - row1 + 1;
    
    for (int c = row1; c <= row2; c++) {
        Vectorn tmp(pm_column_dim);
        for (int r = column1; r <= column2; r++) {
            tmp[r - column1] = other(r,c);
        }
        pm_matrix.push_back(tmp);
    }
}

Matrix::Matrix(const std::initializer_list<std::initializer_list<float>>& other) {
    //Preconditions
    constructorPreconditions(other);
    
    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Row " << pm_row_dim 
                << " | Column " << pm_column_dim
                << " | Index "  << index << " |" << std::endl;
    #endif

    //Constructor
    pm_column_dim = other.begin()->size();
    pm_row_dim = other.size();
    
    for (auto element : other) {
        pm_matrix.push_back(element);
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

//Assignment operators
Matrix& Matrix::operator=(const Matrix& other) {
    pm_row_dim = other.pm_row_dim;
    pm_column_dim = other.pm_column_dim;

    pm_matrix = other.pm_matrix;

    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept{
    pm_row_dim = other.pm_row_dim;
    pm_column_dim = other.pm_column_dim;

    pm_matrix = std::move(other.pm_matrix);

    return *this;
}

#pragma endregion

#pragma region Functions

void Matrix::Println() const {
    std::string tmp;
    for (int i = 0; i < pm_row_dim; i++) {
        std::string line;
        //Left Wall
        if (i == 0) {
            line += "⎡ ";
        } else if (i == pm_row_dim - 1) {
            line += "⎣ ";
        } else {
            line += "⎢ ";
        }

        //Contents
        for (int j = 0; j < pm_column_dim; j++) {
            if (j == pm_column_dim - 1){
                line += std::to_string((pm_matrix[i])[j]);
            } else {
                line += std::to_string((pm_matrix[i])[j]) + " | ";
            }      
        }

        //Right Wall
        if (i == 0) {
            line += "⎤\n";
        } else if (i == pm_row_dim - 1) {
            line += "⎦";
        } else {
            line += "⎥\n";
        }
        tmp += line;
    }
    std::cout << tmp << std::endl;
}

#pragma endregion


#if DEBUG
unsigned int Vectorn::counter = 0;
#endif