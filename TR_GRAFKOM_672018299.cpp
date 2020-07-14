#include<cmath>
#include<math.h>
#include<windows.h>
#include<GL/glew.h>
#include<GL/freeglut.h>
#include<iostream>

void init (void);
void tampil (void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse (int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);


int main(int argc, char** argv) 
{
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("TR_GRAFKOM_672018299");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}