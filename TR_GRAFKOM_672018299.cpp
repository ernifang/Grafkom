#include<cmath>
#include<math.h>
#include<windows.h>
#include<gl/glut.h>
#include<gl/Gl.h>
#include<iostream>
#define M_PHI 3.14


float xrot = 0.0;
float yrot = 0.0;
float xdiff = 0.0;
float ydiff = 0.0;
bool mouseDown = false;
int is_depth;
int z = 0;
int y =0;
int a =0;
void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran (int, int);

float angle = 0.0f;

void lingkaran (float TITIK_LAYAR_X,float TITIK_LAYAR_Y,
               float LEBAR_X, float LEBAR_Y, float JUMLAH_SUDUT, float ROTASI)
{
    GLfloat derajat =360.0f /JUMLAH_SUDUT *M_PI /100.0f;
    glBegin(GL_TRIANGLE_FAN);
        GLfloat sudut = 0.0f - ROTASI;
        for (int k=0; k< JUMLAH_SUDUT;++k)
        {
            glVertex2f(TITIK_LAYAR_X + (LEBAR_X* cos(sudut)), TITIK_LAYAR_Y+ (LEBAR_Y *sin(sudut)));
            sudut += derajat;
        }
    glEnd();
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
    glColor3f(1.0,0.5,0.5);
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
    glColor3f(1.0,0.5,0.5);
    glVertex3f(0.0, -40.0, -30.0);
    glVertex3f(0.0, -10.0, -30.0);
    glVertex3f(25.0, -10.0, -30.0);
    glVertex3f(25.0, -40.0, -30.0);
    glEnd();

    //kanan melengkung
    glBegin(GL_QUADS);
    glColor3f(1.0,0.5,0.5);
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
    glColor3f(1.0,0.5,0.5);
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
    glColor3f(1.0,0.5,0.5);
    glVertex3f(0.0, -40.0,-30.0);
    glVertex3f(0.0, -10.0, -30.0);
    glVertex3f(0.0, -10.0, -80.0);
    glVertex3f(0.0, -40.0, -80.0);
    glEnd();

     //kiri datar
    glBegin(GL_QUADS);
    glColor3f(1.0,0.5,0.5);
    glVertex3f(-28.0, -40.0,-5.0);
    glVertex3f(-28.0, -10.0, -5.0);
    glVertex3f(-28.0, -10.0, -70.0);
    glVertex3f(-28.0, -40.0, -70.0);
    glEnd();

          glBegin(GL_QUADS);
          glColor3f(1.0,0.6,0.5);
          glVertex3f(-28.1, -35.0,-11);
          glVertex3f(-28.1, -15.0, -11);
          glVertex3f(-28.1, -15.0,-14);
          glVertex3f(-28.1, -35.0, -14);

         //putih-putih part 5
                glBegin(GL_QUADS);
                glColor3f(1.0,1.0,1.0);
                glVertex3f(-28.1, -16.0, -5);
                glVertex3f(-28.1, -17.0, -5);
                glVertex3f(-28.1, -17.0, -11);
                glVertex3f(-28.1, -16.0, -11);

                glVertex3f(-28.1, -19.0, -5);
                glVertex3f(-28.1, -20.0, -5);
                glVertex3f(-28.1, -20.0, -11);
                glVertex3f(-28.1, -19.0, -11);

                glVertex3f(-28.1, -22.0, -5);
                glVertex3f(-28.1, -23.0, -5);
                glVertex3f(-28.1, -23.0, -11);
                glVertex3f(-28.1, -22.0, -11);

                glVertex3f(-28.1, -25.0, -5);
                glVertex3f(-28.1, -26.0, -5);
                glVertex3f(-28.1, -26.0, -11);
                glVertex3f(-28.1, -25.0, -11);

                glVertex3f(-28.1, -28.0, -5);
                glVertex3f(-28.1, -29.0, -5);
                glVertex3f(-28.1, -29.0, -11);
                glVertex3f(-28.1, -28.0, -11);

                glVertex3f(-28.1, -31.0, -5);
                glVertex3f(-28.1, -32.0, -5);
                glVertex3f(-28.1, -32.0, -11);
                glVertex3f(-28.1, -31.0, -11);
                glEnd();

            //putih-putih part 6
                glBegin(GL_QUADS);
                glColor3f(1.0,1.0,1.0);
                glVertex3f(-28.1, -16.0, -14);
                glVertex3f(-28.1, -17.0, -14);
                glVertex3f(-28.1, -17.0, -70);
                glVertex3f(-28.1, -16.0, -70);

                glVertex3f(-28.1, -19.0, -14);
                glVertex3f(-28.1, -20.0, -14);
                glVertex3f(-28.1, -20.0, -70);
                glVertex3f(-28.1, -19.0, -70);

                glVertex3f(-28.1, -22.0, -14);
                glVertex3f(-28.1, -23.0, -14);
                glVertex3f(-28.1, -23.0, -70);
                glVertex3f(-28.1, -22.0, -70);

                glVertex3f(-28.1, -25.0, -14);
                glVertex3f(-28.1, -26.0, -14);
                glVertex3f(-28.1, -26.0, -70);
                glVertex3f(-28.1, -25.0, -70);

                glVertex3f(-28.1, -28.0, -14);
                glVertex3f(-28.1, -29.0, -14);
                glVertex3f(-28.1, -29.0, -70);
                glVertex3f(-28.1, -28.0, -70);

                glVertex3f(-28.1, -31.0, -14);
                glVertex3f(-28.1, -32.0, -14);
                glVertex3f(-28.1, -32.0, -70);
                glVertex3f(-28.1, -31.0, -70);
                glEnd();

     //belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5,0.5);
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

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-20, -12.5, 10.3);
    glVertex3f(20, -12.5, 10.3);
    glEnd();

    //garis sekitar nama toko
        for (int x=-12; x<=-2; x++){
            glBegin(GL_LINES);
            glColor3f(1.0,1.0,1.0);
            glVertex3f(x,-23, 10.2);
            glVertex3f(x, -15, 10.2);
            glEnd();
            x+=0;
        }
}

