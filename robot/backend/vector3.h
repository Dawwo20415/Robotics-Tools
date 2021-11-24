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
        VectorN (const VectorN &vec);
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
        //Operators
        //Vector3 operator=(const Vector3& vec);
        VectorN& operator=(const VectorN<N>& vec);
        VectorN operator+(const VectorN<N>& vec);
        VectorN operator-(const VectorN<N>& vec);
        VectorN operator*(const VectorN<N>& vec);
        VectorN operator*(float val);  
        float DotProduct(VectorN<N> vec);  
        //Statics
        static VectorN UnitVector();
        static VectorN NullVector();
        static const VectorN &UnitVectorPtr();
        static const VectorN &NullVectorPtr();     
};

template <int N>
int VectorN<N>::counter = 0;

#endif