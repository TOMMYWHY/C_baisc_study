#include <stdio.h>

#define  THE_NUM 2

#define MAX(A,B)A>B?A:B
int main(){
    printf("Max : %d",MAX(9,5));
    printf("the number: %d",THE_NUM);
    return 0;
}