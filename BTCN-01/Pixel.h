#pragma once
#include <bits/stdc++.h>
using namespace std;

class Pixel;
class Line;
class Circle;
class Ellipse;
class Hyperbole;

class Pixel {
private:
    int x, y;
    friend class Line;
    friend class Circle;
    friend class Ellipse;
    friend class Hyperbole;
public:
    Pixel(int x = 0, int y = 0) : x(x), y(y) {}
    friend istream& operator>>(istream& is, Pixel& p);
    friend ostream& operator<<(ostream& os, const Pixel& p);
};

istream& operator>>(istream& is, Pixel& p) {
    is >> p.x >> p.y;
    return is;
}
ostream& operator<<(ostream& os, const Pixel& p) {
    os << p.x << " " << p.y;
    return os;
}