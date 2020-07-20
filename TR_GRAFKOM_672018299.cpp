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

//alas1
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-50.0,-40.1, 30.0);
    glVertex3f(-50.0, -40.1, -100.0);
    glVertex3f(50.0, -40.1, -100.0);
    glVertex3f(50.0, -40.1, 30.0);
    glEnd();

 //jalan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-50.0, -40.0, 10.0);
    glVertex3f(-50.0, -40.0, 12.0);
    glVertex3f(50.0, -40.0,   12.0);
    glVertex3f(50.0, -40.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-50.0, -40.0, 30.0);
    glVertex3f(-50.0, -40.0, 28.0);
    glVertex3f(50.0, -40.0,   28.0);
    glVertex3f(50.0, -40.0, 30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-40.0, -40.0, 18.0);
    glVertex3f(-40.0, -40.0, 20.0);
    glVertex3f(-30.0, -40.0,   20.0);
    glVertex3f(-30.0, -40.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-25.0, -40.0, 18.0);
    glVertex3f(-25.0, -40.0, 20.0);
    glVertex3f(-15.0, -40.0,   20.0);
    glVertex3f(-15.0, -40.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-10.0, -40.0, 18.0);
    glVertex3f(-10.0, -40.0, 20.0);
    glVertex3f(0.0, -40.0,   20.0);
    glVertex3f(0.0, -40.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -40.0, 18.0);
    glVertex3f(10.0, -40.0, 20.0);
    glVertex3f(20.0, -40.0,   20.0);
    glVertex3f(20.0, -40.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(25.0, -40.0, 18.0);
    glVertex3f(25.0, -40.0, 20.0);
    glVertex3f(35.0, -40.0,   20.0);
    glVertex3f(35.0, -40.0, 18.0);
    glEnd();
}

