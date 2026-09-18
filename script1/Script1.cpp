#include <GL/freeglut.h>

// Função responsável por inicializar as configurações do OpenGL
void inicializar() {
    // Define a cor de fundo da janela (Preto)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // Em 2D com transparência, não usamos GL_DEPTH_TEST.
    // A ordem de desenho determina quem fica na frente.
}

// Função responsável por desenhar a cena
void desenharCena() {
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
    // A cor verde vai se misturar com o vermelho do fundo
    glColor4f(0.0f, 1.0f, 0.0f, 0.6f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f,  0.8f);
    glVertex2f(-0.5f, -0.8f);
    glVertex2f( 0.8f,  0.0f);
    glEnd();

    // 3. Quadrado Azul (Frente - Mais transparente)
    // A cor azul vai se misturar com o triângulo verde e com o fundo preto
    glColor4f(0.0f, 0.0f, 1.0f, 0.4f);
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

// Função para ajustar a projeção quando a janela for redimensionada
void redimensionar(int largura, int altura) {
    if (altura == 0) altura = 1;

    // Define a área de exibição na tela
    glViewport(0, 0, largura, altura);

    // Ajusta a matriz de projeção para 2D (Ortogonal)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5); // Define as coordenadas visíveis (X e Y)

    // Volta para a matriz de visualização do modelo
    glMatrixMode(GL_MODELVIEW);
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
    glutCreateWindow("Objetos 2D - Cores, Transparencia e Ordem");

    // Executa as configurações iniciais
    inicializar();

    // Define as funções de callback (eventos) do GLUT
    glutDisplayFunc(desenharCena);
    glutReshapeFunc(redimensionar);

    // Entra no loop principal de eventos do GLUT
    glutMainLoop();

    return 0;
}
