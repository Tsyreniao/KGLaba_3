#include "Render.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include <math.h>

double f1(double p0, double p1, double p2, double p3, double t)
{
	return p0 * (1 - t) * (1 - t) * (1 - t) + 3 * t * p1 * (1 - t) * (1 - t) + 3 * t * t * p2 * (1 - t) + t * t * t * p3;
}

double f2(double p0, double p1, double p2, double p3, double t)
{
	return p0 * (1 - t) * (1 - t) * (1 - t) + 3 * t * p1 * (1 - t) * (1 - t) + 3 * t * t * p2 * (1 - t) + t * t * t * p3; 
}

double f3(double p1, double p4, double r1, double r4, double t)
{
	return p1 * (2 * t * t * t - 3 * t * t + 1) + p4 * (3 * t * t - 2 * t * t * t) + r1 * (t * t * t - 2 * t * t + t) + r4 * (t * t * t - t * t); 
}

double f4(double p1, double p4, double r1, double r4, double t)
{
	return p1 * (2 * t * t * t - 3 * t * t + 1) + p4 * (3 * t * t - 2 * t * t * t) + r1 * (t * t * t - 2 * t * t + t) + r4 * (t * t * t - t * t); 
}



double t_max = 0;

void Render(double delta_time)
{

	t_max += delta_time / 5; 

	if (t_max > 1) t_max = 0;

	double Koord1[] = {0,0,0};
	double Koord2[] = {2,-2,7};
	double Koord3[] = {5,-6,-3};
	double Koord4[] = {3,1,-5};
	double Koord[3];

	glBegin(GL_LINE_STRIP);
	glVertex3dv(Koord1);
	glVertex3dv(Koord2);
	glVertex3dv(Koord3);
	glVertex3dv(Koord4);
	glEnd();

	glLineWidth(3);  

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= t_max; t += 0.01)
	{
		Koord[0] = f1(Koord1[0], Koord2[0], Koord3[0], Koord4[0], t);
		Koord[1] = f1(Koord1[1], Koord2[1], Koord3[1], Koord4[1], t);
		Koord[2] = f1(Koord1[2], Koord2[2], Koord3[2], Koord4[2], t);
		glVertex3dv(Koord);
	}

	glEnd();
	
	glColor3d(1, 0, 1);
	glLineWidth(1); 

	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex3dv(Koord);
	glEnd();

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(Koord1);
	glVertex3dv(Koord2);
	glVertex3dv(Koord3);
	glEnd();

	
	
	double Koord50[] = {0,-1,3};
	double Koord60[] = {5,1,2};
	double Koord70[] = {4,5,6};
	double Koord80[] = {-3,5,4};
	double KoordK[3];

	glBegin(GL_LINE_STRIP);
	glVertex3dv(Koord50);
	glVertex3dv(Koord60);
	glVertex3dv(Koord70);
	glVertex3dv(Koord80);
	glEnd();

	glLineWidth(3);

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		KoordK[0] = f2(Koord50[0], Koord60[0], Koord70[0], Koord80[0], t);
		KoordK[1] = f2(Koord50[1], Koord60[1], Koord70[1], Koord80[1], t);
		KoordK[2] = f2(Koord50[2], Koord60[2], Koord70[2], Koord80[2], t);
		glVertex3dv(KoordK);
	}

	glEnd();

	glColor3d(1, 0, 1);
	glLineWidth(1);

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(Koord50);
	glVertex3dv(Koord60);
	glVertex3dv(Koord70);
	glEnd();

	

	double r1[] = {0,4,0}; 
	double r2[] = {0,2,6};

	double r3[] = {4,6,3};
	double r4[] = {8,8,8};

	double Koord5[] = {0,4,0};;
	double Koord6[] = {4,6,3};

	double R1[] = {0,-2,6};
	double R2[] = {4,2,5};

	double KoordKK[3];

	glBegin(GL_LINES);
	glVertex3dv(r1);
	glVertex3dv(r2);
	glVertex3dv(r3);
	glVertex3dv(r4);
	glEnd();

	glLineWidth(3);  

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		KoordKK[0] = f3(Koord5[0], Koord6[0], R1[0], R2[0], t);
		KoordKK[1] = f3(Koord5[1], Koord6[1], R1[1], R2[1], t);
		KoordKK[2] = f3(Koord5[2], Koord6[2], R1[2], R2[2], t);
		glVertex3dv(KoordKK);  
	}
	glEnd();
	
	glColor3d(1,0,1);
	glLineWidth(1);  

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(r1);
	glVertex3dv(r2);
	glVertex3dv(r3);
	glVertex3dv(r4);
	glEnd();



	double r5[] = {3,2,3};
	double r6[] = {1,0,1};

	double r7[] = {5,3,3};
	double r8[] = {8,2,4};

	double Koord7[] = {3,2,3};;
	double Koord8[] = {5,3,3};

	double R3[] = {-3,-3,-3};
	double R4[] = {4,-2,2};

	double KoordKKK[3];

	glBegin(GL_LINES);
	glVertex3dv(r5);
	glVertex3dv(r6);
	glVertex3dv(r7);
	glVertex3dv(r8);
	glEnd();

	glLineWidth(3);

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		KoordKKK[0] = f4(Koord7[0], Koord8[0], R3[0], R4[0], t);
		KoordKKK[1] = f4(Koord7[1], Koord8[1], R3[1], R4[1], t);
		KoordKKK[2] = f4(Koord7[2], Koord8[2], R3[2], R4[2], t);
		glVertex3dv(KoordKKK);
	}
	glEnd();

	glColor3d(1, 0, 1);
	glLineWidth(1);

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(r5);
	glVertex3dv(r6);
	glVertex3dv(r7);
	glVertex3dv(r8);
	glEnd();

	glLineWidth(1);
}