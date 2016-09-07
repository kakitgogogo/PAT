#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int n,m;
const int INF=1<<30;
vector<int>happiness;
vector<vector<int> >road;

int dijkstra(int des)
{
	vector<int>cost(n);
	for(int i=0;i<n;i++) cost[i]=road[0][i];
	vector<bool>isvis(n,false);
	while(true)
	{
		int index,Min=INF;
		for(int i=1;i<n;i++)
		{
			if(!isvis[i]&&cost[i]<Min)
			{
				Min=cost[i];
				index=i;
			}
		}
		if(index==des)
		{
			return Min;
		}
		isvis[index]=true;
		for(int i=1;i<n;i++)
		{
			if(!isvis[i]&&road[index][i]<INF&&cost[index]+road[index][i]<cost[i])
			{
				cost[i]=cost[index]+road[index][i];
			}
		}
	}
}

int count=0,max_sum=0;
vector<int>res;
void dfs(int cur,int des,int cost,int min_cost,int sum,vector<bool>isvis,vector<int>path)
{
	if(cost>min_cost) return;
	if(cur==des)
	{
		if(cost==min_cost)
		{
			count++;
			if(sum>max_sum)
			{
				max_sum=sum;
				res=path;
			}
			else if(sum==max_sum&&path.size()<res.size())
			{
				res=path;
			}
		}
	}
	isvis[cur]=true;
	for(int i=1;i<n;i++)
	{
		if(!isvis[i]&&road[cur][i]<INF)
		{
			path.push_back(i);
			dfs(i,des,cost+road[cur][i],min_cost,sum+happiness[i],isvis,path);
			path.pop_back();
		}
	}
}

int main()
{
	cin>>n>>m;
	happiness.resize(n);
	road.resize(n,vector<int>(n,INF));
	
	string src;
	cin>>src;
	map<string,int>str2int;
	vector<string>city(n);
	str2int[src]=0;
	int des;
	for(int i=1;i<n;i++) 
	{
		string s;
		cin>>s;
		if(s=="ROM") des=i;
		str2int[s]=i;
		cin>>happiness[i];
		city[i]=s;
	}
	
	for(int i=0;i<m;i++)
	{
		string a,b;int dis;
		cin>>a>>b>>dis;
		int x=str2int[a],y=str2int[b];
		road[x][y]=road[y][x]=dis;
	}
	int min_cost=dijkstra(des);
	//cout<<min_cost;
	vector<bool>isvis(n,false);
	vector<int>path;
	dfs(0,des,0,min_cost,0,isvis,path);
	printf("%d %d %d %d\n",count,min_cost,max_sum,max_sum/res.size());
	cout<<src;
	for(int i=0;i<res.size();i++)
	{
		cout<<"->"<<city[res[i]];
	}
}