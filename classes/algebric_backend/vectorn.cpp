#include "vectorn.h"

#pragma region Exeption_Handlers

void Vectorn::constructorPreconditions(const int& dimension) {
    try {
        if (
        //Conditions
        dimension > pm_vector.max_size() || 
        dimension == 0
        ) {
            //Exception
            throw std::out_of_range(
                "In creation of Vectorn: passed parameter dimension " +
                std::to_string(dimension) + 
                " out of range for std::vector<float>"); //Out of scope dimension
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
    
}

void Vectorn::constructorPreconditions(const int& selectedDimension, const int& originalDimension) {
    try {
        if (
            //Conditions for selected dimension
            selectedDimension > originalDimension || 
            selectedDimension <= 0
            ) {
            throw std::out_of_range(
                "In creation of Vectorn: passed parameter dimension " +
                std::to_string(selectedDimension) + 
                " out of range for std::vector<float>"); //Out of scope dimension
        } 

        if (
            //Conditions for input vector type
            selectedDimension > originalDimension || 
            originalDimension <= 0) {
            throw std::invalid_argument("In creation of Vectorn: invalid vector passed as argument in constructor, size="
                    + std::to_string(originalDimension));
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
}

void Vectorn::constructorPreconditions(const int& selectedBeginning, const int& selectedEnd, const int& originalDimension) {
    try {
        if ( //Conditions
            selectedEnd > originalDimension || 
            selectedBeginning < 0 || 
            selectedBeginning > selectedEnd
            ) {
            throw std::out_of_range(
                "In creation of Vectorn: passed parameter beginning=" +
                std::to_string(selectedBeginning) + " or end=" + std::to_string(selectedEnd) +
                " out of range for std::vector<float>"); //Out of scope dimension
        } if (originalDimension <= 0) {
            throw std::invalid_argument("In creation of Vectorn: invalid vector passed as argument in constructor, size="
                    + std::to_string(originalDimension));
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit( EXIT_FAILURE );
    }
}

void Vectorn::selectionOperatorPreconditions(const int& _index) const {
    try {
        if (_index < 0 || _index >= pm_dimension) {
            throw std::out_of_range(
            "Vectorn call for operator [_i], value out of range | _i="
            + std::to_string(_index)); //Out of scope dimension
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit ( EXIT_FAILURE );
    }
}

void Vectorn::algebricOperatorPreconditions(const int& size1, const int& size2) const {
    try {
        if (size1 != size2) {
            throw std::invalid_argument ("Sizes of two vectors in algebric operator are not the same and the operation cannot be accomplished | Size1= " 
            + std::to_string(size1) + " | Size2= " + std::to_string(size2));
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit ( EXIT_FAILURE );
    }
}

#pragma endregion

#pragma region Constructors

//Default Constructor
Vectorn::Vectorn(unsigned int dimension) {

    constructorPreconditions(dimension);

    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Dimension " << dimension << " | Index " 
                << index << " |" << std::endl;
    #endif

    //Constructor
    pm_dimension = dimension;
    for (int i = 0; i < dimension; i++)
        pm_vector.push_back(0.0f);
}

//Copy Constructor | Other Vector | Specified dimension
Vectorn::Vectorn(unsigned int dimension, const Vectorn& other) {
    
    constructorPreconditions(dimension, other.pm_dimension);

    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Dimension " << dimension << " | Index " 
                << index << " |" << std::endl;
    #endif

    //Constructor
    pm_dimension = dimension;
    for (int i = 0; i < dimension; i++)
        pm_vector.push_back(other[i]);
}

//Copy Constructor | Other Vector | Index Range
Vectorn::Vectorn(unsigned int beginning, unsigned int end, const Vectorn& other) {

    constructorPreconditions(beginning, end, other.pm_dimension);

    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Dimension " << end - beginning + 1 << " | Index " 
                << index << " |" << std::endl;
    #endif

    //Constructor
    pm_dimension = end - beginning + 1;
    for (int i = beginning; i <= end; i++)
        pm_vector.push_back(other[i]);
}

//Copy Constructor | Other Vector | Whole Vector
Vectorn::Vectorn(const Vectorn& other) {
    
    constructorPreconditions(other.pm_dimension);

    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Dimension " << other.pm_dimension << " | Index " 
                << index << " |" << std::endl;
    #endif

    //Constructor
    pm_dimension = other.pm_dimension;
    for (int i = 0; i < pm_dimension; i++)
        pm_vector.push_back(other[i]);
}

//Copy Constructor | std::vector | Specified dimension
Vectorn::Vectorn(unsigned int dimension, const std::vector<float>& other) {

    constructorPreconditions(dimension, other.size());

    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Dimension " << dimension << " | Index " 
                << index << " |" << std::endl;
    #endif

    //Constructor
    pm_dimension = dimension;
    for (int i = 0; i < dimension; i++)
        pm_vector.push_back(other[i]);
}

//Copy Constructor | std::vector | Index Range
Vectorn::Vectorn(unsigned int beginning, unsigned int end, const std::vector<float>& other) {

    constructorPreconditions(beginning, end, other.size());

    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Dimension " << end - beginning + 1 << " | Index " 
                << index << " |" << std::endl;
    #endif

    //Constructor
    pm_dimension = end - beginning + 1;
    for (int i = beginning; i <= end; i++)
        pm_vector.push_back(other[i]);
        
}

//Copy Constructor | std::vector | Whole Vector
Vectorn::Vectorn(const std::vector<float>& other) {

    constructorPreconditions(other.size());

    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Dimension " << other.size() << " | Index " 
                << index << " |" << std::endl;
    #endif

    //Constructor
    pm_dimension = other.size();
    for (int i = 0; i < pm_dimension; i++)
        pm_vector = other;
}

//Copy Constructor | initializer_list | Whole Vector
Vectorn::Vectorn(const std::initializer_list<float>& other) {

    constructorPreconditions(other.size());

    //Print Debug?
    #if DEBUG
    index = counter;
    counter++;
    std::cout << "| Default Constructor | Dimension " << other.size() << " | Index " 
                << index << " |" << std::endl;
    #endif

    //Constructor
    pm_dimension = other.size();
    pm_vector = other;
}

//Destructor
Vectorn::~Vectorn() {
    #if DEBUG
    std::cout << "| Default Destructor  | Dimension " << pm_dimension << " | Index " << index << " |" << std::endl;
    #endif
}

#pragma endregion

#pragma region Operators

//Selection operators
float& Vectorn::operator[](int _i) {
    //preconditions
    selectionOperatorPreconditions(_i);

    return pm_vector[_i];
}

const float& Vectorn::operator[](int _i) const {
    //preconditions
    selectionOperatorPreconditions(_i);

    return pm_vector[_i];
}

//Assignment operators
Vectorn& Vectorn::operator=(const Vectorn& other) {
    pm_dimension = other.pm_dimension;
    pm_vector = other.pm_vector;
    return *this;
}

Vectorn& Vectorn::operator=(Vectorn&& other) {
    pm_dimension = std::move(other.pm_dimension);
    pm_vector = std::move(other.pm_vector);
    return *this;
}

//Addition Operator
Vectorn& Vectorn::operator+=(const Vectorn& other) {
    //Preconditions
    algebricOperatorPreconditions(pm_dimension, other.pm_dimension);

    for (int i = 0; i < pm_dimension; i++) {
        pm_vector[i] += other[i];
    }

    return *this;
}

Vectorn operator+(Vectorn initial, const Vectorn& other) {
    initial += other;
    return initial;
}

//Subtraction Operator
Vectorn& Vectorn::operator-=(const Vectorn& other) {
    //Preconditions
    algebricOperatorPreconditions(pm_dimension, other.pm_dimension);

    for (int i = 0; i < pm_dimension; i++) {
        pm_vector[i] -= other[i];
    }

    return *this;
}

Vectorn operator-(Vectorn initial, const Vectorn& other) {
    initial -= other;
    return initial;
}

#pragma endregion

#if DEBUG
unsigned int Vectorn::counter = 0;
#endif