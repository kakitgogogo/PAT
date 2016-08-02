#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

char c[3]={'W','T','L'};

int main()
{
	double d=1.00;
	for(int i=0;i<3;i++)
	{
		double Max=0;int index=0;
		for(int j=0;j<3;j++)
		{
			double a;
			cin>>a;
			if(Max<a)
			{
				Max=a;
				index=j;
			}
		}
		cout<<c[index]<<" ";
		d*=Max;
	}
	double res=(d*0.65-1.00)*2.00;
	printf("%.2f",res);
}