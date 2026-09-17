#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // LAWN / GROUND - GL_POLYGON
    glColor3f(0.0f, 0.65f, 0.1f);

    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(-1.0f, -0.3f);
    glEnd();

    // HOUSE WALLS - GL_QUADS
    glColor3f(0.90f, 0.85f, 0.65f);

    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.5f);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(0.4f, 0.3f);
    glVertex2f(-0.4f, 0.3f);
    glEnd();

    // ROOF - GL_TRIANGLES
    glColor3f(0.85f, 0.0f, 0.05f);

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, 0.3f);
    glVertex2f(0.5f, 0.3f);
    glVertex2f(0.0f, 0.8f);
    glEnd();

    // DOOR - GL_QUADS
    glColor3f(0.45f, 0.20f, 0.05f);

    glBegin(GL_QUADS);
    glVertex2f(-0.10f, -0.5f);
    glVertex2f(0.10f, -0.5f);
    glVertex2f(0.10f, -0.05f);
    glVertex2f(-0.10f, -0.05f);
    glEnd();

    glFlush();
}

void init()
{
    // Sky blue background
    glClearColor(0.0f, 0.75f, 0.80f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("MP05 - Architectural House Scene");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}