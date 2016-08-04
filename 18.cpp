#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define INF 1<<30

int c_max,n,target,m,perfect;
vector<int>bikes_num;
vector<vector<int> >road;
int min_cost;
vector<int>res;
int min_send=INF;
int min_takeback=INF;

int dijkstra()
{
	vector<int>cost(n);
	vector<bool>isvis(n,false);
	for(int i=0;i<n;i++)
	{
		cost[i]=road[0][i];
	}
	while(true)
	{
		int Min=INF,index;
		for(int i=1;i<n;i++)
		{
			if(!isvis[i]&&Min>cost[i])
			{
				Min=cost[i];
				index=i;
			}
		}
		if(index==target) return cost[index];
		isvis[index]=true;
		for(int i=1;i<n;i++)
		{
			if(!isvis[i]&&road[index][i]<INF&&cost[i]>cost[index]+road[index][i])
				cost[i]=cost[index]+road[index][i];
		}
	}
}

void dfs(int cur,int cost,int take,int send,vector<int>path,vector<bool>&isvis)
{
	if(cur==0) send=take=0;
	else if(bikes_num[cur]+take-perfect>0)
	{
		take=bikes_num[cur]+take-perfect;
	}
	else
	{
		send=send+perfect-(bikes_num[cur]+take);
		take=0;
	}
	if(cur==target)
	{
		if(cost==min_cost)
		{
			if(send<min_send)
			{
				min_send=send;
				min_takeback=take;
				res=path;
			}
			else if(send==min_send&&min_takeback>take)
			{
				min_takeback=take;
				res=path;
			}
		}
		return;
	}
	for(int i=1;i<n;i++)
	{
		if(!isvis[i]&&road[cur][i]<INF&&cost+road[cur][i]<=min_cost)
		{
			path.push_back(i);
			isvis[i]=true;	
			dfs(i,cost+road[cur][i],take,send,path,isvis);
			path.pop_back();
			isvis[i]=false;
		}
	}
}

int main()
{
	cin>>c_max>>n>>target>>m;
	perfect=c_max/2;
	n+=1;
	bikes_num.resize(n);
	for(int i=1;i<n;i++)
	{
		cin>>bikes_num[i];
	}
	road.resize(n,vector<int>(n,INF));
	for(int i=0;i<m;i++)
	{
		int a,b,l;
		cin>>a>>b>>l;
		road[a][b]=road[b][a]=l;
	}
	min_cost=dijkstra();
	//cout<<min_cost<<endl;
	vector<bool>isvis(n,false);
	vector<int>path;
	isvis[0]=true;
	dfs(0,0,0,0,path,isvis);
	cout<<min_send<<" "<<0;
	for(int i=0;i<res.size();i++) cout<<"->"<<res[i];
	cout<<" "<<min_takeback<<endl;	
}