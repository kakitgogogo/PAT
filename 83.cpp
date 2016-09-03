#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
	string name;
	string id;
	int grade;
};

bool cmp(const student &s1,const student &s2)
{
	return s1.grade>s2.grade;
}

int main()
{
	int n;
	cin>>n;
	vector<student>students(n);
	for(int i=0;i<n;i++)
	{
		cin>>students[i].name>>students[i].id>>students[i].grade;
	}
	int high,low;
	cin>>low>>high;
	sort(students.begin(),students.end(),cmp);
	bool isnone=true;
	for(int i=0;i<n;i++)
	{
		if(students[i].grade>high) continue;
		else if(students[i].grade<low) break;
		cout<<students[i].name<<" "<<students[i].id<<endl;
		isnone=false;
	}
	if(isnone) cout<<"NONE"<<endl;
}