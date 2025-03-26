//
// Created by Gustavo Novais on 22/03/2025.
//

#include "Circle.h"
#include <cmath>

void Circle::draw() {
    glBegin(type);
    glColor3f(0.5f, 0.0f, 0.5f); // Roxo escuro
    glVertex3f(0.0f, 0.0f,0.0f);  // Centro do círculo
    for (int i=0; i<NUM_SEGMENTS; i++) {
        float theta = 2.0f * M_PI * float(i) / float(NUM_SEGMENTS);  // Ângulo
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}

