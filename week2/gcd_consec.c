#include <stdio.h>
#define SIZE 1000




void consec_check_1(int num1,int num2)
{

    int i=0,j=0;
    int arr1[SIZE]=0;
    int large_prime1=0;

  printf("\nBefore num1 loop");
  for(i=1;i<num1;++i)
  {
   
    arr1[i]=(int)(num1/i);
    
  
  }

  printf("\nBefore num2 loop");
  for(j=1;j<num2;++j)
  {
    arr2[i]=(int)(num2/i);
    
  }

  printf("\nArray 1:\t");

  for(i=1;i<(num1);++i)
  {
    printf("%d",arr1[i]);
    printf("\t");
  }
  
  printf("\nArray 2:\t");

  for(j=2;j<(num2);j++)
  {
  	printf("%d",arr2[i]);
  	printf("\t");
  }
return arr1;
}	


void prime_check(int num1,int num2,int arr1[SIZE],int arr2[SIZE])
{

int prime_arr1[100]=0,prime_arr2[100]=0,i=0,j=0;

int flag=0;

for(i=2,j=2;i<num1,j<num2;++i,++j)
 {
   if((arr1[i]%2==0)||(arr2[j]%2==0))
    continue;
    

   prime_arr1[i]=arr1[i];
   prime_arr2[j]=arr2[j];
     

   
}	

  printf("\nPrime_Array 1:\t");

  for(i=0;i<(num1+1);++i)
  {
    printf("%d",prime_arr1[i]);
    printf("\t");
  }
  

 

 printf("\nPrime_Array 2:\t");

  for(j=0;j<(num2+1);j++)
  {
  	printf("%d",prime_arr2[i]);
  	printf("\t");



}

}

void main()
{
int num1=0,num2=0;

printf("\nEnter first number");
scanf("%d",&num1);

printf("\nEnter 2nd number");
scanf("%d",&num2);

consec_check(num1,num2);
prime_check(num1,num2,)

}