void dalam_gedung3()
{
    //lantai atas
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.5);
    glVertex3f(-20.0, -35.0,10.0);
    glVertex3f(-28.0, -35.0, -5.0);
    glVertex3f(25.0, -35.0, -5.0);
    glVertex3f(20.0, -35.0, 10.0);

    glVertex3f(-28.0, -35.0, -5.0);
    glVertex3f(-28.0, -35.0, -30.0);
    glVertex3f(25.0, -35.0, -30.0);
    glVertex3f(25.0, -35.0, -5.0);

    glVertex3f(-28.0, -35.0, -30.0);
    glVertex3f(-28.0, -35.0, -70.0);
    glVertex3f(0.0, -35.0, -80.0);
    glVertex3f(0.0, -35.0, -30.0);
    glEnd();

        //depan toko 3
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(-20.0, -34.9, -39.0);
            glVertex3f(-20.0, -25.0, -39.0);
            glVertex3f(-20.0, -25.0, -40.0);
            glVertex3f(-20.0, -34.9, -40.0);

            glVertex3f(-20.0, -34.9, -30.0);
            glVertex3f(-20.0, -25.0, -30.0);
            glVertex3f(-20.0, -25.0, -31.0);
            glVertex3f(-20.0, -34.9, -31.0);

            glVertex3f(-20.0, -34.9, -39.0);
            glVertex3f(-20.0, -25.0, -39.0);
            glVertex3f(-20.5, -25.0, -39.0);
            glVertex3f(-20.5, -34.9, -39.0);

            glVertex3f(-20.0, -34.9, -31.0);
            glVertex3f(-20.0, -25.0, -31.0);
            glVertex3f(-20.5, -25.0, -31.0);
            glVertex3f(-20.5, -34.9, -31.0);

            //kanan toko 3
            glVertex3f(-20.0, -34.9, -40.0);
            glVertex3f(-20.0, -25.0, -40.0);
            glVertex3f(-27.9, -25.0, -40.0);
            glVertex3f(-27.9, -34.9, -40.0);

            //atap
            glVertex3f(-20.0, -25.0, -30.0);
            glVertex3f(-20.0, -25.0, -40.0);
            glVertex3f(-27.9, -25.0, -40.0);
            glVertex3f(-27.9, -25.0, -30.0);
            glEnd();

            //pintu toko 2
            glBegin(GL_QUADS);
            glColor3f(0.7,0.7,0.7);
            glVertex3f(-20.5, -34.9, -31.0);
            glVertex3f(-20.5, -25.2, -31.0);
            glVertex3f(-20.5, -25.2, -39.0);
            glVertex3f(-20.5, -39.9, -39.0);
            glEnd();


            //toko 4
            //depan toko 4
            glBegin(GL_QUADS);
            glColor3f(0.1,0.5,1.0);
            glVertex3f(-20.0, -34.9, -23.0);
            glVertex3f(-20.0, -25.0, -23.0);
            glVertex3f(-20.0, -25.0, -30.0);
            glVertex3f(-20.0, -34.9, -30.0);

            //kiri toko 4
            glVertex3f(-20.0, -34.9, -20.0);
            glVertex3f(-20.0, -25.0, -20.0);
            glVertex3f(-27.9, -25.0, -20.0);
            glVertex3f(-27.9, -34.9, -20.0);

            //kakan toko 4
            glVertex3f(-20.0, -34.9, -30.0);
            glVertex3f(-20.0, -25.0, -30.0);
            glVertex3f(-27.9, -25.0, -30.0);
            glVertex3f(-27.9, -34.9, -30.0);

            //atap
            glVertex3f(-20.0, -25.0, -20.0);
            glVertex3f(-20.0, -25.0, -30.0);
            glVertex3f(-27.9, -25.0, -30.0);
            glVertex3f(-27.9, -25.0, -20.0);
            glEnd();

    //lantai bawah
    glBegin(GL_QUADS);
    glColor3f(1.0,0.9,0.5);
    glVertex3f(-20.0, -40.0,10.0);
    glVertex3f(-28.0, -40.0, -5.0);
    glVertex3f(25.0, -40.0, -5.0);
    glVertex3f(20.0, -40.0, 10.0);

    glVertex3f(-28.0, -40.0, -5.0);
    glVertex3f(-28.0, -40.0, -30.0);
    glVertex3f(25.0, -40.0, -30.0);
    glVertex3f(25.0, -40.0, -5.0);

    glVertex3f(-28.0, -40.0, -30.0);
    glVertex3f(-28.0, -40.0, -70.0);
    glVertex3f(0.0, -40.0, -80.0);
    glVertex3f(0.0, -40.0, -30.0);
    glEnd();

          //pintu masuk
              glBegin(GL_QUADS);
              glColor3f(0.5,0.5,0.5);
              glVertex3f(0.0, -40.0,9.9);
              glVertex3f(0.0, -38.0, 9.9);
              glVertex3f(8.0, -38.0,9.9);
              glVertex3f(8.0, -40.0, 9.9);
              glEnd();

          //karpet
            glBegin(GL_QUADS);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.0, -39.9,10.0);
            glVertex3f(0.0, -39.9, -5.0);
            glVertex3f(8.0, -39.9,-5.0);
            glVertex3f(8.0, -39.9, 10.0);
            glEnd();

          //call center
            //depan 1
            glBegin(GL_QUADS);
            glColor3f(0.5,0.5,0.5);
            glVertex3f(0.0, -40.0, -23.0);
            glVertex3f(0.0, -39.0, -23.0);
            glVertex3f(10.0, -39.0,-23.0);
            glVertex3f(10.0, -40.0, -23.0);

            //kanan 1
            glVertex3f(10.0, -40.0, -23.0);
            glVertex3f(10.0, -39.0, -23.0);
            glVertex3f(10.0, -39.0,-30.0);
            glVertex3f(10.0, -40.0, -30.0);

            //kiri 1
            glVertex3f(0.0, -40.0, -23.0);
            glVertex3f(0.0, -39.0, -23.0);
            glVertex3f(0.0, -39.0,-30.0);
            glVertex3f(0.0, -40.0, -30.0);
            glEnd();

            //atas
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(0.0, -39.0, -23.0);
            glVertex3f(0.0, -39.0, -25.0);
            glVertex3f(10.0, -39.0,-25.0);
            glVertex3f(10.0, -39.0, -23.0);

            glVertex3f(10.0, -39.0, -25.0);
            glVertex3f(9.0, -39.0, -25.0);
            glVertex3f(9.0, -39.0,-30.0);
            glVertex3f(10.0, -39.0, -30.0);

            glVertex3f(0.0, -39.0, -25.0);
            glVertex3f(1.0, -39.0, -25.0);
            glVertex3f(1.0, -39.0,-30.0);
            glVertex3f(0.0, -39.0, -30.0);
            glEnd();

         //pot 1
            //depan
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(-1.0, -39.5, 8.2);
            glVertex3f(-1.0, -40.0, 8.2);
            glVertex3f(-0.5, -40.0, 8.2);
            glVertex3f(-0.5, -39.5, 8.2);
            glEnd();

            //belakang
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(-1.0, -39.5, 5.8);
            glVertex3f(-1.0, -40.0, 5.8);
            glVertex3f(-0.5, -40.0, 5.8);
            glVertex3f(-0.5, -39.5, 5.8);
            glEnd();

            //kiri
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(-1.0, -39.5, 8.2);
            glVertex3f(-1.0, -40.0, 8.2);
            glVertex3f(-1.0, -40.0, 5.8);
            glVertex3f(-1.0, -39.5, 5.8);
            glEnd();

            //kanan
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(-0.5, -39.5, 8.2);
            glVertex3f(-0.5, -40.0, 8.2);
            glVertex3f(-0.5, -40.0, 5.8);
            glVertex3f(-0.5, -39.5, 5.8);
            glEnd();

            //atas
            glBegin(GL_QUADS);
            glColor3f(0.5,0.5,0.5);
            glVertex3f(-1.0, -39.7, 8.2);
            glVertex3f(-1.0, -39.7, 5.8);
            glVertex3f(-0.5, -39.7, 5.8);
            glVertex3f(-0.5, -39.7, 8.2);
            glEnd();

            //bawah
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(-1.0, -39.9, 8.2);
            glVertex3f(-1.0, -39.9, 5.8);
            glVertex3f(-0.5, -39.9, 5.8);
            glVertex3f(-0.5, -39.9, 8.2);
            glEnd();

            //pohon 1
                    for (int z=6.0; z<8.5; z++){
                    glBegin(GL_LINES);
                    glColor3f(0.0,0.0,0.0);
                    glVertex3f(-0.8,-39.7, z);
                    glVertex3f(-0.8,-38.0, z);
                    glEnd();
                    z+=0;
                    }

        //pot 2
            //depan
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(8.5, -39.5, 8.2);
            glVertex3f(8.5, -40.0, 8.2);
            glVertex3f(9.0, -40.0, 8.2);
            glVertex3f(9.0, -39.5, 8.2);
            glEnd();

            //belakang
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(8.5, -39.5, 5.8);
            glVertex3f(8.5, -40.0, 5.8);
            glVertex3f(9.0, -40.0, 5.8);
            glVertex3f(9.0, -39.5, 5.8);
            glEnd();

            //kiri
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(8.5, -39.5, 8.2);
            glVertex3f(8.5, -40.0, 8.2);
            glVertex3f(8.5, -40.0, 5.8);
            glVertex3f(8.5, -39.5, 5.8);
            glEnd();

            //kanan
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(9.0, -39.5, 8.2);
            glVertex3f(9.0, -40.0, 8.2);
            glVertex3f(9.0, -40.0, 5.8);
            glVertex3f(9.0, -39.5, 5.8);
            glEnd();

            //atas
            glBegin(GL_QUADS);
            glColor3f(0.5,0.5,0.5);
            glVertex3f(8.5, -39.7, 8.2);
            glVertex3f(8.5, -39.7, 5.8);
            glVertex3f(9.0, -39.7, 5.8);
            glVertex3f(9.0, -39.7, 8.2);
            glEnd();

            //bawah
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(8.5, -39.9, 8.2);
            glVertex3f(8.5, -39.9, 5.8);
            glVertex3f(9.0, -39.9, 5.8);
            glVertex3f(9.0, -39.9, 8.2);
            glEnd();

                //pohon 2
                    for (int z=6.0; z<8.5; z++){
                    glBegin(GL_LINES);
                    glColor3f(0.0,0.0,0.0);
                    glVertex3f(8.8,-39.7, z);
                    glVertex3f(8.8,-38.0, z);
                    glEnd();
                    z+=0;
                    }

  //eskalator
            //kiri
            glBegin(GL_POLYGON);
            glColor3f(0.5,0.5,0.5);
            glVertex3f(-15.0, -39.9, -60.0);
            glVertex3f(-15.0, -35.0, -60.0);
            glVertex3f(-15.0, -39.9, -45.0);
            glEnd();

            //kanan
            glBegin(GL_POLYGON);
            glColor3f(0.5,0.5,0.5);
            glVertex3f(-10.0, -39.9, -60.0);
            glVertex3f(-10.0, -35.0, -60.0);
            glVertex3f(-10.0, -39.9, -45.0);
            glEnd();

            //tengah
            glBegin(GL_POLYGON);
            glColor3f(0.5,0.5,0.5);
            glVertex3f(-12.5, -39.9, -60.0);
            glVertex3f(-12.5, -35.0, -60.0);
            glVertex3f(-12.5, -39.9, -45.0);
            glEnd();


        //anak tangga eskalator
            //dasar
            glBegin(GL_QUADS);
            glColor3f(1.0,1.0,1.0);
            glVertex3f(-15.0, -39.9, -46.0);
            glVertex3f(-15.0, -39.3, -46.0);
            glVertex3f(-12.6, -39.3, -46.0);
            glVertex3f(-12.6, -39.9, -46.0);

            glVertex3f(-15.0, -39.3, -48.0);
            glVertex3f(-15.0, -38.7, -48.0);
            glVertex3f(-12.6, -38.7, -48.0);
            glVertex3f(-12.6, -39.3, -48.0);

            glVertex3f(-15.0, -38.6, -50.0);
            glVertex3f(-15.0, -38.1, -50.0);
            glVertex3f(-12.6, -38.1, -50.0);
            glVertex3f(-12.6, -38.6, -50.0);

            glVertex3f(-15.0, -38.1, -52.0);
            glVertex3f(-15.0, -37.5, -52.0);
            glVertex3f(-12.6, -37.5, -52.0);
            glVertex3f(-12.6, -38.1, -52.0);

            glVertex3f(-15.0, -37.5, -54.0);
            glVertex3f(-15.0, -36.9, -54.0);
            glVertex3f(-12.6, -36.9, -54.0);
            glVertex3f(-12.6, -37.5, -54.0);

            glVertex3f(-15.0, -36.9, -56.0);
            glVertex3f(-15.0, -36.3, -56.0);
            glVertex3f(-12.6, -36.3, -56.0);
            glVertex3f(-12.6, -36.9, -56.0);

            glVertex3f(-15.0, -36.3, -58.0);
            glVertex3f(-15.0, -35.7, -58.0);
            glVertex3f(-12.6, -35.7, -58.0);
            glVertex3f(-12.6, -36.3, -58.0);

            glVertex3f(-15.0, -35.7, -60.0);
            glVertex3f(-15.0, -35.1, -60.0);
            glVertex3f(-12.6, -35.1, -60.0);
            glVertex3f(-12.6, -35.7, -60.0);
            glEnd();

        //toko 1
            //depan toko 1
            glBegin(GL_QUADS);
            glColor3f(0.1,0.5,1.0);
            glVertex3f(-20.0, -39.9, -23.0);
            glVertex3f(-20.0, -36.0, -23.0);
            glVertex3f(-20.0, -36.0, -30.0);
            glVertex3f(-20.0, -39.9, -30.0);

            glVertex3f(-20.0, -38.0, -23.0);
            glVertex3f(-20.0, -36.0, -23.0);
            glVertex3f(-20.0, -36.0, -30.0);
            glVertex3f(-20.0, -38.0, -30.0);

            //kiri toko 1
            glVertex3f(-20.0, -39.9, -20.0);
            glVertex3f(-20.0, -36.0, -20.0);
            glVertex3f(-27.9, -36.0, -20.0);
            glVertex3f(-27.9, -39.9, -20.0);

            //kakan toko 1
            glVertex3f(-20.0, -39.9, -30.0);
            glVertex3f(-20.0, -36.0, -30.0);
            glVertex3f(-27.9, -36.0, -30.0);
            glVertex3f(-27.9, -39.9, -30.0);

            //atap
            glVertex3f(-20.0, -36.0, -20.0);
            glVertex3f(-20.0, -36.0, -30.0);
            glVertex3f(-27.9, -36.0, -30.0);
            glVertex3f(-27.9, -36.0, -20.0);
            glEnd();

            //dalam toko 1
            glBegin(GL_QUADS);
            glColor3f(1.0,1.0,1.0);
            glVertex3f(-20.0, -39.9, -25.0);
            glVertex3f(-20.0, -38.5, -25.0);
            glVertex3f(-27.9, -38.5, -25.0);
            glVertex3f(-27.9, -39.9, -25.0);

            glVertex3f(-20.0, -38.5, -25.0);
            glVertex3f(-20.0, -38.5, -27.0);
            glVertex3f(-27.9, -38.5, -27.0);
            glVertex3f(-27.9, -38.5, -25.0);

            glVertex3f(-20.0, -39.9, -27.0);
            glVertex3f(-20.0, -38.5, -27.0);
            glVertex3f(-27.9, -38.5, -27.0);
            glVertex3f(-27.9, -39.9, -27.0);
            glEnd();

            //meja toko 1
             glBegin(GL_QUADS);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-25.0, -38.5, -21.5);
            glVertex3f(-25.0, -38.5, -23.5);
            glVertex3f(-27.9, -38.5, -23.5);
            glVertex3f(-27.9, -38.5, -21.5);

            //bawah
            glVertex3f(-25.0, -38.8, -21.5);
            glVertex3f(-25.0, -38.8, -23.5);
            glVertex3f(-27.9, -38.8, -23.5);
            glVertex3f(-27.9, -38.8, -21.5);

             //kiri
            glVertex3f(-27.7, -38.8, -21.5);
            glVertex3f(-27.7, -38.5, -21.5);
            glVertex3f(-27.7, -38.5, -23.5);
            glVertex3f(-27.7, -38.8, -23.5);

            //kanan
            glVertex3f(-25.0, -38.8, -21.5);
            glVertex3f(-25.0, -38.5, -21.5);
            glVertex3f(-25.0, -38.5, -23.5);
            glVertex3f(-25.0, -38.8, -23.5);

            //depan
            glVertex3f(-27.7, -38.8, -21.5);
            glVertex3f(-27.7, -38.5, -21.5);
            glVertex3f(-25.0, -38.5, -21.5);
            glVertex3f(-25.0, -38.8, -21.5);

            //belakang
            glVertex3f(-27.7, -38.8, -23.5);
            glVertex3f(-27.7, -38.5, -23.5);
            glVertex3f(-25.0, -38.5, -23.5);
            glVertex3f(-25.0, -38.8, -23.5);

            //alas
            glVertex3f(-26.0, -39.9, -22.0);
            glVertex3f(-26.0, -39.9, -23.0);
            glVertex3f(-26.5, -39.9, -23.0);
            glVertex3f(-26.5, -39.9, -22.0);
            glEnd();

            //gsgang meja
            //depan
            glBegin(GL_QUADS);
            glColor3f(1.0,1.0,1.0);
            glVertex3f(-26.5, -38.8, -22.3);
            glVertex3f(-26.5, -39.9, -22.3);
            glVertex3f(-26.0, -39.9, -22.3);
            glVertex3f(-26.0, -38.8, -22.3);

            //belakang
            glVertex3f(-26.5, -38.8, -22.5);
            glVertex3f(-26.5, -39.9, -22.5);
            glVertex3f(-26.0, -39.9, -22.5);
            glVertex3f(-26.0, -38.8, -22.5);

            //kiri
            glVertex3f(-26.5, -38.8, -22.3);
            glVertex3f(-26.5, -39.9, -22.3);
            glVertex3f(-26.5, -39.9, -22.5);
            glVertex3f(-26.5, -38.8, -22.5);

            //kanan
            glVertex3f(-26.0, -38.8, -22.3);
            glVertex3f(-26.0, -39.9, -22.3);
            glVertex3f(-26.0, -39.9, -22.5);
            glVertex3f(-26.0, -38.8, -22.5);
            glEnd();

            //kursi 1
            glBegin(GL_QUADS);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-25.0, -39.2, -20.5);
            glVertex3f(-25.0, -39.2, -21.5);
            glVertex3f(-27.0, -39.2, -21.5);
            glVertex3f(-27.0, -39.2, -20.5);
            glEnd();

            glBegin(GL_QUADS);
            glColor3f(1.0,1.0,1.0);
            glVertex3f(-27.0, -39.2, -20.5);
            glVertex3f(-27.0, -39.2, -21.5);
            glVertex3f(-27.0, -39.9, -21.5);
            glVertex3f(-27.0, -39.9, -20.5);

            glVertex3f(-25.0, -39.2, -20.5);
            glVertex3f(-25.0, -39.2, -21.5);
            glVertex3f(-25.0, -39.9, -21.5);
            glVertex3f(-25.0, -39.9, -20.5);
            glEnd();

            //toko 2
            //depan toko 2
            glBegin(GL_QUADS);
            glColor3f(0.3,0.2,0.2);
            glVertex3f(-20.0, -39.9, -39.0);
            glVertex3f(-20.0, -36.0, -39.0);
            glVertex3f(-20.0, -36.0, -40.0);
            glVertex3f(-20.0, -39.9, -40.0);

            glVertex3f(-20.0, -39.9, -30.0);
            glVertex3f(-20.0, -36.0, -30.0);
            glVertex3f(-20.0, -36.0, -31.0);
            glVertex3f(-20.0, -39.9, -31.0);

            glVertex3f(-20.0, -39.9, -39.0);
            glVertex3f(-20.0, -36.0, -39.0);
            glVertex3f(-20.5, -36.0, -39.0);
            glVertex3f(-20.5, -39.9, -39.0);

            glVertex3f(-20.0, -39.9, -31.0);
            glVertex3f(-20.0, -36.0, -31.0);
            glVertex3f(-20.5, -36.0, -31.0);
            glVertex3f(-20.5, -39.9, -31.0);

            //kanan toko 2
            glVertex3f(-20.0, -39.9, -40.0);
            glVertex3f(-20.0, -36.0, -40.0);
            glVertex3f(-27.9, -36.0, -40.0);
            glVertex3f(-27.9, -39.9, -40.0);

            //atap
            glVertex3f(-20.0, -36.0, -30.0);
            glVertex3f(-20.0, -36.0, -40.0);
            glVertex3f(-27.9, -36.0, -40.0);
            glVertex3f(-27.9, -36.0, -30.0);
            glEnd();

            //pintu toko 2
            glBegin(GL_QUADS);
            glColor3f(0.7,0.7,0.7);
            glVertex3f(-20.5, -39.9, -31.0);
            glVertex3f(-20.5, -36.2, -31.0);
            glVertex3f(-20.5, -36.2, -39.0);
            glVertex3f(-20.5, -39.9, -39.0);
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

