#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int>sum(n+1,0);
	for(int i=0;i<n;i++)
	{
		int d;
		scanf("%d",&d);
		sum[i+1]=sum[i]+d;
	}
	vector<pair<int,int> >res;
	int Best=1<<30;
	for(int i=0;i<n+1;i++)
	{
		int j;
		for(j=i+1;j<n+1;j++)
		{
			if((sum[j]-sum[i])>=m)
			{
				if((sum[j]-sum[i])<Best)
				{
					Best=sum[j]-sum[i];
					res.clear();
					res.push_back(pair<int,int>(i+1,j));
				}
				else if((sum[j]-sum[i])==Best)
				{
					res.push_back(pair<int,int>(i+1,j));
				}
				break;
			}
		}
		int save=i;
		while((sum[j]-sum[++i])>=m);
		i--;
		if((sum[j]-sum[i])==Best&&save!=i)
		{
			res.push_back(pair<int,int>(i+1,j));
		}
		else if((sum[j]-sum[i])<Best&&save!=i)
		{
			Best=sum[j]-sum[i];
			res.clear();
			res.push_back(pair<int,int>(i+1,j));
		}
		if(j==n) break;
	}
	for(int i=0;i<res.size();i++)
	{
		printf("%d-%d\n",res[i].first,res[i].second);
	}
}