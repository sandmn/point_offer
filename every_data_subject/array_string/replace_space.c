#include<stdio.h>
#include<string.h>


//将字符串中的空格替换为特殊字符
void Replacement(char* iniString, int length)
{
    if (iniString == NULL || length <= 0)
    {
        //非法输入
        return;
    }
    //首先统计字符串中的空格个数
    int spacenum = 0;
    int i = 0;
    for (i = 0; i < length; i++)
    {
        if (iniString[i] == ' ')
        {
            spacenum++;
        }
    }
    //将数组的长度替换为原字符串的长度加上空格的个数乘2
    int newnum = length + spacenum * 2;
    int index = newnum;//新串也从尾部开始遍历
    //将字符串从尾部拷贝到新数组的尾部
    for (i = length; i >= 0; i--)
    {
        //如果遇到空格则替换为%20
        if (iniString[i] == ' ')
        {
            iniString[index--] = '0';
            iniString[index--] = '2';
            iniString[index--] = '%';
        }
        else
        {
            iniString[index--] = iniString[i];
        }
    }
    return;
}
int main()
{
    char str[100] = "Hello World";
    Replacement(str, strlen(str));
    printf("%s\n", str);
    return 0;
}
