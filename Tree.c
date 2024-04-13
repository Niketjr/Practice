#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree* left;
    struct tree* right;
}*tree;
tree* root = NULL;

tree* insert(tree* t, int val){
    if(t==NULL){
        tree* pt = (tree*)malloc(sizeof(tree));
        pt->data = val;
        pt->left = NULL;
        pt->right = NULL;
        return pt;
    }
    else{
        if(t->data > val){
            t->left = insert(t->left, val);
        }
        else if(t->data < val){
            t->right = insert(t->right, val);
        }
    }
    return t;
}

void inorder(tree* t){
    if(t!=NULL){
        inorder(t->left);
        printf("%d ",t->data);
        inorder(t->right);
    }
    else{
        return;
    }
}

void preorder(tree* t){
    if(t!=NULL){
        printf("%d ",t->data);
        preorder(t->left);
        preorder(t->right);
    }
    else{
        return;
    }
}

void postorder(tree* t){
    if(t!=NULL){
        preorder(t->left);
        preorder(t->right);
        printf("%d ",t->data);
    }
    else{
        return;
    }
}

tree* search(tree* t, int key){
    if(t==NULL){
        return NULL;
    }
    else{
        if(t->data == key){
            return t->data;
        }
        else if(t->data<key){
            return search(t->left, key);
        }
        else{
            return search(t->right, key);
        }
    }
}

tree* delete(tree* t, int val){
    if(t==NULL){
        return NULL;
    }
    else if(t->data>val){
        t->left = delete(t->left, val);
    }
    else if(t->data < val){
        t->right = delete(t->right, val);
    }
    else{
        if(t->left == NULL && t->right == NULL){
            free(t);
            t = NULL;
        }
        else if(t->left == NULL){
            tree* t2 = t;
            t = t->right;
            free(t2);
        }
        else{
            tree* t2 = t->right;
            while(t2->left!=NULL){
                t2 = t2->left;
            }
            t->data = t2->data;
            t->right = delete(t->right, t2->data);
        }
    }
    return t;
}

void main(){
    
}
