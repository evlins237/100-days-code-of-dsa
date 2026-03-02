#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL, *temp1 = NULL, *temp2 = NULL, *newNode;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        if (head1 == NULL) {
            head1 = newNode;
            temp1 = head1;
        } else {
            temp1->next = newNode;
            temp1 = newNode;
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        if (head2 == NULL) {
            head2 = newNode;
            temp2 = head2;
        } else {
            temp2->next = newNode;
            temp2 = newNode;
        }
    }

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    temp1 = head1;
    temp2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++)
            temp1 = temp1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++)
            temp2 = temp2->next;
    }

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data == temp2->data) {
            printf("%d", temp1->data);
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    printf("No Intersection");
    return 0;
}
