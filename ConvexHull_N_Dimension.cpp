#include<stdio.h>
#include<stdlib.h>

#define numOfPoint 10
#define DIMENSION 3
#define MAX 1000000
#define MIN -1000000

typedef struct _point
{
	double coord[DIMENSION];
	int exc; //exception of convex hull
}Point;

typedef struct _queue
{
	Point* arr[DIMENSION];
	int idx;
}Queue;

typedef struct _linear_eqn
{
	double coef[DIMENSION];//coef[0]x+coef[1]y+coef[2]z+...=1
}LEqation;

void QInit(Queue *pq)
{
	pq->idx = 0;
}
int QNextIdx(int i)
{
	return (i + 1) % DIMENSION;
}
void QInsert(Queue *pq, Point *point)
{
	for(int i=0;i<DIMENSION;i++)
		pq->arr[pq->idx]->coord[i] = point->coord[i];
	pq->idx=QNextIdx(pq->idx);
}
double solveEqn(LEqation eqn, int unknown, Point val)
{
	//unknown차 항을 제외한 값(val)이 입력되고, 이를 eq에 넣었을 때 unknown차 항의 해가 반환된다.
	double sum = 0;
	for (i = 0; i < DIMENSION; i++)
		if(i!=unknown)
			sum += eqn.coef[i] * val.coord[i];
	return (1 - sum) / coef[0];
}

void findeqn(LEqation *eqn, Queue pointSet)//DIMENSION 개의 점을 지나는 1차방정식을 찾는다.
{
	if (DIMENSION == 2)
	{

	}
	else if (DIMENSION == 3)
	{

	}
}

double distance(Point p1, Point p2)
{
	double dbsum = 0;
	for (i = 0; i < DIMENSION; i++)
		dbsum += (p1.coord[i]- p2.coord[i])*(p1.coord[i]- p2.coord[i]) ;
	return pow(dbsum, 0.5);
}

int pointPos(Point p, LEquation eqn)
{
	if (p.coord[0] < solveEqn(eqn, 0, p))
		return -1; //point under the eqation
	else if (p.coord[0] > solveEqn(eqn, 0, p))
		return 1; //point over the eqation
	else
		return 0;
}

int SetFirstPoint(Point *point)
{
	int maxPoint;
	double max = MIN;
	for (int i = 0; i<numOfPoint; i++)
	{
		if (point[i].coord[0] >= max)
		{
			max = point[i].coord[0];
			maxPoint = i;
		}
	}
	return maxPoint;
}



int main()
{
	
}


