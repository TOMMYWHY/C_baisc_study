#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int main(){
    printf("review previous...");
    return 0;
}
#endif
//*********************************

#if 0
// b数组 首元素；  &b 整个数组首地址
int main(){
    int b[10];
    printf("b   => %d \n", b);//b   => 1561798112   //首元素
    printf("b+1 => %d \n", b+1);//b+1 => 1561798116 //+4
    printf("&b   => %d \n", &b);//&b   => 1561798112 // 数组首地址
    printf("&b+1 => %d \n", &b+1);//&b+1 => 1561798152 // +40
    return 0;
}
#endif
//*********************************

#if 0
// 指针传递

int get_a(int *p){
    printf("p => %d \n",p);//p => 1535964680 //p 保存 了 变量 a 地址
    printf("&p => %d \n",&p);//&p => 1535964624 // 变量 p 自己地址
    printf("*p => %d \n",*p);//*p => 10
//    p = 0x11;
    *p = 20;
    printf("p => %d \n",p);
    printf("&p => %d \n",&p);
    printf("*p => %d \n",*p);
}
int pointers(***q){

    printf("q => %d \n",q);
    printf("*q => %d \n",*q);//*q => 1535964680 // == &a
}

int main(){
    int a = 10;
    get_a(&a);
    printf("a => %d \n",a);
    printf("&a => %d \n",&a);//&a => 1535964680 //变量 a 地址
    printf("============== \n");

    int *p = &a;
    int ** q = p;
    pointers(&q);
    printf("&q => %d \n",&q);
    printf("============== \n");

    return 0;
}
#endif
//*********************************


#if 0
// 指针 值传递 与 指针传递
void fun(int  *p){
    printf("fun p => %p \n",p);
    p = 0xaabb; //值传递
    printf("fun p => %p \n",p);
}
void fun1(int  **p){
//    printf("fun1 p => %p \n",p);
    *p = 0xaabb;
//    printf("fun1 p => %p \n",p);
}

int main(){
    int * p = 0x1122;
    fun(p);//值传递
    printf("mian1 p => %p \n",p);

    fun1(&p);
    printf("mian2 p => %p \n",p);
    return 0;
}
#endif
//*********************************

#if 0
// string copy
void my_strcopy(char dst[], char *src ){
    // *(dst+i) == dst[i]
    for ( int i =0; src[i] != '\0'; i++) {
        *(dst+i) = src[i];
    }
//    dst[i]= 0;
}
int main(){
    char src[] = "asdqwe";
    char dst[100] ={0};
    my_strcopy(dst, src);
    printf("%s \n",dst);
    return 0;
}
#endif
//*********************************

#if 0
// 指针数组
int main(){
    char *p1="asd";
    printf("%s \n",p1);
    printf("%c \n",p1[2]);
    char *p[10] = {"111","222","3333","444"};
    printf("p => %d; sizeof p =>%d \n",p, sizeof(p));//p => 1389135280; sizeof p =>80
    printf("p+1 => %d \n",p+1);//p => 1389135288  //+8 增加一个指针大小
    printf("&p => %d \n",&p);//&p => 1521448368
    printf("&p+1 => %d \n",&p+1);//&p+1 => 1521448448 //+80
    return 0;
}
#endif
//*********************************

#if 0
// 二维数组
void print_arr_err(int **a, int n){
    printf("print_arr a => %d \n",a);
    printf("print_arr a+1 => %d \n",a+1); //+4
}
void print_arr(char a[][10], int n){
    printf("print_arr a => %d \n",a);
    printf("print_arr a+1 => %d \n",a+1); //+40
    for (int i = 0; i < n; i++) {
        printf("%s \n",a[i]);
    }
}
int main(){

    char a[4][30] = {"111","222","3333","444"};
    printf("&a=> %d \n",&a);
    printf("&a+1=> %d \n",&a+1); //+120 这个二维数组地址
    printf("a=> %d \n",a);// 首行地址
    printf("a+1=> %d \n",a+1); //+30
    printf("d *a=> %d \n",*a);// 首行地址
    printf("d *a+1=> %d \n",*a+1);// 首行首元素地址 +1

    printf("s a=> %s \n",a);
    printf("s *a=> %s \n",*a);
    printf("s *(a+1)=> %s \n",*(a+1));
    printf("s a[1]=> %s \n",a[1]);
    int n = sizeof(a)/ sizeof(a[0]);
    print_arr(a,n);
    return 0;
}
#endif
//*********************************
#if 1
// replace substring
int replaceSubstring(char *src, char **dst, char *sub, char * new_sub){
    /*
     * src = "00asd123qwe22222asd9999"
     * sub = asd
     * new_sub = abcd
     */
    char * start = src;
    char *p = NULL;
    char temp [512] = {0};
    int len = 0;
    do{
        p = strstr(start,sub);
        if(p !=NULL){
            len = 0;
            len= p - start;
            if(len >0){
                strncat(temp,start, len);
            }
            strncat(temp,new_sub,strlen(new_sub));
            start =  p + strlen(sub);

        } else{
            strcat(temp,start);
            break;
        }

    }while (*start !=0);
    char *buf = (char *)malloc(strlen(temp)+1);
    strcpy(buf,temp);
    * dst = buf;
    return 0;
}
void freeBuf(char * buf){
    free(buf);
}
void freeBuff(char **buf){
    char *temp = *buf;
    free(temp);
    *buf = NULL;
}
int main(){
    char *p = "00asd123qwe22222asd9999";
    char * buf = NULL;
    int ret = 0;
    ret = replaceSubstring(p,&buf,"asd","_");
    if(ret !=0){
        printf("replaceSubstring err %d \n", ret);
        return ret;
    }
    printf("p : %s \n",p);
    printf("buf : %s \n",buf);
    if(buf !=NULL){
        free(buf);
        buf = NULL;
    }

    /*freeBuf(buf);
    buf = NULL;*/
    freeBuff(&buf);
    return 0;
}
#endif
//*********************************
