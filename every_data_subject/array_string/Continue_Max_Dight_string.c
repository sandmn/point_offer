
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned int Continumax(char** pOutputstr,  char* intputstr)
{
        //定义一个快指针和慢指针，慢指针指向数字串的起始位置，快指针用于遍历数字字符串
    char* fast = intputstr;
    char* slow = fast;    //定义一个变量，来记录数字字符串的长度
    char* ret = (char*)malloc(sizeof(char)*1024);
    //定义一个变量，来记录数字字符串的长度
    unsigned int max = 0;
    int i = 0;
    //当慢指针没有走到字符串结尾时，可以一直往后进行遍历
    while(*fast)
    {
        while(*fast)
        {
            if(*fast >= '0' && *fast <= '9')
            {
                break;
            }
            else
            {
                fast++;
            }
        }
        if(*fast != 0)
        {
            slow = fast;
            unsigned int size = 0;
            while(*fast >= '0' && *fast <= '9')
            {
                size++;
                fast++;
            }
            if(max < size)
            {
                i = 1;
                max = size;
                strcpy(ret,slow);
                ret[max] = 0;
                //*pOutputstr = slow;
            }
            else if(max == size)
            {
                strcat(ret,slow);
                ret[max*(++i)] = 0;                  
            }
        }
        else
        {
            break;
        }
    }
    *pOutputstr = ret;
    return max;
}
int main()
{
    char* pOutputstr = NULL;
    char intputstr[1024];
    scanf("%s",intputstr);
    int size = Continumax(&pOutputstr,intputstr);
    printf("%s,%d",pOutputstr,size);
    return 0;
}
