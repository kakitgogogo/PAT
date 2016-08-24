#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a.begin()+1,a.end(),greater<int>());
	
	vector<vector<bool> >dp(n+1,vector<bool>(m+1,false));
	vector<vector<bool> >used(n+1,vector<bool>(m+1,false));
	for(int i=0;i<=n;i++) dp[i][0]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j-a[i]>=0&&dp[i-1][j-a[i]])
			{
				dp[i][j]=true;
				used[i][j]=true;
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	if(!dp[n][m])
	{
		printf("No Solution\n");
	}
	else
	{
		int i=n,j=m;
		vector<int>res;
		while(j)
		{
			while(!used[i][j]) i--;
			res.push_back(a[i]);
			j-=a[i];
			i--;
		}
		printf("%d",res[0]);
		for(int k=1;k<res.size();k++)
		{
			printf(" %d",res[k]);
		}
	}
}