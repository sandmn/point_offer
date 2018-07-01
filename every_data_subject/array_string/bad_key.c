
//题目描述：
//旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出
//肯定坏掉的那些键
//
//输入描述：
//输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过80个字符的串，由字母A-Z（包括大、小写）、数字0-9、
//以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。
//
//输出描述：
//按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* find_problem(char* expect, char* actual)
{
    //申请空间保存坏的键
    char* problem = (char*)malloc(80 * sizeof(char));
    memset(problem, '*',80 * sizeof(char));
    
    char* index_e = expect;
    char* index_a = actual;
    char* index_p = problem;
    
    //当预期的字符串没有遍历完时
    while (*index_e != '*')
    {
        //如果预期的字符与实际的字符对应相等
        //则两个字符串指针分别后移，进行下一次的循环
        if (*index_e == *index_a)
        {
            index_e++;
            index_a++;
        }
        //如果对应字符不相等
        else
        {
            //保存不想等的字符为temp1
            char temp1 = *index_e;
            //遍历实际的字符串，观察temp1是否在实际的字符串中存在
            char* index = actual;
            while (*index != '*' && *index != temp1)
            {
                index++;
            }
            //如果存在,则预期的字符串变量后移，然后进入下一论循环
            if(*index == temp1)
            {
                index_a++;
                continue;
            }
            //否则表示不存子于实际的字符串中，此时该不想等的字符一定的坏的字符，判断该字符是否应该放在坏的字符串中
            //将不想等的字符串以正确的形式保存起来
            char temp;
            if (*index_e >= 'a' && *index_e <= 'z')
            {
                temp = *index_e - ('a' - 'A');
            }
            else
            {
                temp = *index_e;
            }

            //遍历坏的字符串，观察temp是否在环的字符串中出现
            index = problem;
            while (*index != '*')
            {
                //如果出现，则将预期的字符串指针后移，进入下一轮循环
                if (*index == temp)
                {
                    index_e++;
                    break;
                }
                else
                {
                    index++;
                }
            }
            //如果没有出现，则将坏的字符保存在坏的字符串中,然后预期的字符串和坏的字符串指针均后移
            if (*index == '*')
            {
                *index_p = temp;
                index_e++;
                index_p++;
            }
        }
    }
    return problem;
}

int main()
{
    char expect[80] = {'*'};
    char actual[80] = {'*'};
    memset(expect, '*',80 * sizeof(char));
    memset(actual,'*', 80 * sizeof(char));
    scanf("%s",expect);
    scanf("%s",actual);

    char* problem = find_problem(expect, actual);
    char* index = problem;
    //将得到的字符串以\0结尾进行输出
    while (*index != '*')
    {
        index++;
    }
    *index = 0;
    printf("%s\n", problem);
    return 0;
}
