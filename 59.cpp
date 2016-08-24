#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

bool isprime(long long n,long long &factor)
{
	for(long i=factor;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			factor=i;
			return false;
		}
	}
	return true;
}

int main()
{
	long long n;
	scanf("%lld",&n);
	long long save=n;
	if(n<=3) 
	{
		printf("%lld=%lld",n,n);
		return 0;
	}
	vector<long long>fac;
	vector<long long>exp;
	long long factor=2;
	while(true)
	{
		bool flg=isprime(n,factor);
		if(flg) break;
		else
		{
			fac.push_back(factor);
			n=n/factor;
			long long count=1;
			while(n%factor==0)
			{
				count++;
				n=n/factor;
			}
			exp.push_back(count);
		}
		if(n==1) break;
	}
	printf("%lld=",save);
	for(int i=0;i<fac.size();i++)
	{
		printf("%lld",fac[i]);
		if(exp[i]>=2) printf("^%lld",exp[i]);
		if(i<fac.size()-1) printf("*");
	}
	if(n!=1) printf("*%lld",n);
}