//atoi函数的实现
#include<stdio.h>

#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int myatoi(char arr[])
{
    if(arr == NULL)
    {
        //非法输入
        return -1;
    }
    int index = 0;//记录数组下标
    int num = 0;//存放最终要返回的值
    int flag = 1;//设置符号标志位
        
    while(isspace(arr[index]))//是空格返回非零值(不一定是1)，否则返回0
    {
        index++;//跳过空格字符,不只有空格，还有\n，\r,\f,\t,\v之类的字符
    }
    if(arr[index] == '-')
    {
        flag = -1; //除空格外遇到的第一个数字是符号，标记为-1，如果遇到的
    }
    //注意：正负号不算作1
    if(arr[index] == '-' || arr[index] == '+')//如果遇到正负号，说明可以往后继续走
    {
        index++;
    }
    while(arr[index] >= '0' && arr[index] <= '9')//如果遇到的数字说明可以继续往下走
    {
        num = num*10 + arr[index] - '0';
        index++;
    }
    return flag*num;
}

int main()
{
    char buf1[] = "\n+8cjjs";
    char buf2[] = "  123nv";
    char buf3[] = "+73bcj";
    char buf4[] = "6378";
    char buf5[] = "-76j527v67e2";
    char buf6[] = "-sj527v67e2";

    //int b1 = atoi(buf1);
    //int b2 = atoi(buf2);
    //int b3 = atoi(buf3);
    //int b4 = atoi(buf4);
    //int b5 = atoi(buf5);
    //int b6 = atoi(buf6);

    int b1 = myatoi(buf1);
    int b2 = myatoi(buf2);
    int b3 = myatoi(buf3);
    int b4 = myatoi(buf4);
    int b5 = myatoi(buf5);
    int b6 = myatoi(buf6);

    printf("b1 = %d\n",b1);
    printf("b2 = %d\n",b2);
    printf("b3 = %d\n",b3);
    printf("b4 = %d\n",b4);
    printf("b5 = %d\n",b5);
    printf("b6 = %d\n",b6);

    return 0;
}
