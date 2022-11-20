#include "global.h"

// -----------------------------------------------------------
RGBColor::RGBColor() : RGBColor(0, 0, 0) {}
RGBColor::RGBColor(float _r, float _g, float _b) {
    this->r = _r;
    this->g = _g;
    this->b = _b;
}
bool operator==(const RGBColor& c1, const RGBColor& c2) {
    return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b;
}
bool operator!=(const RGBColor& c1, const RGBColor& c2) {
    return !(c1 == c2);
}
ostream &operator<<(ostream &os, const RGBColor &color) {
    os << "RGBColor(" << color.r << ", " << color.g << ", " << color.b << ")";
    return os;
}
// -----------------------------------------------------------
Pixel::Pixel() : Pixel(0, 0) {}
Pixel::Pixel(int _x, int _y) {
    this->x = _x;
    this->y = _y;
}
vector<Pixel> Pixel::getNeighbours() const {
    return {
        *this + Pixel(1, 0),
        *this + Pixel(0, 1),
        *this + Pixel(-1, 0),
        *this + Pixel(0, -1)
    };
}
Pixel& Pixel::operator+=(const Pixel &p) {
    this->x += p.x;
    this->y += p.y;
    return *this;
}
Pixel& Pixel::operator/=(const int &n) {
    this->x /= n;
    this->y /= n;
    return *this;
}
Pixel operator+(const Pixel &p1, const Pixel &p2) {
    return Pixel(p1.x + p2.x, p1.y + p2.y);
}
Pixel operator-(const Pixel &p1, const Pixel &p2) {
    return Pixel(p1.x - p2.x, p1.y - p2.y);
}
Pixel operator/(const Pixel &p, const int &n) {
    return Pixel(p.x / n, p.y / n);
}
Pixel operator*(const Pixel &p, const int &n) {
    return Pixel(p.x * n, p.y * n);
}
ostream &operator<<(ostream &os, const Pixel &p) {
    os << "Pixel(" << p.x << ", " << p.y << ")";
    return os;
}
// -----------------------------------------------------------
void glVertex(const Pixel &p) {
    glVertex2i(p.x, p.y);
}
void glColor(const RGBColor &color) {
    glColor3f(color.r, color.g, color.b);
}
// -----------------------------------------------------------
vector<RGBColor> colorsMap = {
    RGBColor(1, 0, 0),
    RGBColor(0, 1, 0),
    RGBColor(0, 0, 1),
    RGBColor(1, 1, 0),
    RGBColor(1, 0, 1),
    RGBColor(0, 1, 1),
    RGBColor(1, 1, 1),
    RGBColor(0, 0, 0)
};
vector<string> colorNames = {
    "Red",
    "Green",
    "Blue",
    "Yellow",
    "Magenta",
    "Cyan",
    "White",
    "Black"
};
// -----------------------------------------------------------
int measureTime(void (*func)()) {
    auto start = high_resolution_clock::now();
    func();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
};
bool isBetween(const int &a, const int &x, const int &b) {
    return (a <= x && x <= b) || (b <= x && x <= a);
}