void bangun3 ()
{
   //tembok depan
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(-20.0, -40.0,10.0);
    glVertex3f(-20.0, -10.0, 10.0);
    glVertex3f(20.0, -10.0,10.0);
    glVertex3f(20.0, -40.0, 10.0);
    glEnd();

        //hiasan besar
          glBegin(GL_QUADS);
          glColor3f(1.0,0.5,0.5);
          glVertex3f(-15.0, -35.0,10.1);
          glVertex3f(-15.0, -15.0, 10.1);
          glVertex3f(-12.0, -15.0,10.1);
          glVertex3f(-12.0, -35.0, 10.1);

          glVertex3f(-2.0, -35.0,10.1);
          glVertex3f(-2.0, -15.0, 10.1);
          glVertex3f(1.0, -15.0,10.1);
          glVertex3f(1.0, -35.0, 10.1);
          glEnd();

        //nama toko
          glBegin(GL_QUADS);
          glColor3f(0.0,0.9,1.0);
          glVertex3f(-12.0, -23.0,10.1);
          glVertex3f(-12.0, -15.0, 10.1);
          glVertex3f(-2.0, -15.0,10.1);
          glVertex3f(-2.0, -23.0, 10.1);
          glEnd();

          glBegin(GL_QUADS);
          glColor3f(1.0,0.5,0.5);
          glVertex3f(-12.0, -23.0,10.1);
          glVertex3f(-12.0, -25.0, 10.1);
          glVertex3f(-2.0, -25.0,10.1);
          glVertex3f(-2.0, -23.0, 10.1);
          glEnd();

          glBegin(GL_QUADS);
          glColor3f(1.0,1.0,1.0);
          glVertex3f(-12.0, -25.0,10.1);
          glVertex3f(-12.0, -26.0, 10.1);
          glVertex3f(-2.0, -26.0,10.1);
          glVertex3f(-2.0, -25.0, 10.1);
          glEnd();

          glBegin(GL_QUADS);
          glColor3f(1.0,0.5,0.5);
          glVertex3f(-12.0, -26.0,10.1);
          glVertex3f(-12.0, -28.0, 10.1);
          glVertex3f(-2.0, -28.0,10.1);
          glVertex3f(-2.0, -26.0, 10.1);
          glEnd();

          glBegin(GL_QUADS);
          glColor3f(1.0,1.0,1.0);
          glVertex3f(-12.0, -28.0,10.1);
          glVertex3f(-12.0, -29.0, 10.1);
          glVertex3f(-2.0, -29.0,10.1);
          glVertex3f(-2.0, -28.0, 10.1);
          glEnd();

          glBegin(GL_QUADS);
          glColor3f(1.0,0.5,0.5);
          glVertex3f(-12.0, -29.0,10.1);
          glVertex3f(-12.0, -31.0, 10.1);
          glVertex3f(-2.0, -31.0,10.1);
          glVertex3f(-2.0, -29.0, 10.1);
          glEnd();

          glBegin(GL_QUADS);
          glColor3f(1.0,1.0,1.0);
          glVertex3f(-12.0, -31.0,10.1);
          glVertex3f(-12.0, -32.0, 10.1);
          glVertex3f(-2.0, -32.0,10.1);
          glVertex3f(-2.0, -31.0, 10.1);
          glEnd();

          //pintu luar
          glBegin(GL_QUADS);
          glColor3f(0.5,0.5,0.5);
          glVertex3f(0.0, -40.0,10.2);
          glVertex3f(0.0, -38.0, 10.2);
          glVertex3f(8.0, -38.0,10.2);
          glVertex3f(8.0, -40.0, 10.2);
          glEnd();

          //putih-putih part 1
                glBegin(GL_QUADS);
                glColor3f(1.0,1.0,1.0);
                glVertex3f(-15.0, -16.0,10.1);
                glVertex3f(-15.0, -17.0, 10.1);
                glVertex3f(-20.0, -17.0,10.1);
                glVertex3f(-20.0, -16.0, 10.1);

                glVertex3f(-15.0, -19.0,10.1);
                glVertex3f(-15.0, -20.0, 10.1);
                glVertex3f(-20.0, -20.0,10.1);
                glVertex3f(-20.0, -19.0, 10.1);

                glVertex3f(-15.0, -22.0,10.1);
                glVertex3f(-15.0, -23.0, 10.1);
                glVertex3f(-20.0, -23.0,10.1);
                glVertex3f(-20.0, -22.0, 10.1);

                glVertex3f(-15.0, -25.0,10.1);
                glVertex3f(-15.0, -26.0, 10.1);
                glVertex3f(-20.0, -26.0,10.1);
                glVertex3f(-20.0, -25.0, 10.1);

                glVertex3f(-15.0, -28.0,10.1);
                glVertex3f(-15.0, -29.0, 10.1);
                glVertex3f(-20.0, -29.0,10.1);
                glVertex3f(-20.0, -28.0, 10.1);

                glVertex3f(-15.0, -31.0,10.1);
                glVertex3f(-15.0, -32.0, 10.1);
                glVertex3f(-20.0, -32.0,10.1);
                glVertex3f(-20.0, -31.0, 10.1);
                glEnd();


              //putih-putih part 2
              glBegin(GL_QUADS);
              glColor3f(1.0,1.0,1.0);
              glVertex3f(1.0, -16.0,10.1);
              glVertex3f(1.0, -17.0, 10.1);
              glVertex3f(20.0, -17.0,10.1);
              glVertex3f(20.0, -16.0, 10.1);
              glEnd();

                //jendela kanan 1
                glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(10,-17.5,10.1);
                glVertex3f(10,-18.5, 10.1);
                glVertex3f(12,-18.5,10.1);
                glVertex3f(12,-17.5, 10.1);
                glEnd();

                //jendela kanan 2
                glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(16,-17.5,10.1);
                glVertex3f(16,-18.5, 10.1);
                glVertex3f(18,-18.5,10.1);
                glVertex3f(18,-17.5, 10.1);
                glEnd();

              glBegin(GL_QUADS);
              glColor3f(1.0,1.0,1.0);
              glVertex3f(1.0, -19.0,10.1);
              glVertex3f(1.0, -20.0, 10.1);
              glVertex3f(20.0, -20.0,10.1);
              glVertex3f(20.0, -19.0, 10.1);
              glEnd();

                 //jendela kanan 3
                glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(10,-20.5,10.1);
                glVertex3f(10,-21.5, 10.1);
                glVertex3f(12,-21.5,10.1);
                glVertex3f(12,-20.5, 10.1);
                glEnd();

                //jendela kanan 4
                glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(16,-20.5,10.1);
                glVertex3f(16,-21.5, 10.1);
                glVertex3f(18,-21.5,10.1);
                glVertex3f(18,-20.5, 10.1);
                glEnd();

              glBegin(GL_QUADS);
              glColor3f(1.0,1.0,1.0);
              glVertex3f(1.0, -22.0,10.1);
              glVertex3f(1.0, -23.0, 10.1);
              glVertex3f(20.0, -23.0,10.1);
              glVertex3f(20.0, -22.0, 10.1);
              glEnd();

                 //jendela kanan 5
                glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(10,-23.5,10.1);
                glVertex3f(10,-24.5, 10.1);
                glVertex3f(12,-24.5,10.1);
                glVertex3f(12,-23.5, 10.1);
                glEnd();

                //jendela kanan 6
                glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(16,-23.5,10.1);
                glVertex3f(16,-24.5, 10.1);
                glVertex3f(18,-24.5,10.1);
                glVertex3f(18,-23.5, 10.1);
                glEnd();

              glBegin(GL_QUADS);
              glColor3f(1.0,1.0,1.0);
              glVertex3f(1.0, -25.0,10.1);
              glVertex3f(1.0, -26.0, 10.1);
              glVertex3f(20.0, -26.0,10.1);
              glVertex3f(20.0, -25.0, 10.1);
              glEnd();

               //jendela kanan 7
                glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(10,-26.5,10.1);
                glVertex3f(10,-27.5, 10.1);
                glVertex3f(12,-27.5,10.1);
                glVertex3f(12,-26.5, 10.1);
                glEnd();

                //jendela kanan 8
                glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(16,-26.5,10.1);
                glVertex3f(16,-27.5, 10.1);
                glVertex3f(18,-27.5,10.1);
                glVertex3f(18,-26.5, 10.1);
                glEnd();

              glBegin(GL_QUADS);
              glColor3f(1.0,1.0,1.0);
              glVertex3f(1.0, -28.0,10.1);
              glVertex3f(1.0, -29.0, 10.1);
              glVertex3f(20.0, -29.0,10.1);
              glVertex3f(20.0, -28.0, 10.1);
              glEnd();

                 //jendela kanan 9
                glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(10,-29.5,10.1);
                glVertex3f(10,-30.5, 10.1);
                glVertex3f(12,-30.5,10.1);
                glVertex3f(12,-29.5, 10.1);
                glEnd();

                //jendela kanan 10
                glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(16,-29.5,10.1);
                glVertex3f(16,-30.5, 10.1);
                glVertex3f(18,-30.5,10.1);
                glVertex3f(18,-29.5, 10.1);
                glEnd();

              glBegin(GL_QUADS);
              glColor3f(1.0,1.0,1.0);
              glVertex3f(1.0, -31.0,10.1);
              glVertex3f(1.0, -32.0, 10.1);
              glVertex3f(20.0, -32.0,10.1);
              glVertex3f(20.0, -31.0, 10.1);
              glEnd();

                 //jendela kanan 11
                glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(10,-32.5,10.1);
                glVertex3f(10,-33.5, 10.1);
                glVertex3f(12,-33.5,10.1);
                glVertex3f(12,-32.5, 10.1);
                glEnd();

                //jendela kanan 12
                glBegin(GL_POLYGON);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(16,-32.5,10.1);
                glVertex3f(16,-33.5, 10.1);
                glVertex3f(18,-33.5,10.1);
                glVertex3f(18,-32.5, 10.1);
                glEnd();

          //hiasan putih part 2
            for (int x=2; x<=20; x++){
            glBegin(GL_LINES);
            glColor3f(0.0,0.0,0.0);
            glVertex3f(x,-15, 10.2);
            glVertex3f(x, -16, 10.2);
            glEnd();
            x+=0.5;
            }

          //hiasan hitam 1
            for (int x=-10; x<=-4; x++){
            glBegin(GL_LINES);
            glColor3f(0.0,0.0,0.0);
            glVertex3f(x,-26, 10.3);
            glVertex3f(x, -28, 10.3);
            glEnd();
            x+=0;
            }

          //hiasan hitam 2
            for (int x=-10; x<=-4; x++){
            glBegin(GL_LINES);
            glColor3f(0.0,0.0,0.0);
            glVertex3f(x,-29, 10.3);
            glVertex3f(x, -31, 10.3);
            glEnd();
            x+=0;
            }

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

         //putih-putih part 3
                glBegin(GL_QUADS);
                glColor3f(1.0,1.0,1.0);
                glVertex3f(20.0, -16.0,10.1);
                glVertex3f(20.0, -17.0, 10.1);
                glVertex3f(25.1, -17.0,-5.1);
                glVertex3f(25.1, -16.0, -5.1);

                glVertex3f(20.0, -19.0,10.1);
                glVertex3f(20.0, -20.0, 10.1);
                glVertex3f(25.1, -20.0,-5.1);
                glVertex3f(25.1, -19.0, -5.1);

                glVertex3f(20.0, -22.0,10.1);
                glVertex3f(20.0, -23.0, 10.1);
                glVertex3f(25.1, -23.0,-5.1);
                glVertex3f(25.1, -22.0, -5.1);

                glVertex3f(20.0, -25.0,10.1);
                glVertex3f(20.0, -26.0, 10.1);
                glVertex3f(25.1, -26.0,-5.1);
                glVertex3f(25.1, -25.0, -5.1);

                glVertex3f(20.0, -28.0,10.1);
                glVertex3f(20.0, -29.0, 10.1);
                glVertex3f(25.1, -29.0,-5.1);
                glVertex3f(25.1, -28.0, -5.1);

                glVertex3f(20.0, -31.0,10.1);
                glVertex3f(20.0, -32.0, 10.1);
                glVertex3f(25.1, -32.0,-5.1);
                glVertex3f(25.1, -31.0, -5.1);
                glEnd();

    //kiri melengkung
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.7);
    glVertex3f(-20.0, -40.0,10.0);
    glVertex3f(-20.0, -10.0, 10.0);
    glVertex3f(-28.0, -10.0, -5.0);
    glVertex3f(-28.0, -40.0, -5.0);
    glEnd();

                //putih-putih part 4
                glBegin(GL_QUADS);
                glColor3f(1.0,1.0,1.0);
                glVertex3f(-20.0, -16.0,10.1);
                glVertex3f(-20.0, -17.0, 10.1);
                glVertex3f(-28.1, -17.0,-5.1);
                glVertex3f(-28.1, -16.0, -5.1);

                glVertex3f(-20.0, -19.0,10.1);
                glVertex3f(-20.0, -20.0, 10.1);
                glVertex3f(-28.1, -20.0,-5.1);
                glVertex3f(-28.1, -19.0, -5.1);

                glVertex3f(-20.0, -22.0,10.1);
                glVertex3f(-20.0, -23.0, 10.1);
                glVertex3f(-28.1, -23.0,-5.1);
                glVertex3f(-28.1, -22.0, -5.1);

                glVertex3f(-20.0, -25.0,10.1);
                glVertex3f(-20.0, -26.0, 10.1);
                glVertex3f(-28.1, -26.0,-5.1);
                glVertex3f(-28.1, -25.0, -5.1);

                glVertex3f(-20.0, -28.0,10.1);
                glVertex3f(-20.0, -29.0, 10.1);
                glVertex3f(-28.1, -29.0,-5.1);
                glVertex3f(-28.1, -28.0, -5.1);

                glVertex3f(-20.0, -31.0,10.1);
                glVertex3f(-20.0, -32.0, 10.1);
                glVertex3f(-28.1, -32.0,-5.1);
                glVertex3f(-28.1, -31.0, -5.1);
                glEnd();


    //kanan datar
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(25.0, -40.0,-5.0);
    glVertex3f(25.0, -10.0, -5.0);
    glVertex3f(25.0, -10.0, -30.0);
    glVertex3f(25.0, -40.0, -30.0);
    glEnd();

        //garis-garis
        for (int z=-30; z<-5; z++){
            glBegin(GL_LINES);
            glColor3f(1.0,1.0,1.0);
            glVertex3f(25.1,-35.0, z);
            glVertex3f(25.1,-10.0, z);
            glEnd();
            z+=1;
        }

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

    //hiasan bawah
     //depan
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-20.0, -40.0,10.1);
    glVertex3f(-20.0, -35.0, 10.1);
    glVertex3f(20.0, -35.0,10.1);
    glVertex3f(20.0, -40.0, 10.1);

    glVertex3f(20.0, -40.0,10.1);
    glVertex3f(20.0, -35.0, 10.1);
    glVertex3f(25.0, -35.0, -4.9);
    glVertex3f(25.0, -40.0, -4.9);

    glVertex3f(-20.0, -40.0,10.1);
    glVertex3f(-20.0, -35.0, 10.1);
    glVertex3f(-28.0, -35.0, -4.9);
    glVertex3f(-28.0, -40.0, -4.9);

    glVertex3f(25.1, -40.0,-5.0);
    glVertex3f(25.1, -35.0, -5.0);
    glVertex3f(25.1, -35.0, -30.0);
    glVertex3f(25.1, -40.0, -30.0);

    glVertex3f(-28.1, -40.0,-5.0);
    glVertex3f(-28.1, -35.0, -5.0);
    glVertex3f(-28.1, -35.0, -70.0);
    glVertex3f(-28.1, -40.0, -70.0);
    glEnd();

    //hiasan atas
    glBegin(GL_QUADS);
    glColor3f(0.0,0.9,1.0);
    glVertex3f(-20.0, -10.0,10.1);
    glVertex3f(-20.0, -15.0, 10.1);
    glVertex3f(20.0, -15.0,10.1);
    glVertex3f(20.0, -10.0, 10.1);

    glVertex3f(20.0, -10.0,10.1);
    glVertex3f(20.0, -15.0, 10.1);
    glVertex3f(25.0, -15.0, -4.9);
    glVertex3f(25.0, -10.0, -4.9);

    glVertex3f(-20.0, -10.0,10.1);
    glVertex3f(-20.0, -15.0, 10.1);
    glVertex3f(-28.0, -15.0, -4.9);
    glVertex3f(-28.0, -10.0, -4.9);

    glVertex3f(-28.1, -10.0,-5.0);
    glVertex3f(-28.1, -15.0, -5.0);
    glVertex3f(-28.1, -15.0, -15.0);
    glVertex3f(-28.1, -10.0, -15.0);
    glEnd();

    //garis jendela depan
    for (int x=-20; x<=20; x++){
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(x,-10, 10.2);
    glVertex3f(x, -15, 10.2);
    glEnd();
    x+=1;
    }
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
//lantai3
     glBegin(GL_QUADS);
    glColor3f(1.0,0.6,0.6);
    glVertex3f(-20.0, 44.0,10.0);
    glVertex3f(-28.0, 44.0, -5.0);
    glVertex3f(25.0, 44.0, -5.0);
    glVertex3f(20.0, 44.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,0.6,0.6);
    glVertex3f(-28.0, 44.0, -5.0);
    glVertex3f(-28.0, 44.0, -30.0);
    glVertex3f(25.0, 44.0, -30.0);
    glVertex3f(25.0, 44.0, -5.0);
    glEnd();

