#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int n;
vector<vector<int> >edge; 
vector<int>parent;
set<int>res;

int find(int i)
{
	while(parent[i]!=-1) i=parent[i];
	return i;
}

void dfs(int cur,vector<bool>isvis,int deep,int &max_deep)
{
	isvis[cur]=true;
	bool isleaf=true;
	for(int i=0;i<edge[cur].size();i++)
	{
		if(!isvis[edge[cur][i]])
		{
			dfs(edge[cur][i],isvis,deep+1,max_deep);
			isleaf=false;
		}
	}
	if(isleaf==true)
	{
		if(max_deep<deep)
		{
			res.clear();
			res.insert(cur);
			max_deep=deep;
		}
		else if(max_deep==deep)
		{
			res.insert(cur);
		}
	}
}

int main()
{
	cin>>n;
	edge.resize(n+1);
	parent.resize(n+1,-1);
	bool isloop=false;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
		int aa=find(a),bb=find(b);
		if(aa!=bb)
		{
			parent[bb]=aa;
		}
		else
		{
			isloop=true;
		}
	}
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(parent[i]==-1) count++;
	}
	if(count>1||isloop) 
	{
		printf("Error: %d components",count);
		return 0;
	}

	int max_deep=0;
	vector<bool>isvis(n+1,false);	
	dfs(1,isvis,0,max_deep);
	set<int>res1=res;
	
	isvis.assign(n+1,false);
	int p=*(res.begin());
	dfs(p,isvis,0,max_deep);
	set<int>res2=res;

	set_union(res1.begin(),res1.end(),res2.begin(),res2.end(),inserter(res,res.begin()));

	set<int>::iterator it;
	for(it=res.begin();it!=res.end();it++)
		cout<<*it<<endl;
}