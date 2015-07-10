#include<bits/stdc++.h>
using namespace std;
int a[11];
void upAdjust(int i)
{

	while(i > 1 && a[i] < a[i/2])
	{
		swap(a[i],a[i/2]);
		i=i/2;
	}
}
int main()
{
	a[0]=0;
	cout<<"Enter 10 number for min heap : \n";
	for(int i=1;i<11;i++)
	{
		cin>>a[i];
		a[0]++;
		upAdjust(a[0]);
	}
	cout<<"Containts of min heap : \n";
	for(int i=0;i<11;i++)
	{
		cout<<i<<" "<<a[i]<<endl;
	}
	return 0;
