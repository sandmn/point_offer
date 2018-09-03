
//大数运算------》减法

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Sub(char* a,char* b)
{
    //计算两个字符串的长度创建数组以数字的格式存放减数和被减数
    int len = strlen(a);
    int* x = (int*)malloc(sizeof(int)* len);
    int* y = (int*)malloc(sizeof(int)* len);
    int* z = (int*)malloc(sizeof(int)* len);

    memset(x,sizeof(int)*len,0);
    memset(y,sizeof(int)*len,0);
    memset(z,sizeof(int)*len,0);

    //将减数和被减数以数字的形式进行存放
    int j = 0;
    int i = 0;
    for(i = strlen(a) - 1;i >= 0;i--)
    {
        x[j++] = a[i] - '0';
    }
    j = 0;
    for(i = strlen(b) - 1;i >= 0;i--)
    {
        y[j++] = b[i] - '0';
    }

    for(i = 0;i < len;i++)
    {
        if(x[i] >= y[i])
        {
            z[i] = x[i] - y[i];
        }
        else
        {
            z[i] = x[i] + 10 - y[i];
            x[i + 1] = x[i + 1] - 1;
        }
    }
    //去掉前面多余的0
    for(i = len - 1;i > 0;i--)
    {
        if(z[i] == 0)
        {
            len--;
        }
        else
        {
            break;
        }
    }
    for(i = len - 1;i >= 0;i--)
    {
        printf("%d",z[i]);
    }
    printf("\n");
}

int main()
{
    char a[1000],b[1000];
    while(scanf("%s %s",a,b))
    {
        int len_a = strlen(a);
        int len_b = strlen(b);
        if(len_a > len_b)
        {
            Sub(a,b);
        }
        else if(len_a < len_b)
        {
            printf("-");
            Sub(b,a);
        }
        else
        {
            int i = 0;
            for(;i < len_a;i++)
            {
                if(a[i] > b[i])
                {
                    Sub(a,b);
                    break;
                }
                else if(a[i] < b[i])
                {
                    printf("-");
                    Sub(b,a);
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    return 0;
}
