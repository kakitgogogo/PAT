#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;


int main()
{
	int n;
	scanf("%d",&n);
	vector<double>num(n);
	double sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	
	for(int i=0;i<n;i++)
	{
		sum+=(num[i]*(n-i)*(i+1));
	}
	
	printf("%.2f",sum);
}