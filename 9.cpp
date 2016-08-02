#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
	int n1,n2;
	cin>>n1;
	map<int,double>poly1;
	for(int i=0;i<n1;i++)
	{
		int ex;
		double co;
		cin>>ex>>co;
		poly1[ex]=co;
	}
	cin>>n2;
	map<int,double>poly;
	int count=0;
	for(int i=0;i<n2;i++)
	{
		int ex;
		double co;
		cin>>ex>>co;
		map<int,double>::iterator it;
		for(it=poly1.begin();it!=poly1.end();it++)
		{ 
			if(poly[ex+it->first]==0) count++;
			poly[ex+it->first]+=co*it->second;
			if(poly[ex+it->first]==0) count--;
		}
	}
	cout<<count;
	map<int,double>::reverse_iterator rit;
	for(rit=poly.rbegin();rit!=poly.rend();rit++)
	{
		if(rit->second!=0) printf(" %d %.1f",rit->first,rit->second);
	}
}