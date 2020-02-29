//
//  main.c
//  xcode2020-1
//
//  Created by 蒋凡安 on 2020/2/25.
//  Copyright © 2020 蒋凡安. All rights reserved.
//

#include <stdio.h>
#define NUMBER 9  //一个常数，整个程序都可以用

void print(int a[], int n, int i)

{
    printf("%d:  ", i); //输出i
    for (int j = 0; j < n; j++) {
        printf("%d  ", a[j]);
    }
    printf("\n");//将数打组中的数值一个一个打印出来
}

void insertSort(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = a[i];
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
        print(a, n, i);
    }
}

int main(void)
{
    int a[NUMBER] = {3, 1, 7, 5, 2, 4, 9, 6, 8};
    print(a, NUMBER, 0);
    insertSort(a, NUMBER);
    return 0;
}
