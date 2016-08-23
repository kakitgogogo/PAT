#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
};

vector<int>a;

node *build(int left,int right)
{
	if(left>right) return NULL;
	node *root=new node();
	if(left==right)
	{
		root->val=a[left];
		return root;
	}
	int n=right-left+1;
	int h=log(n)/log(2);
	int bottom=n-pow(2,h)+1;
	int l=((bottom>pow(2,h-1))?pow(2,h-1):bottom)+pow(2,h)/2-1;
	root->val=a[left+l];
	root->left=build(left,left+l-1);
	root->right=build(left+l+1,right);
	return root;
}

void levelorder(node *root)
{
	queue<node*>q;
	q.push(root);
	bool flg=true;
	while(!q.empty())
	{
		node* tmp=q.front();
		q.pop();
		if(flg)
		{
			cout<<tmp->val;
			flg=false;
		}
		else
		{
			cout<<" "<<tmp->val;
		}
		if(tmp->left) q.push(tmp->left);
		if(tmp->right) q.push(tmp->right);
		
	}
}

int main()
{
	int n;
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	node *root=build(0,n-1);
	levelorder(root);
}