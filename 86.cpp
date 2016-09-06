#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
	node():val(-1),left(NULL),right(NULL){}
};

bool flg=true;
void postorder(node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		if(flg) 
		{
			cout<<root->val;
			flg=false;
		}
		else
		{
			cout<<" "<<root->val;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int count=0;
	stack<node*>sta;
	int tag=-1;
	node *root,*parent;
	while(count<n)
	{
		string s;
		cin>>s;
		if(s[1]=='u')
		{
			int a;
			cin>>a;
			node *tmp=new node();
			tmp->val=a;
			if(tag==-1) 
			{
				root=tmp;
			}
			else if(tag==0)
			{
				node *p=sta.top();
				p->left=tmp;
			}
			else
			{
				parent->right=tmp;
			}
			tag=0;
			sta.push(tmp);
		}
		else if(s[1]=='o')
		{
			parent=sta.top();
			sta.pop();
			tag=1;
			count++;
		}
	}
	postorder(root);
}