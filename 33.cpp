#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 1<<30

struct station
{
	double cost;
	double dist;
};

bool cmp(const station &s1,const station &s2)
{
	if(s1.dist!=s2.dist) return s1.dist<s2.dist;
	else return s1.cost<s2.cost;
}

int main()
{
	double cmax,dist,davg;int n;
	scanf("%lf %lf %lf %d",&cmax,&dist,&davg,&n);
	vector<station>sta;
	for(int i=0;i<n;i++)
	{
		station s;
		scanf("%lf %lf",&s.cost,&s.dist);
		if(s.dist<dist) sta.push_back(s);
	}
	station s;
	s.dist=dist;s.cost=0;
	sta.push_back(s);
	n=sta.size();
	sort(sta.begin(),sta.end(),cmp);
	
	if(sta[0].dist!=0)
	{
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	
	double d=cmax*davg;
	int cur=0;
	double cur_dist=0,cur_gas=0;
	double sum=0;
	while(true)
	{ 
		if(cur==n-1) break;
		int i=cur+1,idx1,Min=INF,idx2=-1; 
		//idx1表示加油站cur后最便宜的加油站
		//idx2表示cur后第一个比cur便宜的加油站
		for(i;i<n;i++)
		{
			if(sta[i].dist>cur_dist+d) break;
			if(sta[i].cost<Min)
			{
				Min=sta[i].cost;
				idx1=i;
			}
			if(sta[i].cost<sta[cur].cost&&idx2==-1)
			{
				idx2=i;
			}
		}
		if(Min==INF) break; //没有能到达的加油站
		if(idx2==-1) //可到达范围内没有加油站比现在的便宜，去最便宜的
		{
			double need=(sta[idx1].dist-sta[cur].dist)/davg;
			sum=sum+(cmax-cur_gas)*sta[cur].cost;
			cur_gas=cmax-need;
			cur=idx1;
			cur_dist=sta[cur].dist;
		}
		else    //可到达范围内有加油站比现在的便宜
		{
			double need=(sta[idx2].dist-sta[cur].dist)/davg;
			if(cur_gas<need)
			{
				sum=sum+(need-cur_gas)*sta[cur].cost;
				cur_gas=0;
			}
			else
			{
				cur_gas=cur_gas-need;
			}
			cur=idx2;
			cur_dist=sta[cur].dist;
		}
	}
	if(cur==n-1)
	{
		printf("%.2f",sum);
	}
	else 
	{
		printf("The maximum travel distance = %.2f",cur_dist+d);
	}
}