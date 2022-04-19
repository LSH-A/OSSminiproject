#include <stdio.h>
#include "product.h"
#include <stdlib.h>
#include <string.h>
int selectMenu(){
    int menu;
    printf("\n*** Menu ***\n");
    printf("1. Read Product\n");
    printf("2. Add Product\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Save Data\n");
    printf("6. Load Data\n");
    printf("0. End\n\n");
    printf("=> Select? ");
    scanf("%d", &menu);
    return menu;
}

int createProduct(Product *p){
    printf("Product Name? ");
    scanf("%s",p->p_name);
    getchar();
    printf("Product Description? ");
    scanf("%[^\n]s",p->desc);
    printf("Product Weight? ");
    scanf("%s",p->weight);
    printf("Product Price? ");
    scanf("%d",&p->price);
    printf("Delivery Method? ");
    scanf("%d",&p->DM);

    printf("\nProduct Added! \n");
    return 1;
#ifdef DEBUG
    printf("%s, %s, %s, %d, %d \n",pr[index-1]->p_name,pr[index-1]->desc,pr[index-1]->weight,pr[index-1]->price,pr[index-1]->DM);
    printf("count = %d\n",count);
#endif
}
int readProduct(Product p){
    if(p.price == -1){
        printf("Product has been deleted.\n");
        return 0;
    }
    printf("Name: %s\n",p.p_name);

    printf("Description: %s\n",p.desc);

    printf("Weight: %s\n",p.weight);

    printf("Price: %d\n",p.price);

    printf("Delivery Method: %d\n",p.DM);


    return 1;
}

int updateProduct (Product *p){
    printf("Product Name? ");
    scanf("%s",p->p_name);
    getchar();
    printf("Product Description? ");
    scanf("%[^\n]s",p->desc);
    printf("Product Weight? ");
    scanf("%s",p->weight);
    printf("Product Price? ");
    scanf("%d",&p->price);
    printf("Delivery Method? ");
    scanf("%d",&p->DM);
    printf("\nProduct Updated! \n");
    return 1;
}
int deleteProduct(Product *p){
    p->price = -1;
    printf("Product Deleted!\n");
    return 1;
}

void saveData(Product *p[], int count){
    FILE *fp;
    fp = fopen("product.txt","wt");

    for (int i = 0; i <count; i++){
        if(p[i]== NULL) continue;
        fprintf(fp,"%s\n",p[i]->p_name);
        fprintf(fp,"%s\n",p[i]->desc);
        fprintf(fp,"%s\n",p[i]->weight);
        fprintf(fp,"%d\n",p[i]->price);
        fprintf(fp,"%d\n",p[i]->DM);
    }
    fclose(fp);
    printf("=> Saved! ");
}
int loadData(Product *p[]){
    int i = 0;
    char strToint[10];
    FILE *fp;
    fp = fopen("product.txt","rt");
    for(; i< 100; i++){
        if(feof(fp)){
            free(p[i-1]); // 쓰레기 struct가 만들어져서 제거
            break;
        } 
        p[i] =(Product *)malloc(sizeof(Product));
        fgets(p[i]->p_name,20,fp);
        p[i]->p_name[strlen(p[i]->p_name) - 1] = '\0';
       // fscanf(fp,"%s",p[i]->p_name);
        fgets(p[i]->desc,100,fp);
        p[i]->desc[strlen(p[i]->desc) - 1] = '\0';
        //fscanf(fp,"%[^\n]s",p[i]->desc);
        fgets(p[i]->weight,20,fp);
        p[i]->weight[strlen(p[i]->weight) - 1] = '\0';
       // fscanf(fp,"%s",p[i]->weight);
        fgets(strToint,10,fp);
        strToint[strlen(strToint) - 1] = '\0';
        p[i]->price = atoi(strToint);
        fgets(strToint,10,fp);
        strToint[strlen(strToint) - 1] = '\0';
        p[i]->DM = atoi(strToint);
       
    }
    fclose(fp);
    printf("=>Load complete!\n");
    return i-1; // 쓰레기 struct카운트 x
} /*
void searchName(Product *p,int count){
    int scnt = 0;
    char search[20];

    print("Searching name?");
    sacnf("%s",search);
    

}*/