//lantai2
     glBegin(GL_QUADS);
    glColor3f(1.0,0.6,0.6);
    glVertex3f(-20.0, 17.0,10.0);
    glVertex3f(-28.0, 17.0, -5.0);
    glVertex3f(25.0, 17.0, -5.0);
    glVertex3f(20.0, 17.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,0.6,0.6);
    glVertex3f(-28.0, 17.0, -5.0);
    glVertex3f(-28.0, 17.0, -30.0);
    glVertex3f(25.0, 17.0, -30.0);
    glVertex3f(25.0, 17.0, -5.0);
    glEnd();
}

void heli(void)
{
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.5,0.4,0.5);
    glVertex3f(-10.0, 60.0,0.0);
    glVertex3f(-10.0, 65.0, 0.0);
    glVertex3f(10.0, 65.0,0.0);
    glVertex3f(10.0, 60.0, 0.0);
    glEnd();

//belakang 1
   glBegin(GL_QUADS);
    glColor3f(0.5,0.4,0.5);
    glVertex3f(-10.0, 60.0,-20.0);
    glVertex3f(-10.0, 65.0, -20.0);
    glVertex3f(10.0, 65.0,-20.0);
    glVertex3f(10.0, 60.0, -20.0);
    glEnd();

//kanan
  glBegin(GL_QUADS);
    glColor3f(0.5,0.4,0.5);
    glVertex3f(10.0, 60.0,-20.0);
    glVertex3f(10.0, 65.0, -20.0);
    glVertex3f(10.0, 65.0,0.0);
    glVertex3f(10.0, 60.0, 0.0);
    glEnd();

