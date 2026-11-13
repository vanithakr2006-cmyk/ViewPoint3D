#include <GL/freeglut.h>
#include "Scene.h"

// ===============================
// Display Function
// ===============================
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Camera position
    gluLookAt(
        0.0, 2.5, 8.0,
        0.0, 2.5, 0.0,
        0.0, 1.0, 0.0
    );

    // Draw the room
    drawRoom();

    glutSwapBuffers();
}

// ===============================
// Window Resize Function
// ===============================
void reshape(int width, int height)
{
    if (height == 0)
        height = 1;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        60.0,
        (double)width / (double)height,
        0.1,
        100.0
    );

    glMatrixMode(GL_MODELVIEW);
}

// ===============================
// Main Function
// ===============================
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );

    glutInitWindowSize(800, 600);

    glutCreateWindow("ViewPoint 3D");

    glClearColor(
        0.1f,
        0.1f,
        0.1f,
        1.0f
    );

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}