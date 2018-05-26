#include<stdio.h>
#include<stdlib.h>

#define numOfPoint 10
#define DIMENSION 3
#define MAX 1000000
#define MIN -1000000

typedef struct _point
{
	double coord[DIMENSION];
	int exc; //exception of search
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
	//unknown���� ������ ��(val)�� �Էµǰ�, �̸� eq�� �־��� �� unknown���� �ذ� ��ȯ�ȴ�.
	double sum = 0;
	for (i = 0; i < DIMENSION; i++)
		if(i!=unknown)
			sum += eqn.coef[i] * val.coord[i];
	return (1 - sum) / coef[0];
}

void findeqn(LEqation *eqn, Queue pointSet)//DIMENSION ���� ���� ������ 1���������� ã�´�.
{
	double matrix[DIMENSION][DIMENSION];
	double D;
	if (DIMENSION == 2)
	{
		for (int i = 0; i < DIMENSION; i++)
			for (int j = 0; j < DIMENSION; j++)
				matrix[i][j] = pointSet.arr[i]->coord[j];
		D = matrix[1][1] * matrix[0][0] - matrix[1][0] * matrix[0][1];

		eqn->coef[0] = (matrix[1][1] - matrix[0][1])/D;
		eqn->coef[1] = (matrix[0][0] - matrix[1][0])/D;
	}
	else if (DIMENSION == 3)
	{
		for (int i = 0; i < DIMENSION; i++)
			for (int j = 0; j < DIMENSION; j++)
				matrix[i][j] = pointSet.arr[i]->coord[j];
		D= (matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1]) ;
		for (k = 0; k < DIMENSION; k++)
		{
			for (int i = 0; i < DIMENSION; i++)
			{
				if (j == k)
					matrix[i][j] = 1;
				else
					matrix[i][j] = pointSet.arr[i]->coord[j];
			
			}
			eqn->coef[k] = (matrix[0][0]*matrix[1][1]*matrix[2][2]+ matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0]- matrix[0][1] * matrix[1][0] * matrix[2][2]- matrix[0][0] * matrix[1][2] * matrix[2][1])/D;
		}

	}
}

double distance(Point p1, Point p2)
{
	double dbsum = 0;
	for (i = 0; i < DIMENSION; i++)
		dbsum += (p1.coord[i]- p2.coord[i])*(p1.coord[i]- p2.coord[i]) ;
	return pow(dbsum, 0.5);
}

int pointPos(Point p, LEqation eqn)
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

void find_CVHull(Point *point, Queue pointSet)//pointset: (2������ ���) ������ �����ϴ� �� �� (3������ ���) ����� �����ϴ� �� ��
{
	Queue nextSet[DIMENSION];
	int ck1, ck2;
	for(int i=0;i<DIMENSION;i++)
		for(int j=0;j<DIMENSION;i++)

	nextSet[i].arr[j]->coord[k] = pointSet.arr[j]->coord[k];
	for (int i = 0; i < DIMENSION; i++)
	{
		nextSet
		LEqation eqn;
		for (int j = 0; j < numOfPoint; j++)
		{
			for(k=0;k<DIMENSION;k++)
				nextSet[i].arr[0]->coord[k] = point[j].coord[k];

			findeqn(&eqn, nextSet[i]);
			ck1 = 1; ck2 = 1;
			for (int k = 0; k < numOfPoint; k++)
				{
					if(pointPos(point[k],eqn))
				}
		}


	}
}

int main()
{
	Point points[numOfPoint];
	Queue set;//
	SetFirstPoint(points);
	find_CVHull(points, set);
}