//kiri
   glBegin(GL_QUADS);
    glColor3f(0.5,0.4,0.5);
    glVertex3f(-10.0, 60.0,-20.0);
    glVertex3f(-10.0, 65.0, -20.0);
    glVertex3f(-10.0, 65.0,0.0);
    glVertex3f(-10.0, 60.0, 0.0);
    glEnd();
//atas
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-10.0, 64.0,-20.0);
    glVertex3f(-10.0, 64.0, 0.0);
    glVertex3f(10.0, 64.0,0.0);
    glVertex3f(10.0, 64.0,-20.0);
    glEnd();
//huruf H
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-8.0, 64.0,-18.0);
    glVertex3f(-8.0, 64.0, -2.0);
    glVertex3f(8.0, 64.0,-2.0);
    glVertex3f(8.0, 64.0,-18.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-5.0, 64.0,-15.0);
    glVertex3f(5.0, 64.0,-15.0);
    glVertex3f(5.0, 64.0,-5.0);
    glVertex3f(-5.0, 64.0, -5.0);
    glVertex3f(0.0, 64.0,-15.0);
    glVertex3f(0.0, 64.0,-5.0);
    glEnd();
}
void jendela(void)
{
//jendela
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-2.0, -9.0,10.5);
    glVertex3f(-2.0, 3.0, 10.5);
    glVertex3f(0.0, 3.0,10.5);
    glVertex3f(0.0, -9.0, 10.5);
    glEnd();
}

