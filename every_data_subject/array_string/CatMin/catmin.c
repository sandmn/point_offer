#include<stdio.h>
#include"seqstack.h"
#include<math.h>

int Front(int num1,int num2)
{
    if(num1 == num2)
    {
        return 1;
    }
    int count1 = 0;
    int count2 = 0;

    int tmp_num1 = num1;
    int tmp_num2 = num2;

    while (tmp_num1 > 9)
    {
        tmp_num1 = tmp_num1 / 10;
        count1++;//r的位数
    }
    while(tmp_num2 > 9)
    {
        tmp_num2 = tmp_num2 / 10;
        count2++;
    }
    while(count1 != 0 && count2 != 0)
    {
        if(num1/pow(10,count1) > num2/pow(10,count2))
        {
            return 1;
        }
        else if(num1/pow(10,count1) < num2/pow(10,count2))
        {
            return -1;
        }
        else
        {
            num1 = num1 - pow(10,count1);
            num2 = num2 - pow(10,count2);
            count1--;
            count2--;
        }
    }
    if(count1 == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
 //   int i = 0;
 //   while (count)
 //   {
 //       putchar(r /pow(10,count) + '0');
 //       r = r - pow(10, count);
 //       count--;
 //                                                           
 //   }
 //   while(1)
 //   {
 //       if()
 //   }
}


void CatMin(int num[],int size)
{
    if(num == NULL || size <= 0)
    {
        return;
    }
    if(size == 1)
    {
        printf("%d",num[0]);
        return;
    }

    SeqStack stack1;
    SeqStack stack2;
    InitSeqStack(&stack1);
    InitSeqStack(&stack2);

    SeqStackPush(&stack1,num[0]);
    int i;
    int ret;
    int top1;
    int top2;
    for(;i < size;++i)
    {
        while(1)
        {
            ret = SeqStackTop(&stack1,&top1);
            if(ret == -1 || Front(top1,num[i]) >= 0)
            {
                SeqStackPush(&stack1,num[i]);
                while(SeqStackTop(&stack2,&top2) != -1)
                {
                    SeqStackPush(&stack1,top2);
                    SeqStackPop(&stack2);
                }
            }
            //if(Front(top1) >= Front(num[i]))
            //{
            //    SeqStackPush(&stack1,num[i]);   
            //    while(SeqStackTop(&stack2,&top2) != -1)
            //    {
            //        SeqStackPush(&stack1,top2);
            //        SeqStackPop(&stack2);
            //    }

            //}
            else
            {
                SeqStackPush(&stack2,top1);
                SeqStackPop(&stack1);          
            }

        }
    }
    int top;
    while(1)
    {

        int ret = SeqStackTop(&stack1,&top);
        if(ret == -1)
        {
            return;
        }
        printf("%d ",top);
        SeqStackPop(&stack1);
    }
    
}

int main()
{
    int num[] = {3,32,321};
    int size = sizeof(num)/sizeof(num[0]);
    CatMin(num,size);
    return 0;
}
