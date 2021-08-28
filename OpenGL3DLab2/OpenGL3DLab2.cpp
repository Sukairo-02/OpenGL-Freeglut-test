#include "pch.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>
#include <time.h>
#include "wtypes.h"
#include <iostream>

GLint r1 = 255, g1 = 127, b1 = 0, r2 = 0, g2 = 191, b2 = 0, rMode = 0, rMode1 = 0, rMode2 = 0, which = 0, light_set = 1;
GLfloat rx1 = 0, ry1 = 0, rz1 = 0, rx2 = 0, ry2 = 0, rz2 = 0, trx1 = 0, try1 = 0, trz1 = 0, trx2 = 0, try2 = 0, trz2 = 0;

GLfloat Vert1[72][3] = {
	{-110.0f, -100.0f, -10.0f}, {-110.0f, 100.0f, -10.0f}, {-90.0f, 100.0f, -10.0f}, {-90.0f, -100.0f, -10.0f},
	{-90.0f, 100.0f, -10.0f}, {-10.0f, 100.0f, -10.0f}, {-10.0f, 80.0f, -10.0f}, {-90.0f, 80.0f, -10.0f},
	{-30.0f, 80.0f, -10.0f}, {-10.0f, 80.0f, -10.0f}, {-10.0f, 20.0f, -10.0f}, {-30.0f, 20.0f, -10.0f},
	{-90.0f, 20.0f, -10.0f}, {-10.0f, 20.0f, -10.0f}, {-10.0f, 0.0f, -10.0f}, {-90.0f, 0.0f, -10.0f},

	{-110.0f, -100.0f, 10.0f}, {-110.0f, 100.0f, 10.0f}, {-90.0f, 100.0f, 10.0f}, {-90.0f, -100.0f, 10.0f},
	{-90.0f, 100.0f, 10.0f}, {-10.0f, 100.0f, 10.0f}, {-10.0f, 80.0f, 10.0f}, {-90.0f, 80.0f, 10.0f},
	{-30.0f, 80.0f, 10.0f}, {-10.0f, 80.0f, 10.0f}, {-10.0f, 20.0f, 10.0f}, {-30.0f, 20.0f, 10.0f},
	{-90.0f, 20.0f, 10.0f}, {-10.0f, 20.0f, 10.0f}, {-10.0f, 0.0f, 10.0f}, {-90.0f, 0.0f, 10.0f},

	{-110.0f, -100.0f, -10.0f}, {-110.0f, -100.0f, 10.0f}, {-110.0f, 100.0f, 10.0f}, {-110.0f, 100.0f, -10.0f},
	{-30.0f, 80.0f, -10.0f}, {-30.0f, 80.0f, 10.0f}, {-30.0f, 20.0f, 10.0f}, {-30.0f, 20.0f, -10.0f},

	{-90.0f, 80.0f, -10.0f}, {-90.0f, 80.0f, 10.0f}, {-90.0f, 20.0f, 10.0f}, {-90.0f, 20.0f, -10.0f},
	{-90.0f, 0.0f, -10.0f}, {-90.0f, 0.0f, 10.0f}, {-90.0f, -100.0f, 10.0f}, {-90.0f, -100.0f, -10.0f},
	{-10.0f, 100.0f, -10.0f}, {-10.0f, 100.0f, 10.0f}, {-10.0f, 0.0f, 10.0f}, {-10.0f, 0.0f, -10.0f},

	{-110.0f, 100.0f, -10.0f}, {-110.0f, 100.0f, 10.0f}, {-10.0f, 100.0f, 10.0f}, {-10.0f, 100.0f, -10.0f},
	{-90.0f, 20.0f, -10.0f}, {-90.0f, 20.0f, 10.0f}, {-30.0f, 20.0f, 10.0f}, {-30.0f, 20.0f, -10.0f},

	{-90.0f, 80.0f, -10.0f}, {-90.0f, 80.0f, 10.0f}, {-30.0f, 80.0f, 10.0f}, {-30.0f, 80.0f, -10.0f},
	{-90.0f, 0.0f, -10.0f}, {-90.0f, 0.0f, 10.0f}, {-10.0f, 0.0f, 10.0f}, {-10.0f, 0.0f, -10.0f},
	{-110.0f, -100.0f, -10.0f}, {-110.0f, -100.0f, 10.0f}, {-90.0f, -100.0f, 10.0f}, {-90.0f, -100.0f, -10.0f}
};

