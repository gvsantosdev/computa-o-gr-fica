#include <GL/glut.h>
#include <math.h>

float angle = 0.0f;

void Bico() {
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(3.0, 6.0, 0);
        glVertex3f(4.0, 8.0, 0);
        glVertex3f(5.0, 6.0, 0);
    glEnd();
}

void Corpo() {
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(3.0, 1.0, 0);
        glVertex3f(5.0, 1.0, 0);
        glVertex3f(5.0, 6.0, 0);
        glVertex3f(3.0, 6.0, 0);
    glEnd();
}

void asaEsquerda() {
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex3f(1.5, 1.0, 0);
        glVertex3f(3.0, 1.0, 0);
        glVertex3f(3.0, 3.0, 0);
        
    glEnd();
}

void asaDireita() {
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex3f(5.0, 1.0, 0);
        glVertex3f(6.5, 1.0, 0);
        glVertex3f(5.0, 3.0, 0);
        
    glEnd();
}

void DesenhaFoguete(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*gluLookAt(
        0.0, 10.0, 0.0,   // posição da câmera
        0.0, 2.0, 0.0,    // ponto para onde olha
        0.0, 1.0, 0.0     // cima
    );*/
    glLoadIdentity();
    glRotatef(angle, 0.0f, 0.0f, 99.0f);
    glTranslatef(-4.0f, -4.5f, -10.0f);
    Bico();
    Corpo();
    asaEsquerda();
    asaDireita();

    glFlush();
    glutSwapBuffers();
}

void DrawCube() {
    glBegin(GL_QUADS);
        // Front face (red)
        glColor3f(0, 1, 0);
        glVertex3f(-1, -1,  1); glVertex3f( 1, -1,  1);
        glVertex3f( 1,  1,  1); glVertex3f(-1,  1,  1);

        // Back face (green)
        glColor3f(0, 1, 1);
        glVertex3f(-1, -1, -1); glVertex3f(-1,  1, -1);
        glVertex3f( 1,  1, -1); glVertex3f( 1, -1, -1);

        // Top face (blue)
        glColor3f(1, 0, 0);
        glVertex3f(-1,  1, -1); glVertex3f(-1,  1,  1);
        glVertex3f( 1,  1,  1); glVertex3f( 1,  1, -1);

        // Bottom face (yellow)
        glColor3f(1, 0, 1);
        glVertex3f(0, 0, 0); glVertex3f( 1, -1, -1);
        glVertex3f( 1, -1,  1); glVertex3f(-1, -1,  1);

        // Right face (magenta)
        glColor3f(0, 0.1, 0);
        glVertex3f( 1, -1, -1); glVertex3f( 1,  1, -1);
        glVertex3f( 1,  1,  1); glVertex3f( 1, -1,  1);

        // Left face (cyan)
        glColor3f(1, 0.2, 1);
        glVertex3f(-1, -1, -1); glVertex3f(-1, -1,  1);
        glVertex3f(-1,  1,  1); glVertex3f(-1,  1, -1);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    
    //glTranslatef(-3.0f, 0.0f, 0.0f);
    asaDireita();
   // glTranslatef(3.0f, 0.0f, 0.0f);
    asaEsquerda();
    //glTranslatef(0.0f, 5.0f, 0.0f);
    Corpo();
   // glTranslatef(0.0f, 10.0f, 0.0f);
    Bico();

    glutSwapBuffers();
}

void display2() {
    
}

void update(int value) {
    angle += 1.0f;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 fps
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Cube");

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glutDisplayFunc(DesenhaFoguete);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}