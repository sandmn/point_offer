#include<stdio.h>
int main()
{

    //程序错误，a没有定义
    int s = 0;
    {
        int a = 5;
        s += a++;
    }
    s += a++;
    printf("%d\n",s);
    return 0;

//    int x,y,z;
//    scanf("%d%d%d",&x,&y,&z);
//    printf("%d %d %d\n",x,y,z);
//    return 0;
//
    //char a[5] = {'a','b','\0','c','\0'};
    //printf("%s",a);
    //return 0;
    //unsigned short a = 10;
    //printf("~a = %lu\n",~a);
    //char c = 128;
    //printf("c = %d\n",c);
    //return 0;


    //char str = {"china","beijing"};
    //char *p = str;
    //printf("%s\n",p+10);
    //return 0;
}