GLfloat Vert2[56][3] = {
	{10.0f, -100.0f, -10.0f}, {10.0f, 100.0f, -10.0f}, {30.0f, 100.0f, -10.0f}, {30.0f, -100.0f, -10.0f},
	{30.0f, 80.0f, -10.0f}, {30.0f, 100.0f, -10.0f}, {110.0f, 100.0f, -10.0f}, {110.0f, 80.0f, -10.0f},
	{30.0f, -100.0f, -10.0f}, {30.0f, -80.0f, -10.0f}, {110.0f, -80.0f, -10.0f}, {110.0f, -100.0f, -10.0f},

	{10.0f, -100.0f, 10.0f}, {10.0f, 100.0f, 10.0f}, {30.0f, 100.0f, 10.0f}, {30.0f, -100.0f, 10.0f},
	{30.0f, 80.0f, 10.0f}, {30.0f, 100.0f, 10.0f}, {110.0f, 100.0f, 10.0f}, {110.0f, 80.0f, 10.0f},
	{30.0f, -100.0f, 10.0f}, {30.0f, -80.0f, 10.0f}, {110.0f, -80.0f, 10.0f}, {110.0f, -100.0f, 10.0f},

	{10.0f, 100.0f, -10.0f}, {10.0f, 100.0f, 10.0f}, {110.0f, 100.0f, 10.0f}, {110.0f, 100.0f, -10.0f},
	{30.0f, -80.0f, -10.0f}, {30.0f, -80.0f, 10.0f}, {110.0f, -80.0f, 10.0f}, {110.0f, -80.0f, -10.0f},

	{30.0f, 80.0f, -10.0f}, {30.0f, 80.0f, 10.0f}, {110.0f, 80.0f, 10.0f}, {110.0f, 80.0f, -10.0f},
	{10.0f, -100.0f, -10.0f}, {10.0f, -100.0f, 10.0f}, {110.0f, -100.0f, 10.0f}, {110.0f, -100.0f, -10.0f},

	{110.0f, 100.0f, -10.0f}, {110.0f, 100.0f, 10.0f}, {110.0f, 80.0f, 10.0f}, {110.0f, 80.0f, -10.0f},
	{30.0f, 80.0f, -10.0f}, {30.0f, 80.0f, 10.0f}, {30.0f, -80.0f, 10.0f}, {30.0f, -80.0f, -10.0f},
	{110.0f, -80.0f, -10.0f}, {110.0f, -80.0f, 10.0f}, {110.0f, -100.0f, 10.0f}, {110.0f, -100.0f, -10.0f},

	{10.0f, -100.0f, -10.0f}, {10.0f, -100.0f, 10.0f}, {10.0f, 100.0f, 10.0f}, {10.0f, 100.0f, -10.0f}
};

GLfloat mat_dif1[] = {(r1 * 1.0 / 255), (g1 * 1.0 / 255), (b1 * 1.0 / 255), 1.0f};//normal
GLfloat mat_amb1[] = {(r1 * 1.0 / 510), (g1 * 1.0 / 510), (b1 * 1.0 / 510), 1.0f};//shadow
GLfloat mat_spec1[] = {(r1 * 1.0 / 300), (g1 * 1.0 / 300), (b1 * 1.0 / 300), 1.0f};//mirror
GLfloat mat_dif2[] = {(r2 * 1.0 / 255), (g2 * 1.0 / 255), (b2 * 1.0 / 255), 1.0f};//normal
GLfloat mat_amb2[] = {(r2 * 1.0 / 510), (g2 * 1.0 / 510), (b2 * 1.0 / 510), 1.0f};//shadow
GLfloat mat_spec2[] = {(r2 * 1.0 / 300), (g2 * 1.0 / 300), (b2 * 1.0 / 300), 1.0f};//mirror

