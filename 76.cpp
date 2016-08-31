#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int n,l;
	cin>>n>>l;
	vector<vector<int> >follower(n+1);
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;
		for(int j=0;j<m;j++)
		{
			int a;
			cin>>a;
			follower[a].push_back(i);
		}
	}
	/*
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<": ";
		for(int j=0;j<follower[i].size();j++)
		{
			cout<<follower[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int q;
		cin>>q;
		vector<bool>isvis(n+1,false);
		isvis[q]=true;
		queue<int>que;
		que.push(q);
		int count=0,level=l;
		while(level>0)
		{
			int qsize=que.size();
			for(int j=0;j<qsize;j++)
			{
				int tmp=que.front();
				que.pop();
				for(int t=0;t<follower[tmp].size();t++)
				{
					if(!isvis[follower[tmp][t]])
					{
						que.push(follower[tmp][t]);
						count++;
						isvis[follower[tmp][t]]=true;
					}
				}
			}
			level--;
		}
		cout<<count<<endl;
	}
}