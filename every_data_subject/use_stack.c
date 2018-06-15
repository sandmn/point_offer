#include<stdio.h>                                                                                                                   
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct SeqStack
{
    int data[128];
    int size;


}SeqStack;

void        SeqStackInit(SeqStack* stack)
{
    stack->size = 0;
    return;

}

void SeqStackPush(SeqStack* stack, int num)
{
    stack->data[stack->size++] = num;
    return;

}
void SeqStackPop(SeqStack* stack)
{
    if (stack->size != 0)
    {
        stack->size--;

    }
    return;


}
int SeqStackTop(SeqStack* stack)
{
    if (stack->size != 0)
    {
        return stack->data[stack->size - 1];

    }
    return -1;


}

void Operation(char* buf, SeqStack* stack)
{
    //进行入栈操作
    if (*buf == 'P')
    {
        buf += 2;
        SeqStackPush(stack, atoi(buf));
        return;
    }
    else if (*buf == 'O')
    {
        if (stack->size != 0)//栈不为空
        {
            SeqStackPop(stack);//进行出栈操作
        }
        return;
    }
    else
    {
        if (stack->size == 0)
        {
            printf("E\n");
        }
        else
        {
            int top = SeqStackTop(stack);
            printf("%d\n", top);
        }
        return;
    }
}


int main()
{
    int n = 0;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        SeqStack stack;
        SeqStackInit(&stack);
        int i = 0;
        for (i = 0; i < n; i++)
        {
            char* temp = (char*)malloc(4);
            int s = read(0, temp, sizeof(temp));
            if (s > 0)
            {
                temp[s - 1] = 0;
            }
            Operation(temp, &stack);
        }
        printf("\n");
    }
    return 0;
}