GLfloat light_diffuse[] = {0.5, 0.5, 0.5};//light_color
GLfloat light_amb[] = {0.3, 0.3, 0.3};//shadow_color
GLfloat light_spec[] = {0.1, 0.1, 0.1, 1.0};//mirrored_color
GLfloat light_position[] = {0.0, 0, 1000.0, 1.0};//source_position
GLfloat light_dot_direction[] = {1.0, 0.0, 1.0, 0.0};//dotlight_direction
GLfloat light_spot_direction[] = {10.0, -100.0, -300.0};//light_direction

void RecalcucateMaterials(void)
{
	mat_dif1[0] = r1 * 1.0 / 255;
	mat_dif1[1] = g1 * 1.0 / 255;
	mat_dif1[2] = b1 * 1.0 / 255;
	mat_dif2[0] = r2 * 1.0 / 255;
	mat_dif2[1] = g2 * 1.0 / 255;
	mat_dif2[2] = b2 * 1.0 / 255;
	//normal
	mat_amb1[0] = r1 * 1.0 / 510;
	mat_amb1[1] = g1 * 1.0 / 510;
	mat_amb1[2] = b1 * 1.0 / 510;
	mat_amb2[0] = r2 * 1.0 / 510;
	mat_amb2[1] = g2 * 1.0 / 510;
	mat_amb2[2] = b2 * 1.0 / 510;
	//shadow
	mat_spec1[0] = r1 * 1.0 / 300;
	mat_spec1[1] = g1 * 1.0 / 300;
	mat_spec1[2] = b2 * 1.0 / 300;
	mat_spec2[0] = r1 * 1.0 / 300;
	mat_spec2[1] = g1 * 1.0 / 300;
	mat_spec2[2] = b2 * 1.0 / 300;
	//mirror
}

void resAngles()
{
	if (which == 1)
	{
		rx1 = 0;
		ry1 = 0;
		rz1 = 0;
	}

	if (which == 2)
	{
		rx2 = 0;
		ry2 = 0;
		rz2 = 0;
	}

	if (which == 3)
	{
		rx1 = 0;
		ry1 = 0;
		rz1 = 0;
		rx2 = 0;
		ry2 = 0;
		rz2 = 0;
	}
}

void modAngles(int aX, int aY, int aZ)
{
	if (which == 1)
	{
		rx1 += aX;
		ry1 += aY;
		rz1 += aZ;
	}

	if (which == 2)
	{
		rx2 += aX;
		ry2 += aY;
		rz2 += aZ;
	}

	if (which == 3)
	{
		rx1 += aX;
		ry1 += aY;
		rz1 += aZ;
		rx2 += aX;
		ry2 += aY;
		rz2 += aZ;
	}
}

void resPos()
{
	if (which == 1)
	{
		trx1 = 0;
		try1 = 0;
		trz1 = 0;
	}

	if (which == 2)
	{
		trx2 = 0;
		try2 = 0;
		trz2 = 0;
	}

	if (which == 3)
	{
		trx1 = 0;
		try1 = 0;
		trz1 = 0;
		trx2 = 0;
		try2 = 0;
		trz2 = 0;
	}
}

void modPos(int aX, int aY, int aZ)
{
	if (which == 1)
	{
		trx1 += aX;
		try1 += aY;
		trz1 += aZ;
	}

	if (which == 2)
	{
		trx2 += aX;
		try2 += aY;
		trz2 += aZ;
	}

	if (which == 3)
	{
		trx1 += aX;
		try1 += aY;
		trz1 += aZ;
		trx2 += aX;
		try2 += aY;
		trz2 += aZ;
	}
}

void resColors()
{
	if (which == 1)
	{
		r1 = 255;
		g1 = 127;
		b1 = 0;
	}

	if (which == 2)
	{
		r2 = 0;
		g2 = 191;
		b2 = 0;
	}

	if (which == 3)
	{
		r1 = 255;
		g1 = 127;
		b1 = 0;
		r2 = 0;
		g2 = 191;
		b2 = 0;
	}

	RecalcucateMaterials();
}

