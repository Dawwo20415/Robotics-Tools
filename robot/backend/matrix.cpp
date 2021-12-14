#include "matrix.h"
#include <math.h>

#pragma region Constructors

//Default Constructor
template <int Row, int Column>
Matrix<Row,Column>::Matrix() {
    try {
        if (Column <= 0 || Row <= 0) {
            throw std::invalid_argument("Row and Column");
        } else {
            index = counter;
            counter++;
            matrix = std::make_unique<std::array<std::unique_ptr<VectorN<Row>>,Column>>();
            printf("Default Constructor Matrix %d*%d index:%d\n", Row, Column, index);
            for (int i = 0; i < Column; i++) {
                (*matrix)[i] = std::make_unique<VectorN<Row>>();
            }
        }    
    } catch (std::exception& e) {
        std::cout << "Exception catched in Matrix constructor, Column or row <= 0, program terminated" << std::endl;
        exit;
    }
    
}

//Copy Constructor
template <int Row, int Column>
Matrix<Row,Column>::Matrix(const Matrix<Row,Column>& other) {
    try {
        if (Column <= 0 || Row <= 0) {
            throw std::invalid_argument("Row and Column");
        } else {
            index = counter;
            counter++;
            matrix = std::make_unique<std::array<std::unique_ptr<VectorN<Row>>,Column>>();
            printf("Copy Constructor Matrix %d*%d index:%d\n", Row, Column, index);
            for (int i = 0; i < Column; i++) {
                std::unique_ptr<VectorN<Row>> tmp = std::make_unique<VectorN<Row>>(other.GetColumn(i));
                (*matrix)[i] = std::move(tmp);
            }
        }
    } catch (std::exception& e) {
        std::cout << "Exception catched in Matrix constructor, Column or row <= 0, program terminated" << std::endl;
        exit;
    }
}

//Float Array Copy Constructor
template <int Row, int Column>
Matrix<Row,Column>::Matrix(const float (&other)[Row][Column]) {
    try {
        if (Column <= 0 || Row <= 0) {
            throw std::invalid_argument("Row and Column");
        } else {
            index = counter;
            counter++;
            matrix = std::make_unique<std::array<std::unique_ptr<VectorN<Row>>,Column>>();
            printf("Float Copy Constructor Matrix %d*%d index:%d\n", Row, Column, index);
            for (int c = 0; c < Column; c++){
                float tmp_arr[Row];
                for (int r = 0; r < Row; r++) {
                    tmp_arr[r] = other[r][c];
                }
                (*matrix)[c] = std::make_unique<VectorN<Row>>(std::move(tmp_arr));
            }
        }
    } catch (std::exception& e) {
        std::cout << "Exception catched in Matrix constructor, Column or row <= 0, program terminated" << std::endl;
        exit;
    }  
}

//Move Constructor
template <int Row, int Column>
Matrix<Row,Column>::Matrix(Matrix<Row,Column>&& other) noexcept {
    try {
        if (Column <= 0 || Row <= 0) {
            throw std::invalid_argument("Row and Column");
        } else {
            index = counter;
            counter++;
            matrix = std::make_unique<std::array<std::unique_ptr<VectorN<Row>>,Column>>();
            printf("Move Constructor Matrix %d*%d index:%d\n", Row, Column, index);
            if (this != &other) {
                this->matrix = std::move(other.matrix);
            }
        }
    } catch (std::exception& e) {
        std::cout << "Exception catched in Matrix constructor, Column or row <= 0, program terminated" << std::endl;
        exit;
    }
}

//Float Move Constructor
template <int Row, int Column>
Matrix<Row,Column>::Matrix(float (&&other)[Row][Column]) noexcept {
    try {
        if (Column <= 0 || Row <= 0) {
            throw std::invalid_argument("Row and Column");
        } else {
            index = counter;
            counter++;
            matrix = std::make_unique<std::array<std::unique_ptr<VectorN<Row>>,Column>>();
            printf("Float Move Constructor Matrix %d*%d index:%d\n", Row, Column, index);
            for (int c = 0; c < Column; c++){
                float tmp_arr[Row];
                for (int r = 0; r < Row; r++) {
                    tmp_arr[r] = other[r][c];
                }
                std::unique_ptr<VectorN<Row>> tmp_vec = std::make_unique<VectorN<Row>>(std::move(tmp_arr));        
                (*matrix)[c] = std::move(tmp_vec);
            }
        }
    } catch (std::exception& e) {
        std::cout << "Exception catched in Matrix constructor, Column or row <= 0, program terminated" << std::endl;
        exit;
    } 
}

#pragma endregion

#pragma region Destructors
//Destructor

template <int Row, int Column>
Matrix<Row,Column>::~Matrix() {
    printf("Destructed Matrix %d\n", index);   
}
#pragma endregion

