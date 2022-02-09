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
                " out of range for std::vector<double>"); //Out of scope dimension
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

void Matrix::constructorPreconditions(const std::initializer_list<std::initializer_list<double>>& other) const {
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
                " out of range for std::vector<double>"); //Out of scope dimension
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
}

void Matrix::algebricSumPreconditions(const Matrix& other) const {
    try {
        if (
        //Conditions
        pm_column_dim != other.pm_column_dim ||
        pm_row_dim != other.pm_row_dim
        ) {
            //Exception
            throw std::invalid_argument(
                "In algebric sum of 2 Matrixes: passed parameter row or colum that are not the same");
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }    
}

void Matrix::multiplicationPreconditions(const Matrix& other) const {
    try {
        if (
        //Conditions
        pm_column_dim != other.pm_row_dim
        ) {
            //Exception
            throw std::invalid_argument(
                "In algebric sum of 2 Matrixes: passed parameter row or colum that are not the same");
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
}

void Matrix::determinantPreconditions() const {
    try {
        if (
        //Conditions
        pm_column_dim != pm_row_dim
        ) {
            //Exception
            throw std::invalid_argument(
                "Determinant cannot be calculated on non-square Matrix");
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
}

void Matrix::areTheSamePreconditions(unsigned int value1, unsigned int value2) const {
    try {
        if (
        //Conditions
        value1 != value2
        ) {
            //Exception
            throw std::invalid_argument(
                "Cannot Append matrixes of different sizes on append side");
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
}

void Matrix::rowPreconditions(const int& index) const {
    try {
        if (
        //Conditions
        index < 0 || index > pm_row_dim
        ) {
            //Exception
            throw std::out_of_range(
                "Invalid row index has been passed to function");
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
}

void Matrix::columnPreconditions(const int& index) const {
    try {
        if (
        //Conditions
        index < 0 || index > pm_column_dim
        ) {
            //Exception
            throw std::out_of_range(
                "Invalid row index has been passed to function");
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
}

void Matrix::invertiblePreconditions(const Matrix& other) const {
    try {
        double determinant = 1;

        for (int i = 0; i < other.pm_row_dim; i++) {
            determinant *= other(i,i);
        }

        if (
        //Conditions
            determinant == 0
        ) {
            //Exception
            throw std::invalid_argument(
                "This Matrix cannot be inverted | Determinant = 0");
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
}

void Matrix::toVectorConditions(const Matrix& subject){
    try {

        if (
        //Conditions
            subject.pm_column_dim != 1 && subject.pm_row_dim != 1
        ) {
            //Exception
            throw std::invalid_argument(
                "This Matrix cannot be translated into a Vector | Not a single dimension matrix");
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

    for (int i = 0; i < row; i++) {
        pm_matrix.push_back(std::move(Vectorn(column)));
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
            tmp[r] = other(c,r);
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
            tmp[r - column1] = other(c,r);
        }
        pm_matrix.push_back(tmp);
    }
}

Matrix::Matrix(const std::initializer_list<std::initializer_list<double>>& other) {
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

Matrix::Matrix(const Vectorn& vector, bool direction) {
    if (direction) {
        //Vertical
        pm_column_dim = 1;
        pm_row_dim    = vector.getDimension();
        for (int i = 0; i < pm_row_dim; i++) {
            pm_matrix.push_back(Vectorn({vector[i]}));
        }
    } else {
        //Horizontal
        pm_column_dim = vector.getDimension();
        pm_row_dim    = 1;
        pm_matrix.push_back(vector);
    }
}

#pragma endregion

#pragma region Operators

//Selection operators
double& Matrix::operator()(int row, int column) {
    operatorPreconditions(row,column);
    
    return (pm_matrix[row])[column];
}

const double& Matrix::operator()(int row, int column) const{
    operatorPreconditions(row,column);
    
    return (pm_matrix[row])[column];
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

//Addition operators
Matrix& Matrix::operator+=(const Matrix& other) {
    //Preconditions
    algebricSumPreconditions(other);
    
    for (int i = 0; i < pm_column_dim; i++) {
        pm_matrix[i] += other.pm_matrix[i];
    }
    return *this;
}

Matrix operator+(Matrix first, const Matrix& second) {
    first += second;
    return first;
}

//Addition operators
Matrix& Matrix::operator-=(const Matrix& other) {
    //Preconditions
    algebricSumPreconditions(other);
    
    for (int i = 0; i < pm_column_dim; i++) {
        pm_matrix[i] -= other.pm_matrix[i];
    }
    return *this;
}

Matrix operator-(Matrix first, const Matrix& second) {
    first -= second;
    return first;
}

//Multiplication by a Scalar operator
Matrix& Matrix::operator*=(const double& value) {
    for (int i = 0; i < pm_column_dim; i++) {
        pm_matrix[i] *= value;
    }
    return *this;
}

Matrix operator*(Matrix mat, const double& value) {
    mat *= value;
    return mat;
}

//Division by a Scalar operator
Matrix& Matrix::operator/=(const double& value) {
    for (int i = 0; i < pm_column_dim; i++) {
        pm_matrix[i] /= value;
    }
    return *this;
}

Matrix operator/(Matrix mat, const double& value) {
    mat /= value;
    return mat;
}

//Multiplication by a Matrix operator
Matrix& Matrix::operator*=(const Matrix& other) {
    //Preconditions
    multiplicationPreconditions(other);

    Matrix tmp(pm_row_dim, other.pm_column_dim);

    for (int r = 0; r < pm_row_dim; r++) {
        for (int c = 0; c < other.pm_column_dim; c++) {
            for (int i = 0; i < pm_column_dim; i++) {
                tmp(r,c) += (pm_matrix[r])[i] * other(i,c);
            }
        }
    }

    *this = tmp;

    return *this;
}

Matrix operator*(Matrix mat, const Matrix& other) {
    mat *= other;
    return mat;
}

#pragma endregion

#pragma region Functions

double& Matrix::access(int row, int column) {
    operatorPreconditions(row,column);
    
    return (pm_matrix[row])[column];
}

const double& Matrix::access(int row, int column) const {
    operatorPreconditions(row,column);
    
    return (pm_matrix[row])[column];
}

void Matrix::println() const {
    this->print();
    std::cout << std::endl;
}

void Matrix::print() const {
    std::string tmp;
    for (int i = 0; i < pm_row_dim; i++) {
        std::stringstream line;
        line << std::fixed << std::setprecision(2);
        //Left Wall
        if (i == 0) {
            line << "⎡ ";
        } else if (i == pm_row_dim - 1) {
            line << "⎣ ";
        } else {
            line << "⎢ ";
        }

        //Contents
        for (int j = 0; j < pm_column_dim; j++) {
            if (j == pm_column_dim - 1){
                (pm_matrix[i])[j] < 0 ? line << (pm_matrix[i])[j] << " " : line << " " << (pm_matrix[i])[j] << " ";
            } else {
                (pm_matrix[i])[j] < 0 ? line << (pm_matrix[i])[j] << " | " : line << " " << (pm_matrix[i])[j] << " | ";
            }      
        }

        //Right Wall
        if (i == 0) {
            line << " ⎤\n";
        } else if (i == pm_row_dim - 1) {
            line << " ⎦";
        } else {
            line << " ⎥\n";
        }
        tmp += line.str();
    }
    std::cout << tmp;
}

void Matrix::moveRow(unsigned int row1, unsigned int row2) {
    //Preconditions
    rowPreconditions(row1);
    rowPreconditions(row2);

    std::swap(pm_matrix[row1], pm_matrix[row2]);

}

void Matrix::multiplyRow(unsigned int row, double value) {
    //Preconditions
    rowPreconditions(row);

    pm_matrix[row] *= value;

}

void Matrix::replaceRow(unsigned int row1, unsigned int row2, double value) {
    //Preconditions
    rowPreconditions(row1);
    rowPreconditions(row2);

    pm_matrix[row1] -= pm_matrix[row2] * value;

}

void Matrix::rowEchelonForm() {
    //Creating Upper Triangular
    for (int i = 0; i < pm_row_dim; i++) {

        //Reorder rows if needed (0 as pivot)
        if (access(i,i) == 0) {
            int j = i + 1;
            while (access(i,j) == 0 && j < pm_row_dim)
                j++;

            if (j >= pm_row_dim)
                continue;

            moveRow(i, j);
        }

        //Row Replacement
        for (int j = i + 1; j < pm_row_dim; j++) {

            if (access(i,i) == 0)
                continue;

            double k = access(j,i) / access(i,i);
            replaceRow(j, i, k);
        }
    }
}

void Matrix::rowEchelonForm(bool& determinant_sign) {
    //Creating Upper Triangular
    for (int i = 0; i < pm_row_dim; i++) {

        //Reorder rows if needed (0 as pivot)
        if (access(i,i) == 0) {
            int j = i + 1;
            while (access(i,j) == 0 && j < pm_row_dim)
                j++;

            if (j >= pm_row_dim)
                continue;

            moveRow(i, j);
            determinant_sign = !determinant_sign;
        }

        //Row Replacement
        for (int j = i + 1; j < pm_row_dim; j++) {

            double k = access(j,i) / access(i,i);
            replaceRow(j, i, k);
        }
    }
}

void Matrix::rowAppend(const Matrix& other) {
    areTheSamePreconditions(pm_row_dim, other.pm_row_dim);
    
    pm_column_dim += other.pm_column_dim;

    for (int i = 0; i < pm_row_dim; i++) {
        pm_matrix[i].append(other.pm_matrix[i]);
    }
}

void Matrix::columnAppend(const Matrix& other) {
    areTheSamePreconditions(pm_column_dim, other.pm_column_dim);

    pm_row_dim += other.pm_row_dim;

    for (int i = 0; i < other.pm_row_dim; i++) {
        pm_matrix.push_back(other.pm_matrix[i]);
    }
}

void Matrix::rowDetatch(const unsigned int& row, bool direction) {
    rowPreconditions(row);

    if (direction) {
        pm_matrix.erase(pm_matrix.begin(), pm_matrix.begin() + row);
    } else {
        pm_matrix.erase(pm_matrix.begin() + row + 1, pm_matrix.end() - 1);
    }

    pm_row_dim -= row;
}

void Matrix::columnDetatch(const unsigned int& column, bool direction) {
    columnPreconditions(column);

    for (int i = 0; i < pm_row_dim; i++) {
        pm_matrix[i].detatch(column, direction);
    }

    pm_column_dim -= column;
}

void Matrix::rotate() {

    //Invert Matrix
    Matrix tmp(pm_column_dim, pm_row_dim);

    for (int r = 0; r < pm_column_dim; r++) {
        for (int c = 0; c < pm_row_dim; c++) {
            tmp(r,c) = (pm_matrix[c])[r];
        }
    }

    *this = tmp;

}

Matrix Matrix::getRotated() {

    //Invert Matrix
    Matrix tmp(pm_column_dim, pm_row_dim);

    for (int r = 0; r < pm_column_dim; r++) {
        for (int c = 0; c < pm_row_dim; c++) {
            tmp(r,c) = (pm_matrix[c])[r];
        }
    }

    return tmp;

}

bool Matrix::isSymmetric() {
    if (pm_column_dim == pm_row_dim) {
        bool result = false;
        for (int i = 0; i < pm_column_dim - 1; i++) {
            for (int j = i + 1; j < pm_column_dim; j++) {
                if ((*this)(i,j) == (*this)(j,i)) {
                    result = true;
                } else {
                    return false;
                }
            }
        } return result;
    } return false;
}

double Matrix::determinant() {
    //Preconditions
    determinantPreconditions();

    unsigned int N = pm_row_dim;

    //Special case 1x1 matrix
    if (N == 1)
        return (pm_matrix[0])[0];

    //Special case 2x2 matrix
    if (N == 2)
        return ( (pm_matrix[0])[0] * (pm_matrix[1])[1] ) - ( (pm_matrix[1])[0] * (pm_matrix[0])[1] );
    
    //General case
    Matrix upperTriangular_U(*this);
    double determinant = 1;
    bool sign = true;

    upperTriangular_U.rowEchelonForm(sign);

    for (int i = 0; i < N; i++) {
        determinant *= upperTriangular_U(i,i);
    }

    if (sign) {
        return determinant;
    } else {
        return -determinant;
    }

}

Matrix Matrix::inverse() {
    //Preconditions
    
    Matrix tmp(*this);

    //Append Identity Matrix [A|I]
    tmp.rowAppend(Matrix::identityMatrix(pm_row_dim));

    //Put Matrix in row echelon form
    tmp.rowEchelonForm();

    //Is matrix invertible?
    invertiblePreconditions(tmp);

    //Get diagonals of A to 1
    for (int i = 0; i < pm_row_dim; i++) {
            tmp.multiplyRow(i, 1 / tmp(i,i) );
    }

    //Make A an identity matrix and get B
    for (int i = 0; i < pm_row_dim - 1; i++) {
        for (int j = i + 1; j < pm_row_dim; j++) {
            tmp.replaceRow(i, j, tmp(i, j));
        }
    }

    tmp.columnDetatch(pm_row_dim, true);

    return tmp;

}

#pragma endregion

#pragma region Statics

Matrix Matrix::nullMatrix(unsigned int row, unsigned int column) {
    return Matrix(row, column);
}

Matrix Matrix::identityMatrix(unsigned int N) {
    Matrix tmp(N,N);

    for (int i = 0; i < N; i++) {
        tmp(i,i) = 1;
    }
    
    return tmp;
}

Vectorn Matrix::toVector(const Matrix& mat) {
    toVectorConditions(mat);

    if (mat.pm_column_dim == 1) {
        Vectorn tmp(mat.pm_row_dim);

        for (int i = 0; i < 3; i++) {
            tmp[i] = mat(i,0);
        }

        return tmp;
    } else {
        Vectorn tmp(mat.pm_column_dim);

        for (int i = 0; i < 3; i++) {
            tmp[i] = mat(0,1);
        }

        return tmp;
    }
}

#pragma endregion

#if DEBUG
unsigned int Vectorn::counter = 0;
#endif