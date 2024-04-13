#include <stdio.h>
#include <stdlib.h>

#define size 7

int H[size];

void start(){
    for(int i=0; i<size; i++){
        H[i] = -1;
    }
}

void hash(int key){
    int i = 0;
    int h1 = (key % size + i*(5-key % 5))% size;
    
    while(H[h1]!=-1){
        i++;
        h1 = (key % size + i*(5-key % 5))% size;
    }
    H[h1] = key;
}

void search(int key){
    int i = 0;
    int h1 = (key % size + i*(5-key % 5))% size;
    while(H[h1] != key && H[h1] != -1){
        i++;
        h1 = (key % size + i*(5-key % 5))% size;
    }
    if(H[h1] == key){
        printf("%d found at %d\n",key,h1);
    }
    else{
        printf("%d not found\n",key);
    }
}

void main()
{
    start();
    hash(12);
    hash(22);
    hash(32);
    hash(42);
    hash(2);
    hash(72);
    hash(92);
    search(2);
    for(int i=0; i<size; i++){
        printf("%d ",H[i]);
    }
}
