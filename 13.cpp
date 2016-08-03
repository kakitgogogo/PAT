#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <set>
using namespace std;
/*
int find(int i,vector<int>parent)
{
	while(parent[i]!=-1) i=parent[i];
	return i;
}

void connect(int a,int b,vector<int>&parent)
{
	int aa=find(a,parent);
	int bb=find(b,parent);
	if(aa!=bb) parent[aa]=bb;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int> >road(n+1,vector<int>(n+1,0));
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		road[a][b]=road[b][a]=1;
	}
	for(int i=0;i<k;i++)
	{
		int check;
		cin>>check;
		vector<vector<int> >tmp(n+1,vector<int>(n+1,0));
		tmp=road;
		for(int j=1;j<n+1;j++)
		{
			tmp[check][j]=tmp[j][check]=0;
		}
		vector<int>parent(n+1,-1);
		for(int p=1;p<n+1;p++)
		{
			for(int q=1;q<n+1;q++)
			{
				if(tmp[p][q]==1) connect(p,q,parent);
			}
		}
		int count=0;
		for(int j=1;j<n+1;j++)
		{
			if(parent[j]==-1) count++;
		}
		cout<<count-2<<endl;
	}
}
*/
vector<vector<int> >road;
vector<bool>isvisited;

void dfs(int cur)
{
	isvisited[cur]=true;
	int n=road[cur].size();
	for(int i=0;i<n;i++)
	{
		if(!isvisited[road[cur][i]])
		{
			dfs(road[cur][i]);
		}
	}
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	road.resize(n+1);
	isvisited.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		road[a].push_back(b);
		road[b].push_back(a);
	}
	for(int i=0;i<k;i++)
	{
		int check;
		cin>>check;
		isvisited.assign(n+1,false);
		isvisited[check]=true;
		int count=0;
		for(int j=1;j<=n;j++)
		{
			if(!isvisited[j])
			{
				dfs(j);
				count++;
			}		
		}
		cout<<count-1<<endl;
	}
}