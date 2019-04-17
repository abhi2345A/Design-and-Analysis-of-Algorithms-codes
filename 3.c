#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Edge
{
	int src,dest,weight;
}Edge;

typedef struct Graph
{
	int v;
	int e;
	Edge* edge;
}Graph;

Graph* CreateGraph(int v,int e)
{
	Graph* graph=(Graph*)malloc(sizeof(Graph));
	graph->v = v;
	graph->e = e;
	graph->edge =(Edge*)malloc(e*sizeof(Edge));
	return graph;
}


void bellmanFord(Graph* graph,int src)
{
	int v=graph->v;
	int e=graph->e;
	int flag=0,i;
	
	int *dist = (int*)malloc(v*sizeof(int));
	for(int i=0;i<v;i++)
		dist[i] = INT_MAX;
	dist[src] = 0;
	
	for(i=1;i<=v-1;i++)
	{
		flag =0;
		for(int j=0;j<e;j++)
		{
			int src = graph->edge[j].src;
			int dest = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			
			if(dist[src]!=INT_MAX && dist[src]+weight < dist[dest])
			{
				dist[dest] = dist[src]+weight;
				flag=1;
			}
			
		}
		
		if(flag==0)
			break;
	}
	
	flag=0;
	if(i==v)
	{
		for(int j=0;j<e;j++)
		{
			int src = graph->edge[j].src;
			int dest = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			
			if(dist[src]!=INT_MAX && dist[src]+weight < dist[dest])
			{
				flag=1;
				break;
			}
			
		}
		
	}
	
	if(flag==1)
	{
		printf("\n Graph Contains a negative Cycle");
	}
	else if(flag==0)
	{
		printf("\nSource\tDestination\tDistance\n");
		for(int i=0;i<v;i++)
		{
			if(dist[i]!=INT_MAX)
			{
				printf("%d\t%d\t\t%d\n",src+1,i+1,dist[i]);
			}
			else
			{
				printf("%d\t%d\t\t-\n",src+1,i+1);
			}
		}
	}
	
	free(dist);
}



int main()
{
	int v,e,u,t,src;
	printf("\n Enter the no. of vertices:");
	scanf("%d",&v);
	while(v<2)
	{
		printf("\n No of vertices must be atleast 2:Enter again::");
		scanf("%d",&v);
	}
	printf("\n Enter the no. of edges:");
	scanf("%d",&e);
	while(e<0  && e>v*v-v)
	{
		printf("\n No of Edges must be +ve and Atmost %d:Enter Again::",v*v-v);
		scanf("%d",&e);
	}
	
	Graph* graph = CreateGraph(v,e);
	
	for(int i=0;i<e;)
	{
		int chk=0;
		printf("\n Enter the Source:");
		scanf("%d",&u);
		printf("\n Enter the Destination:");
		scanf("%d",&t);
		
		if(u>=1 && u<=v && t>=1 && t<=v && u!=t)
		{
			graph->edge[i].src = u-1;
			graph->edge[i].dest = t-1;
			
			for(int j=0;j<i;j++)
			{
				if(graph->edge[i].src==graph->edge[j].src && graph->edge[i].dest==graph->edge[j].dest)
					chk=1;
			}
			
			if(chk==1)
			{
				printf("\n Duplicate Edge found::Please Enter Again");
			}
			else
			{
				printf("\n Enter the weight:");
				scanf("%d",&graph->edge[i].weight);
				i++;
			}
		}
		else
		{
			printf("\n Invalid Vertices entered::Please Enter Again");
		}
	}
	printf("\n Enter the source vertex:");
	scanf("%d",&src);
	bellmanFord(graph,src-1);
	free(graph);
	return 0;
}

/*
Hahahah@Lol:~/Daa_prac$ ./a.out

 Enter the no. of vertices:4

 Enter the no. of edges:5

 Enter the Source:3

 Enter the Destination:2

 Enter the weight:-10

 Enter the Source:4

 Enter the Destination:3

 Enter the weight:3

 Enter the Source:1

 Enter the Destination:4

 Enter the weight:5

 Enter the Source:1

 Enter the Destination:2

 Enter the weight:4

 Enter the Source:2

 Enter the Destination:4

 Enter the weight:5

 Enter the source vertex:1

 Graph Contains a negative Cycle
 
 
 --------------------------------------------------------------------------
 
 Hahahah@Lol:~/Daa_prac$ ./a.out

 Enter the no. of vertices:4

 Enter the no. of edges:4

 Enter the Source:3

 Enter the Destination:2

 Enter the weight:-10

 Enter the Source:4

 Enter the Destination:3

 Enter the weight:3

 Enter the Source:1

 Enter the Destination:4

 Enter the weight:5

 Enter the Source:1

 Enter the Destination:2

 Enter the weight:4

 Enter the source vertex:1

Source	Destination	Distance
1	1		0
1	2		-2
1	3		8
1	4		5

 */
