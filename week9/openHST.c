#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linkedList.h"
int opcount=0; 
void displayHST(Node hst[])
{
    for(int i=0;i<13;i++)
    {
        display(hst[i]); 
    }
}
int hashFunction(char s[])
{
    int sum=0;
    for(int i=0;i<strlen(s);i++)
    {
        sum+=(s[i]-96); 

    }
    return sum%13;  
}
void createHST(Node hst[],int n )
{
    char s[256]; 
    char c; 
    printf("enter strings\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);

        hst[hashFunction(s)]=insertLast(hst[hashFunction(s)],s);

    }

}
int search(Node hst[],char key[])
{
    int i,j;
    i=hashFunction(key); 
    for(Node t=hst[i];t!=NULL;t=t->next)
    {
        opcount++; 
        if(strcmp(t->s,key)==0)
        {
            return i; 
        }

    }
    return -1; 
}
void main()
{
    int n; 
    printf("enter no. of strings\n");
    scanf("%d",&n);
    Node hst[13];
    for(int i=0;i<13;i++)
    {
        hst[i]=NULL; 
    }
    createHST(hst,n);
    printf("displaying hash table\n"); 
    displayHST(hst);     
    char k[256];
    scanf("%s",k);

    int x= search(hst,k); 
    if(x>-1)
       {
       printf("found with %d comparisons \n",opcount);

       }
       else
       printf("not found with %d comparisons \n",opcount);
}
