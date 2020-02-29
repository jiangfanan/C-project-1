//
//  main.c
//  售货机2
//
//  Created by 蒋凡安 on 2020/2/29.
//  Copyright © 2020 蒋凡安. All rights reserved.
//
#include <stdio.h>
#include <string.h>

    /*初始化*/
    /*交易成功后的存款*/
    int income = 0;
    /*临时存款*/
    int deposit = 0;
    /*给出物品，底部标识*/
    char *give = "=";
    /*商品名称*/
    char mctname[][21] = {"Juice", "Cola", "Tea", "Water", "Coffee"};
    /*序号12345和ABCDE进行对应*/
    char abcde [5][2] = {"A", "B", "C", "D", "E"};
    /*商品价格*/
    int price[5] = {10, 6, 5, 8, 7};
    /*商品库存*/
    int inventory[5] = {5, 1, 2, 1, 9};

int homepage()
{
    printf("*---------------------------*\n");
    printf("|     Vending   Machine     |\n");
    printf("*---------------------------*\n");
    
    /*打印字母行*/
    printf("|  ");
    for (int i = 0; i <= 4; i++){
        printf(" %s   ", abcde[i]);
    }
        printf("|\n");
    
    /*打印价格行*/
    printf("|");
    for (int i = 0; i <= 4; i++){
        printf("  $%2d", price[i]);
    }
    printf("  |\n");
    
    /*打印灯行*/
    printf("|");
    for (int i = 0; i <= 4; i++){
        printf("  [");
        if(inventory[i] <= 0)
            printf("X");
        else if(deposit >= price[i])
            printf("O");
        else
            printf(" ");
        printf("]");
    }
    printf("  |\n");

    printf("*---------------------------*\n");
    
    /*打印存钱*/
    printf("|                    [$%2d]  |\n", deposit);

    printf("|                           |\n");
    printf("|           [=%s=]           |\n", give);
    printf("*---------------------------*\n\n");
    return 0;
}

int homemenu()
{
    printf("What would you like to do?\n");
    printf(" 1. Read product information\n");
    printf(" 2. Insert coin\n");
    printf(" 3. Press product button\n");
    printf(" 4. Press return button\n");
    printf(" 9. Open service menu (code required)\n");
    printf(" 0. Quit\n\n");
    printf("Your choice:");
    return 0;
}

/*1. Read product information*/
int choice1(void)
{
    printf("\n(1) The displayed products are:\n");
    for (int i = 0; i <= 4; i++){
        if(i <= 4 && i >=0){
            printf("%s", abcde[i]);
        }
        else{
            printf("Unknown Error (1).\n");
        }
        printf(". %s ", mctname[i]);
        printf("($%d)\n", price[i]);
    }
    printf("\n");
    return 0;
}

/*打印2的菜单*/
int menu2(void)
{
    printf("(2) Which coin would you like to insert?\n");
     printf("1. $1\n");
     printf("2. $2\n");
     printf("3. $5\n");
     printf("4. $10\n");
     printf("0. Go back\n\n");
     printf("Your choice:");
     return 0;
}

/*2. Insert coin*/

int choice2(void)
{
    int quit2 = 0; /*判断是否需要退出，0不退出，1退出*/
    int choice = 10; /*用户选择*/
    printf("\n");
    while (quit2 == 0){
        menu2();
        scanf("%d", &choice);
        switch(choice){
            case 1: deposit += 1; printf("You have inserted $1.\n\n"); break;
            case 2: deposit += 2; printf("You have inserted $2.\n\n"); break;
            case 3: deposit += 5; printf("You have inserted $5.\n\n"); break;
            case 4: deposit += 10; printf("You have inserted $10.\n\n"); break;
            case 0: quit2 = 1; printf("Going back!\n\n"); break;
            default: printf("Invalid choice!\n\n"); break;
        }
        if (deposit > 99)
            deposit = 99;
        homepage();
    }
    return 0;
}

/*打印3的菜单*/
int menu3(void)
{
    printf("(3) Which product button would you like to press?\n");
    for (int i = 0; i <= 4; i++){
            printf(" %d. ", i + 1);
            printf("%s\n", abcde[i]);
        }
     printf(" 0. Go back\n\n");
     printf("Your choice:");
     return 0;
}

/*尝试进行交易*/
int trade(int num)
{
    if (inventory[num - 1] > 0 && deposit >= price[num - 1]){
        inventory[num - 1]--;
        deposit -= price[num - 1];
        income += price[num - 1];
        give = abcde[num - 1];
        printf("\n");
        return 1;
    }
    else{
        printf("Invalid choice!\n\n");
        return 0;
    }
}

/*3. Press product button*/
int choice3(void)
{
    int quit3 = 0; /*判断是否需要退出，0不退出，1退出*/
    int choice = 10; /*用户选择*/
    printf("\n");
    while (quit3 == 0) {
        menu3();
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 5){
            printf("You have pressed button %s.\n", abcde[choice - 1]);
            quit3 = trade(choice);
        }
        else if (choice == 0){
            printf("Going back!\n\n");
            quit3 = 1;
        }
        else{
            printf("Invalid choice!\n\n");
        }
        homepage();
        }
    return 0;
}

