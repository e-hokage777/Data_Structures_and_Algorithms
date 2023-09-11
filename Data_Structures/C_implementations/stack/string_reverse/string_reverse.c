#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str_rev_stack.h"


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
    printf("%s\n", string);
    reverseString(string); // reversing the string
    printf("%s\n", string);
    return 0;
}