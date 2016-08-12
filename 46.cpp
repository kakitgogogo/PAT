#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>dis(n+1);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int d;
		cin>>d;
		sum+=d;
		if(i==n) break;
		dis[i+1]=dis[i]+d;
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		int res=min((dis[y]-dis[x]),sum-(dis[y]-dis[x]));
		cout<<res<<endl;
	}
}