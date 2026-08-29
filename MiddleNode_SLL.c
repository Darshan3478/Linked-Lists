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
    struct node *head=NULL,*newnode,*temp;
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
    
    struct node *slow=head,*fast=head;
    while(fast!=NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("Middle element: %d",slow->data);
}















