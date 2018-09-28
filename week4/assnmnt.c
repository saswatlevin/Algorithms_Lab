// Test cases used
// Case 1:

/* 
3
2500 4000 3500 
4000 6000 3500 
2000 4000 2500
Min cost is 9500 
Mapping of person to job is 
Person 0 to job 1 
Person 1 to job 2 
Person 2 to job 0 

*/

// Case 2:
/*
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
Min cost is 13 
Mapping of person to job is 
Person 0 to job 1 
Person 1 to job 0 
Person 2 to job 2 
Person 3 to job 3 
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cost[100][100];
int min = INT_MAX;
int min_array[10];
int opcount = 0;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArr(int a[],int n)
{
    for (int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
 
// Generating permutation using Heap Algorithm
void heapPermutation(int a[], int size, int n)
{
    // if size becomes 1 then print the obtained
    // permutation
    if (size == 1)
    {
        opcount++;
        int sum = 0;
        //printArr(a, n);
        for (int i = 0; i < n; ++i)
        {
            sum += cost[i][a[i]];
        }

        if(sum < min){
            min = sum;
        
            for (int i = 0; i < n; ++i)
            {
                min_array[i] = a[i];            //store this minimum array
            }
        }
        
        return;
    }
 
    for (int i = 0; i < size - 1; i++)
    {
        heapPermutation(a, size - 1, n);
 
        // if size is odd, swap first and last
        // element
        if (size % 2 != 0)
            swap(&a[0], &a[size-1]);
 
        // If size is even, swap ith and last
        // element
        else
            swap(&a[i], &a[size-1]);
    }

    heapPermutation(a, size - 1, n);
}


int main(int argc, char const *argv[])
{
    int n;

    printf("Enter number of person/jobs \n");
    scanf("%d", &n);

    printf("Enter the cost matrix \n");
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    int a[n];

    for (int i = 0; i < n; ++i)
    {
        a[i] = i;
    }

    heapPermutation(a, n, n);

    printf("Min cost is %d \n", min);

    printf("Mapping of person to job is \n");

    for (int i = 0; i < n; ++i)
    {
        printf("Person %d to job %d \n", i, min_array[i]);
    }

    printf("Opcount is %d \n", opcount);
    
    return 0;
}