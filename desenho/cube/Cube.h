//
// Created by Gustavo Novais on 23/03/2025.
//

#ifndef CUBE_H
#define CUBE_H
#include <GL/glu.h>
#include "../shape/Shape.h"


class Cube: public Shape {
    float side;
    const int type;
public:
    Cube(float side, int t = GL_QUADS) : side(side), type(t) {}
    void draw() override;
    static void setConfigs();
    static void setRotate();

};



#endif //CUBE_H
