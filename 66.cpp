#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
	int height;
	node(int v,int h):val(v),left(NULL),right(NULL),height(h){}
};

int get_height(node *n)
{
	if(n==NULL) return 0;
	else return n->height;
}

node* l_rotate(node *x)
{
	node *y=x->left;
	x->left=y->right;
	y->right=x;
	x->height=max(get_height(x->left),get_height(x->right))+1;
	y->height=max(get_height(y->left),get_height(y->right))+1;
	return y;
}

node* r_rotate(node *x)
{
	node *y=x->right;
	x->right=y->left;
	y->left=x;
	x->height=max(get_height(x->left),get_height(x->right))+1;
	y->height=max(get_height(y->left),get_height(y->right))+1;
	return y;
}

node* lr_rotate(node *x)
{
	x->left=r_rotate(x->left);
	return l_rotate(x);
}

node* rl_rotate(node *x)
{
	x->right=l_rotate(x->right);
	return r_rotate(x);
}

node* Insert(int x,node *root)
{
	if(root==NULL) 
	{
		root=new node(x,1);
	}
	else if(x<root->val)
	{
		root->left=Insert(x,root->left);
		if(get_height(root->left)-get_height(root->right)==2)
		{
			if(x<root->left->val)
				root=l_rotate(root);
			else
				root=lr_rotate(root);
		}
	}
	else if(x>root->val)
	{
		root->right=Insert(x,root->right);
		if(get_height(root->right)-get_height(root->left)==2)
		{
			if(x>root->right->val)
				root=r_rotate(root);
			else
				root=rl_rotate(root);
		}
	}
	root->height=max(get_height(root->left),get_height(root->right))+1;
	return root;
}

int main()
{
	int n;
	cin>>n;
	node *root=NULL;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		root=Insert(x,root);
	}
	cout<<root->val<<endl;
}