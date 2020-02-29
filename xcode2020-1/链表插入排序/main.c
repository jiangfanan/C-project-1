//
//  main.c
//  链表插入排序
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
    r=p;
    q=p->next;
    while(p!=NULL){
    while(q!=NULL){
        if(q->data>p->data)
            q=q->next;
        if(q->next<=p->next)
        {
            r=q;
            q=q->next;
        }
    }
     int m;
     m=r->data;
    r->data=p->data;
    p->data=m;
    p=p->next;
        
    }
    while(p!=NULL){
        printf("%d\n",p->data);
       p=p->next;
    }
   return 0;
    }


