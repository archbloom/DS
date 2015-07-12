#include<stdio.h>
main()
{
	int n,i,j;
	printf("Enter number of elements to sort : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements to sort : \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i]<a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	printf("Sorted Elements : \n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}
/*
10
10
60
50
20
30
90
10
70
80
40
*/
