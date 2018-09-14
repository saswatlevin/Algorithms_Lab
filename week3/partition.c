#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { NO, YES } BOOL;

BOOL isSubsetSum (int arr[], int n, int sum) 
{
	if (sum == 0)
		return YES;
	if (n == 0 && sum != 0)
		return NO;
	if (arr[n-1] > sum)
		return isSubsetSum (arr, n-1, sum);
   	return isSubsetSum (arr, n-1, sum) ||
			isSubsetSum (arr, n-1, sum-arr[n-1]);
}

BOOL findPartition (int arr[], int n) 
{       
	int sum = 0,opcount=0,i=0;
	for (i = 0; i < n; ++i)
	{	
            sum += arr[i];
	    ++opcount;
        }
         printf("\nOpcount= %d",opcount);
         if (sum % 2 != 0) 
		return NO;
   
   return isSubsetSum(arr, n, sum/2);

}

int main (int argc, const char * argv []) 
{
	int i,n,arr[10];
	    printf("\nEnter array size\t");
	    scanf("%d",&n);
        printf("\n Enter array");
        for(i=0;i<n;++i)
        {
          
          scanf("%d",&arr[i]);	
        }
		BOOL res = findPartition(arr, n);
	    if(res==YES)
	    {
	    printf("\nPartition made");
	    	
	    }
	    else
	    	printf("\nPartition not made");
	    return 0;

}
