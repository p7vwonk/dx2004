#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;
Node *HEAD = NULL;

void INSERT(int m, int posi)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = m;
    newnode->next = NULL;

    if (HEAD == NULL)
    {
        HEAD = newnode;
        return;
    }

    if (posi == 1|| posi==0)
    { // 头插法
        newnode->next = HEAD;
        HEAD = newnode;
        return;
    }

    Node *temp = HEAD;
    for (int i = 0; i < posi - 2; i++)
    { // 遍历找到位置
        if (temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void PRINT(){
    Node *temp = HEAD;
    while(temp!=NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void REVERSE(){
    Node *prev = NULL;
    Node *current = HEAD;
    Node *next = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    HEAD = prev;
}

int main(){
    int i, m, posi, n;
    printf("您要输入多少个数据？");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        printf("请输入您要输入的数值和想要插入的位置：");
        scanf("%d%d", &m, &posi);
        INSERT(m, posi);
        PRINT();
    }
    printf("开始反转链表...");
    REVERSE();
    printf("\n");
    PRINT();
    return 0;
}