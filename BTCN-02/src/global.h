#pragma once
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <map>
#include <cmath>
#include <queue>

using namespace std;
using namespace std::chrono;

extern int SCREEN_WIDTH, SCREEN_HEIGHT;

struct RGBColor {
    static const int BYTE_SIZE = 3;
    float r, g, b;
    RGBColor();
    RGBColor(float, float, float);
    void set();
    bool operator==(const RGBColor &);
    bool operator!=(const RGBColor &);
    friend ostream& operator<<(ostream&, const RGBColor&);
};

struct Pixel {
    int x, y;
    Pixel();
    Pixel(int, int);
    void set();
    vector<Pixel> getNeighbours();
    Pixel operator+(const Pixel &);
    Pixel operator+=(const Pixel &);
    Pixel operator-(const Pixel &);
    friend ostream& operator<<(ostream&, const Pixel&);
};

int measureTime(void (*)());