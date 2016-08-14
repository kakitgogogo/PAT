#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
	int id;
	int val;
	bool isleaf;
	vector<int>next;
	node():isleaf(true){}
};
vector<node>tree;
vector<vector<int> >res;

void dfs(int cur,int sum,int target,vector<int>path)
{
	sum+=tree[cur].val;
	path.push_back(tree[cur].val);
	if(tree[cur].isleaf)
	{
		
		if(sum==target)
		{
			res.push_back(path);
		}
		return;
	}
	int n=tree[cur].next.size();
	for(int i=0;i<n;i++)
	{
		dfs(tree[cur].next[i],sum,target,path);
	}
}

bool cmp(vector<int>v1,vector<int>v2)
{
	for(int i=0;i<v1.size()&&i<v2.size();i++)
	{
		if(v1[i]!=v2[i]) return v1[i]>v2[i];
	}
	return false;
}

int main()
{
	int n,m,s;
	cin>>n>>m>>s;
	tree.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>tree[i].val;
	}
	for(int i=0;i<m;i++)
	{
		int id,k;
		cin>>id>>k;
		tree[id].isleaf=false;
		for(int j=0;j<k;j++)
		{
			int next;
			cin>>next;
			tree[id].next.push_back(next);
		}
	}
	vector<int>path;
	dfs(0,0,s,path);
	sort(res.begin(),res.end(),cmp);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i][0];
		for(int j=1;j<res[i].size();j++)
		{
			cout<<" "<<res[i][j];
		}
		cout<<endl;
	}
}