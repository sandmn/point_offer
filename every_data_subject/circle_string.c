////旋转字符串
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//方法一：双倍穷据法
//void rotateString(char str[], int n, int p)
//{
//    if (str == NULL || n <= 0)
//    {
//        return;
//    }
//
//    p = p % n; 
//
//    char* newstr = (char*)malloc(2 * n*sizeof(char) + 1);
//    strcpy(newstr, str);
//    strcat(newstr, str);
//
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        str[i] = newstr[i + p + 1];
//    }
//    free(newstr);
//    return;
//}

//方法二：（逆置法）
//void reverse(char str[],int left,int right)
//{
//    while(left < right)
//    {
//        char temp;
//        temp = str[left];
//        str[left] = str[right];
//        str[right] = temp;
//        left++;
//        right--;
//    }
//}
//
//void rotateString(char str[], int n, int p)
//{
//    if (str == NULL || n <= 0)
//    {
//        return;
//    }
//
//    p = p % n; 
//    int left = 0;
//    int right = n - 1;
//    int mid = p;
//    reverse(str,left,mid);
//    reverse(str,mid + 1,right);
//    reverse(str,left,right);
//    return;
//}

//方法三：循环前移法
void rotateString(char str[], int n, int p)
{
    if (str == NULL || n <= 0)
    {
        return;
    }

    p = p % n; 
    int i = 0;
    for(;i < p+1;i++)
    {
        char temp = str[0];
        int j = 0;
        for(j = 0;j < n - 1;j++)
        {
            str[j] = str[j + 1];
        }
        str[j] = temp;
    }
}

int main()
{
    char str[] = "ABCDEFGH";
    rotateString(str, strlen(str), 4);
    printf("%s\n", str);
    return 0;
}


////旋转字符串
//class StringRotation {
//    public:
//        string rotateString(string A, int n, int p) {
//            string newstr(A);//拷贝构造：定义一个字符串变量newstr，将字符串A拷贝至newstr
//                //定义字符串时，不用定义长度，系统会自动分配，如果不够，会自动扩容
//                newstr.append(A);//将字符串A连接在字符串newstr后
//            int i = 0;
//            for (i = 0; i < n; i++)
//            {
//                A[i] = newstr[i + p + 1];
//            }
//            return A;
//        }
//};
