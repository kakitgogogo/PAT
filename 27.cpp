#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

char itoc(int n)
{
	if(n<10) return n+'0';
	else return n-10+'A';
}

int main()
{
	cout<<'#';
	for(int i=0;i<3;i++)
	{
		int c;
		cin>>c;
		printf("%c%c",itoc(c/13),itoc(c%13));
	}	
}