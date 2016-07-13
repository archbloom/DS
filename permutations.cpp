//All the permutations of a string 

#include "stdio.h"
#include <iostream>
#include <string.h>

using namespace std;

void swap(char *x ,char *y)
{
	char temp = *x;
	*x=*y;
	*y=temp;
}

void permute(char *a,int l,int r)
{
	if(l==r)
		cout<<a<<endl;
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(a+l,a+i);
			permute(a,l+1,r);
			swap(a+l,a+i);
		}
	}
}

int main()
{
	char str[]="bhus";
	int len=strlen(str);
	permute(str,0,len-1);
	return 0;
}


