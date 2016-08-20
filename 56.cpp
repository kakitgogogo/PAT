#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

vector<int>weight;
vector<int>ranks;

void func(vector<int>order,int m)
{
	int n=order.size();
	if(n==1) 
	{
		ranks[order[0]]=1;
		return;
	}
	vector<int>next;
	int cur_rank=(n/m)+((n%m)==0?0:1)+1;
	for(int i=0;i<n;)
	{
		int Max=-1,index,j;
		for(j=i;j<n&&j<i+m;j++)
		{
			if(Max<weight[order[j]])
			{
				Max=weight[order[j]];
				index=order[j];
			}
			ranks[order[j]]=cur_rank;
		}
		next.push_back(index);
		i=j;
	}
	func(next,m);
}

int main()
{
	int n,m;
	cin>>n>>m;
	weight.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>weight[i];
	}
	vector<int>order(n);
	for(int i=0;i<n;i++)
	{
		cin>>order[i];
	}
	ranks.resize(n);
	func(order,m);
	cout<<ranks[0];
	for(int i=1;i<n;i++) cout<<" "<<ranks[i];
}