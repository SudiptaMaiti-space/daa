#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
	clock_t start,end;
	double cpu_time;
	start=clock();
	int i, j, temp;
	int n;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	int *ar=(int *)malloc(n*sizeof(int));
	printf("Randomly generated array: ");
	for(i=0; i<n; i++)
	{
		ar[i]=(rand()%n)+1;
		printf("%d ",ar[i]);
	}
	int min;
	for(i=0;i<n-1;i++)
	{
	        min=i;
		for(j=1+i;j<n;j++)
		{
			if(ar[j]<ar[min])
			{
			min=j;
			}	
		}
		temp=ar[i];
		ar[i]=ar[min];
		ar[min]=temp;
	}
	printf("\nSorted array is: ");
	for(i=0; i<n; i++)
	{
		printf("%d ",ar[i]);
	}
	printf("\n");
	end=clock();
	cpu_time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("CPU time taken: %f sec \n",cpu_time);
	free(ar);
}

