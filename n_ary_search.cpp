#include<iostream>
#include<stdio.h>
using namespace std;
int n_ary_search(int a[],int low,int high,int num,int search)
{
  int pos,space=(low+high)/search;
  
  /*
  if(num==a[space])
    return space;
  else if(low < high)
    {
      if(num < a[space] && num > a[low])
	{
	  pos 
	}
      else 
	{
	  for(int i=;i<
	  //pos = n_ary_search(a,space+1,high,num,search);
	}
    }
  */
  return 1;
}
int main()
{
  int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  int x,n;
  cin>>x;
  cout<<"Enter likewise : for binary 2 ternary 3 and so on:";
  cin>>n;
  int pos =n_ary_search(a,0,15,x,n);
  cout<<"X:"<<pos<<endl;
  return 0;
}
