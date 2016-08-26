#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

string Sub(string a,string b)
{
	string c="0000";
	int r=0;
	for(int i=3;i>=0;i--)
	{
		int t=b[i]-r-a[i];
		if(t<0)
		{
			t+=10;
			r=1;
		}
		else
		{
			r=0;
		}
		c[i]=t+'0';
	}
	return c;
}

int main()
{
	string a;
	cin>>a;
	int n=4-a.size();
	for(int i=0;i<n;i++) a="0"+a;
	if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])
	{
		printf("%s - %s = 0000",a.c_str(),a.c_str());
		return 0;
	}
	else
	{
		while(true)
		{
			string b=a;
			sort(a.begin(),a.end());
			sort(b.begin(),b.end(),greater<char>());
			string c=Sub(a,b);
			printf("%s - %s = %s\n",b.c_str(),a.c_str(),c.c_str());
			a=c;
			if(a=="6174") return 0;
		}
	}
}