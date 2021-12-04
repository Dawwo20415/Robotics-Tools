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
        Matrix(const float (&other)[Row][Column]);
        //Move constructor
        Matrix(Matrix<Row,Column>&& other) noexcept;
        Matrix(float (&&other)[Row][Column]) noexcept;
        //Destructors
        ~Matrix();
        //Operators
        //Copy Assignment Operator
        Matrix& operator=(const Matrix<Row,Column>& other);
        Matrix& operator=(Matrix<Row,Column>&& other) noexcept;
        //Selection operators
        float& operator()(int _row, int _column);
        const float& operator()(int _row, int _column) const;
        VectorN<Column> GetRow(int _row);
        const VectorN<Column> GetRow(int _row) const;
        VectorN<Row> GetColumn(int _column);
        const VectorN<Row> GetColumn(int _column) const;
        //Matrix + Matrix ONLYSAME SIZE
        Matrix& operator+=(const Matrix<Row,Column>& _other);
        template <int _Row, int _Column> 
        friend Matrix<_Row,_Column> operator+(Matrix<_Row,_Column> _this, const Matrix<_Row,_Column>& _other);
        //Matrix - Matrix ONLY OF THE SAME SIZE
        //Matrix * Matrix AB =/ BA
        //Matrix * Scalar
        //Matrix / Scalar
        template<int R, int C> friend std::ostream& operator<<(std::ostream& os, const Matrix<R,C>& m);

        //Functions
        //Inverse of a Matrix
        //Translated of a Matrix
        //Is Symmetric
        //Determinante
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

template<int R, int C>
std::ostream& operator<<(std::ostream& os, const Matrix<R,C>& m);

#endif
