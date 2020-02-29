//
//  main.c
//  模拟售货机
//
//  Created by 蒋凡安 on 2020/2/26.
//  Copyright © 2020 蒋凡安. All rights reserved.
//

#include <stdio.h>
void menu(){
printf("What would you like to do?\n");
printf("1. Read product information");
printf("2. Insert coin\n");
printf("3. Press product button\n");
printf("4. Press return button\n");
printf("9. Open service menu (code required)\n");
printf("0. Quit\n");
printf("Your choice:");
}
int main() {
    printf("*---------------------------*\n");
    printf("|     Vending   Machine     |\n");
    printf("*---------------------------*\n");
    printf("|   A    B    C    D    E   |\n");
    printf("|  $10  $ 6  $ 5  $ 8  $ 7  |\n");
    printf("|  [ ]  [ ]  [ ]  [ ]  [ ]  |\n");
    printf("*---------------------------*\n");
    printf("|                    [$ 0]  |\n");
    printf("|                           |\n");
    printf("|           [===]           |\n");
    printf("*---------------------------*\n");
    printf("\n");
    printf("\n");
    void menu(void);
    int a;
    scanf("%d",&a);
    if(a==1){
        printf("(1) The displayed products are:\n");
        printf("A. Juice ($10)\n");
        printf("B. Cola ($6)\n");
        printf("C. Tea ($5)\n");
        printf("D. Water ($8)\n");
        printf("E. Coffee ($7)\n");
        printf("\n");
        printf("\n");
       
    }
}