void randColors()
{
	if (which == 1)
	{
		r1 = rand() % 256;
		g1 = rand() % 256;
		b1 = rand() % 256;
	}

	if (which == 2)
	{
		r2 = rand() % 256;
		g2 = rand() % 256;
		b2 = rand() % 256;
	}

	if (which == 3)
	{
		r1 = rand() % 256;
		g1 = rand() % 256;
		b1 = rand() % 256;
		r2 = rand() % 256;
		g2 = rand() % 256;
		b2 = rand() % 256;
	}

	RecalcucateMaterials();
}

void GetDesktopResolution(int& scrh, int& scrv)
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	scrh = desktop.right;
	scrv = desktop.bottom;
}

void renderL1(void)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_dif1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_amb1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spec1);
	glColor3ub(r1, g1, b1);
	glVertexPointer(3, GL_FLOAT, 0, Vert1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glNormal3f(0, 0, -1);
	glDrawArrays(GL_QUADS, 0, 16);//back
	glNormal3f(0, 0, 1);
	glDrawArrays(GL_QUADS, 16, 16);//front
	glNormal3f(-1, 0, 0);
	glDrawArrays(GL_QUADS, 32, 8);//left
	glNormal3f(1, 0, 0);
	glDrawArrays(GL_QUADS, 40, 12);//right
	glNormal3f(0, 1, 0);
	glDrawArrays(GL_QUADS, 52, 8);//top
	glNormal3f(0, -1, 0);
	glDrawArrays(GL_QUADS, 60, 12);//bottom
	glDisableClientState(GL_VERTEX_ARRAY);
}

void renderL2(void)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_dif2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_amb2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spec2);
	glColor3ub(r2, g2, b2);
	glVertexPointer(3, GL_FLOAT, 0, Vert2);
	glEnableClientState(GL_VERTEX_ARRAY);
	glNormal3f(0, 0, -1);
	glDrawArrays(GL_QUADS, 0, 12);//back
	glNormal3f(0, 0, 1);
	glDrawArrays(GL_QUADS, 12, 12);//front
	glNormal3f(0, 1, 0);
	glDrawArrays(GL_QUADS, 24, 8);//top
	glNormal3f(0, -1, 0);
	glDrawArrays(GL_QUADS, 32, 8);//bottom
	glNormal3f(1, 0, 0);
	glDrawArrays(GL_QUADS, 40, 12);//right
	glNormal3f(-1, 0, 0);
	glDrawArrays(GL_QUADS, 52, 4);//left
	glDisableClientState(GL_VERTEX_ARRAY);
}

void NullLight(void)
{
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHT4);
	glDisable(GL_LIGHT5);
	glDisable(GL_LIGHT6);
	glDisable(GL_LIGHT7);
}

void LightUp(void)
{
	if (light_set == 0)
	{
		glDisable(GL_LIGHTING);
	}
	if (light_set == 1)
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT0, GL_POSITION, light_dot_direction);
	}
	if (light_set == 2)
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT1);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	}
	if (light_set == 3)
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT2);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT2, GL_POSITION, light_position);
		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.015);
		glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.01);
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.0);
	}
	if (light_set == 4)
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT3);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT3, GL_AMBIENT, light_amb);
		glLightfv(GL_LIGHT3, GL_SPECULAR, light_spec);
		glLightfv(GL_LIGHT3, GL_POSITION, light_position);
		glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 1150);
		glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light_spot_direction);
	}
}

void RenderScene(void)
{
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	rz1 += (0.5 * rMode + 0.5 * rMode1);
	rz2 += (0.5 * rMode + 0.5 * rMode2);

	LightUp();

	glPushMatrix();
	gluLookAt(0, 0, 0, -500, 0, -866, 0, 1, 0);

	glPushMatrix();
	glTranslatef(trx1, try1, trz1);
	glPushMatrix();
	glRotatef(rx1, 1, 0, 0);
	glRotatef(ry1, 0, 1, 0);
	glRotatef(rz1, 0, 0, 1);
	renderL1();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(trx2, try2, trz2);
	glPushMatrix();
	glRotatef(rx2, 1, 0, 0);
	glRotatef(ry2, 0, 1, 0);
	glRotatef(rz2, 0, 0, 1);
	renderL2();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	NullLight();
	glutSwapBuffers();
	glFlush();
}

