#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void traverse(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    struct node *newnode,*head=NULL,*temp,*prev;
    int n;
    scanf("%d",&n);

    // Creation without reversing
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
            head=temp=newnode;
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }

    traverse(head);

    // Deletion at beginning
    printf("Deletion at beginning: ");
    if(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
    traverse(head);

    // Deletion at end
    printf("Deletion at end: ");
    if(head!=NULL){
        if(head->next==NULL){
            free(head);
            head=NULL;
        }else{
            temp=head;
            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            free(temp);
        }
    }
    traverse(head);

    // Deletion at position
    printf("Deletion at pos: ");
    int pos;
    scanf("%d",&pos);

    if(pos<1){
        printf("Invalid position\n");
    }
    else if(pos==1 && head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
        traverse(head);
    }
    else{
        temp=head;

        for(int i=1;i<pos && temp!=NULL;i++){
            prev=temp;
            temp=temp->next;
        }

        if(temp==NULL)
            printf("Invalid position\n");
        else{
            prev->next=temp->next;
            free(temp);
            traverse(head);
        }
    }
}