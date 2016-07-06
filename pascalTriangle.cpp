#include<iostream>
using namespace std;
int fact(int n)
{
  int fac=1;
  if(n==0)
    return fac;
  else
    {
      while(n>0)
	{
	  fac=fac*n;
	  n--;
	}
      return fac;
    }
}
int main()
{
  int n,i,j;
  cin>>n;
  for(i=0;i<n;i++)
    {
      for(j=0;j<=i;j++)
	cout<<(fact(i)/(fact(j)*fact(i-j)))<<" ";
      cout<<endl;
    }
  return 0;
}
