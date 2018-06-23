#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//未完成

//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个
//例如，输入数组{3,32,321},打印出这三个数字能排成的最小数字321323

//遍历数组，将整数转化为字符串，然后将相邻的两个字符串拼接起来
//此时，有两种拼接方法，谁先谁后，比较这两个拼接后的字符串，哪个小则取哪一个
//然后接着将较小的字符串拼接后一个字符
//当遍历完所有的数组元素后，就得到了最小值
//然后将该字符串打印输出即可

void myitoa(char* buf,int num)
{
    if(num < 10)
    {
        *buf = num + '0';
        return;
    }
    myitoa(buf,num/10);
    buf++;
    *buf = num%10 + '0';
    return;
}

char* MinCat(int num[],int size)
{
    if(num == NULL || size <= 0)
    {
        return NULL;
    }
    char* min = (char*)malloc(1024*sizeof(char));
    if(size == 1)
    {
        myitoa(min,num[0]);
        return min;
    }
    int index = 1;
    //int min = num[0];
    //char min[1024];
    myitoa(min,num[0]);
    for(;index < size;index++)
    {
        char tmp[1024] = {0};
        myitoa(tmp,num[index]);
        strcat(min,tmp);
        strcat(tmp,min);
        if(strcmp(min,tmp) == 1)
        {
            strcpy(min,tmp);
        }
    }
    return min;
}


int main()
{
    char buf[1024] = {0};
    myitoa(buf,4531);
    printf("%s\n",buf);
    int num[] = {3,32,321};
    int size = sizeof(num)/sizeof(num[0]);
    char* min_cat = MinCat(num,size);
    printf("%s\n",min_cat);
    free(min_cat);
    return 0;
}
