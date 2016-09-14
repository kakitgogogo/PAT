#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int INF=1<<30;
int n,m;
vector<vector<int> >dist;
vector<vector<int> >Time;
int src,des;

int dijkstra(vector<vector<int> >vec)
{
	vector<int>cost(n);
	for(int i=0;i<n;i++) cost[i]=vec[src][i];
	vector<bool>isvis(n,false);
	isvis[src]=true;
	while(true)
	{
		int Min=INF,index;
		for(int i=0;i<n;i++)
		{
			if(cost[i]<Min&&!isvis[i])
			{
				Min=cost[i];
				index=i;
			}
		}
		if(index==des) return Min;
		isvis[index]=true;
		for(int i=0;i<n;i++)
		{
			if(!isvis[i]&&vec[index][i]&&cost[index]+vec[index][i]<cost[i])
			{
				cost[i]=cost[index]+vec[index][i];
			}
		}
	}
}

vector<int>res_dist;
vector<int>res_time;
int Min_time=INF;
int Min_num=INF;

void dfs1(int cur,int min_sum,int sum,int cmp_num,vector<bool>isvis,vector<int>path)
{
	if(cur==des)
	{
		if(sum==min_sum)
		{
			if(cmp_num<Min_time)
			{
				Min_time=cmp_num;
				res_dist=path;
			}
		}
		return;
	}
	if(sum>=min_sum) return;
	isvis[cur]=true;
	for(int i=0;i<n;i++)
	{
		if(!isvis[i]&&dist[cur][i]<INF)
		{
			path.push_back(i);
			dfs1(i,min_sum,sum+dist[cur][i],cmp_num+Time[cur][i],isvis,path);
			path.pop_back();
		}
	}
}

void dfs2(int cur,int min_sum,int sum,int cmp_num,vector<bool>isvis,vector<int>path)
{
	if(cur==des)
	{
		if(sum==min_sum)
		{
			if(cmp_num<Min_num)
			{
				Min_num=cmp_num;
				res_time=path;
			}
		}
		return;
	}
	if(sum>=min_sum) return;
	isvis[cur]=true;
	for(int i=0;i<n;i++)
	{
		if(!isvis[i]&&Time[cur][i]<INF)
		{
			path.push_back(i);
			dfs2(i,min_sum,sum+Time[cur][i],cmp_num+1,isvis,path);
			path.pop_back();
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	dist.resize(n,vector<int>(n,INF));
	Time.resize(n,vector<int>(n,INF));
	for(int i=0;i<m;i++)
	{
		int a,b,tag,d,t;
		scanf("%d %d %d %d %d",&a,&b,&tag,&d,&t);
		dist[a][b]=d;
		Time[a][b]=t;
		if(tag==0)
		{
			dist[b][a]=d;
			Time[b][a]=t;
		}
	}
	scanf("%d %d",&src,&des);
	
	int min_dist=dijkstra(dist);
	int min_time=dijkstra(Time);
	
	vector<bool>isvis(n,false);
	vector<int>path;
	dfs1(src,min_dist,0,0,isvis,path);
	isvis.assign(n,false);
	dfs2(src,min_time,0,0,isvis,path);
	
	bool iseq=true;
	if(res_dist.size()==res_time.size())
	{
		for(int i=0;i<res_dist.size();i++)
		{
			if(res_dist[i]!=res_time[i])
			{
				iseq=false;
				break;
			}
		}
	}
	else
	{
		iseq=false;
	}
	
	if(iseq)
	{
		printf("Distance = %d; Time = %d: %d",min_dist,min_time,src);
		for(int i=0;i<res_dist.size();i++)
		{
			printf(" -> %d",res_dist[i]);
		}
	}
	else
	{
		printf("Distance = %d: %d",min_dist,src);
		for(int i=0;i<res_dist.size();i++)
		{
			printf(" -> %d",res_dist[i]);
		}
		printf("\n");
		printf("Time = %d: %d",min_time,src);
		for(int i=0;i<res_time.size();i++)
		{
			printf(" -> %d",res_time[i]);
		}
		printf("\n");
	}
}