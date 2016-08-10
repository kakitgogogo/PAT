#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	string t="@#";
	for(int i=0;i<s.size();i++)
	{
		t=t+s[i]+'#';
	}
	//cout<<t<<endl;
	int n=t.size();
	int Max=0;
	for(int i=1;i<n;i++)
	{
		int a=1,count=0;
		while(t[i+a]==t[i-a]) 
		{
			count++;
			a++;
		}
		Max=max(count,Max);
	}
	cout<<Max<<endl;
}