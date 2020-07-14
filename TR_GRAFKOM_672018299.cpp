#include<cmath>
#include<math.h>
#include<windows.h>
#include<gl/Gl.h>
#include<glut.h>
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
}
