#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

float angleZ = 0.0f;
float angleX = 0.0f;
float x0ffset = 0.0f;
float y0ffset = 0.0f; 
float escala = 1.0f;
float espelho = 0.0f;

int estado = -1;

void arrow_keys ( int a_keys, int x, int y ) {
	if (estado == 0) {
    switch(a_keys)
    {
        case GLUT_KEY_LEFT:
            x0ffset -= 5.0f;
            glutPostRedisplay();
            break;

        case GLUT_KEY_RIGHT:
            x0ffset += 5.0f;
            glutPostRedisplay();
            break;
        
        case GLUT_KEY_UP:
            y0ffset += 5.0f;
            glutPostRedisplay();
            break;

        case GLUT_KEY_DOWN:
            y0ffset -= 5.0f;
            glutPostRedisplay();
            break;
	}
    }
    if (estado == 1) {
    switch(a_keys){
        case GLUT_KEY_UP:
            angleX -= 5.0f;     
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            angleX += 5.0f;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            angleZ += 5.0f;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            angleZ -= 5.0f;
            glutPostRedisplay();
            break;
    }
}
    if(estado == 2) {
        switch(a_keys){
        case GLUT_KEY_UP:
            escala += 0.3f;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            escala -= 0.3f;
            glutPostRedisplay();
            break;
    }
    }
}


void keyboard(unsigned char key, int x, int y) {

    if (key == 't' || key == 'T') {
    estado = 0;
    }
    if (key == 'r' || key == 'R') {
        estado = 1;
    }
    if (key == 's' || key == 'S') {
        estado = 2;
    }
    if (key == 'm' || key == 'M') {
        espelho += 180.0f;
        glutPostRedisplay();
        
    }
    if (key == 'i' || key == 'I') {
        y0ffset = 0.0f;
        x0ffset = 0.0f;
        angleZ = 0.0f;
        angleX = 0.0f;
        escala = 1;
        espelho = 0;
        glutPostRedisplay();
    }
}


void drawCross()
{
    glBegin(GL_QUADS);

    // =====================================
    // PARALELEPÍPEDO VERTICAL
    // =====================================

    // Frente
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.3f,  1.5f,  0.3f);
    glVertex3f( 0.3f,  1.5f,  0.3f);
    glVertex3f( 0.3f, -1.5f,  0.3f);
    glVertex3f(-0.3f, -1.5f,  0.3f);

    // Trás
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-0.3f,  1.5f, -0.3f);
    glVertex3f(-0.3f, -1.5f, -0.3f);
    glVertex3f( 0.3f, -1.5f, -0.3f);
    glVertex3f( 0.3f,  1.5f, -0.3f);

    // Lateral esquerda
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-0.3f,  1.5f,  0.3f);
    glVertex3f(-0.3f, -1.5f,  0.3f);
    glVertex3f(-0.3f, -1.5f, -0.3f);
    glVertex3f(-0.3f,  1.5f, -0.3f);

    // Lateral direita
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(0.3f,  1.5f,  0.3f);
    glVertex3f(0.3f,  1.5f, -0.3f);
    glVertex3f(0.3f, -1.5f, -0.3f);
    glVertex3f(0.3f, -1.5f,  0.3f);

    // Topo
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-0.3f, 1.5f,  0.3f);
    glVertex3f( 0.3f, 1.5f,  0.3f);
    glVertex3f( 0.3f, 1.5f, -0.3f);
    glVertex3f(-0.3f, 1.5f, -0.3f);

    // Base
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-0.3f, -1.5f,  0.3f);
    glVertex3f(-0.3f, -1.5f, -0.3f);
    glVertex3f( 0.3f, -1.5f, -0.3f);
    glVertex3f( 0.3f, -1.5f,  0.3f);


    // =====================================
    // PARALELEPÍPEDO HORIZONTAL
    // LEVANTADO
    // =====================================

    // Frente
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.5f,  0.8f, 0.3f);
    glVertex3f( 1.5f,  0.8f, 0.3f);
    glVertex3f( 1.5f,  0.2f, 0.3f);
    glVertex3f(-1.5f,  0.2f, 0.3f);

    // Trás
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.5f,  0.8f, -0.3f);
    glVertex3f(-1.5f,  0.2f, -0.3f);
    glVertex3f( 1.5f,  0.2f, -0.3f);
    glVertex3f( 1.5f,  0.8f, -0.3f);

    // Lateral esquerda
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.5f,  0.8f,  0.3f);
    glVertex3f(-1.5f,  0.2f,  0.3f);
    glVertex3f(-1.5f,  0.2f, -0.3f);
    glVertex3f(-1.5f,  0.8f, -0.3f);

    // Lateral direita
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.5f,  0.8f,  0.3f);
    glVertex3f(1.5f,  0.8f, -0.3f);
    glVertex3f(1.5f,  0.2f, -0.3f);
    glVertex3f(1.5f,  0.2f,  0.3f);

    // Topo
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.5f, 0.8f,  0.3f);
    glVertex3f( 1.5f, 0.8f,  0.3f);
    glVertex3f( 1.5f, 0.8f, -0.3f);
    glVertex3f(-1.5f, 0.8f, -0.3f);

    // Base
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.5f, 0.2f,  0.3f);
    glVertex3f(-1.5f, 0.2f, -0.3f);
    glVertex3f( 1.5f, 0.2f, -0.3f);
    glVertex3f( 1.5f, 0.2f,  0.3f);

    glEnd();
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(
        0.0, 0.0, 20.0,   // posição da câmera
        0.0, 0.0, 0.0,    // ponto para onde olha
        0.0, 1.0, 0.0     // cima
    );
    glTranslatef(x0ffset, y0ffset, 0.0f);

    glRotatef(espelho, 0.0f, 1.0f, 0.0f);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
    
    glScalef(escala, escala, escala);
    drawCross();
    glutSwapBuffers();
}

void update(int value) {
    //angle += 0.05f;
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

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutSpecialFunc( arrow_keys );
    //glutTimerFunc(16, update, 0);

    glutMainLoop(); 
    return 0;
}