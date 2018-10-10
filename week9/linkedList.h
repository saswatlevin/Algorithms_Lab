#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int n;
    struct node* next; 
    char s[]; 
}; 

typedef struct node * Node;

Node createNodeWithString(char s[])
{
    Node temp=(Node)malloc(sizeof(struct node*));
    temp->data=0;
    temp->n=strlen(s);
    strcpy(temp->s,s);
    return temp; 
}

Node insertLast(Node head,char s[])
{
    if(head==NULL)
        {
            return createNodeWithString(s);

        }
    Node temp= head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=createNodeWithString(s);

    return head;
}
void display(Node node )
{
    while(node!=NULL)
    {
        
        printf("%s ",node->s);
        node=node->next; 
    }
    printf("\n");

    
}
