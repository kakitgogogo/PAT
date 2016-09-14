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
	node *left,*right;
	node(int v):val(v),left(NULL),right(NULL){}
};

void build(node *&root,int val)
{
	if(root==NULL)
	{
		root=new node(val);
		return;
	}
	if(val<=root->val) build(root->left,val);
	else build(root->right,val);
}

int main()
{
	int n;
	cin>>n;
	node *root=NULL;
	for(int i=0;i<n;i++)
	{
		int v;
		cin>>v;
		build(root,v);
	}
	
	queue<node*>que;
	que.push(root);
	int n1=0,n2=0;
	while(!que.empty())
	{
		n2=n1;
		n1=que.size();
		for(int i=0;i<n1;i++)
		{
			node *tmp=que.front();
			que.pop();
			if(tmp->left) que.push(tmp->left);
			if(tmp->right) que.push(tmp->right);
		}
	}
	printf("%d + %d = %d\n",n1,n2,n1+n2);
}