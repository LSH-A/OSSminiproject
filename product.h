
#pragma once
#ifndef PRODUCT
#define PRODUCT

typedef struct Product{ //구조체
   char p_name[20]; //제품명
   char desc[100]; //제품 설명
   char weight[20];//제품 중량
   int price; //판매 가격
   int DM; //delivery method, 배송방법
} Product;
int selectMenu();//제품선택
int createProduct(Product *p); //제품 추가 함수
int readProduct(Product p); // 하나의 제품 출력 함수

int updateProduct(Product *p); //등록된 제품 변경 함수
int deleteProduct(Product *p); //등록된 제품 삭제 함수
void saveData(Product *p[], int count);//파일에 제품 데이터 저장하는 함수
int loadData(Product *p[]);//파일에서 제품 데이터를 불러오는 함수 
void searchName(Product *p,int count);//제품 이름 검색
void searchWeight(Product *p[],int count);//입력 무게보다 크거나 같은, 혹은 작거나 같은 제품 검색 
void searchDesc(Product *p[],int count);//제품 설명에 일치하는 단어가 있는 제품 검색
#endif

