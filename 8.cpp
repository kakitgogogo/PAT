#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int from=0,total=0;
	for(int i=0;i<n;i++)
	{
		int to;
		cin>>to;
		int change=to-from;
		if(change>0)
		{
			total=total+change*6+5;
		}
		else
		{
			total=total+abs(change)*4+5;
		}
		from=to;
	}
	cout<<total;
}
