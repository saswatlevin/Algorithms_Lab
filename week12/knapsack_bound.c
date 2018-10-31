#include<stdio.h>
#include<stdlib.h>
int n;
int cap; 
int wt[100]; 
int val[100]; 
int wt_by_val[100]; 
int sol_map[100]={0,0,0,0}; 
int inc[100]={0,0,0,0}; 

int best_bound=0; 
int best_val=0; 
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
    for( i=0;i<n;i++)
    {
        if(sol_map[i])
            printf("item with value= %d\n",a[i]); 
    }


}


int knapsack(int n,int inc[],int k)
{
    if(k==n)
    {
        printf("solution includes \n"); 
        copy_arr(n,inc,sol_map); 
        print_sol(n,val); 
        printf("best value is %d\n",best_val); 

    }

    //calculating include values and upper bound
    int val1=0;
    int wt1=0; 
    int inc_with[n];
    copy_arr(n,inc,inc_with);
    inc_with[k]=1; 
    for(int i=0;i<=k;i++)
    {
        if(inc_with[i])
        {
            val1+=val[i]; 
            wt1+=wt[i]; 

        }
    }
    int ub1=val1+(cap-wt1)*wt_by_val[k+1];

    //calculating non-include values and upper bound
    int val2=0;
    int wt2=0; 
    int inc_without[n];
    copy_arr(n,inc,inc_without);
    inc_without[k]=0; 
    for(int i=0;i<=k;i++)
    {
        if(inc_without[i])
        {
            val2+=val[i]; 
            wt2+=wt[i]; 
        }
    }
    int ub2=val2+(cap-wt2)*wt_by_val[k+1];

    if(val1>val2 && wt1<cap)
        if(val1>best_val) best_val=val1; 
    else
        if(val2>best_val) best_val=val2; 
        
    if(wt1<cap)
    {
        if(ub1>ub2)
            knapsack(n,inc_with,k+1); 
            
    }
    else
    {
        knapsack(n,inc_without,k+1); 
    }

    if(wt2<cap) return 0; 
    
    

}

int main()
{
    printf("enter no. of elements  \n");
    scanf("%d",&n); 
    printf("enter items weight value and weight/value (in descending order of weight/value)\n"); 
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&wt[i],&val[i],&wt_by_val[i]); 
        sol_map[i]=0; 
        inc[i]=0; 
    }
    printf("enter capacity\n"); 
    scanf("%d",&cap); 
    
    knapsack(n,inc,0); 
}
