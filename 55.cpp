#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

struct data
{
	char* name;
	int age;
	int worth;
};

bool cmp1(const data &d1,const data &d2)
{
	if(d1.worth!=d2.worth) return d1.worth>d2.worth;
	else if(d1.age!=d2.age) return d1.age<d2.age;
	else return strcmp(d1.name,d2.name)<0;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<data>people(n);
	for(int i=0;i<n;i++)
	{
		char* name=new char[8];
		int age,worth;
		scanf("%s %d %d",name,&age,&worth);
		people[i].name=name;
		people[i].age=age;
		people[i].worth=worth;
	}
	sort(people.begin(),people.end(),cmp1);
	for(int i=0;i<m;i++)
	{
		int k,Amin,Amax;
		scanf("%d %d %d",&k,&Amin,&Amax);
		int count=0;
		printf("Case #%d:\n",i+1);
		bool isnone=true;
		for(int j=0;j<n;j++)
		{
			if(people[j].age>=Amin&&people[j].age<=Amax)
			{
				printf("%s %d %d\n",people[j].name,people[j].age,people[j].worth);
				count++;
				isnone=false;
			}
			if(count==k) break;
		}
		if(isnone) printf("None\n");
	}
}