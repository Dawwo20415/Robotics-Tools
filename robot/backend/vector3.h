#ifndef VECTOR3_CLASS
#define VECTOR3_CLASS

#include <vector>
#include <memory>

template <int N>
class VectorN {

    private:
        std::vector<float> *v = nullptr; 
        static int counter;
        int index;

    public:
        //Default Constructors
        VectorN();
        //Copy Constructor
        VectorN (const VectorN& other);
        //Move constructor
        VectorN (VectorN&& other) noexcept;
        //Float Constructor
        VectorN(float arr[]);
        //Destructor
        ~VectorN();
        //Functions
        std::vector<float> Get();
        void Print();
        void Println();
        float GetX();
        float GetY();
        float GetZ();
        float GetN(int index);
        int GetIndex() { return index; };
        bool isNull() { return (this->v == nullptr);};
        //Operators
        //Assignment operator
        VectorN& operator=(const VectorN<N>& other);
        VectorN& operator=(VectorN<N>&& other) noexcept;
        //Addition operator
        VectorN operator+(const VectorN<N>& other);
        //Subtraction operator
        VectorN operator-(const VectorN<N>& other);
        //Cross Product operator
        VectorN operator*(const VectorN<N>& other);
        //Scalar Product operator
        VectorN operator*(const float& val);  
        float DotProduct(const VectorN<N>& other);  
        //Statics
        static VectorN UnitVector();
        static VectorN NullVector();    
};

template <int N>
int VectorN<N>::counter = 0;

#endif