#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		bool istrue;
		long long res=a+b;
		if(a>0&&b>0&&res<=0) istrue=true;
		else if(a<0&&b<0&&res>=0) istrue=false;
		else if(res>c) istrue=true;
		else istrue=false;
		printf("Case #%d: %s\n",i,istrue?"true":"false");
	}
}
