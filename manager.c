#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"





void listProduct(Product *p[], int count, int isdebug){
    printf("***********************\n");
    for(int i = 0; i < count; i++){
        if(p[i]== NULL) continue;
        printf("Product Number %d.\n",i+1);
        readProduct(*p[i]);
        printf("*****************\n");
        if(isdebug == 1)
        printf("%s",__DATE__);
    }
}
int selectProductNo(Product *s[], int count,int isdebug){
    int no;
    listProduct(s,count, isdebug);
    printf("번호는 (취소 :0)? ");
    scanf("%d",&no);
    return no;
}
