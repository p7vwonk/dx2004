#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* HEAD = NULL;

void INSERT(int nums, int posi) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = nums;
    newnode->next = NULL;

    if (HEAD == NULL) {
        HEAD = newnode;
        return;
    }

    if (posi == 0 || posi == 1) {
        newnode->next = HEAD;
        HEAD = newnode;
        return;
    }

    Node* temp = HEAD;
    for (int i = 0; i < posi - 1; i++) {
        if (temp == NULL) {
            break;
        }
        temp = temp->next;
    }

    if (temp != NULL) {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void PRINT(Node* q) {
    Node* temp = q;
    while (temp == NULL) {
        return;
    }
    printf("%d ",temp->data);
    PRINT(q->next);
}

Node* REVERSE(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newHead = REVERSE(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}


int main() {
    int i, nums, posi;

    printf("请输入您想要输入多少个数字：");
    scanf("%d", &i);

    for (int k = 0; k < i; k++) {
        printf("请输入您想要插入的数字和位置：");
        scanf("%d%d", &nums, &posi);
        INSERT(nums, posi);
    }

    printf("现在开始翻转链表...\n");
    HEAD = REVERSE(HEAD);
    PRINT(HEAD);

    return 0;
}
