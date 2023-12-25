#include "dot_3d.h"

double Dot3D::X() const { return x; }
void Dot3D::setX(double _x) { x = _x; }

double Dot3D::Y() const { return y; }
void Dot3D::setY(double _y) { y = _y; }

double Dot3D::Z() const { return z; }
void Dot3D::setZ(double _z) { z = _z; }

void Dot3D::move(double _x, double _y, double _z) {
    x += _x;
    y += _y;
    z += _z;
}

void Dot3D::scale(double k, double _x, double _y, double _z) {
    Dot3D::move(-_x, -_y, -_z);

    x *= k;
    y = k;
    z = k;

    Dot3D::move(_x, _y, _z);
}

void Dot3D::rotateX(double angle, double _x, double _y, double _z) {
    Dot3D::move(-_x, -_y, -_z);

    Eigen::Matrix3f rotateMatrix;
    rotateMatrix << 1,           0,          0,
                    0, cos(angle), -sin(angle),
                    0, sin(angle),  cos(angle),
                    0,           0,          0;

    Eigen::MatrixXf v(1, 3);
    v << x, y, z;

    v *= rotateMatrix;

    x = v(0, 0);
    y = v(0, 1);
    z = v(0, 2);

    Dot3D::move(_x, _y, _z);
}

void Dot3D::rotateY(double angle, double _x, double _y, double _z) {
    Dot3D::move(-_x, -_y, -_z);

    Eigen::Matrix3f rotateMatrix;
    rotateMatrix << cos(angle),  0, sin(angle),
                    0,           1,          0,
                    -sin(angle), 0, cos(angle),
                    0,           0,          0;

    Eigen::MatrixXf v(1, 3);
    v << x, y, z;

    v *= rotateMatrix;

    x = v(0, 0);
    y = v(0, 1);
    z = v(0, 2);

    Dot3D::move(_x, _y, _z);
}

void Dot3D::rotateZ(double angle, double _x, double _y, double _z) {
    Dot3D::move(-_x, -_y, -_z);

    Eigen::Matrix3f rotateMatrix;
    rotateMatrix << cos(angle), -sin(angle), 0,
                    sin(angle),  cos(angle), 0,
                    0,                    0, 1,
                    0,                    0, 0;

    Eigen::MatrixXf v(1, 3);
    v << x, y, z;

    v *= rotateMatrix;

    x = v(0, 0);
    y = v(0, 1);
    z = v(0, 2);

    Dot3D::move(_x, _y, _z);
}
