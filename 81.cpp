#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

long long get_GCM(int n,int m)
{
	if(n<m) swap(n,m);
	if(m==0) return 1;
	long long r=n%m;
	while(r!=0)
	{
		n=m;
		m=r;
		r=n%m;
	}
	return m;
}

int main()
{
	int n;
	cin>>n;
	long long num=0,den=1;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int start=0,sign=1,j,count=0;
		if(s[0]=='-') 
		{
			start++;
			sign=-1;
		}
		for(j=start;j<s.size();j++)
		{
			if(s[j]=='/') break;
			count++;
		}
		long long num1=sign*atoll(s.substr(start,count).c_str());
		long long den1=atoll(s.substr(j+1).c_str());
		num=num*den1+num1*den;
		den=den*den1;
		
		int sign1=1;
		if(num<0)
		{
			sign1=-1;
			num=-num;
		}
		long long gcm=get_GCM(num,den);
		num=sign1*num/gcm;
		den/=gcm;
		//cout<<num<<" "<<den<<" "<<gcm<<endl;
	}
	long long a=num/den,b=num%den,c=den;
	if(a==0&&b==0) printf("0");
	else if(a==0) printf("%lld/%lld",b,c);
	else if(b==0) printf("%lld",a);
	else printf("%lld %lld/%lld",a,b,c);
}