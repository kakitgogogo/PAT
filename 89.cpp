#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int>a)
{
	printf("%d",a[0]);
	for(int i=1;i<a.size();i++)
	{
		printf(" %d",a[i]);
	}
}

bool issorted(vector<int>a,int l,int r)
{
	int n=a.size();
	for(int i=l+1;i<r&&i<n;i++)
	{
		if(a[i]<a[i-1]) return false;
	}
	return true;
}

int main()
{
	int n,i,index;
	cin>>n;
	vector<int>a(n),b(n);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(i=1;i<n;i++)
	{
		if(b[i]<b[i-1]) break;
	}
	index=i;
	for(i;i<n;i++)
	{
		if(b[i]!=a[i]) break;
	}
	if(i==n)
	{
		printf("Insertion Sort\n");
		int tmp=b[index],j;
		for(j=index-1;j>=0;j--)
		{
			if(tmp<b[j])
			{
				b[j+1]=b[j];
			}
			else
			{
				break;
			}
		}
		b[j+1]=tmp;
		print(b);
	}
	else
	{
		printf("Merge Sort\n");
		int m=2,flg=0;
		while(true)
		{
			for(int j=0;j<n;j+=m)
			{
				if(!issorted(b,j,j+m))
				{
					flg=1;
					break;
				}
			}
			if(flg==1) break;
			m*=2;
		}
		for(int j=0;j<n;j+=m)
		{
			if(j+m>=n)
			{
				sort(b.begin()+j,b.end());
			}
			else
			{
				sort(b.begin()+j,b.begin()+j+m);
			}
		}
		print(b);
	}
}