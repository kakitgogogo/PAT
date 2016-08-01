#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string spell[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main()
{
  string s;
  cin>>s;
  int n=0;
  for(int i=0;i<s.size();i++)
  {
    n+=s[i]-'0';
  }
  if(n==0) 
  {
    cout<<"zero";
    return 0;
  }
  int m=0;
  vector<int>res;
  while(n>0)
  {
    m=n%10;
    n=n/10;
    res.push_back(m);
  }
  int len=res.size();
  cout<<spell[res[len-1]];
  for(int i=len-2;i>=0;i--)
  {
    cout<<" "<<spell[res[i]];
  }
}