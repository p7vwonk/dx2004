#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *HEAD = NULL; // 全局变量，方便调用

void INSERT(int nums, int posi)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = nums;
    newNode->next = NULL;
    if (HEAD == NULL) // 空表
    {
        HEAD = newNode;
        return;
    }
    if (posi == 0) // 头插
    {
        newNode->next = HEAD;
        HEAD = newNode;
        return;
    }
    // 其他位置，中间和后面
    Node *temp1 = HEAD;
    for (int i = 0; i < posi - 1; i++)
    {
        if (temp1->next == NULL)
        {
            // 插入位置超过链表长度，在尾部插入
            break;
        }
        temp1 = temp1->next;
    }
    newNode->next = temp1->next;
    temp1->next = newNode;
}

void PRINT()
{
    Node *temp = HEAD;
    printf("当前链表的数据： ");
    while (temp != NULL)
    {
        printf("%d ", temp->data); // 在数据之间添加空格
        temp = temp->next;
    }
    printf("\n");
}

void DELETE(int position){
    Node *temp1 = HEAD;
    for (int i = 0; i < position-1; i++)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

int main()
{
    int i, nums, n, posi;
    printf("您要插入多少个数据？");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("请输入您要插入的数据和位置（空格隔开）: ");
        scanf("%d%d", &nums, &posi);
        INSERT(nums, posi);
        PRINT();
    }
    
    return 0;
}
