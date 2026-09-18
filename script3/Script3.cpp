#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Ativa transparência
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // --- PAR 1 (CIMA): Vermelho primeiro, Azul depois ---
    glColor4f(1.0f, 0.0f, 0.0f, 0.7f); // Vermelho
    glBegin(GL_QUADS);
    glVertex2f(-0.8f,  0.1f);
    glVertex2f(-0.2f,  0.1f);
    glVertex2f(-0.2f,  0.9f);
    glVertex2f(-0.8f,  0.7f);
    glEnd();

    glColor4f(0.0f, 0.0f, 1.0f, 0.4f); // Azul
    glBegin(GL_QUADS);
    glVertex2f(-0.3f,  0.1f);
    glVertex2f(0.8f,   0.1f);
    glVertex2f(0.8f,   0.9f);
    glVertex2f(0.2f,   0.9f);
    glEnd();

    // --- PAR 2 (BAIXO): Azul primeiro, Vermelho depois ---
    glColor4f(0.0f, 0.0f, 1.0f, 0.4f); // Azul
    glBegin(GL_QUADS);
    glVertex2f(-0.3f, -0.9f);
    glVertex2f(0.8f,  -0.9f);
    glVertex2f(0.8f,  -0.1f);
    glVertex2f(0.2f,  -0.1f);
    glEnd();

    glColor4f(1.0f, 0.0f, 0.0f, 0.7f); // Vermelho
    glBegin(GL_QUADS);
    glVertex2f(-0.8f, -0.9f);
    glVertex2f(-0.2f, -0.9f);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(-0.8f, -0.3f);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Dois objetos");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
