#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct mooncake
{
	double weight;
	double total;
	double avg;
};

bool cmp(const mooncake &m1,const mooncake &m2)
{
	return m1.avg>m2.avg;
}

int main()
{
	int n,d;
	cin>>n>>d;
	vector<mooncake>m(n);
	for(int i=0;i<n;i++)
	{
		cin>>m[i].weight;
	}
	for(int i=0;i<n;i++)
	{
		cin>>m[i].total;
		m[i].avg=m[i].total/m[i].weight;
	}
	sort(m.begin(),m.end(),cmp);
	int index=0;
	double res;
	while(d>0&&index<n)
	{
		if(m[index].weight<d)
		{
			res+=m[index].total;
			d-=m[index].weight;
		}
		else
		{
			res+=m[index].avg*d;
			d=0;
		}
		index++;
	}
	printf("%.2f\n",res);
}