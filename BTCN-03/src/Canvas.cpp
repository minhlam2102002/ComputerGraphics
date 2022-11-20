#include "Canvas.h"

Canvas::Canvas() {
    this->width = SCREEN_WIDTH;
    this->height = SCREEN_HEIGHT;
    this->frame = new float[this->width * this->height * RGBColor::BYTE_SIZE];
}
// ----------------------------------------------------------------
int Canvas::indexOf(const Pixel &p) {
    return ((this->height - p.y - 1) * this->width + p.x) * RGBColor::BYTE_SIZE;
}
bool Canvas::contain(const Pixel &p) {
    return 0 <= p.x && p.x < this->width && 0 <= p.y && p.y < this->height;
}
void Canvas::setPixelColor(const Pixel &p, const RGBColor &color) {
    int i = this->indexOf(p);
    this->frame[i] = color.r;
    this->frame[i + 1] = color.g;
    this->frame[i + 2] = color.b;
}
RGBColor Canvas::getPixelColor(const Pixel &p) {
    int i = this->indexOf(p);
    return RGBColor(this->frame[i], this->frame[i + 1], this->frame[i + 2]);
}
// ----------------------------------------------------------------
void Canvas::clear() {
    for (int i = 0; i < this->width * this->height * RGBColor::BYTE_SIZE; i++) {
        this->frame[i] = 0;
    }
}
void Canvas::render() {
    glDrawPixels(this->width, this->height, GL_RGB, GL_FLOAT, this->frame);
}
void Canvas::capture() {
    glReadPixels(0, 0, this->width, this->height, GL_RGB, GL_FLOAT, this->frame);
}
// ----------------------------------------------------------------
void Canvas::floodFill(const Pixel &p, const RGBColor &backgroundColor, const RGBColor &fillColor) {
    if (backgroundColor == fillColor) return;

    queue<Pixel> q;
    q.push(p);

    while (!q.empty()) {
        Pixel current = q.front();
        q.pop();

        for (Pixel &neighbour : current.getNeighbours()) {
            if (this->contain(neighbour)) {
                RGBColor currentColor = this->getPixelColor(neighbour);

                if (currentColor == backgroundColor) {
                    this->setPixelColor(neighbour, fillColor);
                    q.push(neighbour);
                }
            }
        }
    }
}
void Canvas::boundaryFill(const Pixel &p, const RGBColor &backgroundColor, const RGBColor &fillColor) {
    // if (!this->contain(p)) return;
    // RGBColor currentColor = this->getPixelColor(p);
    // if (currentColor != backgroundColor && currentColor != fillColor) {
    //     this->setPixelColor(p, fillColor);
    //     for (Pixel &neighbour : p.getNeighbours()) {
    //         this->boundaryFill(neighbour, backgroundColor, fillColor);
    //     }
    // }
}