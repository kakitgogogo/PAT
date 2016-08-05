#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 1<<30
#define END 13*60*60

struct player
{
	int arrive;
	int cost;
	int isvip;
	int start;
};

bool cmp1(const player &p1,const player &p2)
{
	return p1.arrive<p2.arrive;
}

bool cmp2(const player &p1,const player &p2)
{
	return p1.start<p2.start;
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
	int n;
	cin>>n;
	vector<player>players(n);
	for(int i=0;i<n;i++)
	{
		string arrive;
		cin>>arrive>>players[i].cost>>players[i].isvip;
		players[i].arrive=get_time(arrive);
		players[i].cost*=60;
		if(players[i].cost>2*60*60) players[i].cost=2*60*60;
	}
	sort(players.begin(),players.end(),cmp1);
	int tn,vtn;
	cin>>tn>>vtn;
	vector<int>serve_num(tn,0);
	vector<int>end_time(tn,0);
	vector<bool>isvt(tn,false);
	vector<bool>isserved(n,false);
	int min_vt=INF;
	for(int i=0;i<vtn;i++) 
	{
		int t;
		cin>>t;
		min_vt=min(min_vt,t-1);
		isvt[t-1]=true;
	}
	for(int i=0;i<n;i++)
	{
		int j,Min=INF,t_idx,p_idx;
		for(p_idx=0;p_idx<n;p_idx++)
		{
			if(!isserved[p_idx]) break;
		}
		for(j=0;j<tn;j++)
		{
			if(end_time[j]<Min)
			{
				Min=end_time[j];
				t_idx=j;
			}
			if(players[p_idx].arrive>=end_time[j])
			{
				t_idx=j;
				break;
			}
		}
		if(players[p_idx].arrive>=end_time[t_idx])
		{
			if(players[p_idx].isvip==1) 
			{
				for(int j=t_idx;j<tn;j++)
				{
					if(isvt[j]&&players[p_idx].arrive>=end_time[j])
					{
						t_idx=j;
						break;
					}
				}
			}
			players[p_idx].start=players[p_idx].arrive;
		}
		else
		{
			int ind=-1;
			for(int j=p_idx;j<n;j++)
			{
				if(isserved[j]) continue;
				if(players[j].arrive<=Min&&isvt[t_idx]&&players[j].isvip==1) 
				{
					ind=j;
					break;
				}
				if(ind==-1)
				{
					ind=j;
				}
			}
			p_idx=ind;
			players[p_idx].start=Min;
		}
		end_time[t_idx]=players[p_idx].start+players[p_idx].cost;
		if(players[p_idx].start<END) serve_num[t_idx]++;
		isserved[p_idx]=true;
	}
	sort(players.begin(),players.end(),cmp2);
	for(int i=0;i<n;i++)
	{
		if(players[i].start>=END) break;
		int t1=players[i].arrive,t2=players[i].start,t=t2-t1;
		printf("%02d:%02d:%02d ",t1/3600+8,(t1%3600)/60,t1%60);
		printf("%02d:%02d:%02d ",t2/3600+8,(t2%3600)/60,t2%60);
		printf("%d\n",(t+30)/60);
	}
	cout<<serve_num[0];
	for(int i=1;i<tn;i++)
	{
		cout<<" "<<serve_num[i];
	}
}