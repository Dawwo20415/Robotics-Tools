#ifndef JOINT_CLASS
#define JOINT_CLASS

#include "../algebric_backend/matrix.h"
#include <math.h>

//Parent class
class Joint {

    public:

        


};

//Subclasses
class RevoluteJoint {


    public:

        float pm_length;
        Matrix rotation_matrix = Matrix(2,2);
        Vectorn position = Vectorn(2);

        //Constructors ----------------------------------------
            RevoluteJoint(float length);

        //Functions -------------------------------------------
            Matrix getRotationMatrix(float angle);
            Vectorn rotate(float angle);

};

//Functions

#endif
