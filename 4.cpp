#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<sstream>
using namespace std;

struct Node
{
	bool isleaf;
	int next_num;
	int next[100];
	Node()
	{
		isleaf=true;
	}
};

int main()
{
	int n,m;
	cin>>n>>m;
	vector<Node>node(n+1);
	for(int i=0;i<m;i++)
	{
		int a,k;
		cin>>a>>k;
		node[a].isleaf=false;
		node[a].next_num=k;
		for(int j=0;j<k;j++)
		{
			int b;
			cin>>b;
			node[a].next[j]=b;
		}
	}
	queue<Node>q;
	q.push(node[1]);
	bool flg=true;
	while(!q.empty())
	{
		int count=0;
		int q_size=q.size();
		for(int i=0;i<q_size;i++)
		{
			Node tmp=q.front();
			q.pop();
			if(tmp.isleaf) count++;
			else
			{
				for(int j=0;j<tmp.next_num;j++)
				{
					q.push(node[tmp.next[j]]);
				}
			}
		}
		if(flg) 
		{
			cout<<count;
			flg=false;
		}
		else
		{
			cout<<" "<<count;
		}
	}
}