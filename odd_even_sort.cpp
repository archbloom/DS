#include<bits/stdc++.h>
#include<omp.h>
void index_oesort(int a[],int n)
{
  for(int i=0;i<n;i++)
  {
    if(i&1)
    {
      #pragma omp parallel
      for(int j=3;j<n;j+=2)
      {
        if(a[j]<a[j-2])
        {
          std::swap(a[j],a[j-2]);
        }
      }
      #pragma omp parallel
      for(int j=2;j<n;j+=2)
      {
        if(a[j]<a[j-2])
        {
          std::swap(a[j],a[j-2]);
        }
      }
    }
  }
  for(int i=0;i<n;i++)
    printf("%d\n",a[i]);
}
int main()
{
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)
  {
    printf("\nNum :");
    scanf("%d",&a[i]);
  }
  index_oesort(a,n);
  //num_oesort(a,n);
  return 0;
}
