#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

void printvec(vector<int>vec)
{
	printf("%d",vec[0]);
	for(int i=1;i<vec.size();i++)
	{
		printf(" %d",vec[i]);
	}
	printf("\n");
}

int main()
{
	int n,i;
	cin>>n;
	vector<int>a(n);
	vector<int>b(n);
	for(i=0;i<n;i++) 
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++) 
	{
		cin>>b[i];
	}

	int idx=1;
	while(b[idx]>=b[idx-1]) idx++;
	i=idx;
	while(b[i]==a[i]&&i<n) i++;
	if(i==n)
	{
		printf("Insertion Sort\n");
		sort(b.begin(),b.begin()+idx+1);
		printvec(b);
	}
	else 
	{
		printf("Heap Sort\n");
		for(i=n-1;i>=0;i--)
		{
			if(b[i]<b[0]) break; 
		}
		pop_heap(b.begin(),b.begin()+i+1);
		printvec(b);
	}
}