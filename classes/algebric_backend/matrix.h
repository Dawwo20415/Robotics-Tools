#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <iostream>
#include "vectorn.h"

class Matrix {

    private:

        unsigned int pm_column_dim;
        unsigned int pm_row_dim;
        std::vector<Vectorn> pm_matrix;

        //Constructors Exceptions Handlers
        void constructorPreconditions(const int row, const int column) const;
        void constructorPreconditions(const int row, const int column, const int otherRow, const int otherColumn) const;
        void constructorPreconditions(const int row1, const int row2, 
                                        const int column1, const int column2, 
                                        const int otherRow, const int otherColumn) const;
        void constructorPreconditions(const std::initializer_list<std::initializer_list<float>>& other) const;
        void operatorPreconditions(const int row, const int column) const;
        void algebricSumPreconditions(const Matrix& other) const;
        void multiplicationPreconditions(const Matrix& other) const;
        void determinantPreconditions() const;
        void areTheSamePreconditions(unsigned int value1, unsigned int value2) const;
        void rowPreconditions(const int& index) const;
        void columnPreconditions(const int& index) const;
        void invertiblePreconditions(const Matrix& other) const;
        static void toVectorConditions(const Matrix& subject);

        float& access(int row, int column);
        const float& access(int row, int column) const;
        
        //Private operations
        void moveRow(unsigned int row1, unsigned int row2);
        void multiplyRow(unsigned int row, float value);
        void replaceRow(unsigned int row1, unsigned int row2, float value);

        void rowEchelonForm();
        void rowEchelonForm(bool& determinant_sign);

        //Debug Controll
        #if DEBUG

            static unsigned int counter;
            unsigned int index;

        #endif

    public:

        //CONSTRUCTORS ----------------------------------------------

        //Default Constructor
        Matrix(unsigned int row, unsigned int column);

        //Copy Constructor
        Matrix(const Matrix& other);
        Matrix(unsigned int n_rows, unsigned int n_columns, const Matrix& other);
        Matrix(unsigned int row1, unsigned int row2, 
                unsigned int column1, unsigned int column2, 
                const Matrix& other);

        Matrix(const std::initializer_list<std::initializer_list<float>>& other);
        Matrix(const Vectorn& vector, bool direction);

        //DESTRUCTORS -----------------------------------------------
        //~Matrix();


        //OPERATORS -------------------------------------------------

        //Selection operators
        float& operator()(int row, int column);
        const float& operator()(int row, int column) const;

        //Assignment operators
        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;

        //Addition operator
        Matrix& operator+=(const Matrix& other);
        friend Matrix operator+(Matrix first, const Matrix& second);

        //Subtraction operator
        Matrix& operator-=(const Matrix& other);
        friend Matrix operator-(Matrix first, const Matrix& second);

        //Multiplication by a Scalar operator
        Matrix& operator*=(const float& value);
        friend Matrix operator*(Matrix mat, const float& value);

        //Division by a Scalar operator
        Matrix& operator/=(const float& value);
        friend Matrix operator/(Matrix mat, const float& value);

        //Multiplication by a Matrix operator
        Matrix& operator*=(const Matrix& other);
        friend Matrix operator*(Matrix mat, const Matrix& other);

        //FUNCTIONS -------------------------------------------------

        void println() const;
        void print() const;

        void rotate();
        Matrix getRotated();

        float determinant();
        Matrix inverse();

        void rowAppend(const Matrix& other);
        void columnAppend(const Matrix& other);

        void rowDetatch(const unsigned int& row, bool direction);
        void columnDetatch(const unsigned int& column, bool direction);

        //Bools
        bool isSymmetric();

        //STATICS ---------------------------------------------------

        static Matrix nullMatrix(unsigned int row, unsigned int column);
        static Matrix identityMatrix(unsigned int N);
        static Vectorn toVector(const Matrix& mat);

};

#endif