void jendelasmpng1(void)
{
//jendela
    glBegin(GL_QUADS);
    //glColor3f(1.0,0.6,0.6);
    glVertex3f(14.0, -9.0,25.1);
    glVertex3f(14.0, 3.0, 25.1);
    glVertex3f(12.0, 3.0,25.1);
    glVertex3f(12.0, -9.0, 25.1);
    glEnd();
}
void jendela3(void)
{
      glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glRotatef(90.0f,0.0f,180000.0f,120.0f);
    glTranslated(-6,0,0);
    jendelasmpng1();
    glTranslated(4,0,0);
    jendelasmpng1();
    jendelasmpng1();
    glTranslated(4,0,0);
    jendelasmpng1();
    glTranslated(4,0,0);
    jendelasmpng1();
    glTranslated(4,0,0);
    jendelasmpng1();
    glTranslated(4,0,0);
    jendelasmpng1();
    glTranslated(-20,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(4,-39,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(4,-39,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
     glTranslated(0,13,0);
    jendelasmpng1();
     glTranslated(0,13,0);
    jendelasmpng1();
     glTranslated(4,-39,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(4,-39,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(4,-39,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(-20,-52,-53.2);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(4,-52,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(4,-52,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(4,-52,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(4,-52,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(4,-52,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glTranslated(0,13,0);
    jendelasmpng1();
    glPopMatrix();
    glEnd();
}

void jendela1(void)
{
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    jendela();
    glTranslated(0,0,0);
    jendela();
    glTranslated(0,13,0);
    jendela();
    glTranslated(0,13,0);
    jendela();
    glTranslated(0,13,0);
    jendela();
    glTranslated(0,13,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(0,13,0);
    jendela();
    glTranslated(0,13,0);
    jendela();
    glTranslated(0,13,0);
    jendela();
    glTranslated(0,13,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(4,13,0);
    jendela();
    glTranslated(0,13,0);
    jendela();
    glTranslated(4,13,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(20,-13,0);
    jendela();
    glTranslated(0,13,0);
    jendela();
    glTranslated(0,13,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(4,-13,0);
    jendela();
    glTranslated(-4,-13,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(-4,13,0);
    jendela();
    glTranslated(-4,30,-41);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(28,0,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(4,0,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(0,-13,0);
    jendela();
    glTranslated(-4,39,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(44,-13,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(44,-13,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(44,-13,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
    glTranslated(-4,0,0);
    jendela();
     glPopMatrix();
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

//lantai2
    glBegin(GL_QUADS);
    glColor3f(1.0,0.6,0.6);
    glVertex3f(-1.0, 17.0, -70.0);
    glVertex3f(-1.0, 17.0, -35.0);
    glVertex3f(23.0, 17.0, -35.0);
    glVertex3f(23.0, 17.0, -70.0);
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
void jendelaa(void)
{
    //jendela bangun 2
    glBegin(GL_QUADS);
    glColor3f(1.0,0.6,0.6);
    glVertex3f(23.0, -9.0,-38.5);
    glVertex3f(23.0, 3.0, -38.5);
    glVertex3f(23.0, 3.0,-40.5);
    glVertex3f(23.0, -9.0, -40.5);
    glEnd();
}

void jendela2(void)
{
    glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-5);
    jendelaa();
    glTranslated(0,0,-5.5);
    jendelaa();
    glTranslated(0,0,-6.0);
    jendelaa();
    glTranslated(0,0,-6.5);
    jendelaa();

    glTranslated(0,20,0);
    jendelaa();
    glTranslated(0,0,6);
    jendelaa();
    glTranslated(0,0,5.5);
    jendelaa();
    glTranslated(0,0,5);
    jendelaa();
    glTranslated(0,0,4);
    jendelaa();

    glPopMatrix();
}

void jembatan (){
     //jembatan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-28.0, -37.0, -6.0);
    glVertex3f(-28.0, -37.0, -11.0);
    glVertex3f(-50.0, -37.0, -11.0);
    glVertex3f(-50.0, -37.0, -6.0);

    glVertex3f(-35.0, -37.0, -11.0);
    glVertex3f(-35.0, -37.0, -55.0);
    glVertex3f(-40.0, -37.0, -55.0);
    glVertex3f(-40.0, -37.0, -11.0);

    glVertex3f(-28.0, -37.0, -60.0);
    glVertex3f(-28.0, -37.0, -55.0);
    glVertex3f(-50.0, -37.0, -55.0);
    glVertex3f(-50.0, -37.0, -60.0);

    glVertex3f(-50.0, -37.0, -55.0);
    glVertex3f(-50.0, -40.0, -53.0);
    glVertex3f(-45.0, -40.0, -53.0);
    glVertex3f(-45.0, -37.0, -55.0);

    glVertex3f(-50.0, -37.0, -11.0);
    glVertex3f(-50.0, -37.0, 35.0);
    glVertex3f(-45.0, -37.0, 35.0);
    glVertex3f(-45.0, -37.0, -11.0);

    glVertex3f(-50.0, -37.0, 35.0);
    glVertex3f(-50.0, -40.0, 38.0);
    glVertex3f(-45.0, -40.0, 38.0);
    glVertex3f(-45.0, -37.0, 35.0);
    glEnd();

    //pegangan jembatan
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-28.0, -37.0, -6.0);
    glVertex3f(-28.0, -36.0, -6.0);
    glVertex3f(-45.0, -36.0, -6.0);
    glVertex3f(-45.0, -37.0, -6.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-28.0, -37.0, -11.0);
    glVertex3f(-28.0, -36.0, -11.0);
    glVertex3f(-35.0, -36.0, -11.0);
    glVertex3f(-35.0, -37.0, -11.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-40.0, -37.0, -11.0);
    glVertex3f(-40.0, -36.0, -11.0);
    glVertex3f(-50.0, -36.0, -11.0);
    glVertex3f(-50.0, -37.0, -11.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-35.0, -37.0, -11.0);
    glVertex3f(-35.0, -36.0, -11.0);
    glVertex3f(-35.0, -36.0, -55.0);
    glVertex3f(-35.0, -37.0, -55.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-40.0, -37.0, -11.0);
    glVertex3f(-40.0, -36.0, -11.0);
    glVertex3f(-40.0, -36.0, -55.0);
    glVertex3f(-40.0, -37.0, -55.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-28.0, -37.0, -55.0);
    glVertex3f(-28.0, -36.0, -55.0);
    glVertex3f(-35.0, -36.0, -55.0);
    glVertex3f(-35.0, -37.0, -55.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-35.0, -37.0, -55.0);
    glVertex3f(-35.0, -36.0, -55.0);
    glVertex3f(-45.0, -36.0, -55.0);
    glVertex3f(-45.0, -37.0, -55.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-28.0, -37.0, -60.0);
    glVertex3f(-28.0, -36.0, -60.0);
    glVertex3f(-50.0, -36.0, -60.0);
    glVertex3f(-50.0, -37.0, -60.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-50.0, -37.0, -60.0);
    glVertex3f(-50.0, -36.0, -60.0);
    glVertex3f(-50.0, -36.0, -55.0);
    glVertex3f(-50.0, -37.0, -55.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-50.0, -37.0, -55.0);
    glVertex3f(-50.0, -36.0, -55.0);
    glVertex3f(-50.0, -38.5, -52.0);
    glVertex3f(-50.0, -39.9, -52.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-45.0, -37.0, -55.0);
    glVertex3f(-45.0, -36.0, -55.0);
    glVertex3f(-45.0, -38.5, -52.0);
    glVertex3f(-45.0, -39.9, -52.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-50.0, -37.0, -11.0);
    glVertex3f(-50.0, -36.0, -11.0);
    glVertex3f(-50.0, -36.0, 35.0);
    glVertex3f(-50.0, -37.0, 35.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-45.0, -37.0, -6.0);
    glVertex3f(-45.0, -36.0, -6.0);
    glVertex3f(-45.0, -36.0, 35.0);
    glVertex3f(-45.0, -37.0, 35.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-50.0, -37.0, 35.0);
    glVertex3f(-50.0, -36.0, 35.0);
    glVertex3f(-50.0, -38.5, 38.0);
    glVertex3f(-50.0, -39.9, 38.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-45.0, -37.0, 35.0);
    glVertex3f(-45.0, -36.0, 35.0);
    glVertex3f(-45.0, -38.5, 38.0);
    glVertex3f(-45.0, -39.9, 38.0);
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
    jembatan();
    bangun1();
    heli();
    jendela1();
    jendela3();
    bangun2();
    jendela2();
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
