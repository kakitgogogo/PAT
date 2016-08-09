#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int Hash(char s[])
{
	return (s[0]-'A')*26*26*10+(s[1]-'A')*26*10+(s[2]-'A')*10+(s[3]-'0');
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int>stu[26*26*26*10+1];
	for(int i=0;i<k;i++)
	{
		int course,m;
		scanf("%d %d",&course,&m);
		for(int j=0;j<m;j++)
		{
			char *name=new char[4];
			scanf("%s",name);
			int key=Hash(name);
			stu[key].push_back(course);
		}
	}
	for(int i=0;i<n;i++)
	{
		char name[4];
		scanf("%s",name);
		int key=Hash(name);
		vector<int>res=stu[key];
		printf("%s %d",name,res.size());
		sort(res.begin(),res.end());
		for(int j=0;j<res.size();j++)
		{
			printf(" %d",res[j]);
		}
		printf("\n");
	}
	
}