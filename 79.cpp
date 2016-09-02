#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

struct node
{
	int val;
	vector<int>next;
	node():val(-1){}
};
int n;
double p,r;
vector<node>chain;
double sum=0;

void dfs(int cur,double rate)
{
	if(chain[cur].val!=-1)
	{
		sum+=chain[cur].val*p*rate;
		return;
	}
	int n=chain[cur].next.size();
	for(int i=0;i<n;i++)
	{
		dfs(chain[cur].next[i],rate*(1+r/100));
	}
}

int main()
{	
	cin>>n>>p>>r;
	vector<bool>isroot(n,true);
	chain.resize(n);
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		if(m==0)
		{
			int amount;
			cin>>amount;
			chain[i].val=amount;
		}
		else
		{
			for(int j=0;j<m;j++)
			{
				int next;
				cin>>next;
				isroot[next]=false;
				chain[i].next.push_back(next);
			}
		}
	}
	int root;
	for(int i=0;i<n;i++) 
	{
		if(isroot[i])
		{
			root=i;
			break;
		}
	}
	dfs(root,1);
	printf("%.1f",sum);
}