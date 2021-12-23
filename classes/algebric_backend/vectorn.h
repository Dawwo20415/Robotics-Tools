#ifndef VECTORN_CLASS
#define VECTORN_CLASS

//Print debug??
#define DEBUG 1

#include <iostream>
#include <vector>

class Vectorn {

    private:

        unsigned int pm_dimension;
        std::vector<float> pm_vector;

        //Constructors Exceptions Handlers
        void constructorPreconditions(const int& dimension);
        void constructorPreconditions(const int& selectedDimension, const int& originalDimension);
        void constructorPreconditions(const int& selectedBeginning, const int& selectedEnd, const int& originalDimension);
        void selectionOperatorPreconditions(const int& _index) const;
        void algebricOperatorPreconditions(const int& size1, const int& size2) const;

        //Debug Controll
        #if DEBUG

            static unsigned int counter;
            unsigned int index;

        #endif

    public:

        //CONSTRUCTORS ----------------------------------------------
        
        //Default Constructor
        Vectorn(unsigned int dimension);

        //Copy Constructors
        Vectorn(unsigned int dimension, const Vectorn& other);
        Vectorn(unsigned int beginning, unsigned int end, const Vectorn& other);
        Vectorn(const Vectorn& other);

        Vectorn(unsigned int dimension, const std::vector<float>& other);
        Vectorn(unsigned int beginning, unsigned int end, const std::vector<float>& other);
        Vectorn(const std::vector<float>& other);

        Vectorn(const std::initializer_list<float>& other);

        //DESTRUCTORS -----------------------------------------------

        ~Vectorn();

        //OPERATORS -------------------------------------------------

        //Selection Operators
        float& operator[](int _i);
        const float& operator[](int _i) const;

        //Assignment Operators
        Vectorn& operator=(const Vectorn& other);
        Vectorn& operator=(Vectorn&& other);

        //Addition Operators
        Vectorn& operator+=(const Vectorn& other);
        friend Vectorn operator+(Vectorn initial, const Vectorn& other);

        //FUNCTIONS -------------------------------------------------
};

#endif
