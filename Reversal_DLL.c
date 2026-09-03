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
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    printf("Original List: ");
    traverse(head);
    
    struct node *curr=head;
    while(curr!=NULL){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        
        curr=curr->prev;
    }
    temp=head;
    head=tail;
    tail=temp;
    
    printf("Reversed List: ");
    traverse(head);
}



























