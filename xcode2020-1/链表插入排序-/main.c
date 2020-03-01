//
//  main.c
//  链表插入排序-
//
//  Created by 蒋凡安 on 2020/2/29.
//  Copyright © 2020 蒋凡安. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node{
    int data;
    struct node *next;
};

int main() {
    struct node *p;
    struct node *head;
    head =(struct node*)malloc (sizeof (struct node));
    head->data=NULL;
    head->next=NULL;//初始化头结点
    int i=0;
    int len=10;
    srand(time(NULL));
    for(i=0;i<len;i++){
        p= (struct node *)malloc(sizeof(struct node));
        p->data =rand()%100;

        p->next=head->next;
        head->next=p;
    }//利用头插法将数加入链表
    struct node *q;
    struct node *r;
    p=head->next;
    q=p->next;
    for (int i=1;i<10;i++)
        for(int j=0;j<i;j++)
        {
            if(q->data>p->data)
                q=q->next;
            if(q->next<=p->next)
            {
                r=q;
                q=q->next;
            }
        }
    return 0;
}
