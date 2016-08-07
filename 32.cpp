#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int next[100001];
	bool vis[100001];
	memset(next,-1,100001);
	memset(vis,false,100001);
	int a1,a2,n;
	scanf("%d %d %d",&a1,&a2,&n);
	for (int i=0;i<n;i++)
	{
		int a,b;
		char c;
		scanf("%d %c %d",&a,&c,&b);
		next[a]=b;
	}
	int index=a1;
	while(index!=-1)
	{
		vis[index]=true;
		index=next[index];
	}
	index=a2;
	while(index!=-1&&!vis[index])
	{
		index=next[index];
	}
	if(index==-1)
		printf("-1");
	else
		printf("%05d",index);
}