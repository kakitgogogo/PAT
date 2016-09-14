#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	int val;
	int left,right;
	node():left(-1),right(-1){}
};

vector<node>tree;

void invert(int cur)
{
	if(cur==-1) return;
	swap(tree[cur].left,tree[cur].right);
	invert(tree[cur].left);
	invert(tree[cur].right);
}

void levelorder(int root)
{
	queue<int>que;
	que.push(root);
	bool flg=true;
	while(!que.empty())
	{
		int tmp=que.front();
		que.pop();
		if(flg)
		{
			cout<<tmp;
			flg=false;
		}
		else
		{
			cout<<" "<<tmp;
		}
		if(tree[tmp].left!=-1) que.push(tree[tmp].left);
		if(tree[tmp].right!=-1) que.push(tree[tmp].right);
	}
}

bool flg1=true;
void inorder(int root)
{
	if(root!=-1)
	{
		inorder(tree[root].left);
		if(flg1)
		{
			cout<<root;
			flg1=false;
		}
		else
		{
			cout<<" "<<root;
		}
		inorder(tree[root].right);
	}
}

int main()
{
	int n;
	cin>>n;
	tree.resize(n);
	int root;
	vector<bool>isroot(n,true);
	for(int i=0;i<n;i++)
	{
		tree[i].val=i;
		char l,r;
		cin>>l>>r;
		if(l!='-') 
		{
			tree[i].left=l-'0';
			isroot[l-'0']=false;
		}
		if(r!='-') 
		{
			tree[i].right=r-'0';
			isroot[r-'0']=false;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(isroot[i]) 
		{
			root=i;
			break;
		}
	}
	//cout<<root;
	invert(root);
	levelorder(root);
	cout<<endl;
	inorder(root);
}