#pragma region Prints & Display

/*
template <int Row, int Column>
void Matrix<Row,Column>::Print() {
    std::string tmp;
    for (int i = 0; i < Row; i++) {
        std::string line;
        //Left Wall
        if (i == 0) {
            line += "⎡ ";
        } else if (i == Row - 1) {
            line += "⎣ ";
        } else {
            line += "⎢ ";
        }

        //Contents
        for (int j = 0; j < Column; j++) {
            if (j == Column - 1){
                line += std::to_string((*matrix)[j].GetN(i));
            } else {
                line += std::to_string((*matrix)[j].GetN(i)) + " | ";
            }      
        }

        //Right Wall
        if (i == 0) {
            line += "⎤\n";
        } else if (i == Row - 1) {
            line += "⎦";
        } else {
            line += "⎥\n";
        }
        tmp += line;
    }
    std::cout << tmp;
}*/

template <int Row, int Column>
void Matrix<Row,Column>::Println() {
    std::string tmp;
    for (int i = 0; i < Row; i++) {
        std::string line;
        //Left Wall
        if (i == 0) {
            line += "⎡ ";
        } else if (i == Row - 1) {
            line += "⎣ ";
        } else {
            line += "⎢ ";
        }

        //Contents
        for (int j = 0; j < Column; j++) {
            if (j == Column - 1){
                line += std::to_string((*((*matrix)[j]))[i]);
            } else {
                line += std::to_string((*((*matrix)[j]))[i]) + " | ";
            }      
        }

        //Right Wall
        if (i == 0) {
            line += "⎤\n";
        } else if (i == Row - 1) {
            line += "⎦";
        } else {
            line += "⎥\n";
        }
        tmp += line;
    }
    std::cout << tmp << std::endl;
}

#pragma endregion

#pragma region Operators

//Copy Assignment operator
template <int Row, int Column>
Matrix<Row,Column>& Matrix<Row,Column>::operator=(const Matrix<Row,Column>& other) {
    std::unique_ptr<std::array<std::unique_ptr<VectorN<Row>>,Column>> tmp_arr = std::make_unique<std::array<std::unique_ptr<VectorN<Row>>,Column>>();
    for (int i = 0; i < Column; i++) {
        (*(tmp_arr))[i] = std::make_unique<VectorN<Row>>(other.GetColumn(i));
    }
    printf("Matrix Used copy assignment operator = on i:%d for i:%d\n",this->index, other.index);
    this->matrix = std::move(tmp_arr);
    return *this;
}

//Move Assignment operator
template <int Row, int Column>
Matrix<Row,Column>& Matrix<Row,Column>::operator=(Matrix<Row,Column>&& other) noexcept {
    printf("Matrix Used move assignment operator = on i:%d for i:%d\n",this->index, other.index);
    if (this != &other) {
        this->matrix = std::move(other.matrix);
    }
    return *this;
}

//Selection operators
template <int Row, int Column>
float& Matrix<Row,Column>::operator()(int _row, int _column) {
    return (*((*(matrix))[_column]))[_row];
}

template <int Row, int Column>
const float& Matrix<Row,Column>::operator()(int _row, int _column) const {
    return (*((*(matrix))[_column]))[_row];
}

template <int Row, int Column>
VectorN<Column> Matrix<Row,Column>::GetRow(int _row) {
    VectorN<Column> tmp;
    for (int i = 0; i < Column; i++) {
        tmp[i] = (*((*(matrix))[i]))[_row];
    }
    return tmp;
}

template <int Row, int Column>
const VectorN<Column> Matrix<Row,Column>::GetRow(int _row) const {
    VectorN<Column> tmp;
    for (int i = 0; i < Column; i++) {
        tmp[i] = (*((*(matrix))[i]))[_row];
    }
    return tmp;
}

template <int Row, int Column>
VectorN<Row> Matrix<Row,Column>::GetColumn(int _column) {
    VectorN<Row> tmp;
    tmp = (*((*(matrix.get()))[_column]));
    return tmp;
}

template <int Row, int Column>
const VectorN<Row> Matrix<Row,Column>::GetColumn(int _column) const {
    VectorN<Row> tmp;
    tmp = (*((*(matrix.get()))[_column]));
    return tmp;
}

template <int Row, int Column>
Matrix<Row,Column>& Matrix<Row,Column>::operator+=(const Matrix<Row,Column>& _other) {
    std::cout << "Matrix operator +=" << std::endl;
    for (int i = 0; i < Column; i++) {
        (*((*(matrix.get()))[i])) += _other.GetColumn(i);
    }
    return *this;
}

