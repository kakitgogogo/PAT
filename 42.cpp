#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

string num[14]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13"};

int main()
{
	int n;
	cin>>n;
	int to[55];
	for(int i=1;i<=54;i++) cin>>to[i];
	string card[55];
	for(int i=1;i<=13;i++)
	{
		card[i]="S"+num[i];
	}
	for(int i=14;i<=26;i++)
	{
		card[i]='H'+num[i-13];
	}
	for(int i=27;i<=39;i++)
	{
		card[i]='C'+num[i-26];
	}
	for(int i=40;i<=52;i++)
	{
		card[i]='D'+num[i-39];
	}
	card[53]="J1";
	card[54]="J2";
	for(int i=0;i<n;i++)
	{
		string tmp[55];
		for(int j=1;j<=54;j++)
		{
			tmp[to[j]]=card[j];
		}
		for(int j=1;j<=54;j++)
			card[j]=tmp[j];
	}
	cout<<card[1];
	for(int i=2;i<=54;i++)
	{
		cout<<" "<<card[i];
	}
}