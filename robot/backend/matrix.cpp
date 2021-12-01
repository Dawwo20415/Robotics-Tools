#include "matrix.h"

#pragma region Constructors
//Default Constructor
template <int Row, int Column>
Matrix<Row,Column>::Matrix() {
    index = counter;
    counter++;
    matrix = std::make_unique<std::array<std::unique_ptr<VectorN<Row>>,Column>>();
    printf("Default Constructor Matrix %d*%d index:%d\n", Row, Column, index);
    for (int i = 0; i < Column; i++) {
        std::unique_ptr<VectorN<Row>> tmp = std::make_unique<VectorN<Row>>();
        (*matrix)[i] = std::move(tmp);
    }
}

//Copy Constructor
template <int Row, int Column>
Matrix<Row,Column>::Matrix(const Matrix<Row,Column>& other) {
    index = counter;
    counter++;
    matrix = std::make_unique<std::array<std::unique_ptr<VectorN<Row>>,Column>>();
    printf("Copy Constructor Matrix %d*%d index:%d\n", Row, Column, index);
    for (int i = 0; i < Column; i++) {
        std::unique_ptr<VectorN<Row>> tmp = std::make_unique<VectorN<Row>>(other.GetColumn(i));
        (*matrix)[i] = std::move(tmp);
    }
}

//Move Constructor
template <int Row, int Column>
Matrix<Row,Column>::Matrix(Matrix<Row,Column>&& other) noexcept {
    index = counter;
    counter++;
    matrix = std::make_unique<std::array<std::unique_ptr<VectorN<Row>>,Column>>();
    printf("Move Constructor Matrix %d*%d index:%d\n", Row, Column, index);
    if (this != &other) {
        this->matrix = std::move(other.matrix);
    }
}

//Float Copy Constructor
template <int Row, int Column>
Matrix<Row,Column>::Matrix(const float (&other)[Row][Column]) {
    index = counter;
    counter++;
    matrix = std::make_unique<std::array<std::unique_ptr<VectorN<Row>>,Column>>();
    printf("Float Copy Constructor Matrix %d*%d index:%d\n", Row, Column, index);
    for (int c = 0; c < Column; c++){
        float tmp_arr[Row];
        for (int r = 0; r < Row; r++) {
            tmp_arr[r] = other[r][c];
        }
        std::unique_ptr<VectorN<Row>> tmp_vec = std::make_unique<VectorN<Row>>(std::move(tmp_arr));
        (*matrix)[c] = std::move(tmp_vec);
    }
}

//Float Move Constructor
template <int Row, int Column>
Matrix<Row,Column>::Matrix(float (&&other)[Row][Column]) noexcept {
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
                line += std::to_string((*matrix)[j]->GetN(i));
            } else {
                line += std::to_string((*matrix)[j]->GetN(i)) + " | ";
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

template <int Row, int Column>
Matrix<Row,Column> Matrix<Row,Column>::operator+(const Matrix<Row,Column>& other) {
    Matrix<Row,Column> tmp_mat;
    for (int c = 0; c < Column; c++) {
        std::cout << "For cycle step " << c << " ---------------------" << std::endl;
        VectorN<Row> tmp_vec;
        std::cout << "Declared " << c << " ---------------------" << std::endl;
        tmp_vec = other.GetVector(c);
        std::cout << "Assigned " << c << " ---------------------" << std::endl;
        *((*(tmp_mat.matrix))[c]) = tmp_vec;
        std::cout << "Arrived at after sum ----------------------" << std::endl;
    }
    return tmp_mat;
}

#pragma endregion