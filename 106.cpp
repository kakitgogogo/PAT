#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n;
double p,r;
vector<vector<int> >chain;
int Min=1<<30,count=0;

void dfs(int cur,int level)
{
	if(chain[cur].size()==0)
	{
		if(level<Min)
		{
			Min=level;
			count=1;
		}
		else if(level==Min)
		{
			count++;
		}
		return;
	}
	for(int i=0;i<chain[cur].size();i++)
	{
		dfs(chain[cur][i],level+1);
	}
}

int main()
{
	cin>>n>>p>>r;
	chain.resize(n);
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			int rt;
			cin>>rt;
			chain[i].push_back(rt);
		}
	}
	dfs(0,0);
	double res=p*pow((1+r/100),Min);
	printf("%.4f %d",res,count);
}