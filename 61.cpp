#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	char day[8][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

	char s1[65],s2[65];
	scanf("%s %s",s1,s2);
	int m=strlen(s1),n=strlen(s2),i,d,h;
	for(i=0;i<m&&i<n;i++)
	{
		if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G')
		{
			break;
		}
	}
	d=s1[i]-'A';
	for(i++;i<m&&i<n;i++)
	{
		if(s1[i]==s2[i]&&((s1[i]>='A'&&s1[i]<='N')||(s1[i]>='0'&&s1[i]<='9')))
		{
			break;
		}
	}
	if(isupper(s1[i])) h=10+s1[i]-'A';
	else h=s1[i]-'0';
	
	scanf("%s %s",s1,s2);
	m=strlen(s1);
	n=strlen(s2);
	for(i=0;i<m&&i<n;i++)
	{
		if(s1[i]==s2[i]&&isalpha(s1[i]))
		{
			break;
		}
	}
	printf("%s %02d:%02d\n",day[d],h,i);
}