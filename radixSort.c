#include<stdio.h>
radix(int a[],int sz,int n)
{
	int box[10][10],count[10];
	int i,j,k,div,boxno;
	div=1;
	for(i=0;i<sz;i++)
	{
		for(j=0;j<10;j++)
			count[j]=0;
		for(j=0;j<n;j++)
		{
			boxno = (a[j]/div)%10;
			box[boxno][count[boxno]] = a[j];
			count[boxno]++;
		}
		j=0;
		for(boxno=0;boxno<10;boxno++)
			for(k=0;k<count[boxno];k++)
				a[j++] = box[boxno][k];
				div *= 10;
	}
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}
main()
{
	int max=0,n,count=0,i;
	printf("Enter number of elements to sort : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements to sort : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(max < a[i])
			max = a[i];
	}
	while(max!=0)
	{
		max/=10;
		++count;
	}
	radix(a,count,n);
}
