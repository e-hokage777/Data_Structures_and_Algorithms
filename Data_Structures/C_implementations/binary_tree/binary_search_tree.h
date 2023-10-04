#pragma once

#include <stdio.h>
#include <stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode * newBstNode(int data){
    struct BstNode* nodePtr = (struct BstNode*)malloc(sizeof(struct BstNode));
    nodePtr->data = data;
    nodePtr->left = NULL;
    nodePtr->right = NULL;

    return nodePtr;
}

void insertInBST(struct BstNode** rootPtr, int data){
    if(*rootPtr == NULL){
        *rootPtr = newBstNode(data);
    }
    else if(data <= (*rootPtr)->data){
        insertInBST(&(*rootPtr)->left, data);
    }
    else{
        insertInBST(&(*rootPtr)->right, data);
    }
}

// function to search for a value in the binary tree
int searchBST(struct BstNode* rootPtr, int data){
    if(rootPtr == NULL)
        return 0;
    if(rootPtr->data == data)
        return 1;
    else if(data < rootPtr->data)
        return searchBST(rootPtr->left, data);
    else{
        return searchBST(rootPtr->right, data);
    }
}

// function to find minimum value in the tree
int bstFindMin(struct BstNode *nodePtr){
    if(nodePtr == NULL){
        printf("Error: Empty tree");
        return NULL;
    }
    else if(nodePtr->left == NULL){
        return nodePtr->data;
    }
    
    return bstFindMin(nodePtr->left);
}

// function to find maximum value in the tree
int bstFindMax(struct BstNode *nodePtr){
    if(nodePtr == NULL){
        printf("Error: Empty tree");
        return NULL;
    }
    else if(nodePtr->right == NULL){
        return nodePtr->data;
    }
    
    return bstFindMax(nodePtr->right);
}