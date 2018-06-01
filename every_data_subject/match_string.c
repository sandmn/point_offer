#include<stdio.h>

int match(char* str, char* pattern)
{
    if (*str == '\0' && *pattern == '\0')
    {
        return 1;

    }
    if (*str != '\0' && *pattern == '\0')
    {
        return 0;

    }
    if (*(pattern + 1) == '*')
    {
        if (*str == *pattern || (*pattern == '.'&& *str != '\0'))
        {
            return  match(str, pattern + 2)||match(str + 1, pattern + 2) || match(str + 1, pattern);

        }
        else
        {
            return match(str, pattern + 2);

        }

    }
    if (*str == *pattern || (*pattern == '.' && *str != '\0'))
    {
        return match(str + 1, pattern + 1);

    }
    return 0;
}

int match1(char* str, char* pattern)
{
    if (str == NULL || pattern == NULL)
    {
        return 0;

    }
    return match(str, pattern);

}
int main()
{
    char* str = "aaa";
    char* pattern1 = "a.a";
    int ret;
    ret = match(str, pattern1);
    printf("expect 1,actually %d\n", ret);

    char* pattern2 = "ab*ac*a";
    ret = match(str, pattern2);
    printf("expect 1,actually %d\n", ret);

    char* pattern3 = "aa.a";
    ret = match(str, pattern3);
    printf("expect 0,actually %d\n", ret);

    char* pattern4 = "ab*a";
    ret         = match(str, pattern4);
    printf("expect 0,actually %d\n", ret);

    char* pattern5 = "ab*a*";
    ret = match(str, pattern5);
    printf("expect 1,actually %d\n", ret);


    char* str1 = "aaaaa";
    char* pattern6 = "ab*a*aa";
    ret = match(str1, pattern6);
    printf("expect 1,actually %d\n", ret);
    return 0;

}
