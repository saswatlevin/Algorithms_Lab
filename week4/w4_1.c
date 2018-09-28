#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort[100][100];
int min=INT_MAX;
int min_arr[10];
int fcount=0;

void swap(int &x,int &y)
{
int temp=x;
*x=*y;
*y=temp;
}

void first_arr(int a[],int n)
{
int i;
for(i=0;i<n;++i)
printf("%d",a[i]);

printf("\n");
}

void heapformation(int a[],int size,int n)
{
if(size==1)
{
++opcount;
int sum=0;
}

for(int i=0;i<n;++i)
sum+=core[i][a[i]];
if(sum<min)
min=sum;
for(int i=0;i<n;++i)
min_array[i]=a[i];
return ;
}

for(int i=0;i<size-1;++i)
{
heap_formation(0,size-1,n);

if(size%2!=0)
swap(&a[0],&a[size-1]);

else
swap(&a[i],&a[size-1]);
}

heapformation(a,size-1,n);

int main()
{

int a;
printf("\nEnter no. of elements");

for(int i=0;i<n;++i)
{
for(int j=0;j<n;++j)
{
scanf("%d",&sor[i][j]);
}
}

int a[n];

for(i=0;i<n;++i)
a[i]=i;

heapformation(a,n,n);
printf("\nsupply of pairs="%d,min_avg[i]);
return 0;
}

 


