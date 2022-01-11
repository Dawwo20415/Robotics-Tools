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

        //DESTRUCTORS -----------------------------------------------
        //~Matrix();


        //OPERATORS -------------------------------------------------

        //Selection operators
        float& operator()(int row, int column);
        const float& operator()(int row, int column) const;

        //Assignment operators
        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;


        //FUNCTIONS -------------------------------------------------

        void Println() const;

        //STATICS ---------------------------------------------------



};

#endif
