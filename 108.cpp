#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int count=0;
	double sum=0;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		bool isvalid=true;
		int point=-1;
		int sign=1;
		int start=0;
		if(s[0]=='-')
		{
			sign=-1;
			start++;
		}
		for(int j=start;j<s.size();j++)
		{
			if(s[j]=='.')
			{
				if(point!=-1) 
				{
					isvalid=false;
					break;
				}
				else
				{
					point=j;
				}
			}
			else if(isdigit(s[j]))
			{
				if(point!=-1&&j-point>2)
				{
					isvalid=false;
					break;
				}
			}
			else
			{
				isvalid=false;
				break;
			}
		}
		if(isvalid)
		{
			double num=atof(s.c_str());
			if(num>1000||num<-1000) printf("ERROR: %s is not a legal number\n",s.c_str());
			else
			{
				sum+=num;
				count++;
			}
		}
		else
		{
			printf("ERROR: %s is not a legal number\n",s.c_str());
		}
	}
	if(count==0)
	{
		printf("The average of 0 numbers is Undefined");
	}
	else
	{
		printf("The average of %d number%s is %.2f",count,count==1?"":"s",sum/count);
	}
}