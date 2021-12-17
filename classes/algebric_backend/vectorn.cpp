#include "vectorn.h"

#pragma region Constructors

//Default Constructor
Vectorn::Vectorn(unsigned int dimension) {
    //preconditions
    if (dimension > pm_vector.max_size() || dimension == 0) {
        throw std::out_of_range(
            "In creation of Vectorn: passed parameter dimension " +
            std::to_string(dimension) + 
            "out of range for std::vector<float> " +
            std::to_string(pm_vector.max_size())); //Out of scope dimension
    }

    //Print Debug?
    #if DEBUG

    index = counter;
    index++;

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
    //preconditions
    if (dimension > other.pm_dimension || dimension == 0) {
        throw std::out_of_range(
            "In creation of Vectorn: passed parameter dimension " +
            std::to_string(dimension) + 
            "out of range for std::vector<float> " +
            std::to_string(pm_vector.max_size())); //Out of scope dimension
    } if (dimension > other.pm_dimension || other.pm_dimension <= 0) {
        throw std::invalid_argument("In creation of Vectorn: invalid vector passed as argument in constructor, size="
                + std::to_string(other.pm_dimension));
    }

    //Print Debug?
    #if DEBUG

    index = counter;
    index++;

    std::cout << "| Default Constructor | Dimension " << dimension << " | Index " 
                << index << " |" << std::endl;

    #endif

    //Constructor
    pm_dimension = dimension;
    for (int i = 0; i < dimension; i++)
        pm_vector[i] = other[i];
}

//Copy Constructor | Other Vector | Index Range
Vectorn::Vectorn(unsigned int beginning, unsigned int end, const Vectorn& other) {
    //preconditions
    if (end > other.pm_dimension || end < 0 || beginning < 0 || beginning > end) {
        throw std::out_of_range(
            "In creation of Vectorn: passed parameter dimension " +
            std::to_string(end - beginning) + 
            "out of range for std::vector<float> " +
            std::to_string(pm_vector.max_size())); //Out of scope dimension
    } if (other.pm_dimension <= 0) {
        throw std::invalid_argument("In creation of Vectorn: invalid vector passed as argument in constructor, size="
                + std::to_string(other.pm_dimension));
    }

    //Print Debug?
    #if DEBUG

    index = counter;
    index++;

    std::cout << "| Default Constructor | Dimension " << end - beginning << " | Index " 
                << index << " |" << std::endl;

    #endif

    //Constructor
    pm_dimension = end - beginning;
    for (int i = beginning; i < end; i++)
        pm_vector[i] = other[i];
}

//Copy Constructor | Other Vector | Whole Vector
Vectorn::Vectorn(const Vectorn& other) {
    //preconditions
    if (other.pm_dimension <= 0) {
        throw std::invalid_argument("In creation of Vectorn: invalid vector passed as argument in constructor, size="
                + std::to_string(other.pm_dimension));
    }

    //Print Debug?
    #if DEBUG

    index = counter;
    index++;

    std::cout << "| Default Constructor | Dimension " << other.pm_dimension << " | Index " 
                << index << " |" << std::endl;

    #endif

    //Constructor
    pm_dimension = other.pm_dimension;
    for (int i = 0; i < pm_dimension; i++)
        pm_vector[i] = other[i];
}

//Copy Constructor | std::vector | Specified dimension
Vectorn::Vectorn(unsigned int dimension, const std::vector<float>& other) {
    //preconditions
    if (dimension > other.size() || dimension == 0) {
        throw std::out_of_range(
            "In creation of Vectorn: passed parameter dimension " +
            std::to_string(dimension) + 
            "out of range for std::vector<float> " +
            std::to_string(pm_vector.max_size())); //Out of scope dimension
    } if (dimension > other.size() || other.size() <= 0) {
        throw std::invalid_argument("In creation of Vectorn: invalid vector passed as argument in constructor, size="
                + std::to_string(other.size()));
    }

    //Print Debug?
    #if DEBUG

    index = counter;
    index++;

    std::cout << "| Default Constructor | Dimension " << dimension << " | Index " 
                << index << " |" << std::endl;

    #endif

    //Constructor
    pm_dimension = dimension;
    for (int i = 0; i < dimension; i++)
        pm_vector[i] = other[i];
}

