#include <iostream>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <cmath>

#include "desenho/axes/Axes.h"
#include "desenho/circle/Circle.h"
#include "desenho/cube/Cube.h"
#include "desenho/triangle/Triangle.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.


// Rotação do cubo
float angleX = 0.0f, angleY = 0.0f;

void displayCone(float cx, float cy, float r, int num_segments) {
    // Desenhando linhas (eixos)

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5f, 0.0f, 0.5f); // Roxo escuro
    //glVertex2f(cx, cy);  // Centro do círculo
    glVertex3f(0.0, 0.5,0.0);
    //glVertex3f(cx, 0.5,cy);

    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(num_segments);  // Ângulo
        float x = r * cos(theta);
        float y = r * sin(theta);
        //glVertex2f(cx + x, cy + y);
        // glVertex3f(cx + x, 0.0,cy + y);
        glVertex3f(cx + x, 0.0,cy + y);
    }

    glEnd();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main(int argc, char **argv) {
    Shape* figura = nullptr;
    figura = new Triangle(0.5,0.5);
    Circle c(0.5f);
    //Cube cube(0.5f);
    //Triangle triangle(0.5,0.5);

    if (!glfwInit()) {
        std::cerr << "Erro ao inicializar o GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Exemplo - GLFW", nullptr, nullptr);
    if (!window) {
        std::cerr << "Erro ao criar a janela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Configura a projeção do Cubo
    // Cube::setConfigs();
    Axes axes(1.0f,1.0f,1.0f);
    //Axes axes(1.0f,1.0f,0.0f);

    // Habilitar profundidade para 3D
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        // Limpar tela e buffer de profundidade
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Cube::setRotate();
        //cube.draw();

        // Desenhar os eixos
        axes.drawAxes();
        c.draw();
        figura->draw();

        glPointSize(4.0);
        glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f);    glVertex3f(0.7, 0.7, 0.0);
        glColor3f(1.0f, 0.0f, 1.0f);    glVertex3f(0.7, 0.7, 1.0);
        glVertex3f(0.7f, 0.7f, -1.0f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();

        // angleX += 0.5f;
        // angleY += 0.3f;

    }

    glfwTerminate();

    return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.