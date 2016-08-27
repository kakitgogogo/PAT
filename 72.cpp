#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

#define INF 1<<30
int n,m,k,d;
vector<vector<double> >dis;
vector<double>avg;
vector<double>minimum;

int str2num(string s)
{
	return s[0]=='G'?atoi(s.substr(1,s.size()-1).c_str())+n:atoi(s.c_str());
}

void dijkstra(int from)
{
	vector<double>cost(n+m+1,INF);
	for(int i=1;i<=n+m;i++) cost[i]=dis[from][i];
	vector<bool>isvis(n+m+1,false);
	isvis[from]=true;
	double sum=0;
	while(true)
	{
		double Min=INF;int index=-1;
		for(int i=1;i<=n+m;i++)
		{
			if(!isvis[i]&&cost[i]<Min)
			{
				Min=cost[i];
				index=i;
			}
		}
		if(index==-1) 
		{
			avg[from-n]=sum/n;
			return;
		}
		if(index<=n)
		{
			if(Min>d)
			{
				avg[from-n]=INF;
				return;
			}
			sum+=Min;
			minimum[from-n]=min(minimum[from-n],Min);

			printf("From G%d to %d:cost %.1f\n",from-n,index,Min);
		}
		isvis[index]=true;
		for(int i=1;i<=n+m;i++)
		{
			if(!isvis[i]&&dis[index][i]<INF&&cost[i]>cost[index]+dis[index][i])
			{
				cost[i]=cost[index]+dis[index][i];
			}
		}
	}
}

int main()
{
	cin>>n>>m>>k>>d;
	dis.resize(n+m+1,vector<double>(n+m+1,INF));
	for(int i=0;i<k;i++)
	{
		string a,b;double dist;
		cin>>a>>b>>dist;
		int x=str2num(a),y=str2num(b);
		dis[x][y]=dis[y][x]=dist;		
	}
	avg.resize(m+1,INF);
	minimum.resize(m+1,INF);
	for(int i=n+1;i<=n+m;i++) 
	{
		dijkstra(i);
		cout<<endl;
	}
	
	double Max=0,Min=INF;
	int index=-1;
	for(int i=1;i<=m;i++)
	{
		if(avg[i]==INF) continue;
		if(minimum[i]>Max)
		{
			Max=minimum[i];
			Min=avg[i];
			index=i;
		}
		else if(minimum[i]==Max&&avg[i]<Min)
		{
			Min=avg[i];
			index=i;
		}
	}
	if(index==-1) printf("No Solution");
	else 
	{
		printf("G%d\n%.1f %.1f\n",index,minimum[index],Min);
	}
}