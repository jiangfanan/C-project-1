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
void display(struct node *);
int main(int argc,  char * argv[]) {
    // insert code here...
    struct node *p;
    struct node *head;
    head = p;
    int m;
    int i=0;
    int len=10;
    srand(time(NULL));
    for(i=0;i<len;i++){
        p= (struct node *)malloc(sizeof(struct node));
        p->data =rand()%100;
        p=p->next;
        }
    struct node *q;
    p=head->next;
    q=p->next;
    while(q!=NULL){
        if(q->data>p->data)
            q=q->next;
        else
        { int *m;
            *m=q->data;
        q->data=p->data;
        p->data=*m;
        q=q->next;
        }
        
        
    }
   p=head->next;
    while(p!=NULL){
        printf("%d",p->data);
    }
    return 0;
}

