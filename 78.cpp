#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

bool isprime(int n)
{
	if(n<=1) return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

int main()
{
	int msize,n;
	cin>>msize>>n;
	while(!isprime(msize))
	{
		msize++;
	}
	vector<bool>isoccupied(n,false);
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		int idx1=a%msize,idx2=idx1;
		if(i!=0) cout<<" "; 
		int d=1,j=0;
		while(isoccupied[idx2]&&j<msize)
		{
			idx2=(idx1+d*d)%msize;
			d++;
			j++;
		}
		if(!isoccupied[idx2])
		{
			cout<<idx2;
			isoccupied[idx2]=true;
		}
		else
		{
			cout<<"-";
		}
	}
}