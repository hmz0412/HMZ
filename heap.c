#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

void swap2_num(int *x,int *y){
    int tmp=0;
    tmp=*x;
    *x=*y;
    *y=tmp;

}

void maxheapfy_num(int a[],int root,int len){
    int left=2*root;
    int right=2*root+1;
    int largest;
    if(left<len && a[left]>a[root]){
        largest=left;
    }
    else{
        largest=root;
    }
    if(right<len && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=root){
        swap2_num(&a[largest],&a[root]);
        maxheapfy_num(a,largest,len);
    }
}

void builtmaxheap_num(int a[],int length){
    int i;
    for(i=(length/2);i>=0;i--){
        maxheapfy_num(a,i,length);
    }
}

void heapsort_num(int a[],int length){
    int i=0;
    builtmaxheap_num(a,length);
    for(i=length-1;i>0;i--){
        swap2_num(&a[0],&a[i]);
        maxheapfy_num(a,0,i);
    }
}


void swap2_str(char *x,char *y){
    char tmp[100];
    strcpy(tmp,x);
    strcpy(x,y);
    strcpy(y,tmp);

}

void maxheapfy_str(char *a[],int root,int len){
    int left=2*root;
    int right=2*root+1;
    int largest;
    if(left<len && strcmp(a[left],a[root])>0){
        largest=left;
    }
    else{
        largest=root;
    }
    if(right<len && strcmp(a[right],a[largest])>0){
        largest=right;
    }
    if(largest!=root){
        swap2_str(a[largest],a[root]);
        maxheapfy_str(a,largest,len);
    }
}

void builtmaxheap_str(char *a[],int length){
    int i;
    for(i=(length/2);i>=0;i--){
        maxheapfy_str(a,i,length);
    }
}

void heapsort_str(char *a[],int length){
    int i=0;
    builtmaxheap_str(a,length);
    for(i=length-1;i>0;i--){
        swap2_str(a[0],a[i]);
        maxheapfy_str(a,0,i);
    }
}
