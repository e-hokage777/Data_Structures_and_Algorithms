#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "./bst_node_queue.h"

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

int maxInt(int a, int b){
    if(a > b)
        return a;
    return b;
}

int bstHeight(struct BstNode *nodePtr){
    if(nodePtr == NULL)
        return -1;

    return(maxInt(bstHeight(nodePtr->left), bstHeight(nodePtr->right)) + 1);
}


// Breadth First Search
void bstBfs(struct BstNode * root){
    struct BST_NODE_QUEUE queue;
    queue.front = -1;
    queue.rear = -1;

    // checking if bst is empty
    if(root == NULL) return;

    enqueue(&queue, root);

    printf("Traversing: ");
    while(!isEmpty(queue)){
        struct BstNode *current = dequeue(&queue);
        printf("%d ", current->data);

        // pushing children into the queue
        if(current->left != NULL)
            enqueue(&queue, current->left);
        if(current->right != NULL)
            enqueue(&queue, current->right);
    }

    printf("\n");
}

// Depth First Search (Preorder traversal)
void bstDfsPre(struct BstNode *root){
    if(root == NULL) return;

    printf("%d ", root->data);

    // calling function for left tree
    bstDfsPre(root->left);
    // calling function for right subtree
    bstDfsPre(root->right);
}

// Depth First Search (Inorder traversal)
void bstDfsIn(struct BstNode *root){
    if(root == NULL) return;

    // calling function for left tree
    bstDfsIn(root->left);

    printf("%d ", root->data);

    // calling function for right subtree
    bstDfsIn(root->right);
}

// Depth First Search (Inorder traversal)
void bstDfsPost(struct BstNode *root){
    if(root == NULL) return;

    // calling function for left tree
    bstDfsPost(root->left);

    // calling function for right subtree
    bstDfsPost(root->right);

    printf("%d ", root->data);
}