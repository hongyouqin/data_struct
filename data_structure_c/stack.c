//stack 的实现
//链表的方式实现栈
//栈的特点的是先进后出
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define DataType int
#define ERROR_VAL 65535


//栈
typedef struct Node {
    DataType data;
    struct Node *next;
} Stack;

//栈顶
//stack是否为空
bool Empty(Stack stack) {
    if (stack.next == NULL) {
        return true;
    }
    return false;
}

//取元素
DataType Pop(Stack *stack){
    if (Empty(*stack)) {
        return ERROR_VAL;
    }
    struct Node *node = stack->next;
    DataType data = node->data;
    stack->next = stack->next->next;
    free(node);

    return data;
}

//押入元素
void Push(Stack *stack, DataType data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    struct Node *temp = stack->next;
    stack->next = node;
    node->next = temp;

}

//元素个数
int Count(Stack stack) {
   int count = 0;
   struct Node *node = stack.next;
   while(node) {
        count++;
        node = node->next;
   }
   return count;
}

//打印元素
void Print(Stack stack) {
    struct Node *node = stack.next;
    DataType data;
    while(node) {
        data = node->data;
        printf("元素: %d\n", data);
        node = node->next;
    }
}


int main() {
    Stack stack;
    stack.next = NULL;
    Push(&stack, 3);
    Push(&stack, 4);
    Push(&stack, 5);
    Push(&stack, 9);
    Push(&stack, 10);
    printf("栈前：\n");
    Print(stack);
    printf("栈个数: %d\n",  Count(stack));
    printf("出栈: %d\n", Pop(&stack));
    printf("出栈: %d\n", Pop(&stack));
    printf("栈后: \n");
    Print(stack);
    printf("栈个数: %d\n", Count(stack));
    return 0;
}
