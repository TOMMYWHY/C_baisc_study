#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * const
 * */

#if 0
int getMem(char *p);
int main(){
    char *p = NULL; //*p
    int ret = 0;
    ret = getMem(p); // p 此处为值传递
    if(ret !=0){
        printf("getMem :%d \n",ret);
        return ret;
    }
    printf("p from main : %s \n",p);//p from main : (null)
    return 0;

}

int getMem(char *p) {
    p = (char *)malloc(100);
    if(p ==NULL){
        return -1;
    }
    strcpy(p,"asdqwe");
    printf("p from getMem : %s \n",p);//p from getMem : asdqwe
    return 0;
}
#endif


#if 0
int getMem(char **p) {
//    *p = (char *)malloc(100);
    char *temp = (char *)malloc(100);
   /* if(*p ==NULL){
        return -1;
    }*/
//    strcpy(*p,"asdqwe");
    strcpy(temp,"asdqwe");
    *p= temp;
    printf("*p from getMem : %s \n",*p);//p from getMem : asdqwe
    return 0;
}
int main(){
    char *p = NULL; //*p
    int ret = 0;
    ret = getMem(&p); // &p 此处为地址传递
    if(ret !=0){
        printf("getMem :%d \n",ret);
        return ret;
    }
    printf("p from main : %s \n",p);//p from main : (null)
    return 0;

}
#endif

#if 0
/*
 * 指针数组
 */
//void test (int a[])
void test (int *a)
{
    // 形参中， a[] == *a
}
void fun (){
    int a[10];
    test(a);
}

//void print_arr(char *p[] )
void print_arr(char **p )
{
    //*p[] == **p
    for (int i = 0; i < 3; ++i) {
        printf("%s, ",p[i]);
    }
}

int main(){
    char *p[] = {"a123","bbb","ccc"};
    printf("p[0] : %s \n",p[0]); //p[0] 是个指针,指向 a123 的 a
//    printf("p[0][2] : %s \n",p[0][2]); //p[0] 是个指针

    print_arr(p);
    return 0;
}
#endif

#if 0
/*
 * 二维数组
 */
int main(){
    char a [][30] = {"1111","2222","aaaaa","bbbbb"};
    char b [30];
    printf("a : %d => %s \n",a,a);//a : 1586484608 => 1111  //首行
    printf("a+1 : %d => %s  \n",a+1,a+1);//a+1 : 1586484638 => 2222
    printf("a+1 : %d  => %s \n",a+1);//a+1 : 2222

    printf("b : %d  => %s \n",b,b);//b : 1485411680  =>  ��X� 步长为1
    printf("b+1 : %d  => %s \n",b+1,b+1);//b+1 : 1485411681  => ��X�
    printf("&b : %d  => %s \n",&b,&b); //步长为30
    printf("&b+1 : %d  => %s \n",&b+1,&b+1);
    return 0;
}

#endif

#if 1

int main() {
    int n =10;
    int  a[10];
    int *q = (int * )malloc(n * sizeof(int));

    char **buf = (char **)malloc(n * sizeof(char *)); // char * buf[10]
    for (int i = 0; i < n; i++ ) {
        buf[i] = (char *)malloc(30 * sizeof(char));
        char str[30];
        sprintf(str,"test %d%d",i,i);
        strcpy(buf[i],str);
    }
    printf("%s",buf[1]);
    for (int i = 0; i <n ; i++) {
        printf("%s , ",buf[i]);
    }

    for (int i = 0; i <n; ++i) {
        free(buf[i]);
    }
    if(buf !=NULL){
        free(buf);
    }
    return 0;
}

#endif