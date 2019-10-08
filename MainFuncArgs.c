#include <stdio.h>


int main (int argc, char ** argv){

    printf("arguments count %d \n", argc);
//    printf("fuck %s\n",argv[0]);
//    printf("fuck %s\n",argv[1]);
    for (int i = 0; i < argc; i++) {
        printf("arg index:%d; arg value : %s \n",i, argv[i]);
    }
    return 0;
}