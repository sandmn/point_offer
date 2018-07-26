#include<iostream>
using namespace std;
#include<string>

//进制转换，将十进制数M转化为N机制后输出
string Radix_Convert(int M,int N)
{
    int flag = 1;
    string ret;//定义一个字符串来保存转换之后的进制数
    //注意负数的转换
    if(M < 0)
    {
        flag = -1;
        M = (-1)*M;
    }
    int div = M;
    cout<<M<<endl;
    int remain;
    while(1)
    {
        remain = div%N;//获得余数
        cout<<remain<<endl;
        div = div/N;//获取商
        //如果余数大于等于10，将余数转换为字符A~F插入字符串中
        if(remain >= 10)
        {
            ret.insert(0,1,remain + 55);
        }
        else//否则将余数转换为数字字符插入字符串中
        {
            ret.insert(0,1,remain + '0');
        }
        //如果商为0,则跳出循环
        if(div == 0)
        {
            break;
        }
    }
    if(flag == -1)
    {
        ret.insert(0,1,'-');
    }
    //最后返回转换后的字符串
    return ret;
}

int main()
{
    int M;
    int N;
    cin>>M>>N;
    string s = Radix_Convert(M,N);
    cout<<s<<endl;
    return 0;
}
