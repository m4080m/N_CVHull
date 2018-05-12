#include <stdio.h>

#define numOfPoint 7
#define MAX 1000000
#define MIN -1000000


/// 세 개 이상의 점이 같은 x좌표 가질 경우 오류 생길 수 있음 (수정 필요)///
/// 세 개 이상의 점이 한 직선 위에 있을 시 가까운 점을 먼저 잡는(혹은 먼 점만 거치는) 코드 추가 필요.///

typedef struct _point //2차원 좌표
{
    double xpos, ypos;

}Point;

typedef struct _linear_function //일차 함수
{
    double a, b;

}LFunc;

double FuncVal(LFunc f, double x) //함수값 계산
{
    return (f.a)*x+f.b;
}

void findFunc(LFunc *func, Point p1, Point p2) //p1, p2를 지나는 y=ax+b 찾는 함수
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

int pointPos(Point p, LFunc func) //한 점과 그래프의 관계
{
    if(FuncVal(func, p.xpos)<p.ypos)
        return 1; //점이 그래프 위쪽에 있음.
    else if(FuncVal(func, p.xpos)>p.ypos)
        return -1; //점이 그래프 아래쪽에 있음.
    else
        return 0; // 점이 그래프 상에 있음.
}

int SetFirstPoint(Point *point)//처음으로 탐색을 진행할 점을 설정한다.
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
    pPoint : 바로 이전에 탐색한 점의 index
    cPoint : 현재 탐색 중인 점의 index
    ck1 : 다른 모든 점이 그래프보다 크거나 같은 구간에 있는지 체크
    ck2 : 다른 모든 점이 그래프보다 작거나 같은 구간에 있는지 체크
    */
    LFunc func;
    Point point[100];
    int link[100][100]={};

    point[0].xpos=3; point[0].ypos=2;
    point[1].xpos=4; point[1].ypos=1;
    point[2].xpos=2; point[2].ypos=2;
    point[3].xpos=3; point[3].ypos=4;
    point[4].xpos=2; point[4].ypos=4;
    point[5].xpos=1; point[5].ypos=3;
    point[6].xpos=5; point[6].ypos=3;

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
