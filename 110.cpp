#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	int val;
	int left,right;
	node():left(-1),right(-1){}
};

int main()
{
	int n;
	cin>>n;
	vector<node>tree(n);
	vector<bool>isroot(n,true);
	for(int i=0;i<n;i++)
	{
		string l,r;
		cin>>l>>r;
		if(l[0]!='-')
		{
			int left=atoi(l.c_str());
			tree[i].left=left;	
			isroot[left]=false;
		}
		if(r[0]!='-')
		{
			int right=atoi(r.c_str());
			tree[i].right=right;
			isroot[right]=false;
		}
	}
	int root;
	for(int i=0;i<n;i++)
	{
		if(isroot[i])
		{
			root=i;
			break;
		}
	}
	queue<int>que;
	que.push(root);
	int count=0,last;
	while(!que.empty())
	{
		int tmp=que.front();
		if(tmp==-1)
		{
			break;
		}
		last=tmp;
		count++;
		que.pop();
		que.push(tree[tmp].left);
		que.push(tree[tmp].right);
	}
	if(count==n)
	{
		cout<<"YES "<<last;
	}
	else
	{
		cout<<"NO "<<root;
	}
}