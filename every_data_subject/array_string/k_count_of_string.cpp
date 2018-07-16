#include<iostream>
#include<hashtable.h>
using namespace std;

//在字符串中查找第一次出现k次的字符
char FindK(string s,int k)
{
    //创建一个有256个元素的哈希表
    //其中字符串中的字符为哈希表的key值
    //字符串出现的次数为哈希表的value值
    size_t HashTable[256] = {0};
    //首先遍历一次字符串，对哈希表中的元素值进行修改
    int index = 0;
    for(index = 0;index < s.size();index++)
    {
        HashTable[s[index]]++;
    }
    //再遍历一遍字符串，提取出现k次的字符
    for(index = 0;index < s.size();index++)
    {
        if(HashTable[s[index]] == k)
        {
            return s[index];
        }
    }
    return '#';
}


int main()
{
    string s;
    getline(cin,s);
    int k;
    cin>>k;
    char ch = FindK(s,k);
    cout<<ch<<endl;
    return 0;
}
