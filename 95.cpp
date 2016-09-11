#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct data
{
	string plate;
	int time;
	int state;
};

struct car
{
	int in_time;
	int total;
};

bool cmp(const data &d1,const data &d2)
{
	return d1.time<d2.time;
}

int get_time(string t)
{
	int h=atoi(t.substr(0,2).c_str());
	int m=atoi(t.substr(3,2).c_str());
	int s=atoi(t.substr(6,2).c_str());
	return h*3600+m*60+s;
}

int print_time(int time)
{
	int h=time/3600;
	time=time%3600;
	int m=time/60;
	time=time%60;
	printf("%02d:%02d:%02d\n",h,m,time);
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<data>d(n);
	for(int i=0;i<n;i++)
	{
		string t,s;
		cin>>d[i].plate>>t>>s;
		d[i].time=get_time(t);
		d[i].state=(s=="in")?1:0;
	}
	sort(d.begin(),d.end(),cmp);
	
	vector<bool>isvalid(n,false);
	map<string,int>in_idx;
	map<string,int>::iterator it0;
	for(int i=0;i<n;i++)
	{
		it0=in_idx.find(d[i].plate);
		if(d[i].state==0&&it0!=in_idx.end())
		{
			isvalid[i]=isvalid[it0->second]=true;
			in_idx.erase(it0);
		}
		else if(d[i].state==1)
		{
			in_idx[d[i].plate]=i;
		}
	}
	
	map<string,car>cars;
	map<string,car>::iterator it;
	map<int,int>count;
	count[0]=0;
	int last_count=0;
	int i=0,j;
	int Max=0;
	
	while(i<n)
	{
		count[d[i].time]=last_count;
		for(j=i;j<n;j++)
		{
			if(d[j].time!=d[i].time)
			{
				break;
			}
			if(!isvalid[j]) continue;
			if(d[j].state==1) 
			{
				count[d[j].time]++;
				cars[d[j].plate].in_time=d[j].time;
			}
			else if(d[j].state==0)
			{
				count[d[j].time]--;
				it=cars.find(d[j].plate);
				(it->second).total+=(d[j].time-(it->second).in_time);
				Max=max(Max,(it->second).total);
			}
		}
		last_count=count[d[i].time];
		i=j;
	}
	
	map<int,int>::iterator it1=count.begin();
	for(i=0;i<m;i++)
	{
		char s[9];
		scanf("%s",s);
		string t(s);
		int time=get_time(t);
		for(it1++;it1!=count.end();it1++)
		{
			if(it1->first>time) break;
		}
		it1--;
		printf("%d\n",it1->second);
	}
	vector<string>res;
	for(it=cars.begin();it!=cars.end();it++)
	{
		if((it->second).total==Max)
		{
			res.push_back(it->first);
		}
	}
	for(i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	print_time(Max);
}