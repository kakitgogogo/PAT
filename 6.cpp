#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct data
{
	string id;
	int in;
	int out;
};

int get_time(string time)
{
	int hour=atoi(time.substr(0,2).c_str());
	int min=atoi(time.substr(3,2).c_str());
	int sec=atoi(time.substr(6,2).c_str());
	//cout<<hour<<" "<<min<<" "<<sec<<endl;
	return 3600*hour+60*min+sec;
}

int main()
{
	int n;
	cin>>n;
	vector<data>person(n);
	for(int i=0;i<n;i++)
	{
		string id,in,out;
		cin>>id>>in>>out;
		person[i].id=id;
		person[i].in=get_time(in);
		person[i].out=get_time(out);
	}
	int MIN=1<<30,unlock;
	for(int i=0;i<n;i++)
	{
		if(person[i].in<MIN)
		{
			MIN=person[i].in;
			unlock=i;
		}
	}
	cout<<person[unlock].id<<" ";
	
	int MAX=-1,lock;
	for(int i=0;i<n;i++)
	{
		if(person[i].out>MAX)
		{
			MAX=person[i].out;
			lock=i;
		}
	}
	cout<<person[lock].id;
}