void jndl (void)
{
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(18.0, -9.0,-34.5);
    glVertex3f(18.0, 3.0, -34.5);
    glVertex3f(20.0, 3.0,-34.5);
    glVertex3f(20.0, -9.0, -34.5);
    glEnd();
}

void jndla (void)
{
    glPushMatrix();
    jndl();
    glTranslated(-4,0,0);
    jndl();
    glTranslated(-4,0,0);
    jndl();
    glTranslated(-4,0,0);
    jndl();
    glTranslated(-4,0,0);
    jndl();

    glTranslated(0,14,0);
    jndl();
    glTranslated(4,0,0);
    jndl();
    glTranslated(4,0,0);
    jndl();
    glTranslated(4,0,0);
    jndl();
    glTranslated(4,0,0);
    jndl();

    glTranslated(0,15,0);
    jndl();
    glTranslated(-4,0,0);
    jndl();
    glTranslated(-4,0,0);
    jndl();
    glTranslated(-4,0,0);
    jndl();
    glTranslated(-4,0,0);
    jndl();

    glPopMatrix();
    glEnd();
}
void jendelabangun2()
{
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-1.5, -9.0,-38.5);
    glVertex3f(-1.5, 3.0, -38.5);
    glVertex3f(-1.6, 3.0,-40.5);
    glVertex3f(-1.6, -9.0, -40.5);
    glEnd();
}

