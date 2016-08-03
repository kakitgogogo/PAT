#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

bool isprime(long long num)
{
	if(num<=1) return false;
	long long k=sqrt(num);
	for(int i=2;i<=k;i++)
	{
		if(num%i==0) return false;
	}
	return true;
}

int main()
{
	while(true)
	{
		long long num,radix;
		cin>>num;
		if(num<0) break;
		cin>>radix;
		long long num1=num,num2=0;
		while(num>0)
		{
			num2=num2*radix+num%radix;
			num/=radix;
		}
		if(isprime(num1)&&isprime(num2)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}