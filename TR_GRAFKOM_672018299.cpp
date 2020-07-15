#include<cmath>
#include<math.h>
#include<windows.h>
#include<gl/glut.h>
#include<gl/Gl.h>
#include<iostream>
#define M_PHI 3.14
void init(void);
void tampil(void);
void keyboard(unsigned char,int,int);
void ukuran(int,int);
void mouse(int button,int state,int x,int y);
void mouseMotion(int x,int y);
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
double opintu=0;
bool mouseDown =false;

int is_depth;

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200,1100);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("TR_GRAFKOM - 672108299");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0,0.5,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}

void halaman(){

    //alas
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-50.0,-40.1, 30.0);
    glVertex3f(-50.0, -40.1, -100.0);
    glVertex3f(50.0, -40.1, -100.0);
    glVertex3f(50.0, -40.1, 30.0);
    glEnd();

}
void bangun3 ()
{
    //depan
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(-20.0, -40.0,10.0);
    glVertex3f(-20.0, -10.0, 10.0);
    glVertex3f(20.0, -10.0,10.0);
    glVertex3f(20.0, -40.0, 10.0);
    glEnd();

    //belakang 1
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(0.0, -40.0, -30.0);
    glVertex3f(0.0, -10.0, -30.0);
    glVertex3f(25.0, -10.0, -30.0);
    glVertex3f(25.0, -40.0, -30.0);
    glEnd();

    //kanan melengkung
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(20.0, -40.0,10.0);
    glVertex3f(20.0, -10.0, 10.0);
    glVertex3f(25.0, -10.0, -5.0);
    glVertex3f(25.0, -40.0, -5.0);
    glEnd();

    //kiri melengkung
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(-20.0, -40.0,10.0);
    glVertex3f(-20.0, -10.0, 10.0);
    glVertex3f(-28.0, -10.0, -5.0);
    glVertex3f(-28.0, -40.0, -5.0);
    glEnd();

    //kanan datar
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(25.0, -40.0,-5.0);
    glVertex3f(25.0, -10.0, -5.0);
    glVertex3f(25.0, -10.0, -30.0);
    glVertex3f(25.0, -40.0, -30.0);
    glEnd();

     //kanan datar belakang
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(0.0, -40.0,-30.0);
    glVertex3f(0.0, -10.0, -30.0);
    glVertex3f(0.0, -10.0, -80.0);
    glVertex3f(0.0, -40.0, -80.0);
    glEnd();

     //kiri datar
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(-28.0, -40.0,-5.0);
    glVertex3f(-28.0, -10.0, -5.0);
    glVertex3f(-28.0, -10.0, -70.0);
    glVertex3f(-28.0, -40.0, -70.0);
    glEnd();

     //belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9,0.7);
    glVertex3f(-28.0, -40.0,-70.0);
    glVertex3f(-28.0, -10.0, -70.0);
    glVertex3f(0.0, -10.0, -80.0);
    glVertex3f(0.0, -40.0, -80.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.3,0.2,0.2);
    glVertex3f(-20.0, -10.0,10.0);
    glVertex3f(-28.0, -10.0, -5.0);
    glVertex3f(25.0, -10.0, -5.0);
    glVertex3f(20.0, -10.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.2,0.2);
    glVertex3f(-28.0, -10.0, -5.0);
    glVertex3f(-28.0, -10.0, -30.0);
    glVertex3f(25.0, -10.0, -30.0);
    glVertex3f(25.0, -10.0, -5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.2,0.2);
    glVertex3f(-28.0, -10.0, -30.0);
    glVertex3f(-28.0, -10.0, -70.0);
    glVertex3f(0.0, -10.0, -80.0);
    glVertex3f(0.0, -10.0, -30.0);
    glEnd();


}
void bangun1(void)
{
//depan
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-20.0, 60.0,10.0);
    glVertex3f(-20.0, -10.0, 10.0);
    glVertex3f(20.0, -10.0,10.0);
    glVertex3f(20.0, 60.0, 10.0);
    glEnd();

//belakang 1
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(0.0, 60.0, -30.0);
    glVertex3f(0.0, -10.0, -30.0);
    glVertex3f(25.0, -10.0, -30.0);
    glVertex3f(25.0, 60.0, -30.0);
    glEnd();

//kanan melengkung
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(20.0, 60.0,10.0);
    glVertex3f(20.0, -10.0, 10.0);
    glVertex3f(25.0, -10.0, -5.0);
    glVertex3f(25.0, 60.0, -5.0);
    glEnd();

//kiri melengkung
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-20.0, 60.0,10.0);
    glVertex3f(-20.0, -10.0, 10.0);
    glVertex3f(-28.0, -10.0, -5.0);
    glVertex3f(-28.0, 60.0, -5.0);
    glEnd();

//kanan datar
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(25.0, 60.0,-5.0);
    glVertex3f(25.0, -10.0, -5.0);
    glVertex3f(25.0, -10.0, -30.0);
    glVertex3f(25.0, 60.0, -30.0);
    glEnd();

//kanan datar belakang
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(0.0, 60.0,-30.0);
    glVertex3f(0.0, -10.0, -30.0);
    glVertex3f(-28.0, -10.0, -30.0);
    glVertex3f(-28.0, 60.0, -30.0);
    glEnd();

//kiri datar
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-28.0, 60.0,-5.0);
    glVertex3f(-28.0, -10.0, -5.0);
    glVertex3f(-28.0, -10.0, -30.0);
    glVertex3f(-28.0, 60.0, -30.0);
    glEnd();
