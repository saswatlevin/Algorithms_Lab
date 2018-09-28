#include<stdio.h>
#include<string.h>

int adj[100][100],visited[100];
void modif(int i,int v)
{
for(int j=0;j<v;++j)
adj[i][j]=0;
}
int minn(int v)
{
int i,j,sum;
for(i=0;i<v;++i)
{
sum=0;
for(j=0;j<v;++j)
sum+=adj[j][i];
if(sum==0&&visited[i]==0)
{
printf("%d",i+1);
visited[i]=1;
modif(i,v);
}
}
}

void main()
{
int v,i,j;
printf("enter the no. of vertices\n");
scanf("%d",&v);
printf("enter the matrices");
for(i=0;i<v;++i)
for(j=0;j<v;++j)
scanf("%d",&adj[i][j]);
for(i=0;i<v;++i)
minn(v);
}
