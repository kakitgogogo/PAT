#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
	int val;
	int left;
	int right;
	int lnum,rnum;
	node():val(-1),left(NULL),right(NULL){}
};

vector<node>tree;
vector<int>val;

int count(int cur)
{
	if(cur==-1) return 0;
	tree[cur].lnum=count(tree[cur].left);
	tree[cur].rnum=count(tree[cur].right);
	return tree[cur].lnum+tree[cur].rnum+1;
}

void build(int cur,int l,int r)
{
	if(cur==-1) return;
	int idx=l+tree[cur].lnum;
	tree[cur].val=val[idx];
	build(tree[cur].left,l,idx);
	build(tree[cur].right,idx+1,r);
}

void levelorder()
{
	queue<int>que;
	que.push(0);
	bool flg=true;
	while(!que.empty())
	{
		int tmp=que.front();
		que.pop();
		if(flg)
		{
			cout<<tree[tmp].val;
			flg=false;
		}
		else
		{
			cout<<" "<<tree[tmp].val;
		}
		if(tree[tmp].left!=-1) que.push(tree[tmp].left);
		if(tree[tmp].right!=-1) que.push(tree[tmp].right);
	}
}

int main()
{
	int n;
	cin>>n;
	tree.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>tree[i].left>>tree[i].right;
	}
	val.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}
	count(0);
	sort(val.begin(),val.end());
	build(0,0,n);
	levelorder();
}