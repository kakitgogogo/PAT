#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	
	for(int num=11;num>1;num--)
	{
		for(int i=2;i+num<=13;i++)
		{
			long long m=1;
			for(int j=i;j<i+num;j++)
			{
				m*=j;
			}
			if(n%m==0)
			{
				printf("%d\n%d",num,i);
				for(int j=i+1;j<i+num;j++)
				{
					printf("*%d",j);
				}
				return 0;
			}
		}
	}
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) 
		{
			printf("1\n%d",i);
			return 0;
		}
	}
	printf("1\n%d",n);
}