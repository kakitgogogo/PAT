#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int get_num(char *s,int n,string &num)
{
	int m=strlen(s);
	int i=0,ex;
	while(i<m&&s[i]=='0') i++;
	if(i<m&&s[i]=='.')
	{
		i++;
		ex=0;
		while(i<m&&s[i]=='0')
		{
			i++;
			ex--;
		}
		while(i<m&&num.size()<n)
		{
			num+=s[i++];
		}
		while(num.size()<n)
		{
			num+='0';
		}
		return ex;
	}
	else
	{
		ex=0;
		while(i<m&&s[i]!='.')
		{
			ex++;
			if(num.size()<n)
			{
				num+=s[i];
			}
			i++;
		}
		i++;
		while(i<m&&num.size()<n)
		{
			num+=s[i++];
		}
		while(num.size()<n)
		{
			num+='0';
		}
		return ex;
	}
}

int main()
{
	int n;
	char s1[105],s2[105];
	scanf("%d %s %s",&n,s1,s2);
	string res1,res2;
	int ex1=get_num(s1,n,res1);
	int ex2=get_num(s2,n,res2);
	if(res1[0]=='0') ex1=0;
	if(res2[0]=='0') ex2=0;
	if(res1==res2&&ex1==ex2)
	{
		printf("YES 0.%s*10^%d",res1.c_str(),ex1);
	}
	else
	{
		printf("NO 0.%s*10^%d 0.%s*10^%d",res1.c_str(),ex1,res2.c_str(),ex2);
	}
}