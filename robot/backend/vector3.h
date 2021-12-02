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
        //Vector Copy Constructor
        VectorN (const std::vector<float>& other);
        //Vector Move Constructor
        VectorN (std::vector<float>&& other) noexcept;
        //Float Array Constructor
        VectorN(const float (&other)[N]);
        //Float Constructor
        VectorN(float (&&other)[N]) noexcept;
        //Destructor
        ~VectorN();
        //Functions
        std::vector<float>& Get();
        const std::vector<float>& Get() const;
        void Print();
        void Println();
        int GetIndex() { return index; };
        bool isNull() { return (this->v == nullptr);};
        //Operators
        //Assignment operator
        VectorN& operator=(const VectorN<N>& other);
        VectorN& operator=(VectorN<N>&& other) noexcept;
        //Float Array Assignment operators
        VectorN& operator=(const float (&other)[N]);
        VectorN& operator=(float (&&other)[N]) noexcept;
        //Selection operator
        float& operator[](int _i);
        const float& operator[](int _i) const;
        //Addition Operator 
        VectorN& operator+=(const VectorN<N>& _other);
        template<int _N> friend VectorN<_N> operator+(VectorN<_N> _this, const VectorN<_N>& _other);
        //Subtraction operator
        VectorN& operator-=(const VectorN<N>& _other);
        template<int _N> friend VectorN<_N> operator-(VectorN<_N> _this, const VectorN<_N>& _other);

        //Subtraction operator
        //Cross Product operator
        VectorN operator*(const VectorN<N>& other);
        //Scalar Product operator
        VectorN operator*(const float& val);  
        float DotProduct(const VectorN<N>& other); 
        //Selection operator
        float& operator[](int _i);
        const float& operator[](int _i) const;
        //Output stream operator
        template<int T> friend std::ostream& operator<<(std::ostream& os, const VectorN<T>& _v);
        //Statics
        static VectorN UnitVector();
        static VectorN NullVector();    
};

template <int N>
int VectorN<N>::counter = 0;

//Friendly operators
template <int _N>
VectorN<_N> operator+(VectorN<_N> _this, const VectorN<_N>& _other) {
    _this += _other;
    return _this;
}

template <int _N>
VectorN<_N> operator-(VectorN<_N> _this, const VectorN<_N>& _other) {
    _this -= _other;
    return _this;
}

template<int T>
std::ostream& operator<<(std::ostream& os, const VectorN<T>& _v);

#endif