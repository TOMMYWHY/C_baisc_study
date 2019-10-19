#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int main(){
  char src[] = "asdasd";
  char dst [100] = {0};
    for (int i = 0; src[i]!='\0'; i++) {
        dst[i] = src[i];
    }
    printf("%s \n",dst);
}
#endif

#if 0
void my_strCopy(char * dst,char * src ){
    for (int i = 0; *(src+i)!='\0'; i++) {
        dst[i] = *(src+i);
    }
}
void my_strCopy2(char * dst,char * src ){
    while (*src !='\0'){
        *dst = *src;
        dst++;
        src++;
    }
    *dst = 0; //补结束符
}
int my_strCopy3(char * dst,char * src ){
    if(dst ==NULL || src == NULL){
        return  -1;
    }
    while (*src !='\0'){
        *dst++ = *src++; // 运算符优先级：同级且右到左//++在后，先++再取*
    }
    *dst = 0; //补结束符

    return  0;
}
int main(){
    char src[] = "asdasd";
    char dst [100] = {0};
    int ret = 0;
    ret = my_strCopy3(dst,src);
    printf("%d \n",ret);
   if(ret ==0){
       printf("%s \n",dst);
   }
   return 0;
}
#endif

#if 1
// 查找字符出现次数
int findChar(){};
int main(){
    char *p ="123asdasd0002215asdqwewqecxzasd";
    int n = 0;
    /*
    while (*p !=0){
        p = strstr(p ,"asd");//找到 asd 起始指针
        if(p !=NULL){
            n++;
            p = p+strlen("asd"); // 找到 asd 结束指针
        } else{
            break;
        }
    }
      */
    while ((p = strstr(p,"asd")) != NULL){
        if(*p==0){
            break;
        } else{
            n++;
            p = p+strlen("asd"); // 找到 asd 结束指针
        }
    }
    printf("asd : n = %d \n", n);
    return 0;
}
#endif