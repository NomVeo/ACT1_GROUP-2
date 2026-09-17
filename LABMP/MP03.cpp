#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Translucent red panel on the left.
    glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.75f, -0.45f);
        glVertex2f( 0.15f, -0.45f);
        glVertex2f( 0.15f,  0.45f);
        glVertex2f(-0.75f,  0.45f);
    glEnd();

    // Translucent green panel on the right.
    glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, -0.45f);
        glVertex2f( 0.75f, -0.45f);
        glVertex2f( 0.75f,  0.45f);
        glVertex2f(-0.15f,  0.45f);
    glEnd();

    // Translucent blue panel crossing both panels vertically.
    glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.45f, -0.75f);
        glVertex2f( 0.45f, -0.75f);
        glVertex2f( 0.45f,  0.15f);
        glVertex2f(-0.45f,  0.15f);
    glEnd();

    glDisable(GL_BLEND);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutCreateWindow("MP 03: Stained Glass Panels");
    glClearColor(0.08f, 0.08f, 0.08f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
