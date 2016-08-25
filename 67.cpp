#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

void print(vector<int>a)
{
	for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<int>a(n);
	vector<int>idx(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		idx[a[i]]=i;
	}
	int count=0,i=1;
	while(true)
	{
		if(a[0]==0)
		{
			for(i;i<n;i++)
			{
				if(a[i]!=i)
				{
					break;
				}
			}
			if(i==n) break;
			else
			{
				swap(a[0],a[i]);
				swap(idx[a[0]],idx[a[i]]);
				count++;
			}
		}
		else
		{
			swap(a[idx[idx[0]]],a[idx[0]]);
			swap(idx[idx[0]],idx[0]);
			count++;
		}
		//print(a);
	}
	
	printf("%d\n",count);
}