void jendlabangun2()
{
    glPushMatrix();
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();

    glTranslated(0,14,24);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();

    glTranslated(0,15,24);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();
    glTranslated(0,0,-4);
    jendelabangun2();

    glPopMatrix();
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
    glColor3f(1.0,0.6,0.6);
    glVertex3f(-1.0, -10.0, -35.0);
    glVertex3f(-1.0, -40.0, -35.0);
    glVertex3f(23.0, -40.0, -35.0);
    glVertex3f(23.0, -10.0, -35.0);
    glEnd();

    //belakang bawah
    glBegin(GL_QUADS);
    glColor3f(1.0,0.6,0.6);
    glVertex3f(-1.0, -10.0, -70.0);
    glVertex3f(-1.0, -40.0, -70.0);
    glVertex3f(23.0, -40.0, -70.0);
    glVertex3f(23.0, -10.0, -70.0);
    glEnd();

    //kiri bawah
    glBegin(GL_QUADS);
    glColor3f(1.0,0.6,0.6);
    glVertex3f(-1.0, -10.0,-35.0);
    glVertex3f(-1.0, -40.0, -35.0);
    glVertex3f(-1.0, -40.0, -70.0);
    glVertex3f(-1.0, -10.0, -70.0);
    glEnd();

    //kanan bawah
    glBegin(GL_QUADS);
    glColor3f(1.0,0.6,0.6);
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
    glVertex3f(-1.0, -40.0, -70.0);
    glVertex3f(-1.0, -40.0, -35.0);
    glVertex3f(23.0, -40.0, -35.0);
    glVertex3f(23.0, -40.0, -70.0);
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
void lampumerah(void)
{
    //tiang
    glBegin(GL_QUADS);
    glColor3f(1.0,0.5,0.0);
    glVertex3f(-40.0, -40.0,10.0);
    glVertex3f(-40.0, -40.0, 8.0);
    glVertex3f(-40.0, -20.0,8.0);
    glVertex3f(-40.0, -20.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,0.5,0.0);
    glVertex3f(-40.0, -20.0,8.0);
    glVertex3f(-40.0, -40.0, 8.0);
    glVertex3f(-38.0, -40.0,8.0);
    glVertex3f(-38.0, -20.0, 8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,0.5,0.0);
    glVertex3f(-38.0, -40.0,10.0);
    glVertex3f(-38.0, -40.0, 8.0);
    glVertex3f(-38.0, -20.0,8.0);
    glVertex3f(-38.0, -20.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,0.5,0.0);
    glVertex3f(-40.0, -20.0,10.0);
    glVertex3f(-40.0, -40.0, 10.0);
    glVertex3f(-38.0, -40.0,10.0);
    glVertex3f(-38.0, -20.0, 10.0);
    glEnd();

    //temoat lampu
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -15.0,12.0);
    glVertex3f(-42.0, -30.0, 12.0);
    glVertex3f(-42.0, -30.0,6.0);
    glVertex3f(-42.0, -15.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-36.0, -15.0,12.0);
    glVertex3f(-36.0, -30.0, 12.0);
    glVertex3f(-36.0, -30.0,6.0);
    glVertex3f(-36.0, -15.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -15.0,12.0);
    glVertex3f(-42.0, -30.0, 12.0);
    glVertex3f(-36.0, -30.0,12.0);
    glVertex3f(-36.0, -15.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -15.0,6.0);
    glVertex3f(-42.0, -30.0, 6.0);
    glVertex3f(-36.0, -30.0,6.0);
    glVertex3f(-36.0, -15.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -15.0,12.0);
    glVertex3f(-42.0, -15.0, 6.0);
    glVertex3f(-36.0, -15.0,6.0);
    glVertex3f(-36.0, -15.0, 12.0);
    glEnd();

    //merah
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-40.1, -18.0,12.2);
    glVertex3f(-40.1, -20.0, 12.2);
    glVertex3f(-38.1, -20.0,12.2);
    glVertex3f(-38.1, -18.0, 12.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-40.1, -22.0,12.2);
    glVertex3f(-40.1, -24.0, 12.2);
    glVertex3f(-38.1, -24.0,12.2);
    glVertex3f(-38.1, -22.0, 12.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-40.1, -26.0,12.2);
    glVertex3f(-40.1, -28.0, 12.2);
    glVertex3f(-38.1, -28.0,12.2);
    glVertex3f(-38.1, -26.0, 12.2);
    glEnd();
}
void jendelaa(void)
{
    //jendela bangun 2
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(23.0, -9.0,-38.5);
    glVertex3f(23.0, 3.0, -38.5);
    glVertex3f(23.1, 3.0,-40.5);
    glVertex3f(23.1, -9.0, -40.5);
    glEnd();
}

