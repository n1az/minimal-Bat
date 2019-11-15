#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
#include<iostream>
using namespace std;
#define PI acos(-1)
GLdouble x=0;

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void circle(GLfloat x, GLfloat y, GLfloat radius);
void drawCircle(GLdouble x, GLdouble y, GLfloat r, GLint steps);
void display() {
    glClearColor(0.345, 0.337, 0.337, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.270, 0.254, 0.231);
	glVertex2f(-6.0,0.1);
	glVertex2f(0.3,-1.0);
	glVertex2f(1.0,-1.0);
	glVertex2f(1.0,-0.5);
	glVertex2f(0.6,0.1);
	glEnd();

	glBegin(GL_QUAD_STRIP);
	glColor3f(0.345, 0.337, 0.337);
	glVertex2f(-1.0,.1);
	glVertex2f(-.6,.1);
	glVertex2f(-1,-1);
	glVertex2f(0.3,-1);
	glEnd();
//main
    glBegin(GL_TRIANGLES);
    glColor3f(0.937, 0.607, 0.043);
    glVertex2f(-.6,.1);
    glVertex2f(.6,.1);
    glVertex2f(0.0,-.1);
    glEnd();
//left
    glBegin(GL_TRIANGLES);
    glColor3f(0.937, 0.607, 0.043);
    glVertex2f(-.4,.05);
    glVertex2f(-.1,-0.04);
    glVertex2f(-.32,-.03);
    glEnd();


  //right
    glBegin(GL_TRIANGLES);
    glColor3f(0.937, 0.607, 0.043);
    glVertex2f(.4,.05);
    glVertex2f(.1,-0.04);
    glVertex2f(.32,-.03);
    glEnd();
//tail
    glBegin(GL_TRIANGLES);
    glColor3f(0.937, 0.607, 0.043);
    glVertex2f(-0.13,0);
    glVertex2f(0.13,0);
    glVertex2f(0.0,-.16);
    glEnd();

    glColor3f(0.345, 0.337, 0.337);
    drawCircle(0.0,+0.17,.15,100);
    glColor3f(0.937, 0.607, 0.043);
    drawCircle(0.0,0.03,.03,100);
//head left
    glBegin(GL_TRIANGLES);
    glColor3f(0.937, 0.607, 0.043);
    glVertex2f(-.04,.08);
    glVertex2f(-.1,0.0);
    glVertex2f(0.0,0.0);

    glEnd();
  //head right
    glBegin(GL_TRIANGLES);
    glColor3f(0.937, 0.607, 0.043);
    glVertex2f(.04,.08);
    glVertex2f(.1,0.0);
    glVertex2f(0.0,0.0);

    glEnd();
	//cout<<x;
	glFlush();  // Render now
	//glFlush();  // Render now
	x+=0.001;
	if(x>1.00)
    {
        x=-1.00;
    }
	glutSwapBuffers();
}



void drawCircle(GLdouble x, GLdouble y, GLfloat r, GLint steps)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    GLfloat angle;
    for(GLint i=0;i<=steps;++i)
    {
        angle = i *2.0f *PI / steps ;
        glVertex2f(cos(angle)*r+x,sin(angle)*r+y);

    }
    glEnd();
}

//3.141592653
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);                // Initialize GLUT
	glutCreateWindow("OpenGL Flag Draw"); // Create a window with the given title
	   // Set the window's initial width & height
	glutDisplayFunc(display);
	glutIdleFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
