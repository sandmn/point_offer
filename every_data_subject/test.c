#include<stdio.h>
int main()
{
    char str = {"china","beijing"};
    char *p = str;
    printf("%s\n",p+10);
    return 0;
}
