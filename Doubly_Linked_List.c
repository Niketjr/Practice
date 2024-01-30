#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
Node* head = NULL;

void create(int A[], int n){
    Node* last, *t;
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head->prev = NULL;
    head->data = A[0];
    last = head;
    for(int i=1; i<n;i++){
        t = (Node*)malloc(sizeof(Node));
        t->next = last->next;
        t->data = A[i];
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void insert(int val, int pos){
    Node* p = head;
    Node* t = (Node*)malloc(sizeof(Node));
    if(pos==0){
        t->data = val;
        t->next = head;
        t->prev = NULL;
        head = t;
    }
    else{
        for(int i=0; i<pos-1; i++){
            p = p->next;
        }
        t->data = val;
        t->next = p->next;
        t->prev = p;
        p->next = t;
    }
}

void delete(int pos){
    Node* p = head;
    Node* q = (Node*)malloc(sizeof(Node));
    for(int i=0; i<pos-1; i++){
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    q->next->prev = p;
    q->prev = NULL;
    q->next = NULL;
    free(q);
}

void reverse(Node* p){
    Node* t;
    while(p){
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if(p!=NULL && p->next == NULL){
            head = p;
        }
    }
}
void display(){
    Node* p = head;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    int A[]={1,2,3,4,5,6};
    create(A,6);
    insert(4,3);
    delete(3);
    display();
    reverse(head);
    display();
    return 0;
}