//Copy Constructor | std::vector | Index Range
Vectorn::Vectorn(unsigned int beginning, unsigned int end, const std::vector<float>& other) {
    //preconditions
    if (end > other.size() || end < 0 || beginning < 0 || beginning > end) {
        throw std::out_of_range(
            "In creation of Vectorn: passed parameter dimension " +
            std::to_string(end - beginning) + 
            "out of range for std::vector<float> " +
            std::to_string(pm_vector.max_size())); //Out of scope dimension
    } if (other.size() <= 0) {
        throw std::invalid_argument("In creation of Vectorn: invalid vector passed as argument in constructor, size="
                + std::to_string(other.size()));
    }

    //Print Debug?
    #if DEBUG

    index = counter;
    index++;

    std::cout << "| Default Constructor | Dimension " << end - beginning << " | Index " 
                << index << " |" << std::endl;

    #endif

    //Constructor
    pm_dimension = end - beginning;
    for (int i = beginning; i < end; i++)
        pm_vector[i] = other[i];
}

//Copy Constructor | std::vector | Whole Vector
Vectorn::Vectorn(const std::vector<float>& other) {
    //preconditions
    if (other.size() <= 0) {
        throw std::invalid_argument("In creation of Vectorn: invalid vector passed as argument in constructor, size="
                + std::to_string(other.size()));
    }

    //Print Debug?
    #if DEBUG

    index = counter;
    index++;

    std::cout << "| Default Constructor | Dimension " << other.size() << " | Index " 
                << index << " |" << std::endl;

    #endif

    //Constructor
    pm_dimension = other.size();
    for (int i = 0; i < pm_dimension; i++)
        pm_vector = other;
}

//!!!!! HERE USE std::initializer_list<float> INSTEAD OF A RAW ARRAY POINTER !!!!!
/*
//Copy Constructor | float array | Specified dimension
Vectorn::Vectorn(unsigned int dimension, const float (&other)[]) {
    //preconditions
    if (dimension > other.size() || dimension == 0) {
        throw std::out_of_range(
            "In creation of Vectorn: passed parameter dimension " +
            std::to_string(dimension) + 
            "out of range for std::vector<float> " +
            std::to_string(pm_vector.max_size())); //Out of scope dimension
    } if (dimension > other.size() || other.size() <= 0) {
        throw std::invalid_argument("In creation of Vectorn: invalid vector passed as argument in constructor, size="
                + std::to_string(other.size()));
    }

    //Print Debug?
    #if DEBUG

    index = counter;
    index++;

    std::cout << "| Default Constructor | Dimension " << dimension << " | Index " 
                << index << " |" << std::endl;

    #endif

    //Constructor
    pm_dimension = dimension;
    for (int i = 0; i < dimension; i++)
        pm_vector[i] = other[i];
}

//Copy Constructor | float array | Index Range
Vectorn::Vectorn(unsigned int beginning, unsigned int end, const float (&other)[]) {
    //preconditions
    if (end > other.size() || end < 0 || beginning < 0 || beginning > end) {
        throw std::out_of_range(
            "In creation of Vectorn: passed parameter dimension " +
            std::to_string(end - beginning) + 
            "out of range for std::vector<float> " +
            std::to_string(pm_vector.max_size())); //Out of scope dimension
    } if (other.size() <= 0) {
        throw std::invalid_argument("In creation of Vectorn: invalid vector passed as argument in constructor, size="
                + std::to_string(other.size()));
    }

    //Print Debug?
    #if DEBUG

    index = counter;
    index++;

    std::cout << "| Default Constructor | Dimension " << end - beginning << " | Index " 
                << index << " |" << std::endl;

    #endif

    //Constructor
    pm_dimension = end - beginning;
    for (int i = beginning; i < end; i++)
        pm_vector[i] = other[i];
}

//Copy Constructor | float array | Whole Vector
Vectorn::Vectorn(const float (&other)[]) {
    //preconditions
    if (other.size() <= 0) {
        throw std::invalid_argument("In creation of Vectorn: invalid vector passed as argument in constructor, size="
                + std::to_string(other.size()));
    }

    //Print Debug?
    #if DEBUG

    index = counter;
    index++;

    std::cout << "| Default Constructor | Dimension " << other.size() << " | Index " 
                << index << " |" << std::endl;

    #endif

    //Constructor
    pm_dimension = other.size();
    for (int i = 0; i < pm_dimension; i++)
        pm_vector = other;
}
*/
#pragma endregion

#pragma region Operators

//Selection operators
float& Vectorn::operator[](int _i) {
    //preconditions
    if (_i < 0 || _i > pm_dimension) {
        throw std::out_of_range(
            "Vectorn call for operator [_i], value out of range | _i="
            + std::to_string(_i)); //Out of scope dimension
    }

    return pm_vector[_i];
}

const float& Vectorn::operator[](int _i) const {
    //preconditions
    if (_i < 0 || _i > pm_dimension) {
        throw std::out_of_range(
            "Vectorn call for operator [_i], value out of range | _i="
            + std::to_string(_i)); //Out of scope dimension
    }

    return pm_vector[_i];
}

#pragma endregion

#if DEBUG
unsigned int Vectorn::counter = 0;
#endif