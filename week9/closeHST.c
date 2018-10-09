#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linkedList.h"
int cmpcount=0; 
void displayHST(Node hst[])
{
    for(int i=0;i<13;i++)
    {
        printf("%d : ",i);
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
        //     gets(s);
        scanf("%s",s);

        //   hst[hashFunction(s)]=insertLast(hst[hashFunction(s)],s);
        int j=hashFunction(s);

        while(hst[j]!=NULL)
        {
            j=(j+1)%13;
            if(j==hashFunction(s))
            {
                printf("overflow error\n");
                exit(1); 
            }

        }
        hst[j]=createNodeWithString(s);
    }

}
int search(Node hst[],char key[])
{
    int i,j;

    j=hashFunction(key);
    i=j; 
    while(hst[j]!=NULL)
    {
        cmpcount++; 
        if(strcmp(hst[j]->s,key)==0)
        {
            return i; 
        }
        j=(j+1)%13; 
        if(i==j) break; 
    }
    return -1; 
}
void main()
{
    /*
       Node head=NULL;
       head=insertLast(head,"LUG");
       head=insertLast(head,"&");
       head=insertLast(head,"MIST");
       head=insertLast(head,">");
       head=insertLast(head,"IECSE");
       */ 
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
       printf("enter search key\n");

       scanf("%s",k);

       int x= search(hst,k); 
       if(x>-1)
       {
       printf("found with %d comparisons \n",cmpcount);

       }
       else
       printf("not found with %d comparisons \n",cmpcount); 
}
