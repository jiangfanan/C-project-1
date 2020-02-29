//
//  main.c
//  rand2-2
//
//  Created by 蒋凡安 on 2020/2/27.
//  Copyright © 2020 蒋凡安. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int a[]={0,1,2,3,4,5,6,7};
    for(int i=8;i>0;i--){
       time_t t;
        srand((unsigned)time(&t));
        int m=rand()%i;
        int temp=a[m];
        a[m]=a[i-1];
        a[i-1]=temp;
    }
    int m;
    for(m=0;m<8;m++)
        printf("%d",a[m]);
}
