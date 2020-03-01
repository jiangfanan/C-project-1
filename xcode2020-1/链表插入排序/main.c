//
//  main.c
//  链表插入排序
//
//  Created by 蒋凡安 on 2020/2/29.
//  Copyright © 2020 蒋凡安. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode* LinkList;

struct ListNode* insertionSortList(struct ListNode* head){
    if(!head)
        return NULL;
    LinkList L=(LinkList )malloc(sizeof(struct ListNode));
    L->next=head;
    LinkList p=head->next,pre,temp;
    head->next=NULL;
    while(p){
        temp=p->next;
        pre=L;
        while(pre->next&&pre->next->val<p->val){
            pre=pre->next;
        }
        p->next=pre->next;
        pre->next=p;
        p=temp;
    }
    return L->next;
}
