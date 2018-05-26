#include<Windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define DIMENSION 2
#define POINT_NUM 20
#define MAX_GRID 100

typedef struct {
	int coord[DIMENSION];
}point;

vector< point > PointSet(POINT_NUM);
vector< int > S;


//CCW Algorithm for 2-Dimension
long long CCW_2D(point a, point b, point c) {
	return (b.coord[0] - a.coord[0])*(c.coord[1] - a.coord[1]) - (b.coord[1] - a.coord[1])*(c.coord[0] - a.coord[0]);
}

long long Dist(point a, point b) {
	long long sum = 0;
	for (int i = 0; i < DIMENSION; i++) {
		sum += a.coord[i] * a.coord[i] + b.coord[i] * b.coord[i];
	}
	return sum;
}

void Make_Points(void) {
	for (int i = 0; i < POINT_NUM; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			PointSet[i].coord[j] = (rand() % (2 * MAX_GRID + 1)) - MAX_GRID;
		}
	}
	return;
}

bool cmp(const point& a, const point& b) {
	long long val = CCW_2D(PointSet[0], a, b);
	if (val > 0) return true;
	if (val < 0) return false;
	if (a.coord[0] != b.coord[0]) return a.coord[0] < b.coord[0];
	return a.coord[1] < b.coord[1];
}

void GrahamScan(void) {
	int start = 0;
	for (int i = 0; i < POINT_NUM; i++) {
		if (PointSet[start].coord[0] > PointSet[i].coord[0] || PointSet[start].coord[0] == PointSet[i].coord[0] && PointSet[start].coord[1] > PointSet[i].coord[1]) {
			start = i;
		}
	}
	swap(PointSet[start], PointSet[0]);
	sort(PointSet.begin() + 1, PointSet.end(), cmp);
	for (int i = 0; i < POINT_NUM; i++) {
		while (S.size() >= 2 && CCW_2D(PointSet[S[S.size() - 2]], PointSet[S.back()], PointSet[i]) <= 0) {
			S.pop_back();
		}
		S.push_back(i);
	}
}

void DoDisplay()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < S.size(); i++) {
		glVertex2f((float)PointSet[S[i]].coord[0] / MAX_GRID, (float)PointSet[S[i]].coord[1] / MAX_GRID);
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < POINT_NUM; i++) {
		glVertex2f((float)PointSet[i].coord[0] / MAX_GRID, (float)PointSet[i].coord[1] / MAX_GRID);
	}
	glEnd();
	glFlush();
}

int main() {
	srand(time(NULL));
	Make_Points();
	GrahamScan();
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutMainLoop();
}
