#include<stdio.h>
#include<stdlib.h>

typedef struct MinMax
{
	int min;
	int max;
}Mnxm;

Mnxm getMinMax(int *,int,int);

int main()
{
	int *arr,n,i;
	Mnxm final;
	printf("\n Enter the No. of elements:");
	scanf("%d",&n);
	arr =(int*)malloc(n*sizeof(int));
	printf("\n Enter Array Elements:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	final = getMinMax(arr,0,n-1);
	printf("\n Minimum Element in the array is:%d\n",final.min);
	printf("\n Maximum Element in the array is:%d\n",final.max);
	free(arr);
	return 0;
}


Mnxm getMinMax(int *arr,int low,int high)
{
	Mnxm L,R;
	int mid;
	
	if(low==high)
	{
		L.min = arr[low];
		L.max = arr[low];
		return L;
	}
	
	else if(high==low+1)
	{
		if(arr[low]<arr[high])
		{
			L.min = arr[low];
			L.max = arr[high];
		}
		else
		{
			L.min = arr[high];
			L.max = arr[low];
		}
		
		return L;
	}
	
	mid = (low+high)/2;
	
	L = getMinMax(arr,low,mid);
	R = getMinMax(arr,mid+1,high);
	L.min =L.min<R.min?L.min:R.min;
	L.max =L.max>R.max?L.max:R.max;
	return L;
}
