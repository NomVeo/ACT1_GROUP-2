#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    const float PI = 3.14159265f;
    const float radius = 0.6f;
    const int segments = 16;

    glShadeModel(GL_SMOOTH);

    glBegin(GL_TRIANGLE_FAN);
        // Use the average of magenta and yellow at the central hub.
        glColor3f(1.0f, 0.5f, 0.5f);
        glVertex2f(0.0f, 0.0f);

        // Repeat the first outer vertex at the end to close the full circle.
        for (int i = 0; i <= segments; i++) {
            float angle = (float)i / segments * 2.0f * PI;

            if (i % 2 == 0)
                glColor3f(1.0f, 0.0f, 1.0f); // Bright magenta
            else
                glColor3f(1.0f, 1.0f, 0.0f); // Yellow

            glVertex2f(radius * cosf(angle), radius * sinf(angle));
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("MP 02: Radial Sunburst");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
