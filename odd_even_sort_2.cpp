#include<bits/stdc++.h>
using namespace std;
void oesort(int a[],int n){
  for(int i=1;i<=n;i++){
    for(int j=i%2;j<n-1;j+=2){
      if(a[j]>a[j+1])
        swap(a[j],a[j+1]);
    }
  }
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<endl;
}
int main(){
  int n;
  cout<<"Enter number of elements to sort: ";
  cin>>n;
  int a[n];
  cout<<"Enter "<<n<<" elemets:\n";
  for(int i=0;i<n;i++)
    cin>>a[i];
  oesort(a,n);
  return 0;
}
