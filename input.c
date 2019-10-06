#include <stdio.h>


int main(){
    int flag = 1;
    int i;
    int count = 0;
    int sum = 0;
    while (flag){
        scanf("%d",&i);
        if(0==i){
            break;
        } else{
            count ++;
            sum = sum+i;
        }
    }
    printf("sum : %d,count : %d \n",sum,count);
    return 0;
}