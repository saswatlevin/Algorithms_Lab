#include<stdio.h>
#include <stdlib.h> 
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
 int count=0;
node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    
    if(x==-1)
        return NULL;
    
    p=(node*)malloc(sizeof(node));
    p->data=x;
    
    printf("Enter left child of %d:\n",x);
    p->left=create();
 
    printf("Enter right child of %d:\n",x);
    p->right=create();
    
    return p;
}
 
void inorder(node *t)
{   
    if(t!=NULL)
    {
        ++count;        
        inorder(t->left);        
        printf("\n%d",t->data);
        inorder(t->right);        
    }
}
 
int main()
{    
    node *root;
    root=create();
    printf("\nThe inorder traversal of tree is:\n");
    inorder(root);
    printf("\nOpcount=%d\t",count);
    return 0;
}