#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

int find(long long a[],long long b[],int n,int m,int k)
{
	if(n>m) return find(b,a,m,n,k);
	else if(n==0) return b[k-1];
	else if(k==1) return min(a[0],b[0]);
	
	int ia=min(k/2,n);
	int ib=k-ia;
	if(a[ia-1]<b[ib-1]) return find(a+ia,b,n-ia,m,k-ia);
	else if(a[ia-1]>b[ib-1]) return find(a,b+ib,n,m-ib,k-ib);
	else return a[ia-1];
}

int main()
{
	int n,m;
	cin>>n;
	long long *a;
	a=(long long *)malloc(n*sizeof(long long));
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>m;
	long long *b;
	b=(long long *)malloc(m*sizeof(long long));
	for(int i=0;i<m;i++) cin>>b[i];
	int mid=(n+m)/2+(n+m)%2;
	int res=find(a,b,n,m,mid);
	cout<<res;
}