void jendela2(void)
{
    glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();

    glTranslated(0,14,24);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();

    glTranslated(0,15,24);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
    jendelaa();
    glTranslated(0,0,-4);
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

void lampu(){
     //tiang listrik
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    //tiang listrik 1
    glVertex3f(-30.0, -40.0,35.0);
    glVertex3f(-30.0, -30.0, 35.0);
    glVertex3f(-29.5, -30.0, 35.0);
    glVertex3f(-29.5, -40.0, 35.0);

    glVertex3f(-30.0, -40.0,35.5);
    glVertex3f(-30.0, -30.0, 35.5);
    glVertex3f(-29.5, -30.0, 35.5);
    glVertex3f(-29.5, -40.0, 35.5);

    glVertex3f(-30.0, -40.0,35.0);
    glVertex3f(-30.0, -30.0, 35.0);
    glVertex3f(-30.0, -30.0, 35.5);
    glVertex3f(-30.0, -40.0, 35.5);

    glVertex3f(-29.5, -40.0,35.0);
    glVertex3f(-29.5, -30.0, 35.0);
    glVertex3f(-29.5, -30.0, 35.5);
    glVertex3f(-29.5, -40.0, 35.5);

    //tiang listrik 2
    glVertex3f(0.0, -40.0,35.0);
    glVertex3f(0.0, -30.0, 35.0);
    glVertex3f(0.5, -30.0, 35.0);
    glVertex3f(0.5, -40.0, 35.0);

    glVertex3f(0.0, -40.0,35.5);
    glVertex3f(0.0, -30.0, 35.5);
    glVertex3f(0.5, -30.0, 35.5);
    glVertex3f(0.5, -40.0, 35.5);

    glVertex3f(0.0, -40.0,35.0);
    glVertex3f(0.0, -30.0, 35.0);
    glVertex3f(0.0, -30.0, 35.5);
    glVertex3f(0.0, -40.0, 35.5);

    glVertex3f(0.5, -40.0,35.0);
    glVertex3f(0.5, -30.0, 35.0);
    glVertex3f(0.5, -30.0, 35.5);
    glVertex3f(0.5, -40.0, 35.5);

    //tiang listrik 3
    glVertex3f(30.0, -40.0,35.0);
    glVertex3f(30.0, -30.0, 35.0);
    glVertex3f(30.5, -30.0, 35.0);
    glVertex3f(30.5, -40.0, 35.0);

    glVertex3f(30.0, -40.0,35.5);
    glVertex3f(30.0, -30.0, 35.5);
    glVertex3f(30.5, -30.0, 35.5);
    glVertex3f(30.5, -40.0, 35.5);

    glVertex3f(30.0, -40.0,35.0);
    glVertex3f(30.0, -30.0, 35.0);
    glVertex3f(30.0, -30.0, 35.5);
    glVertex3f(30.0, -40.0, 35.5);

    glVertex3f(30.5, -40.0,35.0);
    glVertex3f(30.5, -30.0, 35.0);
    glVertex3f(30.5, -30.0, 35.5);
    glVertex3f(30.5, -40.0, 35.5);

    //tiang listrik 4
    glVertex3f(49.5, -40.0,35.0);
    glVertex3f(49.5, -30.0, 35.0);
    glVertex3f(50.0, -30.0, 35.0);
    glVertex3f(50.0, -40.0, 35.0);

    glVertex3f(50.0, -40.0,35.5);
    glVertex3f(50.0, -30.0, 35.5);
    glVertex3f(50.0, -30.0, 35.5);
    glVertex3f(50.0, -40.0, 35.5);

    glVertex3f(49.5, -40.0,35.0);
    glVertex3f(49.5, -30.0, 35.0);
    glVertex3f(50.0, -30.0, 35.5);
    glVertex3f(50.0, -40.0, 35.5);

    glVertex3f(49.5, -40.0,35.0);
    glVertex3f(49.5, -30.0, 35.0);
    glVertex3f(49.5, -30.0, 35.5);
    glVertex3f(49.5, -40.0, 35.5);
    glEnd();

    //kabel listrik
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-30, -31.5, 35.0);
    glVertex3f(50, -31.5, 35.0);
    glEnd();

    //lampu
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    //lampu 1
    glVertex3f(-30.0, -29.0,35.0);
    glVertex3f(-30.0, -30.0, 35.0);
    glVertex3f(-29.5, -30.0, 35.0);
    glVertex3f(-29.5, -29.0, 35.0);

    glVertex3f(-30.0, -29.0,35.5);
    glVertex3f(-30.0, -30.0, 35.5);
    glVertex3f(-29.5, -30.0, 35.5);
    glVertex3f(-29.5, -29.0, 35.5);

    glVertex3f(-30.0, -29.0,35.0);
    glVertex3f(-30.0, -30.0, 35.0);
    glVertex3f(-30.0, -30.0, 35.5);
    glVertex3f(-30.0, -29.0, 35.5);

    glVertex3f(-29.5, -29.0,35.0);
    glVertex3f(-29.5, -30.0, 35.0);
    glVertex3f(-29.5, -30.0, 35.5);
    glVertex3f(-29.5, -29.0, 35.5);

    //lampu 2
    glVertex3f(0.0, -29.0,35.0);
    glVertex3f(0.0, -30.0, 35.0);
    glVertex3f(0.5, -30.0, 35.0);
    glVertex3f(0.5, -29.0, 35.0);

    glVertex3f(0.0, -29.0,35.5);
    glVertex3f(0.0, -30.0, 35.5);
    glVertex3f(0.5, -30.0, 35.5);
    glVertex3f(0.5, -29.0, 35.5);

    glVertex3f(0.0, -29.0,35.0);
    glVertex3f(0.0, -30.0, 35.0);
    glVertex3f(0.0, -30.0, 35.5);
    glVertex3f(0.0, -29.0, 35.5);

    glVertex3f(0.5, -29.0,35.0);
    glVertex3f(0.5, -30.0, 35.0);
    glVertex3f(0.5, -30.0, 35.5);
    glVertex3f(0.5, -29.0, 35.5);

    //lampu 3
    glVertex3f(30.0, -29.0,35.0);
    glVertex3f(30.0, -30.0, 35.0);
    glVertex3f(30.5, -30.0, 35.0);
    glVertex3f(30.5, -29.0, 35.0);

    glVertex3f(30.0, -29.0,35.5);
    glVertex3f(30.0, -30.0, 35.5);
    glVertex3f(30.5, -30.0, 35.5);
    glVertex3f(30.5, -29.0, 35.5);

    glVertex3f(30.0, -29.0,35.0);
    glVertex3f(30.0, -30.0, 35.0);
    glVertex3f(30.0, -30.0, 35.5);
    glVertex3f(30.0, -29.0, 35.5);

    glVertex3f(30.5, -29.0,35.0);
    glVertex3f(30.5, -30.0, 35.0);
    glVertex3f(30.5, -30.0, 35.5);
    glVertex3f(30.5, -29.0, 35.5);

    //lampu 4
     glVertex3f(49.5, -29.0,35.0);
    glVertex3f(49.5, -30.0, 35.0);
    glVertex3f(50.0, -30.0, 35.0);
    glVertex3f(50.0, -29.0, 35.0);

    glVertex3f(49.5, -29.0,35.5);
    glVertex3f(49.5, -30.0, 35.5);
    glVertex3f(50.0, -30.0, 35.5);
    glVertex3f(50.0, -29.0, 35.5);

    glVertex3f(49.5, -29.0,35.0);
    glVertex3f(49.5, -30.0, 35.0);
    glVertex3f(49.5, -30.0, 35.5);
    glVertex3f(49.5, -29.0, 35.5);

    glVertex3f(50.0, -29.0,35.0);
    glVertex3f(50.0, -30.0, 35.0);
    glVertex3f(50.0, -30.0, 35.5);
    glVertex3f(50.0, -29.0, 35.5);
    glEnd();

}

