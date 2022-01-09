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


        //DESTRUCTORS -----------------------------------------------
        //~Matrix();


        //OPERATORS -------------------------------------------------

        //Selection operators
        float& operator()(int row, int column);
        const float& operator()(int row, int column) const;


        //FUNCTIONS -------------------------------------------------



        //STATICS ---------------------------------------------------



};

#endif
