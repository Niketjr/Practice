
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}node;
struct node* head = NULL;

void create(int A[], int n){
    struct node *t, *last;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = NULL;
    last = head;
    for(int i=1; i<n; i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void insert(int val, int pos){
    struct node *t = (struct node*)malloc(sizeof(struct node));
    struct node *t1 = head;
    t->data = val;
    t->next = NULL;
    if(pos==0){
        t->next = head;
        head = t;
        return;
    }
    
    for(int i=0;i<pos-1 && t1!=NULL ;i++){
        t1 = t1->next;
    }
    
    
    t->next = t1->next;
    t1->next = t;
    
}

void linsert(int val){
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = val;
    t->next = NULL;
    struct node* last = head;
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = t;
    
}

void delete(){
    
}

void display(struct node*p){
    struct node *t = p;
    while(t!=NULL){
        printf("%d ",t->data);
        t = t->next;
    }
}

int main()
{
    int A[] = {2,4,6,5,1,8};
    create(A,6);
    insert(7,4);
    linsert(0);
    display(head);
    return 0;
}
