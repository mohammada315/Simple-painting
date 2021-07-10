/*
* simple paint application
* @auother      : MohammadAmin Khazaei
* @university   : Khorasan_Institute_of_Higher_Education
* @teacher      : Maryam Saraei
* @date         : 1400 / 09 / 19
*/ 

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <math.h>

using namespace std;

class Point {
private:
	int x , y ;
	static float size;
public:
	Point(int x , int y){
	this->x = x;
	this->y = y; }
	void drawpoint();
	void drawReact();
	void drawCircule();

};

float Point::size = 5.0 ;


void Point::drawpoint() {
	glColor3d(1, 1, 1);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(this->x, 500 - this->y);
	glEnd();
	glutSwapBuffers();
	glFlush();
}

void Point::drawReact(){

	glColor3d(1, 0, 0);  
	glBegin(GL_QUADS);
		glVertex2f(this->x ,   500-this->y);
		glVertex2f(this->x ,    500-this->y + 50);
		glVertex2f(this->x + 50,   500-this->y + 50);
		glVertex2f(this->x + 50,   500-this->y );
	glEnd();
	glutSwapBuffers();
	glFlush();

}

void Point::drawCircule(){



	glColor3d(0, 1, 0);
	glBegin(GL_POLYGON);    

		double radius = 50;
		double ori_x = this->x;
		double ori_y = this->y;
		for (int i = 0; i <= 300; i++) {

			double angle = 2 * 3.14 * i / 300;
			double x = cos(angle) * radius;
			double y = sin(angle) * radius;
			glVertex2d(ori_x + x, 500-ori_y + y);}

		glEnd();
	glutSwapBuffers();
	glFlush();


}

void mousemove(int x, int y) {
	 
	Point point(x , y);
	point.drawpoint();
	 
}



void mouseclick(int bin, int state, int x, int y) {


	if (bin == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		Point point(x , y);
		point.drawReact();

	}else if(bin == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){

		Point point(x , y);
		point.drawCircule();

	}
	 

}


void init(void)
{
	/* select clearing (background) color */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, 500, 500);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0, 500.0, 0.0, 500.0, 1.0, -1.0);

	/* initialize viewing values */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {


	glutInit(&argc, argv);


	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);



	/*Set the posotion of window*/
	glutInitWindowPosition(0, 0);
	glutCreateWindow("SimplePaint");

	 
	glutMouseFunc(mouseclick);
	glutMotionFunc(mousemove);
	
	init();
	glutMainLoop();


}
