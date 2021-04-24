#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
#define len 100

void swap_str(char *x,char *y){
    char temp[len];
    strcpy(temp,x);
    strcpy(x,y);
    strcpy(y,temp);
}
int partition_str(char *arr[],int front,int end){
    char pivot[len];
    strcpy(pivot,arr[end]);
    int i=front-1;
    int j=0;
    for(j=front;j<end;j++){
        if(strcmp(arr[j],pivot)<=0){
            i++;
            swap_str(arr[j],arr[i]);
        }
    }
    i++;
    swap_str(arr[i],arr[end]);
    return i;
}
void quicksort_str(char *arr[],int front,int end){
    int pivot;
    if(front<end){
        pivot=partition_str(arr,front,end);
        quicksort_str(arr,front,pivot-1);
        quicksort_str(arr,pivot+1,end);
    }
}

void swap_num(int *x,int *y){
    int temp=0;
    temp=*x;
    *x=*y;
    *y=temp;
}
int partition_num(int *arr,int front,int end){
    int pivot=arr[end];
    int i=front-1;
    int j=0;
    for(j=front;j<end;j++){
        if(arr[j]<pivot){
            i++;
            swap_num(&arr[j],&arr[i]);
        }
    }
    i++;
    swap_num(&arr[i],&arr[end]);
    return i;
}
void quicksort_num(int *arr,int front,int end){
    int pivot;
    if(front<end){
        pivot=partition_num(arr,front,end);
        quicksort_num(arr,front,pivot-1);
        quicksort_num(arr,pivot+1,end);
    }
}
