#include "global.h"

// -----------------------------------------------------------
RGBColor::RGBColor() : RGBColor(0, 0, 0) {}
RGBColor::RGBColor(float _r, float _g, float _b) {
    this->r = _r;
    this->g = _g;
    this->b = _b;
}
void RGBColor::set() {
    glColor3f(this->r, this->g, this->b);
}
bool RGBColor::operator==(const RGBColor &color) {
    return this->r == color.r && this->g == color.g && this->b == color.b;
}
bool RGBColor::operator!=(const RGBColor &color) {
    return !(*this == color);
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
void Pixel::set() {
    glVertex2i(this->x, this->y);
}
vector<Pixel> Pixel::getNeighbours() {
    return {
        *this + Pixel(1, 0),
        *this + Pixel(0, 1),
        *this + Pixel(-1, 0),
        *this + Pixel(0, -1)};
}
Pixel Pixel::operator+(const Pixel &p) {
    return Pixel(this->x + p.x, this->y + p.y);
}
Pixel Pixel::operator+=(const Pixel &p) {
    this->x += p.x;
    this->y += p.y;
    return *this;
}
Pixel Pixel::operator-(const Pixel &p) {
    return Pixel(this->x - p.x, this->y - p.y);
}
ostream &operator<<(ostream &os, const Pixel &p) {
    os << "Pixel(" << p.x << ", " << p.y << ")";
    return os;
}
// -----------------------------------------------------------
int measureTime(void (*func)()) {
    auto start = high_resolution_clock::now();
    func();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
};