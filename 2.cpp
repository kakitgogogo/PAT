#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
	int m,n;
	cin>>m;
	map<int,double>poly;
	for(int i=0;i<m;i++)
	{
		int ex;double co;
		cin>>ex>>co;
		poly[ex]=co;
	}
	cin>>n;
	int count=m;
	for(int i=0;i<n;i++)
	{
		int ex;double co;
		cin>>ex>>co;
		if(poly[ex]==0) count++;
		poly[ex]+=co;
		if(poly[ex]==0) count--;
	}
	cout<<count;
	map<int,double>::reverse_iterator it;
	for(it=poly.rbegin();it!=poly.rend();it++)
	{
		if(it->second!=0) printf(" %d %.1f",it->first,it->second);
	}
}