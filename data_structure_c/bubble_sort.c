//冒泡排序
//冒泡排序是一种交换排序方法；基本思想是，比较两个记录键值的大小出现逆序，则交换着两个记录，这样将键值较小的纪录向序列前部移动，键值较大的纪录向序列后部移动。
// ｛45， 23， 44， 66， 90， 88， 10， 25， 45｝

#include <stdio.h>
#include <stdbool.h>

void Print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void BubbleSort(int a[], int n) {
    for (int i = 0; i< n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[j] < a[j-1]) {
                //交换
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
        printf("第%d趟排序后\n", i+1);
        Print(a, n);
    }
}

int main(int argc, char *argv[]) {
    int a[] = {45,23,44,66,90,88,10,25,45};
    
    printf("排序前:\n");
    Print(a, sizeof(a) / sizeof(a[0]));
    
    BubbleSort(a, sizeof(a) / sizeof(a[0]));

    printf("排序后:\n");
    Print(a, sizeof(a) / sizeof(a[0]));
    return 0;
}
