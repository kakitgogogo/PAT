#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct applicant
{
	int id;
	int ge;
	int gi;
	int total;
	int choice[10];
};

struct school
{
	int last_total;
	int last_ge;
	vector<int>apps;
};

bool cmp(const applicant& a1,const applicant& a2)
{
	if(a1.total!=a2.total) return a1.total>a2.total;
	else return a1.ge>a2.ge;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<applicant>apps(n);
	vector<int>quota(m);
	for(int i=0;i<m;i++)
	{
		cin>>quota[i];
	}
	for(int i=0;i<n;i++)
	{
		apps[i].id=i;
		cin>>apps[i].ge>>apps[i].gi;
		apps[i].total=apps[i].ge+apps[i].gi;
		for(int j=0;j<k;j++)
		{
			cin>>apps[i].choice[j];
		}
	}
	sort(apps.begin(),apps.end(),cmp);
	vector<school>schools(m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			int c=apps[i].choice[j],s=schools[c].apps.size();
			if(s<quota[c])
			{
				schools[c].apps.push_back(apps[i].id);
				schools[c].last_total=apps[i].total;
				schools[c].last_ge=apps[i].ge;
				break;
			}
			else
			{
				if(apps[i].total==schools[c].last_total&&apps[i].ge==schools[c].last_ge)
				{
					schools[c].apps.push_back(apps[i].id);
					break;
				}
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		sort(schools[i].apps.begin(),schools[i].apps.end());
		if(!schools[i].apps.empty()) cout<<schools[i].apps[0];
		for(int j=1;j<schools[i].apps.size();j++)
		{
			cout<<" "<<schools[i].apps[j];
		}
		cout<<endl;
	}
}
