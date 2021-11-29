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
        float* GetColumn(int dex) const {
            static float tmp[Row];
            if (index < Column && index >= 0) { 
                for (int i = 0; i < Row; i++) {
                    tmp[i] = (*((*matrix)[dex])).GetN(i);
                }
            } else {
                for (int i = 0; i < Row; i++) {
                    tmp[i] = 0.0f;
                }
            }
            return tmp;
        };
            void Print();
            void Println();
            void AddX(float x) {
                std::cout << "Adding" << std::endl;
                *((*(this->matrix))[0]) = *((*(this->matrix))[1]) + (VectorN<Row>::UnitVector() * x);
            };

        //Statics
            //Identity Matrix
            //Unit Matrix
            //Null Matrix


};

template <int Row, int Column>
int Matrix<Row,Column>::counter = 0;

#endif
