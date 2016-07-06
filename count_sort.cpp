#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int count[255]={0};
  int n;
  cout<<"Enter number of elements to sort :";
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    count[a[i]]++;
  }
  cout<<"The sorted array is : \n";
  for(int i=0;i<255;i++)
  {
    for(int j=0;j<count[i];j++)
      cout<<i<<endl;
  }
  return 0;
}
