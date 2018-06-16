

//堆栈的使用：
//对于每一组测试数据，第一行为正整数n（0～10000），n等于0结束
//之后的n行，每行的第一个字符为'A','P','O'三者之一
//如果为'P',则将后面的整数压入栈中
//如果为'O',弹出栈顶元素，如果栈为空，则忽略本次操作
//如果为'A',栈顶为空，打印'E'，栈不为空，返回栈定元素
//
//循环输入多组数据，进行上述操作，如果输入n为0时，结束上述循环
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
