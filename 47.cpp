#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

#define LEN 26*26*26*10+1

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<vector<int> >course(m+1);
	for(int i=0;i<n;i++)
	{
		char name[4];
		int k;
		scanf("%s %d",name,&k);
		int key=(name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
		for(int j=0;j<k;j++)
		{
			int c;
			cin>>c;
			course[c].push_back(key);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int s=course[i].size();
		printf("%d %d\n",i,s);
		sort(course[i].begin(),course[i].end());
		for(int j=0;j<s;j++)
		{
			int key=course[i][j];
			char name[4];
			name[0]=key/(26*26*10)+'A';
			key%=(26*26*10);
			name[1]=key/(26*10)+'A';
			key%=(26*10);
			name[2]=key/(10)+'A';
			name[3]=key%10+'0';
			printf("%s\n",name);
		}
	}
}