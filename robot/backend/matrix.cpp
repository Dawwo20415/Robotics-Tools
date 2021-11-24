#include "matrix.h"

#pragma region Constructors
//Constructors
template <int Row, int Column>
Matrix<Row,Column>::Matrix() {
    index = counter;
    counter++;
    printf("Default Constructor Matrix %d*%d index:%d\n", Row, Column, index);
    std::array<VectorN<Row> *,Column> *tmp = new std::array<VectorN<Row> *,Column>{};
    tmp->fill(new VectorN<3>());
    matrix = std::move(tmp);
}

template <int Row, int Column>
Matrix<Row,Column>::Matrix(std::array<VectorN<Row>,Column> *mtx) {
    index = counter;
    counter++;
    printf("Array Pointer Constructor Matrix %d*%d index:%d\n", Row, Column, index);
    matrix = mtx;
}

template <int Row, int Column>
Matrix<Row,Column>::Matrix(std::array<VectorN<Row>,Column> mtx) {
    index = counter;
    counter++;
    printf("Array Constructor Matrix %d*%d index:%d\n", Row, Column, index);
    matrix = new std::array<VectorN<Row>,Column>(mtx);
}

template <int Row, int Column>
Matrix<Row,Column>::Matrix(std::list<VectorN<Row>> *lst) {
    index = counter;
    counter++;
    printf("List Pointer Constructor Matrix %d*%d index:%d\n", Row, Column, index);
    std::array<VectorN<Row>,Column> *tmp = new std::array<VectorN<Row>,Column>();
    if (lst->size() == Column) {
        int j = 0;
        for (auto i : *lst) {
            (*tmp)[j] = i;
            j++;
        }
    } else {
        *tmp = {VectorN<Row>::NullVector(), VectorN<Row>::NullVector(), VectorN<Row>::NullVector()};
    }
    matrix = tmp;
}

template <int Row, int Column>
Matrix<Row,Column>::Matrix(std::list<VectorN<Row>> lst) {
    index = counter;
    counter++;
    printf("List Constructor Matrix %d*%d index:%d\n", Row, Column, index);
    std::array<VectorN<Row>,Column> *tmp = new std::array<VectorN<Row>,Column>();
    if (lst.size() == Column) {
        int j = 0;
        for (auto i : lst) {
            (*tmp)[j] = i;
            j++;
        }
    } else {
        *tmp = {VectorN<Row>::NullVector(), VectorN<Row>::NullVector(), VectorN<Row>::NullVector()};
    }
    matrix = tmp;
}

template <int Row, int Column>
Matrix<Row,Column>::Matrix(const Matrix<Row,Column>& other) {
    index = counter;
    counter++;
    printf("Copy Constructor Matrix %d*%d index:%d\n", Row, Column, index);
    this->matrix = other.matrix; 
}

#pragma endregion

#pragma region Destructors
//Destructor
template <int Row, int Column>
Matrix<Row,Column>::~Matrix() {
    if (matrix != NULL) {
        delete matrix;
    }
    printf("Destructed Matrix %d\n", index);   
}
#pragma endregion

#pragma region Prints & Display
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
}

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