#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define INF 1<<30

int n,m,s,d;
vector<vector<int> >dist;
vector<vector<int> >cost;

int dijkstra()
{
	vector<int>dis(n,INF);
	vector<bool>isvis(n,false);
	isvis[s]=true;
	for(int i=0;i<n;i++)
	{
		dis[i]=dist[s][i];
	}
	while(true)
	{
		int Min=INF,index;
		for(int i=0;i<n;i++)
		{
			if(dis[i]<Min&&!isvis[i])
			{
				Min=dis[i];
				index=i;
			}
		}
		if(index==d) return Min;
		isvis[index]=true;
		for(int i=0;i<n;i++)
		{
			if(!isvis[i]&&dist[index][i]<INF&&dis[i]>dis[index]+dist[index][i])
			{
				dis[i]=dis[index]+dist[index][i];
			}
		}
	}
}

int min_dist,min_cost=INF;
vector<int>res;
void dfs(int cur,int cur_dist,int cur_cost,vector<int>path,vector<bool>isvis)
{
	if(cur==d) 
	{
		if(cur_dist==min_dist)
		{
			if(cur_cost<min_cost)
			{
				res=path;
				min_cost=cur_cost;
			}
		}
		return;
	}
	isvis[cur]=true;
	for(int i=0;i<n;i++)
	{
		if(!isvis[i]&&dist[cur][i]<INF&&cur_dist+dist[cur][i]<=min_dist)
		{
			path.push_back(i);
			dfs(i,cur_dist+dist[cur][i],cur_cost+cost[cur][i],path,isvis);
			path.pop_back();
		}
	}
}

int main()
{
	cin>>n>>m>>s>>d;
	dist.resize(n,vector<int>(n,INF));
	cost.resize(n,vector<int>(n,INF));
	for(int i=0;i<m;i++)
	{
		int a,b,dis,c;
		cin>>a>>b>>dis>>c;
		dist[a][b]=dist[b][a]=dis;
		cost[a][b]=cost[b][a]=c;
	}
	min_dist=dijkstra();
	
	vector<int>path;
	vector<bool>isvis(n,false);
	dfs(s,0,0,path,isvis);
	
	cout<<s<<" ";
	for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
	cout<<min_dist<<" ";
	cout<<min_cost;
}