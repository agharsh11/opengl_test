
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
float r=0.00,q=0.00,b,c;
void keyPressed (unsigned char key, int x, int y) {  
	if(key=='w' && r<1)
		{r=r+0.1;
		}
	if(key=='s' && r>-1)
		r=r-0.1;
	if(key=='a' && q>-1)
		q=q-0.1;
	if(key=='d' && q<1)
		q=q+0.1;
}

float angle=0.0,move=0.0;
void display()
{
	float i;
	float j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	j=1;
	angle=angle+1;
	
	glLoadIdentity();//to clearing and reseting the cordinate system else you get a continously rotating system;
	glRotatef(0.0,0.0,0.0,1.0);
	if(r<-1)
	r=-0.9; 
	else if(r>1)
	r=0.9; 
	if(q<-1)
		q=-0.9;
	 else if(q>1)
	 	q=0.9;
		glTranslatef(q,r,0.0);
	//r=0;
	//q=0;
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(0.25,0.25,0.0);
	glVertex3f(-0.25,0.25,0.0);
	glVertex3f(-0.25,-0.25,0.0);
	glVertex3f(0.25,-0.25,0.0);
	//glScalef(1.0,0.1,1.0);
	glEnd();
	/*glPushMatrix();
	glRotatef(0.0,0.0,0.0,1.0);
	glTranslatef(0.0,0.25,0.0);
	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(0.25,0.0,0.25);
	glVertex3f(-0.25,0.0,0.25);
	glVertex3f(-0.25,0.0,-0.25);
	glVertex3f(0.25,0.0,-0.25);
	//glScalef(1.0,0.1,1.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0,0.0,0.0,1.0);
	glTranslatef(-0.125,0.125,0.0);
	glBegin(GL_QUADS);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(0.25,0.0,0.25);
	glVertex3f(-0.25,0.0,0.25);
	glVertex3f(-0.25,0.0,-0.25);
	glVertex3f(0.25,0.0,-0.25);
	//glScalef(1.0,0.1,1.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0,0.0,0.0,1.0);
	glTranslatef(0.125,0.125,0.0);
	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex3f(0.25,0.0,0.25);
	glVertex3f(-0.25,0.0,0.25);
	glVertex3f(-0.25,0.0,-0.25);
	glVertex3f(0.25,0.0,-0.25);
	//glScalef(1.0,0.1,1.0);
	glEnd();
	glPopMatrix();*/
	/*for(i=0;i<360;i=i+0.01)
	{	
		glBegin(GL_POINTS);
		glColor3f(0.0,1.0,0.0);
		glVertex3f(j*0.5*cos(i),j*0.5*sin(i),0.0);
		glEnd();
		j=j*1.025;
	}*/
	/*glBegin(GL_LINES);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0.0,0.80,0.0);
	glVertex3f(-0.25,0.5,0.0);
	glEnd();*/
	/*glBegin(GL_TRIANGLES);
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
	glEnd();*/
	/*glBegin(GL_POLYGON);
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
	glViewport(0.0,0.0,w,h);
	//glViewport(10.0,10.0,w/2,h/2);
}
void initOpenGL()
{
	glClearColor(1.0 , 0.0 , 0.0 , 1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
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
  glutKeyboardFunc(keyPressed);
  //glutMouseFunc(MousePressed);
  glutMainLoop();//to display again and again
  return 0;
}
