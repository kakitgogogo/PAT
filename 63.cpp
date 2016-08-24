#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<set<int> >S(n);
	for(int i=0;i<n;i++)
	{
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			int a;
			scanf("%d",&a);
			S[i].insert(a);
		}
	}
	int k;
	scanf("%d",&k);
	vector<vector<double> >save(n+1,vector<double>(n+1,-1));
	for(int i=0;i<k;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(save[x][y]>=0)
		{
			printf("%.1f\%\n",save[x][y]);
			continue;
		}
		set<int>u;
		set_intersection(S[x-1].begin(),S[x-1].end(),S[y-1].begin(),S[y-1].end(),inserter(u,u.begin()));
		double res=u.size()*100.0/(S[x-1].size()+S[y-1].size()-u.size());
		save[x][y]=res;
		printf("%.1f\%\n",res);
	}
}