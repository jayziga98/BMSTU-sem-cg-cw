#ifndef DOT_3D_H
#define DOT_3D_H

#include "../Eigen/Dense"

class Dot3D
{
private:
    double x, y, z;

public:
    Dot3D(){};
    Dot3D(double _x, double _y, double _z)
        : x(_x), y(_y), z(_z) {}

    double X() const;
    void setX(double _x);

    double Y() const;
    void setY(double _y);

    double Z() const;
    void setZ(double _z);

    void scale(double k, double _x, double _y, double _z);
    void move(double _x, double _y, double _z);

    void rotateX(double angle, double _x, double _y, double _z);
    void rotateY(double angle, double _x, double _y, double _z);
    void rotateZ(double angle, double _x, double _y, double _z);
};

#endif // DOT_3D_H
