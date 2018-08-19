//顺序表数据结构

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 256
#define DataType int

//顺序表
typedef struct {
    DataType Data[MAX_SIZE]; 
    int len;
} SeqList;

//push元素
//使用这个函数前，l结构体必须初始化
int Pushback(SeqList *l, DataType elem) {
    if (l->len == MAX_SIZE) {
        return -2;//表满了
    }
    l->Data[l->len] = elem;
    l->len++;
    return 0;
}

//插入
int Insert(SeqList *l, DataType elem, int pos) {
    if (pos < 1 || pos > l->len) {
        return -1;      
    }
    
    if (l->len >= MAX_SIZE) {
        return -2;//表满了
    }

    for (int index = l->len; index >= pos; index--) {
        l->Data[index] = l->Data[index-1];
    }
    l->Data[pos-1] = elem;
    l->len++;

    return 0;
}

//元素为空
bool Empty(SeqList l) {
    if (l.len == 0) {
        return true;
    } else
        return false;
}


//查找元素
int Find(SeqList l, DataType elem) {
    if (Empty(l)) {
        return -1;
    }
  
    for (int index = 0; index < l.len; index++) {
        if (l.Data[index] == elem) {
            return index + 1;   
        }
    }
    return -2;
}

//删除
int Del(SeqList *l, DataType elem) {
    int pos = Find(*l, elem);
    if (pos == -1) {
        return -1;
    }
    for (int index = pos; index < l->len; index++) {
        l->Data[index-1] = l->Data[index];
    }
    l->len--;

    return pos;
}

//打印元素
void Print(SeqList l) {
    for (int index = 0; index < l.len; index++) {
        printf("%d ", l.Data[index]);
    }
    printf("\n");
}


int main() {
    SeqList seq_list;
    memset(&seq_list, 0, sizeof(SeqList));

    Pushback(&seq_list, 2);
    Pushback(&seq_list, 3);
    Pushback(&seq_list, 4);
    Insert(&seq_list, 5, 3);
    Insert(&seq_list, 6, 2);
    Insert(&seq_list, 1, 1);
    Del(&seq_list, 4);
    int pos = Find(seq_list, 4);
    printf("元素4的位置在:%d\n", pos);
    Print(seq_list);


    return 0;
}
