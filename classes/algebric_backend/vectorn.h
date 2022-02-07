#ifndef VECTORN_CLASS
#define VECTORN_CLASS

//Print debug??
#define DEBUG 0

#define VERTICAL true
#define HORIZONTAL false
#define BEGIN_TO_END true
#define END_TO_BEGIN false

#include <iostream>
#include <vector>

class Vectorn {

    private:

        unsigned int pm_dimension;
        std::vector<double> pm_vector;

        //Constructors Exceptions Handlers
        void constructorPreconditions(const int& dimension);
        void constructorPreconditions(const int& selectedDimension, const int& originalDimension);
        void constructorPreconditions(const int& selectedBeginning, const int& selectedEnd, const int& originalDimension);
        void selectionOperatorPreconditions(const int& _index) const;
        void algebricOperatorPreconditions(const int& size1, const int& size2) const;
        void crossProductPreconditions(const int& size) const;

        //Debug Controll
        #if DEBUG

            static unsigned int counter;
            unsigned int index;

        #endif

    public:

        //CONSTRUCTORS ----------------------------------------------
        
        //Default Constructor
        Vectorn(unsigned int dimension);
        Vectorn(unsigned int dimension, double value);

        //Copy Constructors
        Vectorn(unsigned int dimension, const Vectorn& other);
        Vectorn(unsigned int beginning, unsigned int end, const Vectorn& other);
        Vectorn(const Vectorn& other);

        Vectorn(unsigned int dimension, const std::vector<double>& other);
        Vectorn(unsigned int beginning, unsigned int end, const std::vector<double>& other);
        Vectorn(const std::vector<double>& other);

        Vectorn(const std::initializer_list<double>& other);

        //Move Constructor
        Vectorn(Vectorn&& other) = default;

        //DESTRUCTORS -----------------------------------------------

        ~Vectorn();

        //OPERATORS -------------------------------------------------

        //Selection Operators
        double& operator[](int _i);
        const double& operator[](int _i) const;

        //Assignment Operators
        Vectorn& operator=(const Vectorn& other);
        Vectorn& operator=(Vectorn&& other);

        //Addition Operators
        Vectorn& operator+=(const Vectorn& other);
        friend Vectorn operator+(Vectorn initial, const Vectorn& other);
        Vectorn& operator+=(const std::initializer_list<double>& other);
        friend Vectorn operator+(Vectorn initial, const std::initializer_list<double>& other);

        //Subtraction Operators
        Vectorn& operator-=(const Vectorn& other);
        friend Vectorn operator-(Vectorn initial, const Vectorn& other);
        Vectorn& operator-=(const std::initializer_list<double>& other);
        friend Vectorn operator-(Vectorn initial, const std::initializer_list<double>& other);

        //Vector * Scalar Operators
        Vectorn& operator*=(const double& other);
        friend Vectorn operator*(Vectorn initial, const double& other);

        //Vector / Scalar Operators
        Vectorn& operator/=(const double& other);
        friend Vectorn operator/(Vectorn initial, const double& other);

        //Dot Product Operators
        double dotProduct(const Vectorn& other);

        //Cross Product
        Vectorn& operator*=(const Vectorn& other);
        friend Vectorn operator*(Vectorn initial, const Vectorn& other);
        Vectorn& operator*=(const std::initializer_list<double>& other);
        friend Vectorn operator*(Vectorn initial, const std::initializer_list<double>& other);

        //FUNCTIONS -------------------------------------------------

        void print();
        void println();
        unsigned int getDimension() const;
        void append(const Vectorn& other);
        void detatch(const unsigned int& index, bool direction);

        //STATICS ---------------------------------------------------

        static Vectorn unitVector(int dimension);
        static Vectorn nullVector(int dimension);
        static void toHomogenous(Vectorn& other);
        static void toCoordinates(Vectorn& other);
};

#endif
