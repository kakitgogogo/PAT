#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE=100005;

int main()
{
	int first,n,m;
	cin>>first>>n>>m;
	int val[SIZE];
	int next[SIZE];
	for(int i=0;i<n;i++)
	{
		int addr,v,naddr;
		cin>>addr>>v>>naddr;
		val[addr]=v;
		next[addr]=naddr;
	}
	int cur=first;
	vector<int>order;
	for(int i=0;i<n;i++)
	{
		if(cur==-1) break;
		order.push_back(cur);
		cur=next[cur];
	}
	n=order.size();
	int k=0;
	while(m!=0&&k+m<=n)
	{
		reverse(order.begin()+k,order.begin()+k+m);
		k+=m;
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		printf("%05d %d ",order[i],val[order[i]]);
		if(i==n-1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%05d\n",order[i+1]);
		}
	}
}