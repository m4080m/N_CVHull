#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define DIMENSION 2
#define POINT_NUM 100
#define _x [0]
#define _y [1]
#define MAX_GRID 100

vector< vector<int> > PointSet(POINT_NUM);
stack<int> S;


//CCW Algorithm for 2-Dimension
long long CCW_2D(int a, int b, int c) {
	return (PointSet[b]_x - PointSet[a]_x)*(PointSet[c]_y - PointSet[a]_y) - (PointSet[b]_y - PointSet[a]_y)*(PointSet[c]_x - PointSet[a]_x);
}

long long Dist(int a, int b) {
	long long sum = 0;
	for (int i = 0; i < DIMENSION; i++) {
		sum += PointSet[a][i] * PointSet[a][i] + PointSet[b][i] * PointSet[b][i];
	}
	return sum;
}

void Make_Points(void) {
	for (int i = 0; i < POINT_NUM; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			PointSet[i].push_back((rand() % (2 * MAX_GRID + 1)) - MAX_GRID);
		}
	}
	return;
}

void Gift_Wrap(void) {
	int max = PointSet[0]_x, start = 0;
	for (int i = 1; i < POINT_NUM; i++) {
		if (max < PointSet[i]_x) {
			max = PointSet[i]_x;
			start = i;
		}
	}
	S.push(start);
	while (1) {
		int next = -1, cur = S.top();
		for (int i = 0; i < POINT_NUM; i++) {
			if (i == cur) {
				continue;
			}
			long long ccw = CCW_2D(cur, next, i);
			if (ccw > 0) {
				next = i;
			}
			else if (ccw == 0) {
				next = Dist(cur, next) > Dist(cur, i) ? next : i;
			}
		}
		if (next == start) {
			break;
		}
		else {
			S.push(next);
		}
	}
}

int main() {
	srand(time(NULL));
	Make_Points();
	Gift_Wrap();
}