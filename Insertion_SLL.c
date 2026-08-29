// You are using GCC
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void traverse(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
int main(){
    struct  node *head=NULL,*newnode,*temp;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    traverse(head);
    printf("Insertion at beginning: ");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    traverse(head);
    
    printf("Insertion at end: ");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    traverse(head);
    
    int pos;
    scanf("%d",&pos);
    printf("Insertion at pos %d: ",pos);
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    if(pos==1){
        newnode->next=head;
        head=newnode;
    }else if(pos>n || pos<0){
        printf("Invalid position.");
    }else{
        temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    traverse(head);
}










































