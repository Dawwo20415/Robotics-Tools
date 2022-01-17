#ifndef JOINT_CLASS
#define JOINT_CLASS

#include "../algebric_backend/matrix.h"
#include <math.h>

class Transform {

    public:

        Vectorn position; //  x   |   y   |  z
        Vectorn rotation; // roll | pitch | yaw

        Transform() : position({0,0,0,}), rotation({0,0,0}) {};
        Transform(const Vectorn& pos, const Vectorn& rot) : position(pos), rotation(rot) {};

        float roll  () { return rotation[0]; }
        float pitch () { return rotation[1]; }
        float yaw   () { return rotation[2]; }

        float x () { return position[0]; }
        float y () { return position[1]; }
        float z () { return position[2]; }

};

class Link {

    public:

        Vectorn link_end;

        Link(const Vectorn& lk) : link_end(lk) {};

        float link_length () { return sqrt((link_end[0] * link_end[0]) + 
                                           (link_end[1] * link_end[1]) + 
                                           (link_end[2] * link_end[2])); }

};

//Parent class
class Joint {

    protected:

        Transform pm_transform;
        Vectorn pm_joint_effector;
        Link pm_link;

    public:

        Joint(Link link) : pm_transform(), pm_joint_effector({0,0,0}), pm_link(link)  {};

        //Virtual Functions
        virtual Matrix  getHomogenousTransformationMatrix(Transform transform) { return Matrix::identityMatrix(3); };
        virtual Vectorn rototransform(Transform transform) { return Vectorn::nullVector(3); };

    
};

//Subclasses

class AbsoluteJoint : public Joint {

    public:

        //Constructors ----------------------------------------
            AbsoluteJoint(Link link) : Joint(link) {};

        //Functions -------------------------------------------
            Matrix  getHomogenousTransformationMatrix(Transform transform) override;
            Vectorn rototransform(Transform transform) override;
};

class RevoluteJoint : public Joint {

    public:

        //Constructors ----------------------------------------
            RevoluteJoint(Link link) : Joint(link) {};

        //Functions -------------------------------------------
            Matrix  getHomogenousTransformationMatrix(Transform transform) override;
            Vectorn rototransform(Transform transform) override;
};

class UnidirectionalRevoluteJoint : public Joint {

    public:

        enum Axis : char {
            Yaw, Pitch, Roll
        };

        Axis m_axis;

        //Constructors ----------------------------------------
            UnidirectionalRevoluteJoint(Link link, Axis axis) : Joint(link), m_axis(axis) {};

        //Functions -------------------------------------------
            Matrix  getHomogenousTransformationMatrix(Transform transform) override;
            Vectorn rototransform(Transform transform) override;
};

class PrismaticJoint : public Joint {

    public:

        //Constructors ----------------------------------------
            PrismaticJoint(Link link) : Joint(link) {};

        //Functions -------------------------------------------
            Matrix  getHomogenousTransformationMatrix(Transform transform) override;
            Vectorn rototransform(Transform transform) override;
};

class UnidirectionalPrismaticJoint : public Joint {

    public:

        enum Axis : char {
            X, Y, Z
        };

        Axis m_axis;

        //Constructors ----------------------------------------
            UnidirectionalPrismaticJoint(Link link, Axis axis) : Joint(link), m_axis(axis) {};

        //Functions -------------------------------------------
            Matrix  getHomogenousTransformationMatrix(Transform transform) override;
            Vectorn rototransform(Transform transform) override;
};

//Functions

#endif
