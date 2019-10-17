#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#if 0
int main (){

    int arr [10] ={0};

    printf("arr => :   %d \n",arr);//arr => :   1542448592  // 数组第一个元素地址
    printf("arr+1 => : %d \n",arr+1);
    printf("&arr => :  %d \n",&arr); //&arr => :  1542448592 // 整个数组的 首地址
    printf("&arr+1 => :%d \n",&arr+1);

    printf("sizeof(arr) => :   %d \n", sizeof(arr)); //40   //数组大小
    printf("sizeof(arr+2) => :   %d \n", sizeof(arr+2));//8 //指针大小
    printf("sizeof(&arr) => :   %d \n", sizeof(&arr));//8   //指针大小
    return 0;
}

#endif


#if 0
/*
 * 内存分配
 * 全局区 ： 全局变量；静态变量； 文字常量
 */
char* get_str1 (){
    char *p = "asd";
    return p;
}
char* get_str2 (){
    char *q = "asd"; // asd 在全局 文字常量区；将首地址赋值给 *p
    return q;
}
int main(){

    char * p = NULL;
    char *q = NULL;
    p = get_str1(); // 将 asd 首地址 赋值 于 指针 局部变量 *p
    printf("p => : %s \n", p);//p => : asd
    printf("p => : %d \n", p);//p => : 173952898
    q= get_str2();
    printf("q => : %s \n", q);//q => : asd
    printf("q => : %d \n", q);//q => : 173952898

    return 0;
}

#endif

#if 0

char * get_str(){
    char str[] = "tommywhy"; // 将 全局 string 以 char 的形式 一一复制到 stack 的 str[] 中
    printf("str[] => : %s \n",str);
    printf("&str[] => : %d \n",&str);
    return str; //return 首地址
}

int main (){

    char *p= NULL;
    p = get_str();// 指针赋值 后， 原方法被释放。。。
    printf("p => : %s \n", p);//
    printf("&p => : %d \n", &p);//
    return 0;

}

#endif

#if 0
/*
 *   * 为左值时： 给内存赋值，写操作
 *   * 为右值时： 取内存值，  读操作
 */
int main(){
    int a = 10;
    int *p1 = NULL;
    p1 = &a;
    int b  = *p1; // 读取 内存 //10
    *p1 = 22; // 写 内存 //22

}

#endif


#if 0
int main (){

    char * buf1 = "asdqwe"; // 指针指向常量区
    //buf1[1] = 'p'// error
    char  buf2[] = "asdqwe"; // 将常量区字符串，以字符形式负值给 栈区数组
    printf("&buf1 => : %d \n", &buf1);//&buf1 => : 1352996336 //栈区
    printf("buf1 => : %d \n", buf1);//buf1 => : 253423466 // 常量区

    printf("&buf2 => : %d \n", &buf2);//&buf2 => : 1352996329 //栈
    printf("buf2 => : %d \n", buf2);//buf2 => : 1352996329 //栈

printf("================================ \n");

    int a = 10;
    int *p = &a;
    int **q = &p;

    int ****t = NULL;
    int * ****t2 = &t;

    printf("p => : %d \n", p);//p => : 1428334052
    printf("*p => : %d \n", *p);//*p => : 10
    printf("&p => : %d \n", &p);//&p => : 1428334040
    printf("q => : %d \n", q);//q => : 1428334040
    printf("*q => : %d \n", *q);//*q => : 1428334052
    printf("**q => : %d \n", **q);//**q => : 10
    printf("&*q => : %d \n", &*q);//&*q => : 1428334040

    printf("================================ \n");

    return 0;

}

#endif


#if 1
void fun(int * p){
    p = 0xaabb;
    printf("fun: p => %p\n", p); //fun: p => 0xaabb
}
void fun2(int **p){
    *p = 0xeeff;
    printf("fun2: p => %p\n", p); //fun2: p => 0x7fff537175f0
}
int main(){
    int * ptr = 0x1122;
    printf("ptr => : %p \n", ptr); //ptr => : 0x1122
    fun(ptr);//值传递
    printf("ptr => : %p \n", ptr); //ptr => : 0x1122
    fun2( &ptr); //地址传递
    printf("ptr => : %p \n", ptr); //ptr => : 0xeeff
    return 0;
}
#endif
#if 0

void fun(char *p){
    strcpy(p, "abcdef");
}
void fun2(char *p){
    if(p == NULL){
        return;
    }
    strcpy(p, "abcdef");

}
void fun3(char **p,int *len){
    if(p == NULL){
        return;
    }
    char * temp = (char *)malloc(100);
    if(temp == NULL){
        return;
    }
    strcpy(temp,"asdqwe");
    *p = temp;
    *len = strlen(temp);
}
int main() {
    char buf[100] = {0};
    fun(buf);

    printf("buf => %s \n", buf);//buf => abcdef
    char *str = NULL;
    fun2(str);
    printf("str => %s \n", str); //str => (null)

    char *p = NULL;
    int len = 0;
    printf("&p=> %d \n",&p);
    fun3(&p,&len);
    if(p !=NULL){
        printf("p => %s ,len =%d  \n", p,len); //
    }
    return 0;
}

#endif