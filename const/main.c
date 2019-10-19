#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * const
 * */
#if 1
int main(){
    const int a = 10; //只读
//    a = 100; //error
    char buf[] = "asdasdasdasdasdqweqwe";
    const  char * p= buf;//常量指针 // *read only,及*p 指向 buf 内容不可变
//    p[1] = '2';//err
//    *(p+1) = '9';//err
    p="123"; //p 变量指向改变
    char const * p1 = buf;//常量指针

    char * const p2 = buf;//指针常量 //p2变量只能指向内存位置buf，但p2 可以改变 buf 内容
    p2[1] = '9';
//    p2 = "123";//err
    const char * const p3 = buf;//全不能改


//    *p = 0x111;

    return 0;

}

#endif