#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

void print(string s,vector<int>out)
{
	cout<<s<<endl;
	for(int i=out.size()-1;i>=0;i--)
	{
		cout<<out[i];
	}
}

int main()
{
	string num;
	cin>>num;
	vector<int>d1,d2;
	int a[10];
	memset(a,10,0);
	int d=0;
	for(int i=num.size()-1;i>=0;i--)
	{
		int n=num[i]-'0';
		d1.push_back(n);
		d2.push_back((n*2+d)%10);
		d=(n*2+d)/10;
	}
	if(d==1) 
	{
		d2.push_back(1);
		print("No",d2);
		return 0;
	}
	sort(d1.begin(),d1.end());
	vector<int>out=d2;
	sort(d2.begin(),d2.end());
	for(int i=0;i<d1.size();i++) 
	{
		if(d1[i]!=d2[i])
		{
			print("No",out);
			return 0;
		}
	}
	print("Yes",out);
	
}