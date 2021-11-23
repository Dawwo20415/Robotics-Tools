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
        std::array<VectorN<Row>,Column> *matrix;
        static int counter;
        int index;

    public:
        //Constructors
        Matrix();
        Matrix(std::array<VectorN<Row>,Column> *mtx);
        Matrix(std::array<VectorN<Row>,Column> mtx);
        Matrix(std::list<VectorN<Row>> *lst);
        Matrix(std::list<VectorN<Row>> lst);
        Matrix(const Matrix<Row,Column>& other);
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
            void Print();
            void Println();


        //Statics
            //Identity Matrix
            //Unit Matrix
            //Null Matrix


};

template <int Row, int Column>
int Matrix<Row,Column>::counter = 0;

#endif
