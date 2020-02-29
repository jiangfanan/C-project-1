//
//  main.c
//  rand
//
//  Created by 蒋凡安 on 2020/2/27.
//  Copyright © 2020 蒋凡安. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int a[8];
    for(int i=0;i<8;i++){
        time_t t;
        srand((unsigned)time(&t));
        a[i]=rand()%8;
        for(int j=1;i-j>=0;j++){
            while(a[i]==a[i-j]){
                 srand((unsigned)time(&t));
                a[i ]=rand()%8;
            }
            
        
    }
        printf("%d",a[i]);
}
    
}
