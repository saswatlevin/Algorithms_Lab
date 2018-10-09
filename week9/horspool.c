#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int opcount=0; 
void displayString(char s[])
{
    for(int i=0;i<strlen(s);i++)
    {
        printf("%c",s[i]);

    }
    printf("\n"); 
}
void displayInt(int a[],int n)
{
    for(int i=0;i<n; i++)
    {
        printf("%d",a[i]);

    }
    printf("\n"); 
}

void genST(int n,int sh[],char p[])
{
    int i,j;
    for(i=0;i<26;i++)
        sh[i]=strlen(p);
    for(j=0;j<strlen(p)-1;j++)
    {
        sh[p[j]-97]=strlen(p)-1-j;

    }
}

int horspool(char s[],char p[],int sh[])
{
    int i,j,k;
    int n=strlen(s);
    int m=strlen(p);

    i=m-1;
    while(i<n)
    {
        k=0;
        while(k<m &&p[m-1-k]==s[i-k])
        {
            opcount++;
            k++; 
        }
        if(k==m)
            return i-m+1;
        else 
            i=i+sh[s[i]-97];

    }
    return -1; 
}

void main()
{
    char s[]="bess knew about baobab";
    char p[]="baobab"; 
    int sh[26]; 
    genST(26,sh,p);
    displayInt(sh,26); 
    int x=horspool(s,p,sh);
    if(x==-1)
        printf("not found\n");
    else
        printf("found at pos %d\n",x); 


    printf("opcount is  %d\n",opcount); 

}
