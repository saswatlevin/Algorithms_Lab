 //C program to Implement brute-force method of string matching
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
 int i,j,k,n,m,flag=0,opcount=0;
 char text[40],pattern[30];
 
 printf("Enter text: ");
 gets(text);
 printf("\nEnter pattern: ");
 gets(pattern);
 n=strlen(text);
 m=strlen(pattern);
 for(i=0;i<=n-m;i++)
 {
  j=0;
  ++opcount;
  while(j<m && pattern[j]==text[j+i])
   { 
     j++;
     if(j==m)
     {
      flag=1;
      k=i+1;
     }
     else
      flag=0;
   }
 }
 printf("\nOPcount=%d",opcount);
 if(flag==1)
    printf("\nPattern found at position: %d\n ",k);
 else
    printf("\nPattern not found in text \n");
 return 0; 
}

