#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"
#include "product.h"


int main(void){
#ifdef DEBUG
    printf("\nIt is Debugging mode!\n");
#endif
    Product *pr[100];
    int index = 0;
    int count = 0, menu;
    int isdebug = 0;
#ifdef DEBUG
    isdebug = 1;
#endif

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count > 0 )
                listProduct(pr,index,isdebug); 
            else   
                printf("등록된 제품이 없습니다.\n");
        }
        else if (menu == 2){
            pr[index] =(Product *)malloc(sizeof(Product));
            count += createProduct(pr[index++]);
#ifdef DEBUG
    printf("%s, %s, %s, %d, %d \n",pr[index-1]->p_name,pr[index-1]->desc,pr[index-1]->weight,pr[index-1]->price,pr[index-1]->DM);
    printf("count = %d\n",count);
#endif
        }
        else if (menu == 3){
            int no = selectProductNo(pr,index,isdebug);
            if(no == 0){
                printf("==> 취소됨! \n");
                continue;
            }
            updateProduct(pr[no-1]);
#ifdef DEBUG

    printf("%s, %s, %s, %d, %d \n",pr[no-1]->p_name,pr[no-1]->desc,pr[no-1]->weight,pr[no-1]->price,pr[no-1]->DM);
    printf("count = %d\n",count);
#endif
        }
        else if (menu == 4){
            int no = selectProductNo(pr,index,isdebug);
            if(no == 0){
                printf("==> 취소됨! \n");
                continue;
            }
           int deleteok;
           printf("정말로 삭제하시겠습니까?(삭제 :1)");
           scanf("%d",&deleteok);
           if(deleteok == 1){
               if(pr[no-1]) free(pr[no-1]);
               pr[no-1] = NULL;
               count--; 
#ifdef DEBUG
    printf("count = %d\n",count);
#endif
           }
        }
        else if (menu == 5){
            saveData(pr,index); 
        }
        else if (menu == 6){
            count = loadData(pr);
            index = count;
        }
    }
    printf("종료됨!\n");
    system("pause");
    return 0;
}
