#include<iostream>
using namespace std;
void merge(int a[],int low,int mid,int high)
{
  int b[100];
  int i = low;
  int j = mid+1;
  int k = 0;
  while(i<=mid && j<=high)
    {
      if(a[i] <= a[j])
	{
	  b[k]=a[i];
	  i++;
	  k++;
	}
      else
	{
	  b[k]=a[j];
	  j++;
	  k++;
	}
    }
  while(i<=mid)
    {
      b[k]=a[i];
      k++;
      i++;
    }
  while(j<=high)
    {
      b[k]=a[j];
      k++;
      j++;
    }
  for(i=low,j=0;i<=high;i++,j++)
    a[i]=b[j];
}
void merge_sort(int a[],int low,int high)
{
  int mid;
  if(low < high)
    {
      mid=(low+high)/2;
      merge_sort(a,low,mid);
      merge_sort(a,mid+1,high);
      merge(a,low,mid,high);
    }
}
int main()
{
  int a[]={3,1,4,2,9,7,5,6,0,8};
  merge_sort(a,0,9);
  for(int i=0;i<10;i++)
    cout<<a[i]<<endl;
  return 0;
}
