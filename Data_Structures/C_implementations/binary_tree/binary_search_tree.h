#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./bst_node_queue.h"

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct BstNode *newBstNode(int data)
{
    struct BstNode *nodePtr = (struct BstNode *)malloc(sizeof(struct BstNode));
    nodePtr->data = data;
    nodePtr->left = NULL;
    nodePtr->right = NULL;

    return nodePtr;
}

void insertInBST(struct BstNode **rootPtr, int data)
{
    if (*rootPtr == NULL)
    {
        *rootPtr = newBstNode(data);
    }
    else if (data <= (*rootPtr)->data)
    {
        insertInBST(&(*rootPtr)->left, data);
    }
    else
    {
        insertInBST(&(*rootPtr)->right, data);
    }
}

// function to search for a value in the binary tree
int searchBST(struct BstNode *rootPtr, int data)
{
    if (rootPtr == NULL)
        return 0;
    if (rootPtr->data == data)
        return 1;
    else if (data < rootPtr->data)
        return searchBST(rootPtr->left, data);
    else
    {
        return searchBST(rootPtr->right, data);
    }
}

// function to find minimum value in the tree
int bstFindMin(struct BstNode *nodePtr)
{
    if (nodePtr == NULL)
    {
        printf("Error: Empty tree");
        return NULL;
    }
    else if (nodePtr->left == NULL)
    {
        return nodePtr->data;
    }

    return bstFindMin(nodePtr->left);
}

// function to find maximum value in the tree
int bstFindMax(struct BstNode *nodePtr)
{
    if (nodePtr == NULL)
    {
        printf("Error: Empty tree");
        return NULL;
    }
    else if (nodePtr->right == NULL)
    {
        return nodePtr->data;
    }

    return bstFindMax(nodePtr->right);
}

int maxInt(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int bstHeight(struct BstNode *nodePtr)
{
    if (nodePtr == NULL)
        return -1;

    return (maxInt(bstHeight(nodePtr->left), bstHeight(nodePtr->right)) + 1);
}

// Breadth First Search
void bstBfs(struct BstNode *root)
{
    struct BST_NODE_QUEUE queue;
    queue.front = -1;
    queue.rear = -1;

    // checking if bst is empty
    if (root == NULL)
        return;

    enqueue(&queue, root);

    printf("Traversing: ");
    while (!isEmpty(queue))
    {
        struct BstNode *current = dequeue(&queue);
        printf("%d ", current->data);

        // pushing children into the queue
        if (current->left != NULL)
            enqueue(&queue, current->left);
        if (current->right != NULL)
            enqueue(&queue, current->right);
    }

    printf("\n");
}

// Depth First Search (Preorder traversal)
void bstDfsPre(struct BstNode *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);

    // calling function for left tree
    bstDfsPre(root->left);
    // calling function for right subtree
    bstDfsPre(root->right);
}

// Depth First Search (Inorder traversal)
void bstDfsIn(struct BstNode *root)
{
    if (root == NULL)
        return;

    // calling function for left tree
    bstDfsIn(root->left);

    printf("%d ", root->data);

    // calling function for right subtree
    bstDfsIn(root->right);
}

// Depth First Search (Inorder traversal)
void bstDfsPost(struct BstNode *root)
{
    if (root == NULL)
        return;

    // calling function for left tree
    bstDfsPost(root->left);

    // calling function for right subtree
    bstDfsPost(root->right);

    printf("%d ", root->data);
}

// Implementing expensive functions to check if a tree is a BST
int isGreaterThanLeftSubtree(struct BstNode *root, int data)
{
    if (root == NULL)
        return 1;

    if (
        data > root->data &&
        isGreaterThanLeftSubtree(root->left, data) &&
        isGreaterThanLeftSubtree(root->right, data))
        return 1;

    return 0;
}

int isLessThanRightSubtree(struct BstNode *root, int data)
{
    if (root == NULL)
        return 1;

    if (
        data < root->data &&
        isLessThanRightSubtree(root->left, data) &&
        isLessThanRightSubtree(root->right, data))
        return 1;

    return 0;
}

