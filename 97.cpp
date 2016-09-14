#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int n,first;
	cin>>first>>n;
	int Next[100001],val[100001];
	memset(Next,-1,sizeof(Next));
	for(int i=0;i<n;i++)
	{
		int addr;
		cin>>addr;
		cin>>val[addr]>>Next[addr];
	}
	set<int>Set;
	vector<int>addr1,addr2;
	int cur=first;
	while(cur!=-1)
	{
		if(Set.find(abs(val[cur]))==Set.end())
		{
			Set.insert(abs(val[cur]));
			addr1.push_back(cur);
		}
		else
		{
			addr2.push_back(cur);
		}
		cur=Next[cur];
	}
	for(int i=0;i<addr1.size();i++)
	{
		printf("%05d %d ",addr1[i],val[addr1[i]]);
		if(i==addr1.size()-1) printf("-1\n");
		else printf("%05d\n",addr1[i+1]);
	}
	for(int i=0;i<addr2.size();i++)
	{
		printf("%05d %d ",addr2[i],val[addr2[i]]);
		if(i==addr2.size()-1) printf("-1\n");
		else printf("%05d\n",addr2[i+1]);
	}
}