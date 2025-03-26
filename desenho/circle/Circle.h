//
// Created by Gustavo Novais on 22/03/2025.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include <GLFW/glfw3.h>
#include "../shape/Shape.h"

class Circle: public Shape {
    const int NUM_SEGMENTS = 100;  // Número de segmentos do círculo
    float radius;     // Raio do círculo
    const int type;

public:
    Circle(float radius, int t = GL_TRIANGLE_FAN ): radius(radius), type(t) {}
    int getType() const { return type; }
    float getRadius() const { return radius; }
    void setRadius(float r) { radius = r; }
    void draw() override;
};



#endif //CIRCLE_H
