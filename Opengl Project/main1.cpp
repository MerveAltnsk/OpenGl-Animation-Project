#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <math.h>

float move = 0;

struct colorAttribute {
	int red, green, blue;
};
struct colorAttributeFloat {
	float red, green, blue;
};
typedef struct colorAttribute Colors; 
typedef struct colorAttributeFloat ColorsF; 

float cloud_X = 0; 
float cloud_Y = 0; 
int cloudStatus = 1; 
void DrawCloud();

void settings(void) {
	glClearColor(0, 1, 6, 0);
}

void myInit(void) {
	glClearColor(0, 1, 6, 0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1, 1, -1 ,1);
}

void drawFilledCircle(float x, float y, float radius, Colors color) {
	glLoadIdentity();
	int i;
	glColor3ub(color.red, color.green, color.blue);
	double twpi = 2.0 * 3.142;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for(i = 0; i <= 20; i++) {
		glVertex2f(
		(x+(radius * cos(i * twpi / 20))),
		(y+(radius * sin(i * twpi / 20))));
	}
	glEnd();
}
	
//Cloud
void DrawCloud() {
	glPushMatrix();
	Colors clr = {
		255, 255, 255
	};
	
	float clsize = 0.05;
	float init_x1 = 0.2;
	float init_x2 = 0.16; 

	
	drawFilledCircle(init_x1 + cloud_X, 0.68, clsize, clr);
	drawFilledCircle(init_x1 + 0.06 + cloud_X, 0.7, clsize, clr);
	drawFilledCircle(init_x2 + cloud_X, 0.7 , clsize, clr);
	drawFilledCircle(init_x2 + cloud_X + 0.06, 0.73, clsize, clr);
	
	drawFilledCircle(init_x1 + 0.4 - cloud_Y, 0.59, clsize, clr);
	drawFilledCircle(init_x1 + 0.46 - cloud_Y, 0.6, clsize, clr);
	drawFilledCircle(init_x2 + 0.4 - cloud_Y, 0.6, clsize, clr);
	drawFilledCircle(init_x2 + 0.46 - cloud_Y, 0.62, clsize, clr);

	glPopMatrix();
}
	
void cloud() {

	glPushMatrix();
	Colors color = {
		214, 213, 210
	};
	glColor3ub(color.red, color.green, color.blue);
	
	DrawCloud();
	glPopMatrix();
}	


void drawCar()
{
    //body
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-0.96 + move, -0.76, 0.0);
    glVertex3f(-0.96 + move, -0.89, 0.0);
    glVertex3f(-0.68 + move,-0.89, 0.0);
    glVertex3f(-0.68 + move, -0.76, 0.0);
    glEnd();

    //Top Part
   glBegin(GL_POLYGON);
   glVertex3f(-0.88 + move, -0.7, 0.00);
   glVertex3f(-0.78 + move, -0.7, 0.0);
   glVertex3f(-0.72 + move,-0.76, 0.0);
   glVertex3f(-0.92 + move, -0.76, 0.0);
   glEnd();
   
   
   //wheels
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.03;
        float x =-0.89+r * cos(A);
        float y =-0.89+r * sin(A);
        glVertex3f(x + move,y,0);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.03;
        float x =-0.79+r * cos(A);
        float y =-0.89+r * sin(A);
        glVertex3f(x + move,y,0);
    }
    glEnd();
}


//House
void drawRoof() {
  glColor3ub(255, 86, 246);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.3,-0.4);
	glVertex2f(0,-0.1);
	glVertex2f(0.3,-0.4);
	glEnd();
}
void drawHouse() {
  drawRoof();
	
  glColor3ub(255, 255, 255); // set house color
  glBegin(GL_POLYGON);
  glVertex2f(-0.2,-0.4);
  glVertex2f(-0.2,-0.8);
  glVertex2f(0.2,-0.8);
  glVertex2f(0.2,-0.4);
  glEnd();

  //Window 1
  glColor3ub(253, 198, 255); // set window color 
  glBegin(GL_POLYGON);
  glVertex2f(-0.16,-0.52);
  glVertex2f(-0.16,-0.44);
  glVertex2f(-0.06,-0.44);
  glVertex2f(-0.06,-0.52);
  glEnd();
  
  //Window 2
  glColor3ub(253, 198, 255);// set window color 
  glBegin(GL_POLYGON);
  glVertex2f(0.05,-0.44);
  glVertex2f(0.05,-0.52);
  glVertex2f(0.15,-0.52);
  glVertex2f(0.15,-0.44);
  glEnd();
  
  //Door
  glColor3ub(249, 147, 255); // set door color 
  glBegin(GL_POLYGON);
  glVertex2f(0.05,-0.68);
  glVertex2f(0.05,-0.8);
  glVertex2f(-0.05,-0.8);
  glVertex2f(-0.05,-0.68);
  glEnd();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT); // Clear color buffer
	Colors clr = {
		238, 255, 0
	};
		
	// grass
	glColor3ub(117, 242, 15);
	glBegin(GL_POLYGON);
	glVertex2f(-1, 0);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 0);
	glEnd();

	//the mountain on the left
	glColor3ub(120, 74, 22);
	glBegin(GL_TRIANGLES);
	glVertex2f(-1, 0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0, 0);
	glEnd();
	
	//the mountain on the right
	glColor3ub(120, 74, 22);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(0.5, 0.5);
	glVertex2f(1, 0);
	glEnd();
	
	//1. tree top
	glColor3ub(64, 143, 50);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.8,-0.6);
	glVertex2f(-0.6,-0.6);
	glVertex2f(-0.69664,-0.28442);
	glEnd();
	
	//1. tree body
	glColor3ub(112, 49, 29);
	glBegin(GL_POLYGON);
	glVertex2f(-0.72, -0.6);
	glVertex2f(-0.72,-0.79652);
	glVertex2f(-0.68,-0.79652);
	glVertex2f(-0.68,-0.5994);
	glEnd();
	
	//2. tree top
	glColor3ub(64, 143, 50);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.8,-0.05);
	glVertex2f(0.7,-0.4);
	glVertex2f(0.9,-0.4);
	glEnd();
	
	//2. tree body
	glColor3ub(112, 49, 29);
	glBegin(GL_POLYGON);
	glVertex2f(0.78,-0.4);
	glVertex2f(0.82,-0.4);
	glVertex2f(0.82,-0.6);
	glVertex2f(0.78,-0.6);
	glEnd();
	
	
	drawFilledCircle(-0.8, 0.8, 0.1, clr);
	cloud();
	drawHouse();
	drawCar();
	glFlush(); //Run drawing commands
}

void key(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT:
			move -= 0.01;
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
			move += 0.01;
			glutPostRedisplay();
			break;
	}
	
}

void update(int value) {
	if(cloudStatus == 1) {
		cloud_X += 0.01;
		cloud_Y += 0.01;
	}
	if(cloud_X > 1.5) {
		cloud_X -= 3;
	}
	if(cloud_Y > 2) {
		cloud_Y -= 2.5;
	}
   
    glutPostRedisplay(); 
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(850, 850);
	glutCreateWindow("Cute Red Car Animation");
	myInit();
	glutDisplayFunc(display);
	glutTimerFunc(50, update, 0);
	glutSpecialFunc(key);
	glutMainLoop();
	return 0;
}
