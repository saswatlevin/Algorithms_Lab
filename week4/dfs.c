// Test case used
/* 10 vertices

0 3
3 0
0 2
2 0
2 3
3 2
0 4
4 0
2 5
5 2
5 4
4 5
5 1
1 5
4 1
1 4
6 7
7 6
7 8
8 7
8 9
9 8
6 9
9 6
-1 -1

Answer : 
Pushed = 0 2 3 5 1 4 6 7 8 9 
Popped = 3 4 1 5 2 0 9 8 7 6

*/

#include <stdio.h>
#include <stdlib.h>

int a[100][100];			//adjacency matrix
int popped[100];
int k = 0;					//index for popped array

void dfs(int n, int* visited, int i){

	//mark this vertex as visited and print it
	visited[i] = 1;				
	printf("%d ", i);

	for (int j = 0; j < n; ++j)				// check all vertices adjacent to i
	{
		if(!visited[j] && a[i][j] == 1){
			dfs(n,visited,j);
		}
	}

	// after DFS for all adjacent vertices of i
	// is complete (i.e, end of dfs function) 
	// then it is popped from the stack
	popped[k++] = i;			
}


int main(int argc, char const *argv[])
{

	int src,dest;

	int n;
	
	printf("Enter number of vertices\n");
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = 0;
		}
	}

	
	printf("Enter 2 vertices (-1 -1 to break) \n");
	
	while(1){
		scanf("%d %d", &src, &dest);
		
		if(src == -1 && dest == -1)
			break;
		
		a[src][dest] = 1;

	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ", a[i][j]);
		}

		printf("\n");
	}

	int visited[n];			

	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}

	printf("Pushed order is \n");

	for (int i = 0; i < n; ++i)
	{
		if(!visited[i])
			dfs(n,visited,i);		//call dfs for every vertex in graph
	}

	printf("\nPopped order is \n");

	for (int i = 0; i < k; ++i)
	{
		printf("%d ", popped[i]);
	}

	
	return 0;
}