#include<stdio.h>
#include<math.h>
typedef struct{
	int x;
	int y;
}point;
int main(){
	point p1={0,0}, p2={3,0}, p3={-1,0};
	double rad=atan2((p3.y-p1.y),(p3.x-p1.x))-atan2((p2.y-p1.y),(p2.x-p1.x));
	double deg=rad*180.0/3.14159265;
	printf("%lf %lf",rad,deg);
}
