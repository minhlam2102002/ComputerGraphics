#include "Object.h"

bool Object::isClicked(const Pixel &p) {
    cout << start << " " << p << " " << end << endl;
    return isBetween(start.x, p.x, end.x) && isBetween(start.y, p.y, end.y);
}
void Object::drawObject() {
    this->drawFunc(this->start, this->end, this->color);
}
Object::Object(const Pixel &start, const Pixel &end, const RGBColor &color, string name) {
    this->start = start;
    this->end = end;
    this->color = color;
    this->drawFunc = drawFunctions[name];
}
