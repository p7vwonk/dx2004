#include <stdio.h>

#define N 10000//定义数组大小

void swap(int* i,int* j){//交换数组，典中典写法，简单好用
    int temp = *i;
    *i = *j;
    *j = temp;
}

void quick_sort(int q[N],int l,int r){//逆序排序
    if(l>=r){//如果数组只有一位，直接输出，也是递归的基线条件
        return;
    }
    int x = q[l];//x为选择数组第一项的数值为基准数
    int i = l - 1;//最左边开始向中间移动，-1是因为一开始就要i++
    int j = r + 1; //最右边开始向中间移动，+1是因为一开始就要j--

    while (i<j)//第一次排序
    {
        do
        {
            i++;
        } while (q[i]>x);//比x小的数值都放在基准数左边，直到遇到比x大的数值，那就停止循环

        do
        {
            j--;
        } while (q[j]<x);//比x大的数值都放在基准数右边，直到遇到比x小的数值，停止循环

        if(i<j){
            swap(&q[i], &q[j]);//左右都停止了，交换两数，再次进行如上操作
        }
    }
    quick_sort(q, l, j);//比x小的那部分数组继续分成两部分排序
    quick_sort(q, j + 1, r);//比x大的那部分数组继续分成两部分排序
    //一直递归，直到达到基准条件为止，排序完成
}

int main()
{
    int n;
    scanf("%d", &n);

    int q[N];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", q[i]);
    }

    return 0;
}

//慢慢来吧!