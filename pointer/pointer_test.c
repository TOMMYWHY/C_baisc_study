#include <stdio.h>

int main (){
    int a = 10;
    int* p = &a;
//    p=11;
    printf(" &a => %d \n",&a);
    printf(" p => %d\n",p);
    printf(" &p => %d\n",&p);
    printf("===================\n");

    char str[128]="tommy";
    char* p_c = str;
    printf(" str => %p\n",str);
    printf(" str[0] => %c \n",str[0]);
    printf(" str[0] => %p\n",&str[0]);
    printf(" &str => %p\n",&str);
    printf(" p_c => %p\n",p_c);
    printf(" *p_c => %c\n",*p_c);
    printf(" *(p_c+2) => %c\n",*(p_c+2));
    printf(" *(str+2) => %c\n",*(str+2));

    return 0;
}