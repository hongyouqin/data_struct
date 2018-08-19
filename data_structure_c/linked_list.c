//单链表数据结构

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DataType int

typedef struct node {
    DataType data;
    struct node *next;
} Node;

typedef struct {
    Node *header;
} LinkedList;

//创建节点
Node *CreateNode() {
    Node *node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    return node;
}

//释放节点
void FreeNode(Node *node) {
    free(node);
}

//push元素, 在头的部分插入
void Push(LinkedList *list, DataType elem) {
    if (list->header == NULL) {
        list->header = CreateNode();
    }

    Node *new_node = CreateNode();
    new_node->data = elem;
    new_node->next = list->header->next;
    list->header->next = new_node;
}

//获取节点的个数
int GetLength(LinkedList *list) {
    Node *node = list->header;
    if (node == NULL) {
        return 0;
    }
    int count = 0;
    while (node->next) {
        count++;
        node = node->next;
    }
    return count;
}

//获取节点
Node *GetNode(LinkedList *list, int pos) {
    Node *node = list->header;
    if (node == NULL) {
        return NULL;
    }

    if (pos <= 0) {
        return node;
    }
    int count = 0;
    while (node->next) {
        count++;
        if (pos == count) {
            return node->next;
        }
        node = node->next;
    }
    return NULL;
}

//插入
int Insert(LinkedList *list, DataType elem, int pos) {
    if (pos < 1) {
        return -1;
    }
    Node *pre_node = GetNode(list, pos-1);
    if (NULL == pre_node) {
        return -2;
    }
    Node *cur_node = pre_node->next;
    Node *new_node = CreateNode();
    new_node->data = elem;
    pre_node->next = new_node;
    new_node->next = cur_node;
    return 0;
}

//删除
int Del(LinkedList *list, int pos) {
   if (pos < 1) {
        return -1; 
   }

   Node *pre_node = GetNode(list, pos-1);
   if (NULL == pre_node) {
       return -2;
   }
   Node *cur_node = pre_node->next;
   if (cur_node == NULL) {
        return -3; 
   }
   pre_node->next = cur_node->next;
   FreeNode(cur_node);
   return 0;
}


//打印
void Print(LinkedList list) {
    Node *node = list.header->next;
    while(NULL != node) {
        DataType data = node->data;
        printf("%d ", data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    memset(&list, 0, sizeof(LinkedList));
    Push(&list, 4);
    Push(&list, 5);
    Push(&list, 6);
    int code = Insert(&list, 7, 3);
    if (code != 0) {
        printf("插入失败, 失败码:%d\n",code);
    }
    Del(&list, 2);
    Print(list);
    return 0;
}
