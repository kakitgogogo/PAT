#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define latest 9*60*60

struct customer
{
	string time;
	int cost;
};

bool cmp(const customer &c1,const customer &c2)
{
	return c1.time<c2.time;
}

int get_time(string t)
{
	int h=atoi(t.substr(0,2).c_str());
	int m=atoi(t.substr(3,2).c_str());
	int s=atoi(t.substr(6,2).c_str());
	return (h-8)*60*60+m*60+s;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<customer>customers(n);
	for(int i=0;i<n;i++)
	{
		cin>>customers[i].time>>customers[i].cost;
		customers[i].cost*=60;
	}
	sort(customers.begin(),customers.end(),cmp);
	vector<int>end_time(m,0);
	vector<int>cost_time(n);
	int tot_cost=0;
	int count=0;
	for(int i=0;i<n;i++)
	{
		int t=get_time(customers[i].time);
		if(t>=latest) break;
		int Min=1<<30,index;
		for(int j=0;j<m;j++)
		{
			if(Min>end_time[j]) 
			{
				Min=end_time[j];
				index=j;
			}
		}
		if(t<Min) 
		{
			cost_time[i]=Min-t;
			end_time[index]=Min+customers[i].cost;
		}
		else 
		{
			cost_time[i]=0;
			end_time[index]=t+customers[i].cost;
		}	
		tot_cost+=cost_time[i];
		count++;
	}
	printf("%.1f\n",(tot_cost*1.0)/(60*count));
}