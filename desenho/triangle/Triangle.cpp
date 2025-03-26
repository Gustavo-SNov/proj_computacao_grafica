//
// Created by Gustavo Novais on 22/03/2025.
//

#include "Triangle.h"
#include <GLFW/glfw3.h>

void Triangle::draw() {
    glBegin(type);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0,0.0);
    glVertex3f(-width, 0.0,0.5);
    glVertex3f(0.0, height,0.0);

    glEnd();
}

void Triangle::drawLines() {
    glBegin(GL_LINE_LOOP);

    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.0, 0.5);

    glEnd();
}

void Triangle::drawFull() const {
    glBegin(GL_TRIANGLES);
    // glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.5, -0.5);
    // glColor3f(0.0, 1.0, 0.0); glVertex2f( 0.5, -0.5);
    // glColor3f(0.0, 0.0, 1.0); glVertex2f( 0.0,  0.5);
    glColor3f(1.0, 0.0, 0.0); glVertex3f(0.0, 0.0,0.0);
    glColor3f(0.0, 1.0, 0.0); glVertex3f(-width, 0.0,0.5);
    glColor3f(0.0, 0.0, 1.0); glVertex3f(0.0, height,0.0);
    glEnd();
}


