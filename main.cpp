#include <iostream>
#include <GLFW/glfw3.h>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);
//     glBegin(GL_TRIANGLES);
//     glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.5, -0.5);
//     glColor3f(0.0, 1.0, 0.0); glVertex2f( 0.5, -0.5);
//     glColor3f(0.0, 0.0, 1.0); glVertex2f( 0.0,  0.5);
//     glEnd();
//     glFlush();
// }
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(4.0);

    // Desenhando linhas (eixos)
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0);
    glEnd();

    // Desenhando um triângulo (LINE_LOOP)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.0, 0.5);
    glEnd();

    // Desenhando pontos
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.1, 0.4);
    glVertex2f(-0.1, 0.2);
    glVertex2f(-0.1, 0.1);
    glEnd();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}


int main(int argc, char **argv) {
    if (!glfwInit()) {
        std::cerr << "Erro ao inicializar o GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(500, 500, "Exemplo - GLFW", nullptr, nullptr);
    if (!window) {
        std::cerr << "Erro ao criar a janela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.