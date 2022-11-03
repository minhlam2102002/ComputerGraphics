#pragma once
#include "Color.h"

class Point;
class GeometryObject {
public:
    virtual void render(Point*, Point*, RGBColor*, int) = 0;
    virtual void remove() = 0;
};