
////字符串转化为整数
//#include<stdio.h>
//
//int Solution(char* s)
//{
//    if (s == NULL)
//    {
//        return 0;
//    }
//    char* str = s;
//    int flag = 1;
//    int num = 0;
//    if (*str == '-')
//    {
//        flag = -1;
//    }
//    if (*str == '+' || *str == '-')
//    {
//        str++;
//    }
//    while (*str != 0)
//    {
//        if (*str >= '0' && *str <= '9')
//        {
//            num = num * 10 + (*str - '0');
//            str++;
//        }
//        else
//        {
//            return 0;
//        }
//    }
//    return flag*num;
//}
//
//
//int main()
//{
//    char str[] = "+263 135";
//    int num = Solution(str);
//    printf("%d\n", num);
//}


#include<iostream>
using namespace std;
#include<string>
//字符串替换为整数
#include<string>
class Solution {

    public:

        int StrToInt(string str) {
            int flag = 1;
            int num = 0;
            int i = 0;
            if (str[0] == '-')
            {
                flag = -1;
            }

            if (str[0] == '+' || str[0] == '-')
            {
                i = 1;
            }
            for (; i < str.size(); i++)
            {
                if (str[i] >= '0' && str[i] <= '9')
                {
                    num = num * 10 + (str[i] - '0');
                }
            }
        }
};
