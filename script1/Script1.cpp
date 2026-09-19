#include <GL/freeglut.h>

// Função responsável por desenhar a cena
void display() {
    // Limpa a tela
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Ativa a mistura de cores para permitir transparência
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // 1. Quadrado Vermelho (Fundo - Totalmente opaco)
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f,  0.5f);
    glVertex2f( 0.2f,  0.5f);
    glVertex2f( 0.2f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();

    // 2. Triângulo Verde (Meio - Parcialmente transparente)
    glColor4f(0.0f, 1.0f, 0.0f, 0.6f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f,  0.8f);
    glVertex2f(-0.5f, -0.8f);
    glVertex2f( 0.8f,  0.0f);
    glEnd();

    // 3. Quadrado Azul (Frente - Mais transparente)
    glColor4f(0.0f, 0.0f, 1.0f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-0.2f,  0.6f);
    glVertex2f( 1.0f,  0.6f);
    glVertex2f( 1.0f, -0.6f);
    glVertex2f(-0.2f, -0.6f);
    glEnd();

    // Desativa a mistura de cores
    glDisable(GL_BLEND);

    // Troca os buffers de tela
    glutSwapBuffers();
}

// Função principal do programa
int main(int argc, char** argv) {
    // Inicializa o GLUT
    glutInit(&argc, argv);

    // Configura o modo de exibição (Cores RGBA e Double Buffer)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    // Define o tamanho inicial da janela
    glutInitWindowSize(800, 600);

    // Cria a janela com um título
    glutCreateWindow("Script 1");

    // Define as funções de callback (eventos) do GLUT
    glutDisplayFunc(display);

    // Entra no loop principal de eventos do GLUT
    glutMainLoop();

    return 0;
}
