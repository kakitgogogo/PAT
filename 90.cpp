#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

int n;
double p,r;
vector<vector<int> >Next;
int max_deep=0;
int count=0;
void dfs(int cur,int deep)
{
	if(Next[cur].size()==0) 
	{
		if(max_deep<deep)
		{
			max_deep=deep;
			count=1;
		}
		else if(max_deep==deep)
		{
			count++;
		}
		return;
	}
	for(int i=0;i<Next[cur].size();i++)
	{
		dfs(Next[cur][i],deep+1);
	}
}

int main()
{	
	cin>>n>>p>>r;
	Next.resize(n);
	int root;
	for(int i=0;i<n;i++)
	{
		int supplier;
		cin>>supplier;
		if(supplier==-1) root=i;
		else Next[supplier].push_back(i);
	}
	dfs(root,0);
	double res=p*pow(1+r/100,max_deep);
	printf("%.2f %d",res,count);
}