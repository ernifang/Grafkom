#include<cmath>
#include<math.h>
#include<windows.h>
<<<<<<< HEAD
#include<gl/Gl.h>
#include<glut.h>
=======
#include<gl/glut.h>
>>>>>>> c67b0ce... tambahan
#include<iostream>
#define M_PHI 3.14
int t = 0;
int u = 0;
int v = 0;
int i = 0;
int z = 0;
void ngon(int xp, int yp, int r, int n){
    float a,x,y;
    //glColor4ub(i,j,0,200);
    glBegin(GL_POLYGON);
        a=6.28/n;
        for (int i=0; i<n; i++){
            x = xp+r * cos(i*a);
            y = yp+r * sin(i*a);
            glVertex2d(x,y);
        }
    glEnd();
}
void lingkaran(void){
glPushMatrix();
    glRotatef(t+=150.0f,0.0f,0.0f,1.0f);
    glScalef(1.0f,1.0f,0.0f);
    glColor3f(0.0,1.0,0.0);
    glTranslated(-120,280,0);
    ngon(0,0,30,25);
    glPopMatrix();
    glEnd();
}
void tujuh(void)
{
    glPushMatrix();
    glRotatef(u-=130.0f,0.0f,0.0f,1.0f);
    glColor3f(1.0,0.0,0.0);
    //glTranslated(-120,280,0);
    ngon(0,0,150,7);
    glPopMatrix();
    glEnd();

<<<<<<< HEAD
}

void persegi(void)
{
    glPushMatrix();
    glRotatef(v-=130.0f,0.0f,0.0f,1.0f);
    glColor3f(0.0,0.0,1.0);
    glTranslated(200,250,0);
    ngon(0,0,60,4);
    glPopMatrix();
    glEnd();

}
void tampilan(void)
 {
     glClearColor(t+=0.9f,0.5f,0.9f, 1.0f);//membuat ganti warna
     glClear(GL_COLOR_BUFFER_BIT);
     lingkaran();
     tujuh();
     persegi();
    glutSwapBuffers();
 }
void timer(int z)
{
    glutPostRedisplay();
    glutTimerFunc(1500,timer,0);
}

int main(int argc, char *argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1100,1200);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("TR_GRAFKOM_672018299");
    gluOrtho2D(-500,500,-400,400);
    glutDisplayFunc(Tampilan);
    glutTimerFunc(1500,timer,0);
    glutMainLoop();
    return 0;
=======
void init (void);
void tampil (void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse (int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot= 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff= 0.0f;
bool mouseDown= false;

int is_depth;

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200,1100);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("MALL 3D");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0,0.9,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    is_depth=1;
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(13.0);
    glLineWidth(3.0f);
}

void bangun1(){


}

void tampil(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0,0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi== 0) tinggi =1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar /tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

void idle ()    //totasi otomatis
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse (int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
       mouseDown = true;
       xdiff = x- yrot;
       ydiff = -y +xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
>>>>>>> c67b0ce... tambahan
}
