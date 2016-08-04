#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
	node()
	{
		left=NULL;right=NULL;
	}
};

vector<int>post,in;

node* build(int pl,int pr,int il,int ir)
{
	if(il>ir||pl>pr) return NULL;
	
	int i=il;
	for(i;i<=ir;i++)
	{
		if(in[i]==post[pr]) break;
	}
	int len=i-il;
	
	node *root=new node();
	root->val=post[pr];
	root->left=build(pl,pl+len-1,il,i-1);
	root->right=build(pl+len,pr-1,i+1,ir);
	
	return root;
}

void levelorder(node *root)
{
	queue<node *>que;
	que.push(root);
	int flg=0;
	while(!que.empty())
	{
		int n=que.size();
		for(int i=0;i<n;i++)
		{
			node *tmp=que.front();
			que.pop();
			if(flg==0)
			{
				cout<<tmp->val;
				flg=1;
			}
			else
			{
				cout<<" "<<tmp->val;
			}
			if(tmp->left) que.push(tmp->left);
			if(tmp->right) que.push(tmp->right);
		}
	}
}

int main()
{
	int n;
	cin>>n;
	post.resize(n);
	in.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>post[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	node *root;
	root=build(0,n-1,0,n-1);
	levelorder(root);
}