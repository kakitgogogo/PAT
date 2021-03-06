#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n,k,p;
vector<int>res;
vector<int>mypow;
int max_idx;

void init_pow()
{
	for(int i=0;;i++)
	{
		int num=1;
		for(int j=0;j<p;j++)
		{
			num*=i;
		}
		mypow.push_back(num);
		max_idx=i;
		if(num>=400) return;
	}
}


int Max=0;
void dfs(int target,int count,int high,vector<int>fac)
{
	if(count==0)
	{
		if(target==0)
		{
			if(res.empty()) res=fac;
			else
			{
				int sum=0;
				for(int i=0;i<k;i++)
				{
					sum+=fac[i];
				}
				if(sum>Max) 
				{
					Max=sum;
					res=fac;
				}
			}
		}
		return;
	}
	if(target<count) return;
	while(mypow[high]>target-count+1) high--;
	for(int i=high;mypow[i]>=target/count;i--)
	{
		if(target>=mypow[i])
		{
			fac[count-1]=i;
			dfs(target-mypow[i],count-1,i,fac);
		}
	}
}

int main()
{
	cin>>n>>k>>p;
	init_pow();
	vector<int>fac(k);
	dfs(n,k,max_idx,fac);
	if(!res.empty())
	{
		reverse(res.begin(),res.end());
		printf("%d = %d^%d",n,res[0],p);
		for(int i=1;i<res.size();i++)
		{
			printf(" + %d^%d",res[i],p);
		}
	}
	else 
	{
		printf("Impossible");
	}
}