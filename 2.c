#include<stdio.h>
#include<stdlib.h>

typedef struct job
{
	int id;
	char name[20];
	int sz;
	int rt;
}job;


void merge(int arr[],job ptr[],int l,int m,int r)
{
	int n1,n2,i,j,k;
	n1 = m-l+1,n2=r-m;
	int *L=(int*)malloc(n1*sizeof(int));
	int *R=(int*)malloc(n2*sizeof(int));
	for(i=0;i<n1;i++) L[i]=arr[l+i];
	for(i=0;i<n2;i++) R[i]=arr[m+1+i];
	i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(ptr[L[i]].sz <= ptr[R[j]].sz)
		{
			arr[k++] = L[i++];
		}
		
		else
		{
			arr[k++] = R[j++];
		}
	}
	
	while(i<n1)
	{
		arr[k++] = L[i++];
	}
	
	while(j<n2)
	{
		arr[k++] = R[j++];
	}
	
	free(L);
	free(R);
}
		

void merge_sort(int arr[],job ptr[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		merge_sort(arr,ptr,l,m);
		merge_sort(arr,ptr,m+1,r);
		merge(arr,ptr,l,m,r);
	}
}


int main()
{
	int T,n,i,j;
	printf("\n Enter the No. of tapes:");
	scanf("%d",&T);
	printf("\n Enter the No. of Jobs:");
	scanf("%d",&n);
	job *ptr =(job*)malloc(n*sizeof(job));
	for(i=0;i<n;i++)
	{
		printf("\n Enter Job size:");
		scanf("%d",&ptr[i].sz);
		while(ptr[i].sz<0)
		{
			printf("\n -ve Job size not acceptable:Enter Again::");
			scanf("%d",&ptr[i].sz);
		}
		ptr[i].id = i;
		printf("\n Enter Job name:");
		scanf("%s",ptr[i].name);
	}
	if(n<=T)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			printf("\n ID of Job stored on tape %d:%d\n",i+1,i+1);
			ptr[i].rt = ptr[i].sz;
			sum = sum + ptr[i].rt;
		}
		
		printf("\nJobId\tJobname\tJobsize\tRetrievalTime\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t%s\t%d\t%d\n",ptr[i].id+1,ptr[i].name,ptr[i].sz,ptr[i].rt);
		}
		
		printf("Average Retrieval Time is:%0.2f\n",(double)sum/n);
	}
	
	else
	{
		int *arr=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++) arr[i]=i;
		merge_sort(arr,ptr,0,n-1);
		int r,c,k=0,avrgrt=0;
		r = T;
		c = (n+T-1)/T;
		int *a=(int*)malloc(r*c*sizeof(int));
		for(i=0;i<c;i++)
		{
			for(j=0;j<r;j++)
			{
				if (k<=n)
				{
					a[j*c+i] = arr[k];
					k++;
					
					if(i==0)
					{
						ptr[a[j*c+i]].rt = ptr[a[j*c+i]].sz;
						avrgrt = avrgrt + ptr[a[j*c+i]].rt;
					}
					else
					{
						ptr[a[j*c+i]].rt = ptr[a[j*c+i]].sz + ptr[a[j*c+(i-1)]].rt;
						avrgrt = avrgrt + ptr[a[j*c+i]].rt;
					}
				}
				else
				 a[j*c+i] = -1;
			}
		}
		
		for(i=0;i<r;i++)
		{
			printf("\n ID of Job Stored on the tape:%d::",i+1);
			
			for(j=0;j<c;j++)
			{
				if(a[i*c+j]!=-1)
				{
					printf("%d	",a[i*c+j]+1);
				}
				else
				printf("-");
			}
		}
		
		printf("\nJobId\tJobname\tJobsize\tRetrievalTime\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t%s\t%d\t%d\n",ptr[i].id+1,ptr[i].name,ptr[i].sz,ptr[i].rt);
		}
		
		printf("Average Retrieval Time is:%0.2f\n",(double)avrgrt/n);
	free(a);
	free(arr);
	}
	
	
	free(ptr);
	return 0;
}

