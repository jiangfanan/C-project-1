//
//  main.c
//  xcode2020-2
//
//  Created by 蒋凡安 on 2020/2/25.
//  Copyright © 2020 蒋凡安. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
int main() {
   
    printf("请选择难度等级");
    printf("1. 0~9\n");
    printf("2. 0~99\n");
    printf("3. 0~999\n");
    printf("0. 退出\n");
    printf("你的输入：");
    int m;
    scanf("%d",&m);
    while(m<10){
        int rand(void);
        int i;
        i = rand()%10;
        printf("你当前选择的难度等级0~9\n");
        printf("请输入想要猜的次数，0返回上一级\n");
        break;
    }
    while(m>10&& m<100){
        int rand(void);
        int i;
        i = rand()%10;
        printf("你当前选择的难度等级0~99\n");
        printf("请输入想要猜的次数，0返回上一级\n");
        break;
    }
    while(m>99&& m<999){
        int rand(void);
        int i;
        i = rand()%10;
        printf("你当前选择的难度等级0~999\n");
        printf("请输入想要猜的次数，0返回上一级\n");
        break;
    }
    
    int j;
    scanf("%d",&j);
     printf("现在开始猜数\n");
    for(int a=j;a>0;a--){
        printf("请输入数字：");
        int b;
        scanf("%d",&b);
        if(b<m){
            printf("输入的是%d,\n",b);
            printf("没有猜中，猜小了。\n");
        }
        if(b>m){
            printf("输入的是%d,\n",b);
            printf("没有猜中，猜大了。\n");
        }
       printf("剩余次数%d",a);
    }
   
    
}

