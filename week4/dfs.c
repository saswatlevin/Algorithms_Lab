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

#include<stdio.h>
#include<stdlib.h>
int a[100][100]={0},visited[100],k=0,pop[100];
int n,m;
void DFS(int i)
{
	printf("%d",i+1);
	visited[i]=1;
	for(int j=0;j<n;j++)
	    if(!visited[j]&&a[i][j]==1)
	          DFS(j);
	pop[k]=i+1;
	k++;
}
int main()
{
	int x,y;
	printf("enter the no of vertices\n");
	scanf("%d",&n);
	printf("enter the edges\n");
	scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
       scanf("%d  %d",&x,&y);
       a[x-1][y-1]=1;
    }
    printf("\nThe adjacency matrix is:\n");
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    	     printf("%d",a[i][j]);
    	}
    	printf("\n");
    }
   for(int i=0;i<n;i++)
   {
       visited[i]=0;
   }
   printf("push order\n");
   DFS(0);
   printf("\npop order\n");
   for(int i=0;i<k;i++)
   {
   	  printf("%d",pop[i]);
   }
   printf("\n");
}