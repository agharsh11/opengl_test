
#include <GL/glut.h>
#include<stdio.h>
#include<cmath>
/*void draw(void)
{
  //Background color
  glClearColor(0,1,0,1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );//function to clear buffer bits of colour and depth bit
  //Draw order
  glutSwapBuffers();//or use glFlush();
}*/
void display()
{
	int i;
	float j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	j=1;
	for(i=0;i<360;i=i+1)
	{	
		glBegin(GL_POINTS);
		glColor3f(0.0,1.0,0.0);
		glVertex3f(j*0.005*cos(i),j*0.005*sin(i),0.0);
		glEnd();
		j=j*1.0025;
	}
	/*glBegin(GL_LINES);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0.0,0.80,0.0);
	glVertex3f(-0.25,0.5,0.0);
	glVertex3f(0.25,0.5,0.0);
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-0.25,0.5,0.0);
	glVertex3f(0.25,0.5,0.0);
	glVertex3f(-0.25,0.0,0.0);
	glVertex3f(0.25,0.5,0.0);
	glVertex3f(-0.25,0.0,0.0);
	glVertex3f(0.25,0.0,0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(0.08,0.25,0.0);
	glVertex3f(-0.08,0.25,0.0);
	glVertex3f(-0.08,0.0,0.0);
	glVertex3f(0.08,0.0,0.0);
	glEnd();*/
	//glutSolidTeapot(0.2);
	glutSwapBuffers();
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
}
void initOpenGL()
{
	glClearColor(1.0 , 0.0 , 0.0 , 1.0);
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  //Simple buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );//in RGBA A stands for alpha channel basically tells visiblity
  glutInitWindowSize(900,900);
  glutInitWindowPosition(100,100);
  glutCreateWindow("THE Window");
  //Call to the drawing function
  initOpenGL();
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();//to display again and again
  return 0;
}
