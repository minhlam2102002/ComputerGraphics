#pragma once
#include "global.h"

class Matrix {
private:
    static const int MAX = 3;
    double elements[MAX][MAX];

public:
    Matrix();
    Matrix(double, double, double, double, double, double);
    Matrix(const Matrix&);
    Matrix& operator=(const Matrix&);
    Matrix operator*(const Matrix&) const;
    Matrix& reset();
    Matrix& invert();
    Matrix& translate(double, double);
    Matrix& scale(double, double);
    Matrix& rotate(double);
    Matrix& shear(double, double);
    Matrix& multiply(const Matrix&);
    vector<Point> transform(const vector<Point>&) const;
    Point transform(const Point&) const;
};