////旋转字符串
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void rotateString(char str[], int n, int p)
{
    if (str == NULL || n <= 0)
    {
        return;
    }
    char* newstr = (char*)malloc(2 * n*sizeof(char) + 1);
    strcpy(newstr, str);
    strcat(newstr, str);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        str[i] = newstr[i + p + 1];
    }
    free(newstr);
    return;
}

int main()
{
    char str[] = "ABCDEFGH";
    rotateString(str, strlen(str), 4);
    printf("%s\n", str);
    return 0;
}


//旋转字符串
class StringRotation {
    public:
        string rotateString(string A, int n, int p) {
            string newstr(A);//拷贝构造：定义一个字符串变量newstr，将字符串A拷贝至newstr
                //定义字符串时，不用定义长度，系统会自动分配，如果不够，会自动扩容
                newstr.append(A);//将字符串A连接在字符串newstr后
            int i = 0;
            for (i = 0; i < n; i++)
            {
                A[i] = newstr[i + p + 1];
            }
            return A;
        }
};