/*打印9的菜单*/
int menu9(void)
{
    printf("(9) What would you like to do?\n");
     printf("1. Inspect machine status\n");
     printf("2. Withdraw all money\n");
     printf("3. Refill product\n");
     printf("4. Change product\n");
     printf("0. Go back\n\n");
     printf("Your choice:");
     return 0;
}

/*9-1. Inspect machine status*/
int choice9_1(void)
{
    printf("\n(9-1) Machine status\n");
    printf("Amount of revenue: $%d\n", income);
    printf("Amount of inserted coins: $%d\n", deposit);
    for (int i = 0; i <= 4; i++){
        printf("%s", abcde[i]);
        printf(". %s ", mctname[i]);
        printf("($%d) ", price[i]);
        if(inventory[i] > 0)
            printf("(%d left)", inventory[i]);
        else
            printf("sold out");
        printf("\n");
    }
    printf("\n");
    return 0;
}

int choice9_3(void)
{
    int choice = 10; /*用户选择*/
    int quit9_3 = 0; /*判断是否需要退出，0不退出，1退出*/
    while(quit9_3 == 0){
        printf("\n(9-3) Which product would you like to refill?\n");
        for (int i = 0; i <= 4; i++){
            printf(" %d. ", i + 1);
            printf("%s\n", abcde[i]);
        }
        printf(" 0. Go Back\n\n");
        printf("Your choice:");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 5){
            inventory[choice - 1] = 10;
            printf("You have refilled product %s to full.\n\n", abcde[choice - 1]);
            quit9_3 = 1;
        }
        else if (choice == 0){
                printf("Going back!\n\n");
                quit9_3 = 1;
            }
        else
                printf("Invalid choice!\n\n");
    }
    return 0;
}

int choice9_4(void)
{
    int choice = 10; /*用户选择*/
    int quit9_4 = 0; /*判断是否需要退出，0不退出，1退出*/
    while(quit9_4 == 0){
        printf("\n(9-4) Which product would you like to change?\n");
        for (int i = 0; i <= 4; i++){
            printf(" %d. ", i + 1);
            printf("%s\n", abcde[i]);
        }
        printf(" 0. Go Back\n\n");
        printf("Your choice:");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 5){
            printf("You are changing product %s.\n", abcde[choice - 1]);
            do{
            printf("Enter new product name: ");
            scanf("%s", mctname[choice - 1]);
            if (strlen(mctname[choice - 1]) > 20)
                printf("New product name can not be longer than 20 characters!\n\n");
            }while(strlen(mctname[choice - 1]) > 20);
            printf("Enter new product price: ");
            scanf("%d", &price[choice - 1]);
            if (price[choice - 1] > 99)
                price[choice - 1] = 99;
            inventory[choice - 1] = 10;
            printf("The new product %s has been filled to full.\n\n", abcde[choice - 1]);
            quit9_4 = 1;
        }
        else if (choice == 0){
                printf("Going back!\n\n");
                quit9_4 = 1;
            }
        else
                printf("Invalid choice!\n\n");
    }
    return 0;
}

int choice9(void)
{
    int pwd = 1110; /*管理员密码*/
    int iptpwd; /*用户输入密码*/
    int quit9 = 0; /*判断是否需要退出，0不退出，1退出*/
    int choice = 10; /*用户选择*/
    printf("\n(9) Opening service menu. Access code is required.\n");
    printf("Enter access code: ");
    scanf("%d", &iptpwd);
    if(iptpwd - pwd == 0){
        printf("Correct code!\n\n");
        while(quit9 == 0){
            menu9();
            scanf("%d", &choice);
            switch(choice){
                case 1: choice9_1(); break;
                case 2: {
                    /*9-2. Withdraw all money*/
                    printf("\n(9-2) All money is being withdrawn.\n");
                    printf("$%d is withdrawn.\n\n", deposit + income);
                    deposit = 0;
                    income = 0;
                    break;
                    }
                case 3: choice9_3(); break;
                case 4: choice9_4(); break;
                case 0: printf("Going back!\n\n"); quit9 = 1; break;
                default: printf("Invalid choice!\n\n"); break;
            }
        }
    }
    else{
        printf("Incorrect code!\n\n");
        homepage();
    }
    return 0;
}

int main(void)
{
    /*正式运行*/
    int quit = 0; /*判断是否需要退出，0不退出，1退出*/
    int choice = 10; /*用户选择*/
    homepage();
    while (quit == 0){
        give = "="; /*买到的物品清空*/
        homemenu();
        scanf("%d", &choice);
        switch(choice){
            case 1: choice1(); break;
            case 2: choice2(); break;
            case 3: choice3(); break;
            case 4: {
                /*4. Press return button*/
                printf("(4) Return button is pressed.\n$%d has been returned.", deposit);
                deposit = 0;
                printf("\n");
                homepage();
                break;
            }
            case 9: choice9(); break;
            case 0: quit = 1; printf("\n\nProcess finished with exit code 0\n"); break;
            default: printf("Invalid choice!\n\n"); break;
        }
    }
    return 0;
}
