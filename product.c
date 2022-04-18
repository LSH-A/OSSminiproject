#include <stdio.h>
#include "product.h"

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

void saveData(Product *p, int count){
    FILE *fp;
    fp = fopen("product.txt","wt");


    for (int i = 0; i <count; i++){
        if(p[i].price == -1) continue;
        printf("Name: %s\n",p[i].p_name);
        printf("Description: %s\n",p[i].desc);
        printf("Weight: %s\n",p[i].weight);
        printf("Price: %d\n",p[i].price);
        printf("Delivery Method: %d\n",p[i].DM);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}
int loadData(Product *p){

} 
