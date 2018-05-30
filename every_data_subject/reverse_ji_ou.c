
#include<stdio.h>
#include<stdlib.h>

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;

}

void Reverse(int num[], int start, int end)
{
    while (start < end)
    {
        Swap(&num[start], &num[end]);
        start++;
        end--;

    }

}

//将奇数放在前半部分，偶数放在后半部分，相对位置不变
void reOrderArray(int num[], int size)
{
    if (num == NULL || size <= 1)
    {
        return;
    }
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        while (start < end && num[start] % 2 != 0)
        {
            start++;
        }
        while (start < end && num[end] % 2 == 0)
        {
            end--;
        }
        if (start < end)
        {
            Swap(&num[start], &num[end]);
        }
    }
    int i = 0;
    for (; i < size; i++)
    {
        if (num[i] % 2 == 0)
        {
            break;
        }
    }
    Reverse(num, 0, i - 1);
    Reverse(num, i, size - 1);
}
int main()
{
    int num[] = { 8, 4, 2, 1, 3, 5  };
    int size = sizeof(num) / sizeof(num[0]);
    reOrderArray(num, size);
    int i = 0;
    for (; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;

}
