#include <GL/glut.h>
#include <iostream>

float X = 100.0;
float  Y = 200.0;
float squareSize = 50.0;

void redesenha() {
    glClearColor(1.0, 1.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_QUADS);
    glVertex2f(X, Y);
    glVertex2f(X + squareSize, Y);
    glVertex2f(X + squareSize, Y + squareSize);
    glVertex2f(X, Y + squareSize);
    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        X -= 10.0;
        break;
    case '3':
        X += 10.0;
        break;
    case '5':
        Y -= 10.0;
        break;
    case '2':
        Y += 10.0;
        break;
    }
    glutPostRedisplay();
}

int main(void) {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("Square");
    glutKeyboardFunc(keyboard);
    gluOrtho2D(0, 800, 600, 0);
    glutDisplayFunc(redesenha);
    glutMainLoop();
    return 0;
}
