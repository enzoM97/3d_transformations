#include "GL/freeglut.h"
#include <stdlib.h>

float scale = 1.0;
bool rotate = false;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 's':
	case 'S':
		scale += 0.5;
		if (scale >= 3.0) scale = 0.5;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	}
}

void drawCube(void)
{
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity(); 
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glScalef(scale, scale, scale);
	glutWireCube(2.0);
	glFlush();
}

void drawSphere(void)
{
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	gluLookAt(1.0, 6.5, 5.0, 0.0, 0.0, 0.0, 0.0, 5.0, 0.0);
	glutWireSphere(1.5, 10, 10);
	glFlush();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawCube();
	drawSphere();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D Transformations");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}