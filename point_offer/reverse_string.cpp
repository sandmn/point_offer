#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//将字符串中的单词逆置
//首先利用find查找空格所在的位置
//在利用reverse将整个单词逆置
//最后将整个字符串进行逆置
void reverse_string(string& s)
{
    string::iterator it1 = s.begin();
    do
    {
        string::iterator it2 = s.end();
        it2 = find(it1,it2,' ');
        if(it2 == s.end())
        {
            reverse(it1,it2);
            break;
        }
        reverse(it1,it2);
        it1 = ++it2;
    }while(1);
    reverse(s.begin(),s.end());
    return;
}

int main()
{
    string s = "i am a chinese";
    reverse_string(s);
    cout<<s<<endl;
}
