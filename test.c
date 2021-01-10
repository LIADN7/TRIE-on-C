#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_LETTERS ((int)26)



int main(int argc, char const *argv[]){
    char st[] ="abc";
    char c= 'd';
    strncat(st, &c,1);

    printf("%s \n", st);
    return 0;
}

