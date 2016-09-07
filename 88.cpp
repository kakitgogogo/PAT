#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

long long GCM(long long n,long long m)
{
	if(n<m) swap(n,m);
	if(m==0) return n;
	long long r=n%m;
	while(r!=0)
	{
		n=m;
		m=r;
		r=n%m;
	}
	return m;
}

void str2num(string s,long long &num,long long &den)
{
	int sign=1;
	if(s[0]=='-')
	{
		sign=-1;
		s=s.substr(1);
	}
	int i=0;
	while(s[i]!='/') i++;
	num=atoll(s.substr(0,i).c_str());
	den=atoll(s.substr(i+1).c_str());
	long long gcm=GCM(num,den);
	num/=sign*gcm;
	den/=gcm;
}

void print(long long num,long long den)
{
	int sign=1;
	if(num<0&&den>0)
	{
		sign=-1;
		num=-num;
	}
	else if(num>=0&&den<0)
	{
		sign=-1;
		den=-den;
	}
	if(sign==-1) printf("(-");
	long long gcm=GCM(num,den);
	num/=gcm;
	den/=gcm;
	long long a=num/den,b=num%den,c=den;
	if(a==0&&b==0) printf("0");
	else if(a==0) printf("%lld/%lld",b,c);
	else if(b==0) printf("%lld",a);
	else printf("%lld %lld/%lld",a,b,c);
	if(sign==-1) printf(")");
}

int main()
{
	long long num1,den1,num2,den2;
	string a,b;
	cin>>a>>b;
	str2num(a,num1,den1);
	str2num(b,num2,den2);
	
	long long gcm=GCM(den1,den2);
	
	print(num1,den1);
	printf(" + ");
	print(num2,den2);
	printf(" = ");
	print((num1*den2+num2*den1)/gcm,den1*den2/gcm);
	printf("\n");
	
	print(num1,den1);
	printf(" - ");
	print(num2,den2);
	printf(" = ");
	print((num1*den2-num2*den1)/gcm,den1*den2/gcm);
	printf("\n");
	
	print(num1,den1);
	printf(" * ");
	print(num2,den2);
	printf(" = ");
	print(num1*num2,den1*den2);
	printf("\n");
	
	print(num1,den1);
	printf(" / ");
	print(num2,den2);
	printf(" = ");
	if(num2==0) printf("Inf");
	else print(num1*den2,num2*den1);
	printf("\n");
}