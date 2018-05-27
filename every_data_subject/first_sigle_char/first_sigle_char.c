//找字符串中第一个单独出现的字符
#include<stdio.h>
#include<string.h>
//#include"hash.h"

//利用哈希表来实现
//一个字符串的长度最长为256个字符
//因此可以设置一个长度为256的哈希表，以哈希表的下标作为字符的ASCII码
//所以，哈希表的下标即为key值
//哈希表中的元素为该下标处即该字符所出现的次数。
//所以可以用一个整型来表示一个哈希表的元素类型
//当对哈希表插入完成之后，再对数组中的元素进行遍历，
//如果在遍历过程中某个字符所对应的元素值为1，此时就找到了第一个单独出现的字符

#define MAXSIZE 256

typedef struct hash
{
    int data[MAXSIZE];
}hash;

//初始化哈希表
void Init(hash* h)
{
    int i = 0;
    for(;i < MAXSIZE;i++)
    {
        h->data[i] = 0;
    }
    return;
}

//插入
void Insert(char* str,hash* h)
{
    while(*str != 0)
    {
        h->data[(int)*str]++;
        str++;
    }
    return;
}
//查找
int Find(char* str,hash* h)
{
    while(*str != 0)
    {
        if(h->data[(int)*str] == 1)
        {
            return (int)*str;
        }
        str++;
    }
    return -1;
}



int find_first_single_char(char str[],int size)
{
    if(str == NULL)
    {
        return -1;
    }
   hash h;
   Init(&h);
   Insert(str,&h);
   return Find(str,&h);
}

int main()
{
    int ret = find_first_single_char(NULL,8);//测试非法输入
    printf("expect -1,actually %d\n",ret);

    char* str1 = "asdf";
    ret = find_first_single_char(str1,strlen(str1));//测试所有字符都单独出现
    printf("expect a,actually %c\n",(char)ret);

    char* str2 = "asdfasdf";
    ret = find_first_single_char(str2,strlen(str2));//测试没有单独出现的字符
    printf("expect -1,actually %d\n",ret);

    char* str3 = "asdfasdfw";
    ret = find_first_single_char(str3,strlen(str3));//测试有单独出现的字符
    printf("expect w,actually %c\n",(char)ret);
    
//    if(ret == -1)
//    {
//        printf("%d\n",ret);
//    }
//    else
//    {
//        printf("%c\n",(char)ret);
//    }
    return 0;
}


//int find_repeat(char str[], int size, char ch)
//{
//    int i = 0;
//    int         count = 0;
//    for (; i < size; i++)
//    {
//        if (str[i] == ch)
//        {
//            count++;
//        }
//    }
//    if (count > 1)
//    {
//        return 1;
//    }
//    else if (count == 1)
//    {
//        return -1;
//    }
//}
//
//int Find_Single(char str[], int size)
//{
//    if (str == NULL || size <= 0)
//    {
//        return -1;
//    }
//    if (size == 1)
//    {
//        return *str;
//    }
//    int i = 0;
//    for (; i < size; i++)
//    {
//        char ch = str[i];
//        int ret = find_repeat(str, size, ch);
//        if (ret == -1)
//        {
//            return (int)ch;
//        }
//    }
//    return -1;
//}
//
//int main()
//{
//    char str[100];
//    while (1)
//    {
//        scanf("%s", str);
//        int a = Find_Single(str, strlen(str));
//        if (a == -1)
//        {
//            printf("%d\n", a);
//        }
//        else
//        {
//            printf("%c\n", a);
//        }
//    }
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//




