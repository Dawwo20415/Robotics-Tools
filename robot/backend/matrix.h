#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <iostream>
#include <array>
#include <list>
#include <iterator>
#include "vector3.cpp"

template <int Row, int Column>
class Matrix {

    private:
        std::unique_ptr<std::array<std::unique_ptr<VectorN<Row>>,Column>> matrix;
        static int counter;
        int index;

    public:
        //Default Constructor
        Matrix();
        //Copy Constructor
        Matrix(const Matrix<Row,Column>& other);
        //Move constructor
        Matrix(Matrix<Row,Column>&& other);
        //Floart
        //Destructors
        ~Matrix();
        //Operators
            //Matrix + Matrix ONLYSAME SIZE
            //Matrix - Matrix ONLY OF THE SAME SIZE
            //Matrix * Matrix AB =/ BA
            //Matrix * Scalar
            //Matrix / Scalar

        //Functions
            //Inverse of a Matrix
            //Translated of a Matrix
            //Is Symmetric
            //Determinante
            VectorN<Row> GetColumn(int index) const;
            void Print();
            void Println();
            void AddX(float x) {
                std::cout << "Adding" << std::endl;
                *((*(this->matrix))[1]) = *((*(this->matrix))[0]) + (VectorN<Row>::UnitVector() * x);
            };

        //Statics
            //Identity Matrix
            //Unit Matrix
            //Null Matrix


};

template <int Row, int Column>
int Matrix<Row,Column>::counter = 0;

#endif