void jendela_bangun3(){
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-20.0, -39.0,10.2);
    glVertex3f(-20.0, -36.0, 10.2);
    glVertex3f(-18.0, -36.0,10.2);
    glVertex3f(-18.0, -39.0, 10.2);

    glVertex3f(-16.0, -39.0,10.2);
    glVertex3f(-16.0, -36.0, 10.2);
    glVertex3f(-14.0, -36.0,10.2);
    glVertex3f(-14.0, -39.0, 10.2);

    glVertex3f(-12.0, -39.0,10.2);
    glVertex3f(-12.0, -36.0, 10.2);
    glVertex3f(-10.0, -36.0,10.2);
    glVertex3f(-10.0, -39.0, 10.2);

    glVertex3f(-8.0, -39.0,10.2);
    glVertex3f(-8.0, -36.0, 10.2);
    glVertex3f(-6.0, -36.0,10.2);
    glVertex3f(-6.0, -39.0, 10.2);

    glVertex3f(-4.0, -39.0,10.2);
    glVertex3f(-4.0, -36.0, 10.2);
    glVertex3f(-2.0, -36.0,10.2);
    glVertex3f(-2.0, -39.0, 10.2);

    glVertex3f(10.0, -39.0,10.2);
    glVertex3f(10.0, -36.0, 10.2);
    glVertex3f(12.0, -36.0,10.2);
    glVertex3f(12.0, -39.0, 10.2);

    glVertex3f(14.0, -39.0,10.2);
    glVertex3f(14.0, -36.0, 10.2);
    glVertex3f(16.0, -36.0,10.2);
    glVertex3f(16.0, -39.0, 10.2);

    glVertex3f(18.0, -39.0,10.2);
    glVertex3f(18.0, -36.0, 10.2);
    glVertex3f(20.0, -36.0,10.2);
    glVertex3f(20.0, -39.0, 10.2);
    glEnd();

    //kanan melengkung
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(20.1, -39.0, 9.0);
    glVertex3f(20.1, -36.0, 9.0);
    glVertex3f(22.0, -36.0, 5.0);
    glVertex3f(22.0, -39.0, 5.0);

    glVertex3f(22.0, -39.0, 3.0);
    glVertex3f(22.0, -36.0, 3.0);
    glVertex3f(24.0, -36.0, -1);
    glVertex3f(24.0, -39.0, -1);
    glEnd();

    //kiri melengkung
     glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-21.0, -39.0, 9.0);
    glVertex3f(-21.0, -36.0, 9.0);
    glVertex3f(-23.0, -36.0, 5.0);
    glVertex3f(-23.0, -39.0, 5.0);

    glVertex3f(-24.0, -39.0, 3.0);
    glVertex3f(-24.0, -36.0, 3.0);
    glVertex3f(-26.0, -36.0, -1);
    glVertex3f(-26.0, -39.0, -1);
    glEnd();

    //kiri datar
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-28.2, -39.0, -16.0);
    glVertex3f(-28.2, -36.0, -16.0);
    glVertex3f(-28.2, -36.0, -18.0);
    glVertex3f(-28.2, -39.0, -18.0);

    glVertex3f(-28.2, -39.0, -20.0);
    glVertex3f(-28.2, -36.0, -20.0);
    glVertex3f(-28.2, -36.0, -22.0);
    glVertex3f(-28.2, -39.0, -22.0);

    glVertex3f(-28.2, -39.0, -24.0);
    glVertex3f(-28.2, -36.0, -24.0);
    glVertex3f(-28.2, -36.0, -26.0);
    glVertex3f(-28.2, -39.0, -26.0);

    glVertex3f(-28.2, -39.0, -28.0);
    glVertex3f(-28.2, -36.0, -28.0);
    glVertex3f(-28.2, -36.0, -30.0);
    glVertex3f(-28.2, -39.0, -30.0);

    glVertex3f(-28.2, -39.0, -32.0);
    glVertex3f(-28.2, -36.0, -32.0);
    glVertex3f(-28.2, -36.0, -34.0);
    glVertex3f(-28.2, -39.0, -34.0);

    glVertex3f(-28.2, -39.0, -36.0);
    glVertex3f(-28.2, -36.0, -36.0);
    glVertex3f(-28.2, -36.0, -38.0);
    glVertex3f(-28.2, -39.0, -38.0);

    glVertex3f(-28.2, -39.0, -40.0);
    glVertex3f(-28.2, -36.0, -40.0);
    glVertex3f(-28.2, -36.0, -42.0);
    glVertex3f(-28.2, -39.0, -42.0);

    glVertex3f(-28.2, -39.0, -44.0);
    glVertex3f(-28.2, -36.0, -44.0);
    glVertex3f(-28.2, -36.0, -46.0);
    glVertex3f(-28.2, -39.0, -46.0);

    glVertex3f(-28.2, -39.0, -48.0);
    glVertex3f(-28.2, -36.0, -48.0);
    glVertex3f(-28.2, -36.0, -50.0);
    glVertex3f(-28.2, -39.0, -50.0);
    glEnd();

    //jendela bawah nama toko
    glBegin(GL_QUADS);
    glColor3f(0.0,0.9,1.0);
    glVertex3f(-11, -35.0, 10.1);
    glVertex3f(-11, -33.0, 10.1);
    glVertex3f(-3, -33.0, 10.1);
    glVertex3f(-3, -35.0, 10.1);
    glEnd();

}
void jendela_blkg(void)
{
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(18.0, -9.0,-70.5);
    glVertex3f(18.0, 3.0, -70.5);
    glVertex3f(20.0, 3.0,-70.5);
    glVertex3f(20.0, -9.0, -70.5);
    glEnd();
}

