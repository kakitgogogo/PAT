#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

string read1[10]={"ling ","yi ","er ","san ","si ","wu ","liu ","qi ","ba ","jiu "};
string read2[5]={"","","Shi ","Bai ","Qian "};
string read3[4]={"","","Wan ","Yi "};

string read4(string s)
{
	int i=0,j=0,n=s.size();
	string ret="";
	while(true)
	{
		j=i;
		while(s[i]=='0'&&i<n) i++;
		if(i==n) break;
		if(i!=j) ret+="ling ";
		else
		{
			ret+=read1[s[i]-'0']+read2[n-i];
			i++;
		}
		if(i==n) break;
	}
	return ret;
}

int main()
{
	string num;
	cin>>num;
	if(num=="0") 
	{
		cout<<"ling"<<endl;
		return 0;
	}
	string res="";
	if(num[0]=='-') 
	{
		res+="Fu ";
		num=num.substr(1);
	}
	int n=num.size(),m,k=(n%4==0)?4:n%4;
	if(n==9) m=3;
	else if(n>=5) m=2;
	else m=1;
	for(int i=m;i>0;i--)
	{
		if(i<m) k=4;
		res+=read4(num.substr(0,k));
		num=num.substr(k);
		res+=read3[i];
	}
	res=res.substr(0,res.size()-1);
	cout<<res<<endl;
}