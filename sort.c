#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "quicksort.h"
#include "merge.h"
#include "heap.h"
#define size 1000000
#define len 100

char *genRandomString(int length)
{
    int flag, i;
    char *string;
    string=malloc(sizeof(char)*length);
    for (i=0; i <length - 1; i++)
    {
        flag = rand() % 3;
        switch (flag)
        {
        case 0:
        string[i] = 'A' + rand() % 26;
        break;
        case 1:
        string[i] = 'a' + rand() % 26;
        break;
        case 2:
        string[i] = '0' + rand() % 10;
        break;
        default:
        string[i] = 'x';
        break;
        }
    }
    string[length - 1] = '\0';
    return string;
}

int main(){
    int i=0;
    char *Qstr[size];
    char *Mstr[size];
    char *Hstr[size];
    int Qnum[size];
    int Mnum[size];
    int Hnum[size];
    FILE *fp1,*fp2;
    FILE *fp3,*fp4;
    fp1=fopen("data1.txt","w");
    fp2=fopen("data2.txt","w");
    for(i=0;i<size;i++){
        Qstr[i]=malloc(sizeof(char)*len);
        Mstr[i]=malloc(sizeof(char)*len);
	    Hstr[i]=malloc(sizeof(char)*len);
    }
    for(i=0;i<size;i++){
	    fprintf(fp1,"%d\n",rand());
        fprintf(fp2,"%s\n",genRandomString(len));
    }
    fclose(fp1);
    fclose(fp2);
    fp3=fopen("data1.txt","r");
    fp4=fopen("data2.txt","r");//rewind??髡
    for(i=0;i<size;i++){
	    fscanf(fp3,"%d",&Qnum[i]);
        fscanf(fp4,"%s",Qstr[i]);
    }
    rewind(fp3);
    rewind(fp4);
    struct timeval start;
    struct timeval end;
    unsigned long diff;
    gettimeofday(&start, NULL);
    quicksort_num(Qnum,0,size-1);
    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
    printf("quick Sort performance for num %ld us (equal %f sec)\n", diff, diff / 1000000.0);
    gettimeofday(&start, NULL);
    quicksort_str(Qstr,0,size-1);
    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
    printf("quick Sort performance for str %ld us (equal %f sec)\n", diff, diff / 1000000.0);
    for(i=0;i<size;i++){
	fscanf(fp3,"%d",&Mnum[i]);
	fscanf(fp4,"%s",Mstr[i]);
    }
    rewind(fp3);
    rewind(fp4);
   gettimeofday(&start, NULL);
   Mergesort_num(Mnum,0,size-1);
   gettimeofday(&end,NULL);
   diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
   printf("merge Sort performance for num %ld us (equal %f sec)\n", diff, diff / 1000000.0);
   gettimeofday(&start, NULL);
   Mergesort_str(Mstr,0,size-1);
   gettimeofday(&end,NULL);
   diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
   printf("merge Sort performance for str %ld us (equal %f sec)\n", diff, diff / 1000000.0);
    for(i=0;i<size;i++){
	fscanf(fp3,"%d",&Hnum[i]);
	fscanf(fp4,"%s",Hstr[i]);
    }
    gettimeofday(&start, NULL);
    heapsort_num(Hnum,size);
    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
    printf("heap Sort performance for num %ld us (equal %f sec)\n", diff, diff / 1000000.0);
    gettimeofday(&start, NULL);
    heapsort_str(Hstr,size);
    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
    printf("heap Sort performance for str %ld us (equal %f sec)\n", diff, diff / 1000000.0);
 }


