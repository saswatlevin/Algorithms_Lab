#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 1000

int count=0;
void swap(int *xi,int *xj){

int temp=0;
temp=*xi;
*xi=*xj;
*xj=temp;
++count;

}

void bubble_sort(int size,int A[MAX_CAPACITY]){
 int i=0,j=0,count=0;
 for(i=0;i<size-1;++i){
  
  for(j=0;j<size-i-1;++j){
      ++count;
      if(A[j]>A[j+1]){
      
      swap(&A[j],&A[j+1]);  
    
    }
      
  }

    }

}


void list_input(int size,int A[MAX_CAPACITY])
{
  int i=0;
  for(i=0;i<size;++i)
  {
    printf("\nEnter element %d\t",i+1);
    scanf("%d",&A[i]);
  } 
}

void print_sorted(int A[MAX_CAPACITY],int size)
{
   int i=0;
   if(size>MAX_CAPACITY)
   {
    printf("\nList Size exceeding Maximum Capacity.Exiting...");
        exit(1);
   }
   
   for(i=0;i<size;++i)
   {
      
      printf("%d\t",A[i]);
   }

}

int main(int argc,const char *argv[])
{
  int i=0,j=0,size=0,A[MAX_CAPACITY];
  printf("\nEnter the size of the list\t");
  scanf("%d",&size);
  list_input(size,A);
  bubble_sort(size,A);
  print_sorted(A,size);
  printf("\nNumber of times swap occurred is= %d\n",count);
  printf("\nNumber of comparisons=%d",count);
  return 0;
  
}
