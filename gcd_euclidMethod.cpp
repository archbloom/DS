#include<stdio.h>
#include<iostream>
using namespace std;
long long int getn(){
  long long int n=0, c=getchar_unlocked();
  while(c < '0' || c > '9')  c = getchar_unlocked();
  while(c >= '0' && c <= '9')    n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
  return n;
}
int gcd(int a,int b)
{
  int c;
  if(b==0)
    return a;
  else
    while(b!= 0)
      {
				c=b;
				b=a%b;
				a=c;
      }
  return a;
}
int main()
{
  long long int t=getn(),n,q,i,j,l,r,gc;
  while(t--)
    {
      n=getn();
      q=getn();
      long long int a[n];
      //for(i=0;i<n;i++)
      //a=gcd(a,b[i]);
      //cout<<a<<endl;
      for(i=0;i<n;i++)
	a[i]=getn();
      for(i=0;i<q;i++)
	{
	  l=getn();l--; 
	  r=getn();r--;
	  if(l==0) gc=a[r+1];
	  else gc=a[0];
	  for(j=0;j<n;j++)
	    {
	      if(j<l || j>r)
		gc=gcd(gc,a[j]); 
	    }
	  printf("%lld\n",gc);
	}
    }
  return 0;
}
