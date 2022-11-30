#include "Matrix.h"

Matrix::Matrix() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) 
            elements[i][j] = (i == j);
}
Matrix::Matrix(double a, double b, double c, double d, double e, double f) {
    elements[0][0] = a; elements[0][1] = b; elements[0][2] = c;
    elements[1][0] = d; elements[1][1] = e; elements[1][2] = f;
    elements[2][0] = 0; elements[2][1] = 0; elements[2][2] = 1;
}
Matrix::Matrix(const Matrix& other) {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            elements[i][j] = other.elements[i][j];
}
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                elements[i][j] = other.elements[i][j];
    }
    return *this;
}
Matrix Matrix::operator*(const Matrix& other) const{
    Matrix result;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) {
            result.elements[i][j] = 0;
            for (int k = 0; k < MAX; k++)
                result.elements[i][j] += elements[i][k] * other.elements[k][j];
        }
    return result;
}
Matrix& Matrix::reset() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            elements[i][j] = (i == j);
    return *this;
}
Matrix& Matrix::invert() {
    double det = elements[0][0] * elements[1][1] - elements[0][1] * elements[1][0];
    double temp = elements[0][0];
    elements[0][0] = elements[1][1] / det;
    elements[1][1] = temp / det;
    elements[0][1] = -elements[0][1] / det;
    elements[1][0] = -elements[1][0] / det;
    return *this;
}
Matrix& Matrix::translate(double tx, double ty) {
    Matrix temp(1, 0, tx, 0, 1, ty);
    return multiply(temp);
}
Matrix& Matrix::scale(double sx, double sy) {
    Matrix temp(sx, 0, 0, 0, sy, 0);
    return multiply(temp);
}
Matrix& Matrix::rotate(double theta) {
    Matrix temp(cos(theta), -sin(theta), 0, sin(theta), cos(theta), 0);
    return multiply(temp);
}
Matrix& Matrix::shear(double shx, double shy) {
    Matrix temp(1, shx, 0, shy, 1, 0);
    return multiply(temp);
}
Matrix& Matrix::multiply(const Matrix& other) {
    Matrix temp = *this * other;
    return *this = temp;
}
vector<Point> Matrix::transform(const vector<Point>& points) const {
    vector<Point> result;
    for (auto point : points)
        result.push_back(transform(point));
    return result;
}
Point Matrix::transform(const Point& point) const {
    double x = point.x;
    double y = point.y;
    double w = elements[2][0] * x + elements[2][1] * y + elements[2][2];
    return Point((elements[0][0] * x + elements[0][1] * y + elements[0][2]) / w,
                 (elements[1][0] * x + elements[1][1] * y + elements[1][2]) / w);
}
