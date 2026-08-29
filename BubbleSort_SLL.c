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
    printf("Original List: ");
    traverse(head);
    
    
    struct node *i,*j;
    for(i=head;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data > j->data){
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
    printf("Sorted List: ");
    traverse(head);
}