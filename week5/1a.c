#include<stdio.h>
#include<string.h>

int p1=0,adj[100][100]={0},pop[100];
void dfs(int visited[],int start,int n)
{
if(visited[start])
return;
visited[start]=1;
int i=0;
for(i=0;i<n;i++)
{
if(adj[start][i]&&!visited[i]&&i!=start)
{
dfs(visited,i,n);
}
}
pop[p1++]=start;
return;
}

int main()
{
int m,n;
scanf("%d %d",&m,&n);
int i=0;
for(;i<m;++i)
{
int x,y;
scanf("%d %d",&x,&y);
adj[x-1][y-1]=1;
}
int visited[n];
memset(visited,0,n*sizeof(int));
dfs(visited,0,n);
for(i=n-1;i>=0;--i)
printf("%d",pop[i]+1);
}

