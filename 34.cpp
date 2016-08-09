#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<string,string>Map;

string find(string n)
{
	while(Map.find(n)!=Map.end()) n=Map[n];
	return n;
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	map<string,int>weight;
	map<string,set<string> >gang;
	for(int i=0;i<n;i++) 
	{
		string a,b;
		int t;
		cin>>a>>b>>t;
		weight[a]+=t;
		weight[b]+=t;
		string aa=find(a);
		string bb=find(b);
		if(aa!=bb) 
		{
			Map[bb]=aa;
		}
	}
	map<string,string>::iterator it0;
	for(it0=Map.begin();it0!=Map.end();it0++)
	{
		string root=find(it0->first);
		gang[root].insert(it0->first);
	}
	map<string,int>res;
	map<string,set<string> >::iterator it;
	set<string>::iterator sit;
	for(it=gang.begin();it!=gang.end();it++)
	{
		int w=0;
		set<string>tmp=it->second;
		tmp.insert(it->first);
		int m=tmp.size();
		if(m<3) continue;
		
		string idx;int Max=-1;
		for(sit=tmp.begin();sit!=tmp.end();sit++)
		{
			w+=weight[*sit];
			if(Max<weight[*sit])
			{
				Max=weight[*sit];
				idx=*sit;
			}
		}
		w/=2;
		if(w>k) 
		{
			res[idx]=m;
		}
	}
	printf("%d\n",res.size());
	map<string,int>::iterator mit;
	for(mit=res.begin();mit!=res.end();mit++)
	{
		cout<<mit->first<<" "<<mit->second<<endl;
	}
}