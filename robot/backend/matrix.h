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
        std::array<VectorN<Row> *,Column> *matrix = nullptr;
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
            void PrintIndexes() {
                std::cout << "Indexes of vectors in matrix " << std::to_string(index) << " are ";
                for (auto i : *matrix) {
                    std::cout << i->GetIndex() << " "; 
                }
                std::cout << std::endl;
            };
            void InsertValue(float value, int column) {
                (*(*matrix)[column]) = (*(*matrix)[column]) + (VectorN<3>::UnitVector() * value);
            }


        //Statics
            //Identity Matrix
            //Unit Matrix
            //Null Matrix


};

template <int Row, int Column>
int Matrix<Row,Column>::counter = 0;

#endif
