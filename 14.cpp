#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int n,m,k,q;
	cin>>n>>m>>k>>q;
	vector<queue<int> >que(n);
	vector<int>time(n,0);
	vector<int>start_time(k,0);
	vector<int>cost_time(k);
	int index=0,count=0;
	for(int i=0;i<k;i++)
	{
		int t;
		cin>>t;
		cost_time[i]=t;
		if(count<m*n)
		{
			start_time[i]=time[index];
			time[index]+=t;
			que[index].push(t);
			index=(index+1)%n;
			count++;
		}
		else
		{
			int Min=1<<30;
			for(int j=0;j<n;j++)
			{
				if(que[j].front()<Min) 
				{
					Min=que[j].front();
					index=j;
				}
			}
			for(int j=0;j<n;j++)
			{
				que[j].front()-=Min;
			}
			start_time[i]=time[index];
			time[index]+=t;
			que[index].pop();
			que[index].push(t);
		}
	}
	for(int i=0;i<q;i++)
	{
		int target;
		cin>>target;
		int t=start_time[target-1];
		if(t<540) 
		{
			t+=cost_time[target-1];
			printf("%02d:%02d\n",8+t/60,t%60);
		}
		else printf("Sorry\n");
	}
}