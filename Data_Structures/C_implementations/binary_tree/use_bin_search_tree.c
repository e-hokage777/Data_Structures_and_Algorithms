#include <stdlib.h>
#include <stdio.h>
#include "./binary_search_tree.h"


int main(){
    struct BstNode *rootNodePtr;
    rootNodePtr = NULL;
    insertInBST(&rootNodePtr, 5);
    insertInBST(&rootNodePtr, 3);
    insertInBST(&rootNodePtr, 8);
    insertInBST(&rootNodePtr, 6);
    insertInBST(&rootNodePtr, 20);
    insertInBST(&rootNodePtr, 21);
    insertInBST(&rootNodePtr, 1);
    printf("Min: %d\n", bstFindMin(rootNodePtr));
    printf("Max: %d\n", bstFindMax(rootNodePtr));
    printf("Height of Tree %d\n", bstHeight(rootNodePtr));

    return 0;
}