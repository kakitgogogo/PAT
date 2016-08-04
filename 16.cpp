#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define on true
#define off false
int cost[24];
int day_cost=0;

struct record_data
{
	string name;
	string time;
	int state;
};

int get_time(string t,bool flg)
{
	int d=atoi(t.substr(0,2).c_str());
	int h=atoi(t.substr(3,2).c_str());
	int m=atoi(t.substr(6,2).c_str());
	if(flg) return d*24*60+h*60+m;
	else
	{
		int hour_cost=0;
		for(int i=0;i<h;i++)
		{
			hour_cost+=cost[i]*60;
		}
		return day_cost*d*60+hour_cost+cost[h]*m;
	}
}

int get_state(string s)
{
	if(s[1]=='n') return on;
	else return off;
}

bool cmp(const record_data &r1,const record_data &r2)
{
	return r1.time<r2.time;
}

int main()
{
	for(int i=0;i<24;i++) 
	{
		cin>>cost[i];
		day_cost+=cost[i];
	}
	
	int n;
	cin>>n;
	string month;
	vector<record_data>record(n);
	map<string,vector<string> >person;
	map<string,bool>state;
	for(int i=0;i<n;i++)
	{
		string name,time,stat;
		cin>>name>>time>>stat;
		month=time.substr(0,2);
		record[i].name=name;
		record[i].time=time.substr(3,8);
		record[i].state=get_state(stat);
		
		state[name]=off;
	}
	sort(record.begin(),record.end(),cmp);
	for(int i=0;i<n;i++)
	{
		string name=record[i].name;
		if(state[name]==on&&record[i].state==on)
		{
			person[name].pop_back();
			person[name].push_back(record[i].time);
		}
		else if(state[name]!=record[i].state)
		{
			person[name].push_back(record[i].time);
			state[name]=record[i].state;
		}
	}
	map<string,vector<string> >::iterator it;
	for(it=person.begin();it!=person.end();it++)
	{
		vector<string>per;
		per=it->second;
		if(per.size()<=1) continue; 
		cout<<it->first<<" "<<month<<endl;
		int tot_cost=0,m=per.size();
		if(m%2==1) m--;
		for(int i=0;i<m;i+=2)
		{
			int t=get_time(per[i+1],true)-get_time(per[i],true);
			cout<<per[i]<<" "<<per[i+1]<<" "<<t<<" ";
			int single_cost=get_time(per[i+1],false)-get_time(per[i],false);
			tot_cost+=single_cost;
			printf("$%.2f\n",single_cost*1.0/100);
		}
		printf("Total amount: $%.2f\n",tot_cost*1.0/100);
	}
}