///////////////////////////////////
// square.cpp
//
// OpenGL program to draw a square.
// 
// Sumanta Guha.
///////////////////////////////////

#include <GL/glew.h>
#include <GL/freeglut.h> 

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Experiment 2.13 + 2.14
	/*
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(10.0, 90.0, 0.0);
	glVertex3f(10.0, 10.0, 0.0);
	glVertex3f(35.0, 75.0, 0.0);
	glVertex3f(30.0, 20.0, 0.0);
	glVertex3f(90.0, 90.0, 0.0);
	glVertex3f(80.0, 40.0, 0.0);
	glEnd();
	*/

	// Exercise 2.13
	/*
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(10.0, 10.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(60.0, 10.0, 0.0);
	glVertex3f(50.0, 20.0, 0.0);
	glVertex3f(60.0, 60.0, 0.0);
	glVertex3f(50.0, 50.0, 0.0);
	glVertex3f(10.0, 60.0, 0.0);
	glVertex3f(20.0, 50.0, 0.0);
	glVertex3f(10.0, 10.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glEnd();
	*/

	// Exercise 2.14
	/*
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.0, 35.0, 0.0);
	glVertex3f(0.0, 45.0, 0.0);
	glVertex3f(10.0, 35.0, 0.0);
	glVertex3f(20.0, 45.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	glVertex3f(20.0, 10.0, 0.0);
	glVertex3f(50.0, 0.0, 0.0);
	glVertex3f(40.0, 10.0, 0.0);
	glVertex3f(50.0, 35.0, 0.0);
	glVertex3f(40.0, 45.0, 0.0);
	glVertex3f(60.0, 35.0, 0.0);
	glVertex3f(60.0, 45.0, 0.0);
	glEnd();
	*/

	// Exercise 2.15
	/*
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(10.0, 50.0, 0.0);
	glVertex3f(50.0, 50.0, 0.0);
	glVertex3f(40.0, 40.0, 0.0);
	glVertex3f(20.0, 40.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(10.0, 10.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(50.0, 10.0, 0.0);
	glVertex3f(50.0, 50.0, 0.0);
	glVertex3f(40.0, 40.0, 0.0);
	glVertex3f(40.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(10.0, 10.0, 0.0);
	glEnd();
	*/
	
	//Experiment 2.16
	/*
	glRectf(55, 55, 80, 80);
	*/

	// Experiment 2.17
	/*
	glBegin(GL_POLYGON);
	glVertex3f(20, 20, 0);
	glVertex3f(50, 20, 0);
	glVertex3f(80, 50, 0);
	glVertex3f(80, 80, 0);
	glVertex3f(20, 80, 0);
	glEnd();
	*/

	// Experiment 2.18
	/*
	glBegin(GL_POLYGON);
	glVertex3f(20, 20, 0);
	glVertex3f(80, 20, 0);
	glVertex3f(40, 40, 0);
	glVertex3f(20, 80, 0);
	glEnd();

	// Dasselbe, nur die Reihenfolge der Vertices ist anders
	glBegin(GL_POLYGON);
	glVertex3f(80, 20, 0);
	glVertex3f(40, 40, 0);
	glVertex3f(20, 80, 0);
	glVertex3f(20, 20, 0);
	glEnd();
	*/

	// Exercise 2.17
	/*
	glBegin(GL_POLYGON);
	glVertex3f(20, 20, 0);	// 1
	glVertex3f(50, 20, 0);	// 2
	glVertex3f(80, 50, 0);	// 3
	glVertex3f(80, 80, 0);	// 4
	glVertex3f(20, 80, 0);	// 5
	// cycling the vertices does not change appearance of the shape like in experiment 2.18
	glEnd();*/

	// Exercise 2.18

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("square.cpp");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}