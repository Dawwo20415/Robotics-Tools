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

        double roll  () { return rotation[0]; }
        double pitch () { return rotation[1]; }
        double yaw   () { return rotation[2]; }

        double x () { return position[0]; }
        double y () { return position[1]; }
        double z () { return position[2]; }

        std::string getString () {
            return "[ Translation => X: " + std::to_string(position[0]) + " Y: " + std::to_string(position[1]) + " Z: " + std::to_string(position[2]) + " | " +
                   "Rotation => roll: " + std::to_string(rotation[0]) + " pitch: " + std::to_string(rotation[1]) + " yaw: " + std::to_string(rotation[2]) + " ]";
        };
};

class Link {

    public:

        Vectorn link_end;

        Link(const Vectorn& lk) : link_end(lk) {};

        double link_length () { return sqrt((link_end[0] * link_end[0]) + 
                                            (link_end[1] * link_end[1]) + 
                                            (link_end[2] * link_end[2])); }
        
        Matrix link_matrix () {return Matrix({{1,0,0,link_end[0]},
                                              {0,1,0,link_end[1]},
                                              {0,0,1,link_end[2]},
                                              {0,0,0,    1      }});}

};

//Parent class
class Joint {

    protected:

        Transform pm_current_tr = Transform({0,0,0},{0,0,0});
        Transform pm_upper_limit;
        Transform pm_lower_limit;
        Link pm_link;

    public:

        Joint(Link link, Transform upper, Transform lower) :  pm_link(link), pm_upper_limit(upper), pm_lower_limit(lower)  {};

        //Virtual Functions
        virtual bool applyTransform(Transform tr) = 0;
        virtual Matrix  getHomogenousTransformationMatrix(Transform transform) = 0;
        virtual Vectorn getConfigurationSpace() = 0;
        virtual Matrix  linkMatrix();

        virtual void printStatus();
        virtual Vectorn jointVector();
        virtual void printVector();
        virtual Matrix getJacobianSection(const Matrix& homogenous, const Vectorn& endEffector);
    
};

//Subclasses

class AbsoluteJoint : public Joint {

    public:

        //Constructors ----------------------------------------
            AbsoluteJoint(Link link, Transform upper, Transform lower) : Joint(link, upper, lower) {};

        //Functions -------------------------------------------
            Matrix  getHomogenousTransformationMatrix(Transform transform) override;
            Matrix getJacobianSection(const Matrix& homogenous, const Vectorn& endEffector) override;
            virtual bool applyTransform(Transform tr);
            Vectorn getConfigurationSpace();
};

class RevoluteJoint : public Joint {

    public:

        //Constructors ----------------------------------------
            RevoluteJoint(Link link, Transform upper, Transform lower) : Joint(link, upper, lower) {};

        //Functions -------------------------------------------
            Matrix  getHomogenousTransformationMatrix(Transform transform) override;
            Matrix getJacobianSection(const Matrix& homogenous, const Vectorn& endEffector) override;
            virtual bool applyTransform(Transform tr);
            Vectorn getConfigurationSpace();
};

class UnidirectionalRevoluteJoint : public Joint {

    public:

        enum Axis : char {
            Yaw, Pitch, Roll
        };

        Axis m_axis;

        //Constructors ----------------------------------------
            UnidirectionalRevoluteJoint(Link link, Transform upper, Transform lower, Axis axis) : Joint(link, upper, lower), m_axis(axis) {};

        //Functions -------------------------------------------
            Matrix  getHomogenousTransformationMatrix(Transform transform) override;
            Matrix getJacobianSection(const Matrix& homogenous, const Vectorn& endEffector) override;
            virtual bool applyTransform(Transform tr);
            Vectorn getConfigurationSpace();
};

class PrismaticJoint : public Joint {

    public:

        //Constructors ----------------------------------------
            PrismaticJoint(Link link, Transform upper, Transform lower) : Joint(link, upper, lower) {};

        //Functions -------------------------------------------
            Matrix  getHomogenousTransformationMatrix(Transform transform) override;
            Matrix getJacobianSection(const Matrix& homogenous, const Vectorn& endEffector) override;
            virtual bool applyTransform(Transform tr);
            Vectorn getConfigurationSpace();
};

class UnidirectionalPrismaticJoint : public Joint {

    public:

        enum Axis : char {
            X, Y, Z
        };

        Axis m_axis;

        //Constructors ----------------------------------------
            UnidirectionalPrismaticJoint(Link link, Transform upper, Transform lower, Axis axis) : Joint(link, upper, lower), m_axis(axis) {};

        //Functions -------------------------------------------
            Matrix  getHomogenousTransformationMatrix(Transform transform) override;
            Matrix getJacobianSection(const Matrix& homogenous, const Vectorn& endEffector) override;
            virtual bool applyTransform(Transform tr);
            Vectorn getConfigurationSpace();
};

//Functions

#endif
