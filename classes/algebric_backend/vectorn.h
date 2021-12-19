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
        void constructorPreconditions(int dimension);
        void constructorPreconditions(int selectedDimension, int originalDimension);
        void constructorPreconditions(int selectedBeginning, int selectedEnd, int originalDimension);

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

        //Move Constructors

        //DESTRUCTORS -----------------------------------------------

        //OPERATORS -------------------------------------------------

        //Selection Operators
        float& operator[](int _i);
        const float& operator[](int _i) const;

        //FUNCTIONS -------------------------------------------------
};


#endif
