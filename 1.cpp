#include<iostream>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std; 

string int2str(int a)
{
	stringstream ss;
	ss<<a;
	string ret;
	ss>>ret;
	return ret;
}

int main()
{
	int a,b;
	cin>>a>>b;
	int c=a+b;
	if(c<0) 
	{
		cout<<'-';c=-c;
	}
	string res=int2str(c);
	int n=res.size(),i=0,m=n;
	m=m%3;
	if(m==0) m=3;
	for(i=0;i<m;i++) 
	{
		cout<<res[i];
	}
	for(i;i<n;i+=3)
	{
		cout<<","<<res[i]<<res[i+1]<<res[i+2];
	}
}
