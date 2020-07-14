#include<cmath>
#include<math.h>
#include<windows.h>
#include<gl/glut.h>
#include<gl/Gl.h>
#include<iostream>
#define M_PHI 3.14

/*int t = 0;
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

/*void tujuh(void)
{
    glPushMatrix();
    glRotatef(u-=130.0f,0.0f,0.0f,1.0f);
    glColor3f(1.0,0.0,0.0);
    //glTranslated(-120,280,0);
    ngon(0,0,150,7);
    glPopMatrix();
    glEnd();
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

 glutSwapBuffers();
}

void timer(int z)
{
    glutPostRedisplay();
    glutTimerFunc(1500,timer,0);
}*/

void init (void);
void tampil (void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

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
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0,0.5,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
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

void tampil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);


    halaman();
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

void ukuran(int lebar, int tinggi)
{
    if (tinggi== 0) tinggi =1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar /tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
