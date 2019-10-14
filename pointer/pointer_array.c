#include <stdio.h>

int main(){
    /*
     * 指针数组
     * */
    int a =1;
    int b = 2;

    int * ptr_arr[5] ={&a,&b};

    printf("*ptr_arr[1] => %d \n", *ptr_arr[1]); //*ptr_arr[1] => 2 // 数组每一项都是地址，解引用
    printf("ptr_arr[1] => %d \n", ptr_arr[1]); //ptr_arr[1] => 1558758852
    printf("&b => %d \n", &b); //&b => 1558758852

    printf("===================\n");

    char * ptr_arr1[5] ={
            "I love you",
            "whats happening",
            "milk it~!"
    };

    printf("ptr_arr1[1] s => %s \n", ptr_arr1[1]); //*ptr_arr[1] => 2 // 数组每一项都是地址，解引用
    printf("ptr_arr1[1] d => %d \n", ptr_arr1[1]);//ptr_arr1[1] d => 63668048
    printf("*ptr_arr1[1] d => %d \n", *ptr_arr1[1]); //*ptr_arr1[1] d => 119  w =>119 ascII

    for (int i = 0; i < 5; ++i) {
        printf("%s \n", ptr_arr1[i]);
    }

    printf("===================\n");

    /*
     * 数组指针
    * */

    int temp[5] = {11,22,33,44,55};
    int (* p2)[5]= &temp;// 指针 指向 一个数组
    printf("*temp d => %d \n", *temp);
    printf("*(temp+1) d => %d \n", *(temp+1));
    printf("temp d => %d \n", temp);
    printf("&temp d => %d \n", &temp);

    printf("p2 d => %d \n",  (p2));
    printf("* (*p2) d => %d \n", * (*p2));
    printf("(*p2)[0] d => %d \n", (*p2)[0]);
    return 0;
}