template <int Row, int Column>
Matrix<Row,Column>& Matrix<Row,Column>::operator-=(const Matrix<Row,Column>& _other) {
    std::cout << "Matrix operator +=" << std::endl;
    for (int i = 0; i < Column; i++) {
        (*((*(matrix.get()))[i])) -= _other.GetColumn(i);
    }
    return *this;
}

template <int Row, int Column>
Matrix<Row,Column>& Matrix<Row,Column>::operator*=(const Matrix<Row,Column>& _other) {
    std::cout << "Matrix operator *=" << std::endl;
    Matrix<Row,Column> tmp;

    for (int r = 0; r < Row; r++) {
        for (int c = 0; c < Column; c++) {
            for (int i = 0; i < Row; i++) {
                tmp(r,c) += (*((*(matrix.get()))[i]))[r] * _other(i,c);
            }
        }
    }

    *this = std::move(tmp);

    return *this;
}

template <int Row, int Column>
Matrix<Row,Column>& Matrix<Row,Column>::operator*=(const float& _value) {
    std::cout << "Matrix operator +=" << std::endl;
    for (int i = 0; i < Column; i++) {
        (*((*(matrix.get()))[i])) *= _value;
    }
    return *this;
}

template <int Row, int Column>
Matrix<Row,Column>& Matrix<Row,Column>::operator/=(const float& _value) {
    std::cout << "Matrix operator +=" << std::endl;
    for (int i = 0; i < Column; i++) {
        (*((*(matrix.get()))[i])) *= ( 1 / _value );
    }
    return *this;
}

template<int R, int C>
std::ostream& operator<<(std::ostream& os, const Matrix<R,C>& m){
    for (int i = 0; i < R; i++) {
        //Left Wall
        if (i == 0) {
            os << "⎡ ";
        } else if (i == R - 1) {
            os << "⎣ ";
        } else {
            os << "⎢ ";
        }

        //Contents
        for (int j = 0; j < C; j++) {
            if (j == C - 1){
                os << m[i]; 
            } else {
                os <<  m[i] << " | ";
            }      
        }

        //Right Wall
        if (i == 0) {
            os << "⎤\n";
        } else if (i == R - 1) {
            os << "⎦";
        } else {
            os << "⎥\n";
        }
    }
    return os;
}

#pragma endregion

#pragma region Functions

template<int Row, int Column>
Matrix<Column,Row> Matrix<Row,Column>::Traslate() {
    Matrix<Column,Row> tmp;
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Column; j++) {
            tmp(j,i) = (*this)(i,j);
        }
    }

    return tmp;
}

template<int Row, int Column>
bool Matrix<Row,Column>::isSymmetric() {
    if (Row == Column) {
        std::cout << "Column and Row are the same size" << std::endl;
        bool result = false;
        for (int i = 0; i < Column - 1; i++) {
            for (int j = i + 1; j < Column; j++) {
                if ((*this)(j,i) == (*this)(i,j)) {
                    std::cout << "The two values are the same: " << (*this)(j,i) << " and " << (*this)(i,j) << std::endl;
                    std::cout << "using i=" << i << " j=" << j << std::endl;
                    result = true;
                } else {
                    std::cout << "The two values are not the same" << std::endl;
                    return false;
                }
            }
        } return result;
    } return false;
}

template<int Row, int Column>
Matrix<Row-1,Column-1> Matrix<Row,Column>::Submatrix(int x, int y) {
        if (Row <= 2) {
            throw std::invalid_argument("Creating submatrix from invalid parent | x<=2");
        } else {
            Matrix<Row-1,Column-1> tmp;
            for (int i = 0; i < Column - 1; i++) 
                for (int j = 0; j < Row - 1; j++) 
                    tmp(j,i) = (*this)(j < y ? j : j+1, i < x ? i : i+1);
            return tmp;
        }
}

template<int Row, int Column>
float Matrix<Row,Column>::Determinante() {
        if (Row != Column) {
            throw std::invalid_argument("Row and Column of Different Sizes");
        }
        if (Row < 1) {
            throw std::invalid_argument("Length of Matrix < 1");
        }
        
        if (Row == 1) {
            return (*this)(0,0);
        } else if (Row == 2) {
            return (*this)(0,0) * (*this)(1,1) - (*this)(1,0) * (*this)(0,1);
        } else {
            int determinant = 0;
            for ( int i = 0; i < Row; i++) {
                /* THE ERROR IS HERE!!!*/
                determinant += pow(-1, i) * (*this)(i,0) * (*this).Submatrix(i,0).Determinante();
            }
            return determinant;
        }
}

template<int Row, int Column>
Matrix<Row,Column> Matrix<Row,Column>::Inverse() {
    if (Row == Column) {
        if (Determinante != 0) {

        } return NULL;
    } return NULL;
}

#pragma endregion