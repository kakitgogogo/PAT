#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct user
{
	int id;
	int score[6];
	int total;
	int perfect_num;
	bool show;
	user():total(0),perfect_num(0),show(false){memset(score,-2,sizeof(score));}
};

bool cmp(const user &u1,const user &u2)
{
	if(u1.total!=u2.total) return u1.total>u2.total;
	else if(u1.perfect_num!=u2.perfect_num) return u1.perfect_num>u2.perfect_num;
	else return u1.id<u2.id;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>full(m);
	map<int,user>users;
	for(int i=0;i<m;i++) cin>>full[i];
	for(int i=0;i<k;i++)
	{
		int id,pid,score;
		cin>>id>>pid>>score;	
		if(score>=0) users[id].show=true;
		users[id].score[pid-1]=max(score,users[id].score[pid-1]);
	}
	map<int,user>::iterator it;
	vector<user>vec;
	int idx=0;
	for(it=users.begin();it!=users.end();it++)
	{
		if((it->second).show) 
		{
			vec.push_back(it->second);
			vec[idx].id=it->first;
			for(int i=0;i<m;i++)
			{
				if(vec[idx].score[i]>0) 
				{
					vec[idx].total+=vec[idx].score[i];
				}
				else if(vec[idx].score[i]==-1)
				{
					vec[idx].score[i]=0;
				}
				if(vec[idx].score[i]==full[i]) vec[idx].perfect_num++;
			}

			idx++;
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	int rank=1;
	for(int i=0;i<vec.size();i++)
	{
		if(i==0) rank=1;
		else if(vec[i].total!=vec[i-1].total) rank=i+1;
		printf("%d %05d %d",rank,vec[i].id,vec[i].total);
		for(int j=0;j<m;j++)
		{
			if(vec[i].score[j]>=0) printf(" %d",vec[i].score[j]);
			else printf(" -");
		}
		printf("\n");
	}
}