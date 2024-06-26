#include<stdio.h>
#include<stdlib.h>

#define size 7

int H[size];

void start(){
    for(int i=0; i<size; i++){
        H[i] = -1;
    }
}

void insert(int val){
    int index = val%size;
    int i = 0;
    while(H[index]!=-1){
        i++;
        index = (val+i)%size;
    }
    H[index] = val;
}

void search(int num){
    int key=num%size;
    if(H[key]==num){
        printf("%d is at %d\n",num,key);
    }
    else{
        while(H[key]!=num){
                key=(key+1)%size;
            }
            printf("%d is at index %d in HashTable\n",num,key);
    }
}

void display(){
    for(int i=0; i<size; i++){
        printf("%d\n",H[i]);
    }
}

void main(){
    start();
    insert(5);
    insert(24);
    insert(31);
    insert(42);
    insert(39);
    insert(70);
    insert(21);
    search(21);
    display();
}
