#include <stdio.h>
#include "./hello.h"

//private method
static void callMe(){
    printf("hello.c\n");
}
void sayHello(char * name){
    callMe();
    printf("hello %s\n",name);
}