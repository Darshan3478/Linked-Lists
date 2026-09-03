// Doubly Linked List - Deletion Operations
// You are using GCC

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};

void traverse(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){

    struct node *head=NULL,*tail=NULL,*temp,*newnode;
    int n;

    // Creation of DLL
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        newnode=(struct node*)malloc(sizeof(struct node));

        if(newnode==NULL){
            printf("Memory allocation failed\n");
            return 1;
        }

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


    // Deletion at beginning
    printf("Deletion at beginning: ");

    if(head==NULL){
        printf("List is empty\n");
    }
    else if(head==tail){
        free(head);
        head=tail=NULL;
        traverse(head);
    }
    else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        traverse(head);
    }


    // Deletion at end
    printf("Deletion at end: ");

    if(head==NULL){
        printf("List is empty\n");
    }
    else if(head==tail){
        free(head);
        head=tail=NULL;
        traverse(head);
    }
    else{
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
        traverse(head);
    }


    // Deletion at given position
    printf("Deletion at pos: ");

    int pos;
    scanf("%d",&pos);

    if(head==NULL){
        printf("List is empty\n");
    }
    else if(pos<=0){
        printf("Invalid position\n");
    }
    else if(pos==1){

        temp=head;

        if(head==tail){
            head=tail=NULL;
        }
        else{
            head=head->next;
            head->prev=NULL;
        }

        free(temp);
        traverse(head);
    }
    else{

        temp=head;

        for(int i=1;i<pos && temp!=NULL;i++){
            temp=temp->next;
        }

        if(temp==NULL){
            printf("Invalid position\n");
        }
        else if(temp==tail){

            tail=tail->prev;
            tail->next=NULL;
            free(temp);

            traverse(head);
        }
        else{

            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;

            free(temp);

            traverse(head);
        }
    }

    return 0;
}