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
    free(intP);
    printf("=========================\n\n");

    struct Student s = {  18,175};
    struct Student * p = &s;
    printf("struct p * : %d \n", p); //struct p * : 1343915472
    printf("struct *p * : %d \n", *p); //struct p * : 18
    printf("struct &p * : %d \n", (&p)); //struct p * : 18
    printf("struct p->age * : %d \n", p->age); //struct p * : 18

    printf("=========================\n\n");

    char *  str = "hello";
    int64_t  ptr = (int64_t)str;

    printf("str * : %d \n", sizeof(str)); //str * : 8
    printf("ptr * : %s \n", ptr); //ptr * : hello
    char * str1 = (char *)ptr;
    printf("*str1111 * : %s \n", str1); //*str1111 * : hello

    printf("=========================\n\n");

    char ch = "a";
    printf("ch : %d\n", sizeof(ch)); //ch : 1

    int b = 10;
    int * ptr_a = &b;
    int ** ptr_ptr = &ptr_a;
    printf("&b 16 hex : %p \n", &b); //&b:1484391856
    printf("ptr_a 存储内容：%p； =>ptr_a 解引用后的值：%d； ->存放 ptr_a 变量的地址 %p； \n", ptr_a, *ptr_a, &ptr_a); //ptr_a 存储内容：0x7fff581105b0； =>ptr_a 解引用后的值：10； ->存放 ptr_a 变量的地址 0x7fff581105a8；

    printf("ptr_ptr * : 指针的指针：%p； => 指针：%p； -> 值：%p； \n", ptr_ptr, *ptr_ptr,**ptr_ptr);//ptr_ptr * : 指针的指针：0x7fff581105a8； => 指针：0x7fff581105b0； -> 值：0xa；


    printf("=========================\n\n");




    return 0;
}