#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> >child(n+1);
	for(int i=0;i<m;i++)
	{
		int p,k;
		cin>>p>>k;
		for(int j=0;j<k;j++)
		{
			int c;
			cin>>c;
			child[p].push_back(c);
		}
	}
	queue<int>que;
	que.push(1);
	int Max=0,level=1,res=1;
	while(!que.empty())
	{
		int qs=que.size();
		if(qs>Max)
		{
			Max=qs;
			res=level;
		}
		for(int i=0;i<qs;i++)
		{
			int tmp=que.front();
			que.pop();
			for(int j=0;j<child[tmp].size();j++)
			{
				que.push(child[tmp][j]);
			}
		}
		level++;
	}
	cout<<Max<<" "<<res;
}