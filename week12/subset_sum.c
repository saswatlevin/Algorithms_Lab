#include<stdio.h>
#include<stdlib.h>

int sol_map[5]; 
void copy_arr(int n,int a[],int b[])
{
    for(int i=0;i<n;i++)
        b[i]=a[i]; 
}
void print_arr(int n,int a[])
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n"); 
}

void print_sol(int n,int a[])
{
    int i; 
    printf("{");
    for( i=0;i<n;i++)
    {
        if(sol_map[i])
            printf(" %d",a[i]); 
    }
    printf(" }\n"); 


}
int subset_sum(int n,int a[],int inc[],int sum,int k)
{
    if(k>n) return 0; 


    int t_sum=0;
    for(int i=0;i<k;i++)
    {
        if(inc[i])
            t_sum+=a[i]; 

    }
    if(t_sum>sum) return 0; 
    if(sum==t_sum)
    {
        copy_arr(n,inc,sol_map);
        printf("solution is \n");
        print_sol(n,a); 
        return 1; 
    }      
    if(k==n) return 0; 
    int copy_inc[n];
    copy_arr(n,inc,copy_inc);
    copy_inc[k]=0; 
    int with=0,without=0;
    //print_arr(n,copy_inc_with); 
    if(subset_sum(n,a,copy_inc,sum,++k))
    {
        without=1; 
    }
    k--; 
    int copy_inc_with[n];
    copy_arr(n,inc,copy_inc_with);

    copy_inc_with[k]=1;
    if(subset_sum(n,a,copy_inc_with,sum,++k))
    {
        with=1;
    }
    if(with || without) return 1; 
    else return 0; 
}

int main()
{
    int n=5;
    int a[]={1,2,5,6,8};
    int sum=9; 
    int inc[]={0,0,0,0,0}; 
    subset_sum(n,a,inc,sum,0); 
}
