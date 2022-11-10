#include "Frame.h"

Frame::Frame() : Frame(SCREEN_WIDTH, SCREEN_HEIGHT) {}
Frame::Frame(int _width, int _height) {
    this->width = _width;
    this->height = _height;
    this->frame = new float[_width * _height * RGBColor::BYTE_SIZE];
}
void Frame::capture() {
    glReadPixels(0, 0, this->width, this->height, GL_RGB, GL_FLOAT, this->frame);
}
void Frame::display() {
    glDrawPixels(this->width, this->height, GL_RGB, GL_FLOAT, this->frame);
}
int Frame::indexOf(Pixel pixel) {
    return ((this->height - pixel.y - 1) * this->width + pixel.x) * RGBColor::BYTE_SIZE;
}
RGBColor Frame::getPixelColor(Pixel p) {
    if (!this->possess(p)) return RGBColor();
    int i = this->indexOf(p);
    return RGBColor(this->frame[i], this->frame[i + 1], this->frame[i + 2]);
}
void Frame::setPixelColor(Pixel p, RGBColor color) {
    if (!this->possess(p)) return;
    int i = this->indexOf(p);
    this->frame[i] = color.r;
    this->frame[i + 1] = color.g;
    this->frame[i + 2] = color.b;
}
bool Frame::possess(Pixel p) {
    return 0 <= p.x && p.x < this->width && 0 <= p.y && p.y < this->height;
}
void Frame::boundaryFill(Pixel p, RGBColor fillColor, RGBColor boundaryColor) {
    if (!this->possess(p)) return;
    RGBColor currentColor = this->getPixelColor(p);
    if (currentColor != boundaryColor && currentColor != fillColor) {
        this->setPixelColor(p, fillColor);
        this->boundaryFill(p + Pixel(1, 0), fillColor, boundaryColor);
        this->boundaryFill(p + Pixel(0, 1), fillColor, boundaryColor);
        this->boundaryFill(p + Pixel(-1, 0), fillColor, boundaryColor);
        this->boundaryFill(p + Pixel(0, -1), fillColor, boundaryColor);
    }
}
void Frame::floodFill(Pixel p, RGBColor fillColor, RGBColor backgroundColor) {
    queue<Pixel> q;
    q.push(p);
    while (!q.empty()) {
        Pixel current = q.front();
        q.pop();
        for (Pixel &neighbour : current.getNeighbours()) {
            RGBColor currentColor = this->getPixelColor(neighbour);
            if (this->possess(neighbour) && currentColor == backgroundColor && currentColor != fillColor) {
                this->setPixelColor(neighbour, fillColor);
                q.push(neighbour);
            }
        }
    }
}
void Frame::fill(Pixel p, RGBColor color) {
    this->floodFill(p, color, this->getPixelColor(p));
    // cout << p << " " << this->getPixelColor(p) << " " << color << endl;
    // this->setPixelColor(p, color);
}