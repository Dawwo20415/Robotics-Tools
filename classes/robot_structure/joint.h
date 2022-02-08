#ifndef JOINT_CLASS
#define JOINT_CLASS

#include "../algebric_backend/matrix.h"

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
            std::stringstream tmp;
            tmp << std::fixed << std::setprecision(2);

            tmp << "[ Translation => X: " << position[0] << " Y: " << position[1] << " Z: " << position[2] << " | " <<
                     "Rotation => roll: " << rotation[0] << " pitch: " << rotation[1] << " yaw: " << rotation[2] << " ]";

            return tmp.str();
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
        virtual bool setPosition(Transform tr) = 0;
        virtual Matrix  getHomogenousTransformationMatrix() = 0;
        virtual Vectorn getConfigurationSpace() = 0;
        virtual Matrix  linkMatrix();

        virtual void printStatus();
        virtual Vectorn jointVector();
        virtual void printVector();
        virtual Matrix getJacobianSection(Matrix& jacobian, const Matrix& homogenous, const Vectorn& endEffector);
    
};

//Subclasses

class RevoluteJoint : public Joint {

    public:

        //Constructors ----------------------------------------
            RevoluteJoint(Link link, Transform upper, Transform lower) : Joint(link, upper, lower) {};

        //Functions -------------------------------------------
            bool setPosition(Transform tr);
            Matrix  getHomogenousTransformationMatrix() override;
            Matrix  getHomogenousTransformationMatrixSteps(Transform transform, int step);
            Matrix getJacobianSection(Matrix& jacobian, const Matrix& homogenous, const Vectorn& endEffector) override;
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
            bool setPosition(Transform tr);
            Matrix  getHomogenousTransformationMatrix() override;
            Matrix getJacobianSection(Matrix& jacobian, const Matrix& homogenous, const Vectorn& endEffector) override;
            virtual bool applyTransform(Transform tr);
            Vectorn getConfigurationSpace();
};

class PrismaticJoint : public Joint {

    public:

        //Constructors ----------------------------------------
            PrismaticJoint(Link link, Transform upper, Transform lower) : Joint(link, upper, lower) {};

        //Functions -------------------------------------------
            bool setPosition(Transform tr);
            Matrix  getHomogenousTransformationMatrix() override;
            Matrix  getHomogenousTransformationMatrixSteps(Transform transform, int step);
            Matrix getJacobianSection(Matrix& jacobian, const Matrix& homogenous, const Vectorn& endEffector) override;
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
            bool setPosition(Transform tr);
            Matrix  getHomogenousTransformationMatrix() override;
            Matrix getJacobianSection(Matrix& jacobian, const Matrix& homogenous, const Vectorn& endEffector) override;
            virtual bool applyTransform(Transform tr);
            Vectorn getConfigurationSpace();
};

//Functions

#endif
