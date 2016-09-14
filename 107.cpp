#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<vector<int> >hob(1001);
	vector<vector<int> >peo(n);
	int Max=0;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		getchar();
		
		for(int j=0;j<k;j++)
		{
			int h;
			cin>>h;
			Max=max(Max,h);
			peo[i].push_back(h);
			hob[h].push_back(i);
		}	
	}
	vector<bool>isvis_h(Max+1,false);
	vector<bool>isvis_p(n,false);
	vector<int>res;
	for(int i=1;i<=Max;i++)
	{
		if(hob[i].size()==0||isvis_h[i]) continue;
		
		int count=0;
		queue<int>que;
		que.push(i);
		while(!que.empty())
		{
			int tmp=que.front();
			que.pop();
			isvis_h[tmp]=true;
			for(int j=0;j<hob[tmp].size();j++)
			{
				if(!isvis_p[hob[tmp][j]])
				{
					count++;
					isvis_p[hob[tmp][j]]=true;
					for(int k=0;k<peo[hob[tmp][j]].size();k++)
					{
						if(!isvis_h[peo[hob[tmp][j]][k]])
						{
							que.push(peo[hob[tmp][j]][k]);
						}
					}
				}
			}
		}
		res.push_back(count);
	}
	cout<<res.size()<<endl;
	sort(res.begin(),res.end(),greater<int>());
	cout<<res[0];
	for(int i=1;i<res.size();i++)
	{
		cout<<" "<<res[i];
	}
}