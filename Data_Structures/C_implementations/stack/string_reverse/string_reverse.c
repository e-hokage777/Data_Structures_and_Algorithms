#include <stdio.h>
#include "str_rev_stack.h"

void printString(char s[]){
    int n = 0;
    while(s[n] != 0){
        printf("%c", s[n]);
        n+=1;
    }
    printf("\n");
}

void reverseString2(char s[]){
    int i,j;
    i = 0;
    j = strlen(s) - 1;

    while(i < j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        ++i;
        --j;
    }
}

int main(){
    char string[20] = "something";
    printString(string);
    reverseString(string); // reversing the string
    printString(string);
    return 0;
}