void jndl_blkg()
{
    glPushMatrix();
    jendela_blkg();
    glTranslated(-4,0,0);
    jendela_blkg();
    glTranslated(-4,0,0);
    jendela_blkg();
    glTranslated(-4,0,0);
    jendela_blkg();
    glTranslated(-4,0,0);
    jendela_blkg();

    glTranslated(0,14,0);
    jendela_blkg();
    glTranslated(4,0,0);
    jendela_blkg();
    glTranslated(4,0,0);
    jendela_blkg();
    glTranslated(4,0,0);
    jendela_blkg();
    glTranslated(4,0,0);
    jendela_blkg();

    glTranslated(0,14,0);
    jendela_blkg();
    glTranslated(-4,0,0);
    jendela_blkg();
    glTranslated(-4,0,0);
    jendela_blkg();
    glTranslated(-4,0,0);
    jendela_blkg();
    glTranslated(-4,0,0);
    jendela_blkg();

    glPopMatrix();
    glEnd();
}

void bulan(void)
{
    glColor3f(1.0f,1.0f, 0.0f);
    glPushMatrix();
    glRotatef(y-=100.0f,0.0f,0.0f,1.0f);
         glTranslated(-50.0,70.0,0.0);
        glutSolidSphere(10, 20, 20);
    angle+=0.1f;
    glPopMatrix();
    glEnd();
}

