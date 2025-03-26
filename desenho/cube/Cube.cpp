//
// Created by Gustavo Novais on 23/03/2025.
//

#include "Cube.h"
#include <GL/glu.h>

void Cube::setConfigs() {
    // Configura a projeção do Cubo
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Cube::setRotate() {
    // Rotação do cubo
    float angleX = 0.0f, angleY = 0.0f;

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
}

void Cube::draw() {

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

    glBegin(type);

    // Face frontal (vermelha)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-side, -side,  side);
    glVertex3f( side, -side,  side);
    glVertex3f( side,  side,  side);
    glVertex3f(-side,  side,  side);

    // Face traseira (verde)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-side, -side, -side);
    glVertex3f(-side,  side, -side);
    glVertex3f( side,  side, -side);
    glVertex3f( side, -side, -side);

    // Face esquerda (azul)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-side, -side, -side);
    glVertex3f(-side, -side,  side);
    glVertex3f(-side,  side,  side);
    glVertex3f(-side,  side, -side);

    // Face direita (amarela)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(side, -side, -side);
    glVertex3f(side,  side, -side);
    glVertex3f(side,  side,  side);
    glVertex3f(side, -side,  side);

    // Face superior (ciano)
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-side,  side, -side);
    glVertex3f(-side,  side,  side);
    glVertex3f( side,  side,  side);
    glVertex3f( side,  side, -side);

    // Face inferior (magenta)
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-side, -side, -side);
    glVertex3f( side, -side, -side);
    glVertex3f( side, -side,  side);
    glVertex3f(-side, -side,  side);

    glEnd();
}