#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define DIMENSION 2
#define POINT_NUM 100
#define MAX_GRID 100

typedef struct{
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

void Gift_Wrap(void) {
	int start = 0;
	for (int i = 1; i < POINT_NUM; i++) {
		if (PointSet[start].coord[0] < PointSet[i].coord[0]) {
			start = i;
		}
	}
	S.push_back(start);
	while (1) {
		int next = -1, cur = S.back();
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
		if (next == start) {
			break;
		}
		else {
			S.push_back(next);
		}
	}
}

int main() {
	srand(time(NULL));
	Make_Points();
	Gift_Wrap();
}
