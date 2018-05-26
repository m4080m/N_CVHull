#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define DIMENSION 3
#define POINT_NUM 100
#define MAX_GRID 100

typedef struct{
	int coord[DIMENSION];
}point;

typedef struct {
	int a;
	int b;
}edge;

typedef struct {
	int a;
	int b;
	int c;
}face;

vector< point > PointSet(POINT_NUM);
vector< face > S;
queue< edge > Q;

bool check[POINT_NUM];

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

void Start_Edge(void) {
	int start = 0;
	for (int i = 1; i < POINT_NUM; i++) {
		if (PointSet[start].coord[0] < PointSet[i].coord[0]) {
			start = i;
		}
	}
	int next = -1, cur = start;
	for (int i = 0; i < POINT_NUM; i++) {
		if (i == cur) {
			continue;
		}
		if (next == -1) {
			next = i;
			continue;
		}
		long long ccw = CCW_2D(PointSet[cur], PointSet[next], PointSet[i]);
		if (ccw > 0) {
			next = i;
		}
		else if (ccw == 0) {
			next = Dist(PointSet[cur], PointSet[next]) > Dist(PointSet[cur], PointSet[i]) ? next : i;
		}
	}
	edge temp;
	temp.a = cur;
	temp.b = next;
	Q.push(temp);
	return;
}

void Gift_Wrap(void) {
	Start_Edge();
	while (!Q.empty()) {

	}
}

int main() {
	srand(time(NULL));
	Make_Points();
	Gift_Wrap();
}
