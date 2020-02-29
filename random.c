#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *k,int *l){
    int m=*k;
    *k=*l;
    *l=m;
    
}
void RANDOM(int *a[],int length){
    for(int i=length;i>0;i--){
        time_t t;
        srand((unsigned)time(&t));
        int m=rand()%i;
        swap(a[i-1],a[m]);
    }
}
int main() {
    int *a[]={0,1,2,3,4,5,6,7};
    RANDOM(a,8);
    int i;
    for(i=0;i<8;i++)
        printf("%d",a[i]);
    }

