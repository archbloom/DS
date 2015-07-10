#include<iostream>
#include<stdio.h>
using namespace std;
int binary_search(int a[],int low,int high,int num)
{
  int pos,mid=(low+high)/2;
  if(num==a[mid])
    return mid;
  else if(low < high)
    {
      if(num < a[mid])
	pos = binary_search(a,low,mid,num);
      else 
	pos = binary_search(a,mid+1,high,num);
    }
  return pos;
}
int main()
{
  int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  int x;
  cin>>x;
  int pos = binary_search(a,0,15,x);
  cout<<"X:"<<pos<<endl;
  return 0;
}
