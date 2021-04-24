#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len 100

void Merge_str(char *arr[],int front,int end,int mid){
    int num_L=mid-front+1;
    int num_R=end-mid;
    char *Lsub_arr[num_L+1];
    char *Rsub_arr[num_R+1];
    int i=0;
    int j=0;
    int k=0;
    for(i=0;i<=num_L;i++){
        Lsub_arr[i]=malloc(sizeof(char)*len);
        if(i==num_L) break;
        strcpy(Lsub_arr[i],arr[front+i]);
    }
    for(i=0;i<=num_R;i++){
        Rsub_arr[i]=malloc(sizeof(char)*len);
        if(i==num_R) break;
        strcpy(Rsub_arr[i],arr[mid+1+i]);
    }
    for(i=0;i<len;i++){
        Lsub_arr[num_L][i]='z';
    }
    Lsub_arr[num_L][i]='\0';
     for(i=0;i<len;i++){
        Rsub_arr[num_R][i]='z';
    }
    Rsub_arr[num_R][i]='\0';
    i=0;
    j=0;
    for(k=front;k<=end;k++){
        if(strcmp(Lsub_arr[i],Rsub_arr[j])>=0){
            strcpy(arr[k],Rsub_arr[j]);
            j++;
        }
        else{
            strcpy(arr[k],Lsub_arr[i]);
            i++;
        }
    }
}


void Mergesort_str(char *arr[],int front,int end){
    int mid;
    if(front<end){
        mid=(front+end)/2;
        Mergesort_str(arr,front,mid);
        Mergesort_str(arr,mid+1,end);
        Merge_str(arr,front,end,mid);
    }
}


void Merge_num(int *arr,int front,int end,int mid){
    int num_L=mid-front+1;
    int num_R=end-mid;
    int Lsub_arr[num_L+1];
    int Rsub_arr[num_R+1];
    int i=0;
    int j=0;
    int k=0;
    for(i=0;i<num_L;i++){
        Lsub_arr[i]=arr[front+i];
    }
    for(j=0;j<num_R;j++){
        Rsub_arr[j]=arr[mid+1+j];
    }
    Lsub_arr[num_L]=2147483647;
    Rsub_arr[num_R]=2147483647;
    i=0;
    j=0;
    for(k=front;k<=end;k++){
        if(Lsub_arr[i]>=Rsub_arr[j]){
            arr[k]=Rsub_arr[j];
            j++;
        }
        else{
            arr[k]=Lsub_arr[i];
            i++;
        }
    }
}


void Mergesort_num(int *arr,int front,int end){
    int mid;
    if(front<end){
        mid=(front+end)/2;
        Mergesort_num(arr,front,mid);
        Mergesort_num(arr,mid+1,end);
        Merge_num(arr,front,end,mid);
    }
}


