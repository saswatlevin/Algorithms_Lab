
#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
 

int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h-1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
 

void quickSort(int A[], int l, int h)
{
    if (l < h)
    {     
       
        int p = partition(A, l, h); 
        quickSort(A, l, p - 1); 
        quickSort(A, p + 1, h);
    }
     
}
 

int main(){
     
   int i=0,arr[100],n;
   printf("\nEnter the size of the array");
   scanf("%d",&n);
   printf("\nEnter the array");
   
   for(i=0;i<n;++i)
     scanf("%d",&arr[i]);
     
    quickSort(arr, 0, n-1);
     
        for(int i = 0; i < n; i++){
            printf("%d",arr[i]);
            printf("\t");
    
}
     
    return 0;
}
                                                                                             stInsert(root, temp);
	}
	
	inorder(root);
    printf("\n");

    int height = 0, diameter = 0;
    height = bstDiameter(root, &diameter);

    printf("Height of tree is %d and Diameter is %d\n", height, diameter);
	return 0;
}
