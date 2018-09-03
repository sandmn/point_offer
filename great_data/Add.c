

//大数存储：利用数组或字符串进行存储
//大数运算------》大数加法
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//int x[100]={0},y[100]={0},z[105]={0};//将数组元素全部初始化为0 
//int main()
//{
//    char    a[100],b[100];//通过字符串对大数进行输入并储存 
//    int len1,len2,len;
//    while(scanf("%s %s",a,b))
//    {
//        int i,j=0,k=0;
//        len1=strlen(a);
//        len2=strlen(b);
//        for(i=len1-1;i>=0;i--)//将两个字符串中的字符转化为数字，并倒序储存到数组中，即字符串为123456，则数组为654321 
//        {
//            x[j]=a[i]-'0';
//            j++;
//
//        }
//        for(i=len2-1;i>=0;i--)
//        {
//            y[k]=b[i]-'0';
//            k++;
//
//        }
//        if(len1>len2)
//            len=len1;
//        else
//            len=len2;
//        i=0;//从最低位(个位)开始进行计算
//        int m=0;
//        for(i=0;i<len;i++)
//        {
//            z[i]=(x[i]+y[i]+m)%10;//将所得数çSuperTab('n')
//                if((x[i]+y[i]+m)>=10)
//                    m=1;
//                else
//                    m=0;
//
//        }
//        if((x[i-1]+y[i-1]+m)>=10)//判断运算的最大位ç=SuperTab('n')
//                z[i]=1;
//        else
//            i=i-1;
//        for(;i>=0;i--)//到序输出数组 
//            printf("%d",z[i]);
//        printf("\n");
//
//    }
//    return 0; 
//
//}


void Print_Ret(char* a,char* b)
{
    //创建数组将输入数据以数字的形式保存在数组中
    //数组初始化为0
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len = (len_a > len_b) ? len_a:len_b;

    int* x = (int*)malloc(sizeof(int)* (len));
    int i = 0;
    for(i = 0;i < len;i++)
    {
        x[i] = 0;
    }
    int* y = (int*)malloc(sizeof(int)*(len));
    for(i = 0;i < len;i++)
    {
        y[i] = 0;
    }
    int* z = (int*)malloc(sizeof(int)*(len + 1));
    for(i = 0;i <= len;i++)
    {
        z[i] = 0;
    }
    
    //将输入数据由低位到高位依次存放在数组中
    int j = 0;
    for(i = len_a - 1;i >= 0;i--)
    {
        x[j] = a[i] - '0';   
        j++;
    }
    j = 0;
    for(i = len_b - 1;i >= 0;i--)
    {
        y[j] = b[i] - '0';
        j++;
    }

    //对两个输入数据进行运算
    int m = 0;//记录进位标志位
    //从低位开始进行相加
    for(i = 0;i < len;i++)
    {
        z[i] = (x[i] + y[i] + m)%10;
        //printf("%d ",z[i]);
        if((x[i] + y[i] + m) >= 10)
        {
            printf("%d ",x[i] + y[i] + m);
            m = 1;
        }
        else
        {
            m = 0;
        }
    }
    if(x[i - 1] + y[i - 1] + m >= 10)
    {
        z[i] = 1;
    }
    else
    {
        i = i - 1;
    }
    for(;i >= 0;i--)
    {
        printf("%d",z[i]);
    }
    printf("\n");

}

int main()
{
    //利用字符串存储输入的数据
    //将计算结果保存在数组中
    char a[1000],b[1000];
    //循环计算大数相加的结果
    while(scanf("%s%s",a,b))
    {
        Print_Ret(a,b);
    }
    return 0;
}