void tampil(void)
{
glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glColor3f(0.2f,0.f,0.8f);
    gluLookAt(0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(xrot,1,0,0);
	glRotatef(yrot,0,1,0);
    halaman();
    lampumerah();
    jembatan();
    lampu();
    bangun1();
    heli();
    jendela1();
    jendela3();
    bangun2();
    jendela2();
    jndla();
    bangun3();
    dalam_gedung3();
    jendela_bangun3();
    jndl_blkg();
    jendlabangun2();
    bulan();
    glPopMatrix();
    glutSwapBuffers();
}

void timer(int z)
{
    glutPostRedisplay();
    glutTimerFunc(1500,timer,0);
}

void keyboard (unsigned char key, int x, int y){
    switch (key)
    {
     case 'w':
   case 'W':
    glTranslatef(0.0,0.0,3.0);
    break;
   case 'd':
   case 'D':
    glTranslatef(3.0,0.0,0.0);
    break;
   case 's':
   case 'S':
    glTranslatef(0.0,0.0,-3.0);
    break;
    case 'a':
    case 'A':
    glTranslatef(-3.0,0.0,0.0);
    break;
    case '7':
        glTranslatef(0.0,3.0,0.0);
        break;
    case '9':
        glTranslatef(0.0,-3.0,0.0);
    case '2':
        glRotatef(2.0,1.0,0.0,0.0);
        break;
    case '8':
        glRotatef(-2.0,1.0,0.0,0.0);
    case '6':
        glRotatef(2.0,0.0,1.0,0.0);
        break;
    case '4':
        glRotatef(-2.0,0.0,1.0,0.0);
    case '1':
        glRotatef(2.0,0.0,0.0,1.0);
        break;
    case '3':
        glRotatef(-2.0,0.0,0.0,1.0);
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

void idle()
{
  if (!mouseDown)
  {
      xrot +=0.3f;
      yrot +=0.4f;
  }
   glutPostRedisplay();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("TR_GRAFKOM - 672108299");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
     glutTimerFunc(1500,timer,0);
    glutMainLoop();
    return 0;
}
void init(void){
    glClearColor(0.0,0.5,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,-150,800,800);
    glPointSize(9.0);
    glLineWidth(6.0f);
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
