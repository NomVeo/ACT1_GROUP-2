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

    glBegin(GL_QUAD_STRIP);

    // Pair 1
    glColor3f(0.80f, 0.85f, 0.80f);
    glVertex2f(-0.8f, 0.2f);  // Top
    glVertex2f(-0.8f, -0.2f); // Bottom

    // Pair 2
    glColor3f(0.75f, 0.82f, 0.75f);
    glVertex2f(-0.4f, 0.0f);  // Top
    glVertex2f(-0.4f, -0.4f); // Bottom

    // Pair 3
    glColor3f(0.85f, 0.88f, 0.80f);
    glVertex2f(0.0f, 0.4f);  // Top
    glVertex2f(0.0f, -0.1f); // Bottom

    // Pair 4
    glColor3f(0.78f, 0.84f, 0.72f);
    glVertex2f(0.4f, 0.1f);   // Top
    glVertex2f(0.4f, -0.35f); // Bottom

    // Pair 5
    glColor3f(0.88f, 0.90f, 0.78f);
    glVertex2f(0.8f, 0.5f);   // Top
    glVertex2f(0.8f, -0.15f); // Bottom

    glEnd();

    glFlush();
}

void init()
{
    // Dark background
    glClearColor(0.05f, 0.06f, 0.08f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Coordinate system
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("MP04 - Winding Terrain Ribbon");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}