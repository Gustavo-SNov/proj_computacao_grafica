//
// Created by Gustavo Novais on 22/03/2025.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <GLFW/glfw3.h>
#include "../shape/Shape.h"

class Triangle: public Shape {

    float width, height;
    const int type;


public:
    Triangle(float width, float height, int t=GL_TRIANGLES) : width(width), height(height), type(t) {}
    int getType() const { return type; }
    void setWidth(float w) { width = w; }
    void setHeight(float h) { height = h; }
    [[nodiscard]] float getWidth() const { return width; }
    [[nodiscard]] float getHeight() const { return height; }

    void draw() override;
    void drawFull() const;
    static void drawLines();
};




#endif //TRIANGLE_H
