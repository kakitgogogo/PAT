#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define INF 1<<30

int main()
{
	int n;
	cin>>n;
	string mname="",mid,fname="",fid;
	int mgrade=INF,fgrade=0;
	for(int i=0;i<n;i++)
	{
		string name,id;
		char sex;
		int grade;
		cin>>name>>sex>>id>>grade;
		if(sex=='M')
		{
			if(grade<mgrade)
			{
				mname=name;
				mid=id;
				mgrade=grade;
			}
		}
		else
		{
			if(grade>fgrade)
			{
				fname=name;
				fid=id;
				fgrade=grade;
			}
		}
	}
	if(mname!=""&&fname!="")
	{
		cout<<fname<<" "<<fid<<endl;
		cout<<mname<<" "<<mid<<endl;
		cout<<fgrade-mgrade<<endl;
	}
	else 
	{
		if(fname=="") cout<<"Absent"<<endl;
		else cout<<fname<<" "<<fid<<endl;
		if(mname=="") cout<<"Absent"<<endl;
		else cout<<mname<<" "<<mid<<endl;
		cout<<"NA"<<endl;
	}
}