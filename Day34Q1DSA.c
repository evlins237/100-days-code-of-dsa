#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) return 0;
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    int num;
    char token;

    while (scanf("%d", &num) == 1) {
        push(num);
        token = getchar();
        if (token == '\n') break;
    }

    while (scanf(" %c", &token) == 1) {
        if (token == '+' || token == '-' || token == '*' || token == '/') {
            int b = pop();
            int a = pop();
            int res;

            if (token == '+') res = a + b;
            else if (token == '-') res = a - b;
            else if (token == '*') res = a * b;
            else res = a / b;

            push(res);
        }
    }

    printf("%d", pop());

    return 0;
}
