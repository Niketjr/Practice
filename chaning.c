#include<stdlib.h>
#include <stdio.h>

#define size 7

typedef struct Node{
    int val;
    struct Node* next;
}Node;

Node* H[size];

void createHash(){
    for(int i=0; i<size; i++){
        H[i] = NULL;
    }
}

void insert(int val){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = val;
    temp->next = NULL;
    
    int key = val % size;
    
    if(H[key] == NULL){
        H[key] = temp;
    }
    else{
        Node* t = H[key];
        while(t->next != NULL){
            t = t->next;
        }
        t->next = temp;
    }
}

void display(){
    for(int i=0; i<size; i++){
        Node* t = H[i];
        printf("H[%d]: ", i);
        while(t != NULL){
            printf("%d ", t->val);
            t = t->next;
        }
        printf("\n");
    }
}

int main()
{
    createHash();
    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);
    display();

    return 0;
}
