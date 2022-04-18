#include "product.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>





int selectProductNo(Product *p[], int count,int isdebug);//제품 번호를 입력받는 함수
void listProduct(Product *p[], int count,int isdebug); // 전체 제품 리스트 출력 함수