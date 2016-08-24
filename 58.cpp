#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	int a1,b1,c1,a2,b2,c2;
	scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
	int r=0;
	int z=(c1+c2)%29;
	r=(c1+c2)/29;
	int y=(b1+b2+r)%17;
	r=(b1+b2+r)/17;
	int x=a1+a2+r;
	printf("%d.%d.%d",x,y,z);
}