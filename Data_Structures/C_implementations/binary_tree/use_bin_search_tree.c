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

    if(searchBST(rootNodePtr, 18))
        printf("Found\n");
    else
        printf("Not found\n");
    return 0;
}