//atas
     glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-20.0, 60.0,10.0);
    glVertex3f(-28.0, 60.0, -5.0);
    glVertex3f(25.0, 60.0, -5.0);
    glVertex3f(20.0, 60.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-28.0, 60.0, -5.0);
    glVertex3f(-28.0, 60.0, -30.0);
    glVertex3f(25.0, 60.0, -30.0);
    glVertex3f(25.0, 60.0, -5.0);
    glEnd();
//jendela
    glBegin(GL_QUADS);
    glColor3f(1.0,0.6,0.6);
    glVertex3f(-2.0, 6.0,0.0);
    glVertex3f(-2.0, -1.0, 0.0);
    glVertex3f(2.0, -1.0,0.0);
    glVertex3f(2.0, 6.0, 0.0);
    glEnd();
}
void bangun2(void)
{
    //depan atas
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-1.0, 40.0,-35.0);
    glVertex3f(-1.0, -10.0, -35.0);
    glVertex3f(23.0, -10.0,-35.0);
    glVertex3f(23.0, 40.0, -35.0);
    glEnd();

    //belakang atas
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-1, 40.0, -70.0);
    glVertex3f(-1, -10.0, -70.0);
    glVertex3f(23.0, -10.0, -70.0);
    glVertex3f(23.0, 40.0, -70.0);
    glEnd();

    //kiri atas
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-1.0, 40.0,-35.0);
    glVertex3f(-1.0, -10.0, -35.0);
    glVertex3f(-1.0, -10.0, -70.0);
    glVertex3f(-1.0, 40.0, -70.0);
    glEnd();

    //kanan atas
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(23.0, 40.0,-35.0);
    glVertex3f(23.0, -10.0, -35.0);
    glVertex3f(23.0, -10.0, -70.0);
    glVertex3f(23.0, 40.0, -70.0);
    glEnd();

    //depan bawah
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(-1.0, -10.0, -35.0);
    glVertex3f(-1.0, -40.0, -35.0);
    glVertex3f(23.0, -40.0, -35.0);
    glVertex3f(23.0, -10.0, -35.0);
    glEnd();

    //belakang bawah
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(-1.0, -10.0, -70.0);
    glVertex3f(-1.0, -40.0, -70.0);
    glVertex3f(23.0, -40.0, -70.0);
    glVertex3f(23.0, -10.0, -70.0);
    glEnd();

    //kiri bawah
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(-1.0, -10.0,-35.0);
    glVertex3f(-1.0, -40.0, -35.0);
    glVertex3f(-1.0, -40.0, -70.0);
    glVertex3f(-1.0, -10.0, -70.0);
    glEnd();

    //kanan bawah
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(23.0, -10.0,-35.0);
    glVertex3f(23.0, -40.0, -35.0);
    glVertex3f(23.0, -40.0, -70.0);
    glVertex3f(23.0, -10.0, -70.0);
    glEnd();

    //atap atas
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-1.0, 40.0, -70.0);
    glVertex3f(-1.0, 40.0, -35.0);
    glVertex3f(23.0, 40.0, -35.0);
    glVertex3f(23.0, 40.0, -70.0);
    glEnd();

    //lantai atas
    glBegin(GL_QUADS);
    glColor3f(0.3,0.2,0.2);
    glVertex3f(-1.0, -10.0, -70.0);
    glVertex3f(-1.0, -10.0, -35.0);
    glVertex3f(23.0, -10.0, -35.0);
    glVertex3f(23.0, -10.0, -70.0);
    glEnd();

    //kotak kecil depan
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-1.0, 45.0, -50.0);
    glVertex3f(-1.0, 40.0, -50.0);
    glVertex3f(23.0, 40.0, -50.0);
    glVertex3f(23.0, 45.0, -50.0);
    glEnd();

    //kotak kecil belakang
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-1.0, 45.0, -60.0);
    glVertex3f(-1.0, 40.0, -60.0);
    glVertex3f(23.0, 40.0, -60.0);
    glVertex3f(23.0, 45.0, -60.0);
    glEnd();

    //kotak kecil kiri
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-1.0, 45.0, -50.0);
    glVertex3f(-1.0, 40.0, -50.0);
    glVertex3f(-1.0, 40.0, -60.0);
    glVertex3f(-1.0, 45.0, -60.0);
    glEnd();

    //kotak kecil kanan
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(23.0, 45.0, -50.0);
    glVertex3f(23.0, 40.0, -50.0);
    glVertex3f(23.0, 40.0, -60.0);
    glVertex3f(23.0, 45.0, -60.0);
    glEnd();

    //atap imut
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-1.0, 45.0, -60.0);
    glVertex3f(-1.0, 45.0, -50.0);
    glVertex3f(23.0, 45.0, -50.0);
    glVertex3f(23.0, 45.0, -60.0);
    glEnd();

}
void tampil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);
     glLoadIdentity();
    gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
    glRotatef(xrot,1.0f,0.0f,0.0f);
    glRotatef(yrot,0.0f,1.0f,0.0f);
    halaman();
    bangun1();
    bangun2();
    bangun3();
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

void idle()
{
  if (!mouseDown)
  {
      xrot +=0.3f;
      yrot +=0.4f;
  }
   glutPostRedisplay();
}

void mouse(int button,int state,int x,int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x-yrot;
        ydiff = -y+xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x,int y)
{
    if (mouseDown)
    {
        yrot = x-xdiff;
        xrot = y+ydiff;

        glutPostRedisplay();
    }
}

void ukuran(int lebar,int tinggi)
{
    if(tinggi==0) tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0,lebar / tinggi, 5.0,500.0);
    glTranslated(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
