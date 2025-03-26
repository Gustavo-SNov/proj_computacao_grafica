//
// Created by Gustavo Novais on 22/03/2025.
//

#include "Axes.h"
#include <GL/glu.h>
#include <GLFW/glfw3.h>

Axes::Axes(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
    if (z != 0.0f) {
        setConfigs();
    }

}

void Axes::drawAxes() const {

    glLineWidth(2.0f);
    glBegin(GL_LINES);

    // Eixo X (Vermelho)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-x, 0.0f, 0.0f);
    glVertex3f(x, 0.0f, 0.0f);

    // Eixo Y (Verde)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -y, 0.0f);
    glVertex3f(0.0f, y, 0.0f);

    // Eixo Z (Azul)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -z);
    glVertex3f(0.0f, 0.0f, z);

    glEnd();

}

void Axes::setConfigs() const {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 800.0 / 600.0, 0.1, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x+0.5, y+0.5, z+0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}

/*
 * Definir matriz de projeção dos Eixos
 * glMatrixMode(GL_PROJECTION);
 * glLoadIdentity();
 *
 * Parâmetros:
 * 45.0 → Ângulo de visão vertical (FOV, em graus).
 * 800.0 / 600.0 → Proporção da tela (aspect ratio).
 * 0.1 → Plano de recorte próximo (near plane). Objetos mais próximos que 0.1 não serão renderizados.
 * 10.0 → Plano de recorte distante (far plane). Objetos mais distantes que 10.0 não serão renderizados.
 *
 * gluPerspective(45.0, 800.0 / 600.0, 0.1, 10.0);
 * O que isso faz?
 * Essa configuração define um volume de visão em perspectiva, onde objetos mais distantes aparecem
 * menores, criando um efeito de profundidade realista.
 */

/*
 * Definir matriz de modelo e visualização dos Eixos
 * glMatrixMode(GL_MODELVIEW);
 * => Alterna para a matriz de modelo/visualização (responsável por transformações de objetos e da câmera
 * glLoadIdentity();
 * => Reinicializa a matriz de modelo/visualização para garantir que nenhuma transformação anterior interfira.
 * gluLookAt(1.5, 1.5, 1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
 * Define a posição e orientação da câmera.
 *
 * Parâmetros:
 * (1.5, 1.5, 1.5) → Posição da câmera no espaço 3D.
 * (0.0, 0.0, 0.0) → Ponto para onde a câmera está olhando (origem).
 * (0.0, 1.0, 0.0) → Vetor "up" (cima da câmera). Aqui está apontando para o eixo Y positivo.
 *
 * O que isso faz?
 * Coloca a câmera na posição (1.5, 1.5, 1.5), olhando para a origem (0.0, 0.0, 0.0), com a direção "para cima" no eixo Y.
 * Isso significa que estamos visualizando a cena de um ponto elevado, olhando para o centro da cena.
 */
