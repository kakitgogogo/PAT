#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct people
{
	int id;
	int vir;
	int tal;
	int level;
	int total;
	people(int i,int v,int t,int l,int tot):id(i),vir(v),tal(t),level(l),total(tot){}
};

bool cmp(const people &p1,const people &p2)
{
	if(p1.level!=p2.level) return p1.level>p2.level;
	else if(p1.total!=p2.total) return p1.total>p2.total;
	else if(p1.vir!=p2.vir) return p1.vir>p2.vir;
	else return p1.id<p2.id;
}

int main()
{
	int n,l,h;
	scanf("%d %d %d",&n,&l,&h);
	vector<people>peoples;
	for(int i=0;i<n;i++)
	{
		int id,vir,tal,level;
		scanf("%d %d %d",&id,&vir,&tal);
		if(vir<l||tal<l) continue;
		else if(vir>=h&&tal>=h) level=4;
		else if(vir>=h) level=3;
		else if(tal<h&&vir>=tal) level=2;
		else level=1;
		int total=vir+tal;
		peoples.push_back(people(id,vir,tal,level,total));
	}
	sort(peoples.begin(),peoples.end(),cmp);
	int m=peoples.size();
	printf("%d\n",m);
	for(int i=0;i<m;i++)
	{
		printf("%08d %d %d\n",peoples[i].id,peoples[i].vir,peoples[i].tal);
	}
}