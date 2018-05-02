#include<stdio.h>
#include<string.h>
#include<ctype.h>
//参数1为原串的地址，参数2为原串中所能容纳的最大字符个数
int ReplaceBlack(char* arr,int n)
{
    if(arr == NULL || n <= 0)
    {
        return -1;
    }
    char* buf = arr;
    int countofblack = 0;//原串中的空格个数
    int countofchar = 0;//原串中的字符个数
    while(*buf != 0)     //统计空格的个数和字符串中字符的个数         
    {
        if(isspace(*buf))//如果是空格
        {
            countofblack++;
        }
        countofchar++;
        buf++;
    }   

//    //如果字符的个数比所能容纳的空间大
//    if(countofchar > n)
//    {
//        return -1;
//    }
//
    //如果没有空格
    if(countofblack == 0)
    {
        return 0;
    }
    int Newcountofchar = countofchar + 2*countofblack;//新字符串的长度
    if(Newcountofchar + 1 > n)//如果新串的长度比所能容纳的空间大，直接返回
    {
        return -1;
    }
    int index = Newcountofchar;
    int i = 0;
    for(i = countofchar;i >= 0;--i)
    {
        //如果不是空格直接赋值
        if(arr[i] != ' ')//注意这里不能用isspace
        {
            arr[index--] = arr[i];
        }
        else//如果是空格
        {
            arr[index--] = '0';
            arr[index--] = '2';
            arr[index--] = '%';
        }
    }
    return 0;
}


int main()
{
    char arr[100] = "we are happy\n";
    int ret;
    ret = ReplaceBlack(arr,sizeof(arr));
    printf("%s",arr);
    printf("expect 0,actually %d\n",ret);

    strcpy(arr,"wearehappy\n");
    ret = ReplaceBlack(arr,sizeof(arr));
    printf("%s",arr);
    printf("expect 0,actually %d\n",ret);

    return 0;
}
