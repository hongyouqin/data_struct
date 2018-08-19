//队列的实现
//先进先出
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DataType int

typedef struct LinkedNode {
    DataType data;
    struct LinkedNode *next;
} Node;

typedef struct LinkedQueue {
    Node *first;
    Node *rear;
} Queue;

//初始化
void InitQueue(Queue *q) {
    q->first = NULL;
    q->rear = NULL;
}

//队为否为空
bool Empty(Queue q) {
    if (q.first == NULL && q.first == q.rear) {
        return true;
    }
    return false;
}

//入队
void Enqueue(Queue *q, DataType data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    printf("入队：%d\n", data);
    if (Empty(*q)) {
        q->first = node;
        q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = q->rear->next;
    }
}

//出队
void Dequeue(Queue *q, DataType *data) {
    if (Empty(*q)) {
        printf("队列已空\n");
        return;
    }
    Node *node = q->first;
    *data = node->data;
    q->first = node->next;
    if (q->first == q->rear) {
        q->rear = NULL;
    }
    printf("出队列: %d\n", node->data);
    free(node);
}

//输出队列
void Print(Queue q) {
    Node *temp = q.first;
    while(temp != q.rear) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", q.rear->data);
    printf("\n");
}

int main(int agrc, char *agrv[]) {
    Queue q;
    InitQueue(&q);
    Enqueue(&q, 2);
    Enqueue(&q, 7);
    Enqueue(&q, 9);
    DataType data;
    Dequeue(&q, &data);
    Dequeue(&q, &data);
    Dequeue(&q, &data);
    Dequeue(&q, &data);
    Enqueue(&q, 6);
    Enqueue(&q, 8);
    Dequeue(&q, &data);
    Dequeue(&q, &data);
 //   Print(q);


    return 0;
}
