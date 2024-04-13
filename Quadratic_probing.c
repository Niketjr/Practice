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
    int i=0;
    int index = (val)%size;
    while(H[(index+(i*i))%size]!=-1){
        i++;
    }
    H[(index+(i*i))%size] = val;
}

void search(int num){
    int key=num%size;
    if(H[key]==num){
        printf("%d is at %d\n",num,key);
    }
    else{
        int i=1;
        while(H[key]!=num){
            key=(key+i*i)%size;
            i++;
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
