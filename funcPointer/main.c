#include <stdio.h>


void hello(int a, int b, char * c){
    printf("hello %s \n",c);
}

typedef void(* simpleFunc)();

int main(){
    hello(1,2,"tommy");

    void(* fp)(int,int,char*) = &hello;
    fp(11,22,"Sookie");

    simpleFunc ptr_fun = &hello;
    ptr_fun(111,222,"tommywhy");

    printf("=======================\n");

    void * data ="hello world";
    printf("%s \n",data);
    return 0;
}