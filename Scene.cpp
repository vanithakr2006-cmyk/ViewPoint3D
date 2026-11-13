#include <GL/freeglut.h>
#include "Scene.h"

// ======================================
// Draw a Cube
// ======================================
void drawCube(float x, float y, float z,
              float width, float height, float depth)
{
    glPushMatrix();

    glTranslatef(x, y, z);
    glScalef(width, height, depth);

    glutSolidCube(1.0f);

    glPopMatrix();
}


// ======================================
// Draw the Floor
// ======================================
void drawFloor()
{
    glBegin(GL_QUADS);

        glVertex3f(-5.0f, 0.0f, -5.0f);
        glVertex3f( 5.0f, 0.0f, -5.0f);
        glVertex3f( 5.0f, 0.0f,  5.0f);
        glVertex3f(-5.0f, 0.0f,  5.0f);

    glEnd();
}


// ======================================
// Draw a Wall
// ======================================
void drawWall(float x, float y, float z,
              float width, float height, float depth)
{
    glPushMatrix();

    glTranslatef(x, y, z);
    glScalef(width, height, depth);

    glutSolidCube(1.0f);

    glPopMatrix();
}


// ======================================
// Draw the 3D Room
// ======================================
void drawRoom()
{
    // Floor
    glColor3f(0.35f, 0.35f, 0.35f);
    drawFloor();


    // Back Wall
    glColor3f(0.55f, 0.55f, 0.65f);

    drawWall(
        0.0f, 2.5f, -5.0f,
        10.0f, 5.0f, 0.1f
    );


    // Left Wall
    glColor3f(0.45f, 0.50f, 0.60f);

    drawWall(
        -5.0f, 2.5f, 0.0f,
        0.1f, 5.0f, 10.0f
    );


    // Right Wall
    glColor3f(0.45f, 0.50f, 0.60f);

    drawWall(
        5.0f, 2.5f, 0.0f,
        0.1f, 5.0f, 10.0f
    );


    // Ceiling
    glColor3f(0.65f, 0.65f, 0.70f);

    drawWall(
        0.0f, 5.0f, 0.0f,
        10.0f, 0.1f, 10.0f
    );
}