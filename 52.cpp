#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

struct node
{
	int addr;
	int key;
	node(int a,int k):addr(a),key(k){}
};

bool cmp(const node &n1,const node &n2)
{
	return n1.key<n2.key;
}

int main()
{
	int n,first;
	scanf("%d %d",&n,&first);
	int next[100001];
	int keys[100001];
	memset(next,-1,100001);
	vector<node>list;
	for(int i=0;i<n;i++)
	{
		int from,key,to;
		scanf("%d %d %d",&from,&key,&to);
		if(from>=0&&from<100000)
		{
			next[from]=to;
			keys[from]=key;
		}
	}
	int cur=first;
	while(cur>=0)
	{
		list.push_back(node(cur,keys[cur]));
		cur=next[cur];
	}
	
	if(list.empty())
	{
		if(first==-1) 
			printf("0 -1\n");
		else
			printf("0 %5d\n",first);
		return 0;
	}
	sort(list.begin(),list.end(),cmp);
	printf("%d %05d\n",list.size(),list[0].addr);
	for(int i=0;i<list.size();i++)
	{
		if(i<list.size()-1) printf("%05d %d %05d\n",list[i].addr,list[i].key,list[i+1].addr);
		else printf("%05d %d -1\n",list[i].addr,list[i].key);
	}
}