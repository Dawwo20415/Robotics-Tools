#ifndef VECTOR3_CLASS
#define VECTOR3_CLASS

#include <vector>
#include <memory>

class Vector3 {

    private:
        std::vector<float> *v; 
        static int counter;
        int index;

    public:
        //Default Constructors
        Vector3();
        //Copy Constructor
        Vector3 (const Vector3 &vec);
        //Float Constructor
        Vector3(float x, float y, float z);
        //Destructor
        ~Vector3();
        //Functions
        std::vector<float> Get();
        void Print();
        void Println();
        float GetX();
        float GetY();
        float GetZ();
        //Operators
        //Vector3 operator=(const Vector3& vec);
        Vector3 operator+(const Vector3& vec);
        Vector3 operator-(const Vector3& vec);
        Vector3 operator*(const Vector3& vec);
        Vector3 operator*(float val);  
        float DotProduct(Vector3 vec);  
        //Statics
        static Vector3 UnitVector();
        static Vector3 NullVector();    
};

int Vector3::counter = 0;

#endif