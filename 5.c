#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int IsValidPosition(int *x,int n)
{
	for(int j=0;j<n;j++)
	{
		if(abs(x[j]-x[n])==abs(j-n) || x[j]==x[n])
			return 0;
	}
	
	return 1;
}


void PrintChess(int *x,int n)
{
	int i,j;
	
	for(i=0;i<n;i++)
		printf(" _");
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		printf("|");
		
		for(j=0;j<n;j++)
		{
			if(x[i]==j)
				printf("Q");
			else
				printf("_");
			printf("|");
		}
			printf("\n");
	}
		printf("\n");
}


int GetMaxSols()
{
	int s;
	printf("\n Enter no. of solutions you want:");
	scanf("%d",&s);
	if(s<0)
	s = INT_MAX;
	return s;
}


int Iterative_NQueen(int *x,int n,int max_sol)
{
	int r=0,n_sol=0;
	
	for(int i=0;i<n;i++)	x[i]=-1;
	
	while(r!=-1)
	{
		x[r]++;
		
		if(x[r]<n)
		{
			if(IsValidPosition(x,r))
			{
				if(r==n-1)
				{
					if(max_sol>n_sol)
					{
						printf("Solution:%d\n",n_sol+1);
						PrintChess(x,n);
						n_sol++;
					}
					else
					{
						return n_sol;
					}
					
				}
				else
				{
					r++;
				}
			}
		}
		
		else
		{
			x[r]=-1;
			r--;
		}
	}
	
	return n_sol;
}
		

void Recursive_NQueen(int *x,int i,int n,int *n_sol,int *max_sol)
{
	if (i>=n)	return;
	
	for(int k=0;k<n;k++)
	{
		if(*n_sol>=max_sol)	return;
		x[i] = k;
		
		if(IsValidPosition(x,i))
		{
			if(i==n-1)
			{
				PrintChess(x,n);
				(*n_sol)++;
				return;
			}
			else
			{
				Recursive_NQueen(x,i+1,n,n_sol,max_sol);
			}
		}
	}
	
	return;
}








int main()
{
	int ch,kk=0,n,*x;
	printf("\n N-Queen Problem Using Back-Tracking\n");
	do
	{
		printf("\n Press 1 to Use Iterative sol:");
		printf("\n Press 2 to Use Recursive sol:");
		printf("\n Press Any Other Key to Exit:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: do
					{
						printf("\n Enter the No of Queens(Should be Atleast 4):");
						scanf("%d",&n);
					}while(n<4);
				
					int max_sol,n_sol;
					x = (int*)malloc(n*sizeof(int));
					max_sol = GetMaxSols();
					n_sol = Iterative_NQueen(x,n,max_sol);
					printf("\n No. of Solutions::%d\n",n_sol);
					free(x);
					break;
				
			case 2: do
					{
						printf("\n Enter the No of Queens(Should be Atleast 4):");
						scanf("%d",&n);
					}while(n<4);
				
					int max_soll,n_soll=0;
					x = (int*)malloc(n*sizeof(int));
					max_soll = GetMaxSols();
					Recursive_NQueen(x,0,n,&n_soll,max_soll);
					printf("\n No. of Solutions::%d\n",n_soll);
					free(x);
					break;
				
			default: exit(0);
			
		}
		
		printf("\n Do You want to Continue?(1/0):");
		scanf("%d",&kk);
	}while(kk==1);

	return 0;
}
