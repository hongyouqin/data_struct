//直接插入排序
//直接插入排序是一种简单的排序方法，它的基本思想是依次将每个记录插入到一个已排好序的有序表中去，从而得到一个新的、记录树增加1的有序表。

// {45, 38, 66, 90, 88, 10, 25, 45}
#include <stdio.h>
#include <stdbool.h>

//打印后回车
void Print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

}

//打印后不回车
void Print2(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void DirectInsertSort(int a[], int n) {
    int key; //岗哨
    int j;
    for (int i = 1; i < n; i++) {
       key = a[i];
       j = i-1;
       while(a[j] > key && j >= 0 ) {
            a[j+1] = a[j];
            j--;
       }
       a[j+1] = key;
       printf("第%d次排序\n", i);
       printf("[ ");
       Print2(a, i);
       printf("] ");
       Print(a+i, n-i);       
    } 

}

int main(int argc, char *argv[]) {
    int a[] = {45, 38, 66, 90, 88, 10, 25, 45};
    printf("排序前：\n");
    Print(a, sizeof(a)/sizeof(a[0]));
    DirectInsertSort(a, sizeof(a)/sizeof(a[0]));
    printf("排序后: \n");
    Print(a, sizeof(a)/sizeof(a[0]));       

    return 0;
}
