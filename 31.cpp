#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n=s.size(),h=n/3-(n%3==0?1:0),w=n-2*h;
	int l=0,r=n-1;
	char space[40];
	for(int i=0;i<40;i++) space[i]=' ';
	for(int i=0;i<h;i++)
	{
		printf("%c%.*s%c\n",s[l++],w-2,space,s[r--]);
	}
	while(l<=r)
	{
		printf("%c",s[l++]);
	}
}