void Keys(unsigned char key, int x, int y)
{
	if (key == 'z' || key == 'Z')
		which = 1;
	if (key == 'x' || key == 'X')
		which = 2;
	if (key == 'c' || key == 'C')
		which = 3;
	if (key == 'e' || key == 'E')
		modAngles(0, 0, -1);
	if (key == 'q' || key == 'Q')
		modAngles(0, 0, 1);
	if (key == 'w' || key == 'W')
		modAngles(-1, 0, 0);
	if (key == 's' || key == 'S')
		modAngles(1, 0, 0);
	if (key == 'd' || key == 'D')
		modAngles(0, -1, 0);
	if (key == 'a' || key == 'A')
		modAngles(0, 1, 0);
	if (key == ' ')
		resAngles();
	if (key == 'r' || key == 'R')
		resPos();
	if (key == '1')
		light_set = 1;
	if (key == '2')
		light_set = 2;
	if (key == '3')
		light_set = 3;
	if (key == '4')
		light_set = 4;
	if (key == '0')
		light_set = 0;

	if (key == 27)
	{
		glutLeaveMainLoop();
		glutDestroyWindow(glutGetWindow());
		exit(0);
		glutPostRedisplay();
	}
}

void spKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_PAGE_UP)
	{
		if (rMode == 0 || rMode == -1)
			rMode = 1;
		else
			rMode = 0;
	}

	if (key == GLUT_KEY_PAGE_DOWN)
	{
		if (rMode == 0 || rMode == 1)
			rMode = -1;
		else
			rMode = 0;
	}

	if (key == GLUT_KEY_F1)
	{
		if (rMode1 == 0 || rMode1 == -1)
			rMode1 = 1;
		else
			rMode1 = 0;
	}

	if (key == GLUT_KEY_F2)
	{
		if (rMode1 == 0 || rMode1 == 1)
			rMode1 = -1;
		else
			rMode1 = 0;
	}

	if (key == GLUT_KEY_F11)
	{
		if (rMode2 == 0 || rMode2 == -1)
			rMode2 = 1;
		else
			rMode2 = 0;
	}

	if (key == GLUT_KEY_F12)
	{
		if (rMode2 == 0 || rMode2 == 1)
			rMode2 = -1;
		else
			rMode2 = 0;
	}

	if (key == GLUT_KEY_UP)
		modPos(0, 1, 0);
	if (key == GLUT_KEY_DOWN)
		modPos(0, -1, 0);
	if (key == GLUT_KEY_LEFT)
		modPos(-1, 0, 0);
	if (key == GLUT_KEY_RIGHT)
		modPos(1, 0, 0);
	if (key == GLUT_KEY_F3)
		randColors();
	if (key == GLUT_KEY_F4)
		resColors();
	if (key == GLUT_KEY_HOME)
		modPos(0, 0, -1);
	if (key == GLUT_KEY_END)
		modPos(0, 0, 1);
}

void ChangeSize(int width, int height)
{
	if (height == 0)
		height = 1;
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
	gluPerspective(60.0f, aspectRatio, 1.0f, 50000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -400.0f);
}


void main(int argc, char** argv)
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	int scrh = 600, scrv = 800;
	GetDesktopResolution(scrh, scrv);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowSize(scrh / 2, scrv / 2);
	glutInitWindowPosition(scrh / 4, scrv / 4);
	glutSetOption(GLUT_MULTISAMPLE, 8);
	glEnable(GLUT_MULTISAMPLE);
	glutCreateWindow("Лабораторна робота № 1. Виконав Река С.С.");
	glClearColor(0, 0.5, 0.5, 1);

	glDepthFunc(GL_LEQUAL);
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(spKeys);
	glutKeyboardFunc(Keys);
	glutIdleFunc(RenderScene);
	glutMainLoop();
}