int isBinarySearchTreeExpensive(struct BstNode *root)
{
    if (root == NULL)
        return 1;

    if (
        isGreaterThanLeftSubtree(root->left, root->data) &&
        isLessThanRightSubtree(root->right, root->data) &&
        isBinarySearchTreeExpensive(root->left) &&
        isBinarySearchTreeExpensive(root->right))
        return 1;

    return 0;
}

// Less expensive binary tree check
int isBinarySearchTreeUtil(struct BstNode *root, int min, int max)
{
    if (root == NULL)
        return 1;

    if (
        (root->data > min && root->data < max) &&
        isBinarySearchTreeUtil(root->left, min, root->data) &&
        isBinarySearchTreeUtil(root->right, root->data, max))
        return 1;

    return 0;
}

int isBinarySearchTree(struct BstNode *root)
{
    return isBinarySearchTreeUtil(root, INT_MIN, INT_MAX);
}

// Utility function for deletion
// void delUtil(struct BstNode *parent, struct BstNode *target){
//     // handling situation where target node is a leaf node
//     if(target->left == NULL && target->right == NULL){

//     }
// }
void delLeftBstNode(struct BstNode *root)
{
    struct BstNode *target = root->left;

    // handling situation where target is a leaf node
    if (target->left == NULL && target->right == NULL)
    {
        root->left = NULL;
        free(target);
    }
    else if (target->left != NULL)
    {
        root->left = target->left;
        free(target);
    }
    else if (target->right != NULL)
    {
        root->left = target->right;
        free(target);
    }
    else
    {
        int max = bstFindMax(target->left);
        target->data = max;
        deleteBstNode(target->left, max);
    }
}

void delRightBstNode(struct BstNode *root)
{
    struct BstNode *target = root->right;
    // handling situation where target is a leaf node
    if (target->right == NULL && target->right == NULL)
    {
        root->right = NULL;
        free(target);
    }
    else if (target->left != NULL)
    {
        root->right = target->right;
        free(target);
    }
    else if (target->right != NULL)
    {
        root->right = target->right;
        free(target);
    }
    else
    {
        int min = bstFindMin(target->right);
        target->data = min;
        deleteBstNode(target->right, min);
    }
}

// void delRootNode(struct BstNode *root){
//     int max = bstFindMax(root->left);
//     root->data = max;
//     deleteBstNode(root->left, max);
// }

// Function to delete node from a binary tree
void deleteBstNode(struct BstNode *root, int data)
{
    if (root == NULL)
        return;

    // if (root->data == data) delRootNode(root);

    // handle case where root is target
    if (root->left != NULL && root->left->data == data)
    {
        delLeftBstNode(root);
    }
    if (root->right != NULL && root->right->data == data)
    {
        delRightBstNode(root);
    }

    deleteBstNode(root->left, data);
    deleteBstNode(root->right, data);
}

// Function to find address of minimum value in a BST
struct BstNode *bstFindMinAddress(struct BstNode *nodePtr)
{
    if (nodePtr == NULL)
    {
        printf("Error: Empty tree");
        return NULL;
    }
    else if (nodePtr->left == NULL)
    {
        return nodePtr;
    }

    return bstFindMinAddress(nodePtr->left);
}

// Function to find address of a node in a BST
struct BstNode *bstFindAddressOf(struct BstNode *root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data == data)
        return root;
    else if (data < root->data)
        return bstFindAddressOf(root->left, data);
    else
    {
        return bstFindAddressOf(root->right, data);
    }
}

// Function to find the inorder successor of a node
struct BstNode *findInorderSuccessor(struct BstNode *root, int data)
{
    if (root == NULL)
        return NULL;

    struct BstNode *target = bstFindAddressOf(root, data);

    if (target == NULL)
        return NULL;

    if (target->right != NULL)
        return bstFindMinAddress(target->right);

    struct BstNode *successor = root;
    struct BstNode *current = NULL;
    if (data < root->data)
        current = root->left;
    else
        current = root->right;

    while (current != NULL && current != target)
    {
        if (data < current->data)
        {
            successor = current;
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    return successor;
    // find the address of the node with `data`
    // if it has a right subtree, return address of smallest item there
    // else find the address of parent for which it is in the lef subtree of
}