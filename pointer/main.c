#include <stdio.h>
#include <stdlib.h>


struct Student{
    int age;
    int height;
};
int main(){

    char * p_str = "hello";
    int a = 10;
    int * p_a = &a;

    printf("char &p_str : %d \n", &p_str); //char &p_str : 1369794048
    printf("char  p_str : %s \n", p_str); //char  p_str : hello

    printf("a * : %d \n", *&a); //a * : 10
    printf("p_a * : %d \n", p_a); //p_a * : 1369794044
    printf("p_a * : %d \n", *p_a); //p_a * : 10

    printf("=========================\n\n");

//    int32_t * intP = malloc(4);
    int len = 10;
    int32_t * intP = malloc(len * sizeof(int32_t));
    intP[1] = 112;
    printf("intP * : %d \n", *intP); //intP * : 0
    printf("intP * : %d \n", intP); //intP * : -281017488 //
    *intP = 100;
    printf("intP * : %d \n", intP); //intP * : -281017488 //地址永远与上面相同，因为访问的都是同一地址

    intP[0] = 111;
    printf("intP * : %d \n", *intP); //intP * : 111
    printf("intP[0] * : %d \n", intP[0]); //intP * : 111 // intP 是指针， [0] 是从该指针偏移 0 的值；所以取值不用加*
    printf("intP+1 * : %d \n", intP+1); // +1 是加 4个字节 byte
    printf("*(intP+1) * : %d \n", *(intP+1)); // +1 是加 4个字节 byte

    printf("&intP[1] * : %d \n", &intP[1]); //intP * : 112
    printf("intP[1] * : %d \n", intP[1]); //intP * : 112
    printf("&intP[1] * : %d \n", &intP[1]); //intP * : 1413490628 // +4

    printf("=========================\n\n");

    struct Student s = {  18,175};
    struct Student * p = &s;
    printf("struct p * : %d \n", p); //struct p * : 1343915472
    printf("struct p * : %d \n", *p); //struct p * : 18
//    printf("struct p * : %d \n", p); //struct p * : 18
    printf("struct p->age * : %d \n", p->age); //struct p * : 18

    printf("=========================\n\n");

    char *  str = "hello";
    int64_t  ptr = (int64_t)str;

    printf("str * : %d \n", sizeof(str)); //str * : 8
    printf("ptr * : %s \n", ptr); //ptr * : hello
    char * str1 = (char *)ptr;
    printf("*str1111 * : %s \n", str1); //*str1111 * : hello


    free(intP);
    return 0;
}