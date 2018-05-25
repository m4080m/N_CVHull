#include <stdio.h>

#define numOfPoint 11
#define MAX 1000000
#define MIN -1000000


/// �� �� �̻��� ���� ���� x��ǥ ���� ��� ���� ���� �� ���� (���� �ʿ�)///
/// �� �� �̻��� ���� �� ���� ���� ���� �� ����� ���� ���� ���(Ȥ�� �� ���� ��ġ��) �ڵ� �߰� �ʿ�.///

typedef struct _point //2���� ��ǥ
{
    double xpos, ypos;

}Point;

typedef struct _linear_function //���� �Լ�
{
    double a, b;

}LFunc;

double FuncVal(LFunc f, double x) //�Լ��� ���
{
    return (f.a)*x+f.b;
}

void findFunc(LFunc *func, Point p1, Point p2) //p1, p2�� ������ y=ax+b ã�� �Լ�
{
    if(p2.xpos!=p1.xpos)
    {
        func->a = (p2.ypos-p1.ypos) / (p2.xpos-p1.xpos);
        func->b = p1.ypos - (func->a)*p1.xpos;
    }
    else
    {
        func->a=MAX;
        func->b=-MAX*p1.xpos;
    }

}

int pointPos(Point p, LFunc func) //�� ���� �׷����� ����
{
    if(FuncVal(func, p.xpos)<p.ypos)
        return 1; //���� �׷��� ���ʿ� ����.
    else if(FuncVal(func, p.xpos)>p.ypos)
        return -1; //���� �׷��� �Ʒ��ʿ� ����.
    else
        return 0; // ���� �׷��� �� ����.
}

int SetFirstPoint(Point *point)//ó������ Ž���� ������ ���� �����Ѵ�.
{
    int i,maxPoint;
    double max=MIN;
    for(i=0;i<numOfPoint;i++)
    {
        if(point[i].xpos>=max)
        {
            max=point[i].xpos;
            maxPoint=i;
        }
    }
    return maxPoint;
}

int main()
{
    int firstPoint, pPoint, cPoint, i, j, ck1, ck2;
    /*
    pPoint : �ٷ� ������ Ž���� ���� index
    cPoint : ���� Ž�� ���� ���� index
    ck1 : �ٸ� ��� ���� �׷������� ũ�ų� ���� ������ �ִ��� üũ
    ck2 : �ٸ� ��� ���� �׷������� �۰ų� ���� ������ �ִ��� üũ
    */
    LFunc func;
    Point point[100];
    int link[100][100]={};

    point[0].xpos=1; point[0].ypos=0;
    point[1].xpos=0.45; point[1].ypos=0.66;
    point[2].xpos=0; point[2].ypos=0;
    point[3].xpos=0; point[3].ypos=1;
    point[4].xpos=1.59; point[4].ypos=1.32;
    point[5].xpos=0.5; point[5].ypos=1.5;
    point[6].xpos=1.5; point[6].ypos=0.5;
    point[7].xpos=2.19; point[7].ypos=0.75;
    point[8].xpos=1.78; point[8].ypos=-0.44;
    point[9].xpos=1.22; point[9].ypos=0.86;
    point[10].xpos=0.52; point[10].ypos=-0.36;


    firstPoint=SetFirstPoint(point);
    cPoint=firstPoint; pPoint=-1;

    do
    {
        for(i=0;i<numOfPoint;i++)
        {
            if(i==pPoint||i==cPoint)
                continue;
            findFunc(&func,point[cPoint],point[i]);
            ck1=1;ck2=1;

            for(j=0;j<numOfPoint;j++)
                if(pointPos(point[j],func)==1)
                    ck1=0;
                else if(pointPos(point[j],func)==-1)
                    ck2=0;

            if(ck1||ck2)
            {
                pPoint=cPoint;
                cPoint=i;
                link[pPoint][cPoint]=1;
                break;
            }
        }
        printf("point %d -> point %d\n",pPoint, cPoint);
    }while(cPoint!=firstPoint);

    printf("\n   ");
    for(i=0;i<numOfPoint;i++)
        printf("%3d", i);
    for(i=0;i<numOfPoint;i++)
    {
        printf("\n%3d",i);
        for(j=0;j<numOfPoint;j++)
            printf("%3d",link[i][j]);
    }
    printf("\n\n");
    return 0;
}
