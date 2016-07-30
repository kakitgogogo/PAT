#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;

#define INT_MAX 1<<30

int c_num,r_num,from,to;
vector<int>teams;
vector<vector<int> >dist;

int dijkstra()
{
	vector<bool>isvisited(c_num,false);
	isvisited[from]=true;
	vector<int>cost(c_num);
	for(int i=0;i<c_num;i++)
	{
		cost[i]=dist[from][i];
	}
	while(true)
	{
		int Min=INT_MAX,index=0;
		for(int i=0;i<c_num;i++)
		{
			if(cost[i]<Min&&isvisited[i]==false) 
			{
				Min=cost[i];
				index=i;
			}
		}
		if(index==to) return cost[to];
		isvisited[index]=true;
		for(int i=0;i<c_num;i++)
		{
			if(isvisited[i]==false&&dist[index][i]<INT_MAX&&cost[index]+dist[index][i]<cost[i])
			{
				cost[i]=cost[index]+dist[index][i];
			}
		}
	}
}

int count=0,max_teams=0;
void dfs(int cur,int cur_cost,int cur_teams,int min_cost,vector<bool>isvisited)
{
	if(cur==to) 
	{
		if(cur_cost==min_cost)
		{
			count++; 
			if(cur_teams>max_teams)
			{
				max_teams=cur_teams;
			}
		}
		return;
	}
	for(int i=0;i<c_num;i++)
	{
		if(isvisited[i]==false&&dist[cur][i]<INT_MAX&&cur_cost+dist[cur][i]<=min_cost)
		{
			isvisited[i]=true;
			dfs(i,cur_cost+dist[cur][i],cur_teams+teams[i],min_cost,isvisited);
			isvisited[i]=false;
		}
	}
}

int main()
{
	cin>>c_num>>r_num>>from>>to;
	teams.resize(c_num);
	dist.resize(r_num,vector<int>(r_num,INT_MAX));
	for(int i=0;i<c_num;i++)
	{
		cin>>teams[i];
	}
	for(int i=0;i<r_num;i++)
	{
		int a,b,l;
		cin>>a>>b>>l;
		dist[a][b]=dist[b][a]=l;
	}
	if(from==to) 
	{
		cout<<1<<" "<<teams[from]<<endl;
		return 0;
	}
	int min_cost=dijkstra();
	vector<bool>isvisited(c_num,false);
	isvisited[from]=true;
	dfs(from,0,teams[from],min_cost,isvisited);
	cout<<count<<" "<<max_teams<<endl; 
}