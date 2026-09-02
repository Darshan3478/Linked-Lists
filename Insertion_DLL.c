// Doubly Linked List - Insertion Operations

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
};

void traverse(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){

    struct node *head=NULL,*newnode,*temp,*tail=NULL;
    int n;

    // Creation of DLL
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);

        newnode->next=NULL;
        newnode->prev=NULL;

        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }

    traverse(head);


    // Insertion at beginning
    printf("Insertion at beginning: ");

    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);

    newnode->prev=NULL;
    newnode->next=head;

    if(head!=NULL)
        head->prev=newnode;
    else
        tail=newnode;

    head=newnode;

    traverse(head);


    // Insertion at end
    printf("Insertion at end: ");

    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);

    newnode->next=NULL;
    newnode->prev=tail;

    if(tail!=NULL)
        tail->next=newnode;
    else
        head=newnode;

    tail=newnode;

    traverse(head);


    // Insertion at given position
    printf("Insertion at pos: ");

    int pos;
    scanf("%d",&pos);

    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);

    if(pos==1){

        newnode->prev=NULL;
        newnode->next=head;

        if(head!=NULL)
            head->prev=newnode;
        else
            tail=newnode;

        head=newnode;
    }
    else{

        temp=head;

        for(int i=1;i<pos-1 && temp!=NULL;i++){
            temp=temp->next;
        }

        if(temp==NULL){
            printf("Invalid position\n");
            free(newnode);
            return 0;
        }

        newnode->next=temp->next;
        newnode->prev=temp;

        if(temp->next!=NULL)
            temp->next->prev=newnode;
        else
            tail=newnode;

        temp->next=newnode;
    }

    traverse(head);

    return 0;
}