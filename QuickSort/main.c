//
//  main.c
//  AlgoritmaAnalizi
//
//  Created by nevzat on 30/10/15.
//  Copyright © 2015 nevzat. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void quickSort(int left,int right);
int partitionLeft(int left,int right);
int partitionRandom(int left,int right);
int partitionSecondMax(int left,int right);
int *array,sayi;
int main()
{
    int elemanSayisi,i;
    double timeForPivotLeft=0.0;
    clock_t start, end;
    printf("Kac elemanli bir array gireceksiniz? \n");
    scanf("%d",&elemanSayisi);
    printf("\n");
    array = (int *)malloc(sizeof(int)*elemanSayisi);
    
    for(i=0;i<elemanSayisi;i++)
    {
        //printf("%d. Elemani girin :",i+1);
        //scanf("%d",&sayi);
        //int rando = rand()%elemanSayisi;
        //array[i]=rando;
        array[i]=i;
    }
    
    printf("\n");
    printf("Siralanmamis array \n");
    
    
    
    start = clock();
    quickSort(0,elemanSayisi-1);
    end = clock();
    timeForPivotLeft = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n\n%f\n",timeForPivotLeft);
    printf("sirali array \n");
    
    for(i=0;i<elemanSayisi;i++)
    {
        printf("%d ",array[i]);
    }
    
}
void quickSort(int left,int right)
{
    if (left < right)
    {
        int p = partitionRandom(left, right);
        quickSort(left, p-1);
        quickSort(p + 1, right);
    }
    
}
void swap(int left,int right)
{
    int temporary = array[left];
    array[left] = array[right];
    array[right] = temporary;
}

int partitionLeft(int left,int right)
{
    int i=left;
    int j=right+1;
    
    int pivotValue = array[left];
    do
    {
        do
        {
            i++;
        }while((i<j)&&(array[i]<=pivotValue));
        
        do
        {
            j--;
        }while (array[j]>pivotValue);
        
        swap(i,j);
    }while(i<=j);
    swap(i,j);
    swap(j,left);
    return j;
    
    
}
int partitionRandom(int left,int right)
{
    int i=left;
    int j=right;
    int random = (rand()%(right-left))+left;
    swap(left, random);
    
    int pivotValue = array[left];
    while (i<j)
    {
        while((i<j)&&(array[i]<=pivotValue))
        {
            i++;
        }
        
        while (array[j]>pivotValue)
        {
            j--;
        }
        
        swap(i,j);
    }
    swap(i,j);
    swap(j,left);
    return j;
    
}
int partitionSecondMax(int left,int right)
{
    int i=left;
    int j=right;
    int secondMax;
    int mid = (left+right)/2;
    if((array[mid]>array[left])&&(array[mid]>array[right])&&(array[left]>array[right]))
        secondMax=left;
    else if((array[right]>array[left])&&(array[mid]>array[left])&&(array[right]>array[mid]))
        secondMax=mid;
    else
        secondMax=right;
    swap(left, secondMax);
    int pivotValue = array[left];
    while(i<j)
    {
        while((i<j)&&(array[i]<=pivotValue))
        {
            i++;
        }
        
        while (array[j]>pivotValue)
        {
            j--;
        }
        
        swap(i,j);
    }
    swap(i,j);
    swap(j,left);
    return j;
    
}