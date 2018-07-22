#include<iostream>
#include<hashtable.h>
#include<string>
using namespace std;

string& Quit_Repeat(string& s)
{
    //保存待返回的字符串
    string ret;
    size_t HashTable[256] = {0};
    size_t index = 0;
    for(index = 0;index < s.size();index++)
    {
        HashTable[s[index]]++;
    }
    for(index = 0;index < s.size();index++)
    {
        if(HashTable[s[index]] != 0)
        {
            ret.push_back(s[index]);
            HashTable[s[index]] = 0;
        }
    }
    s = ret;
    return s;
}

int main()
{
    char str[100];
    while(cin>>str)
    {
        string s(str);
        string ret = Quit_Repeat(s);
        cout<<ret<<endl;
    }
    return 0;
}
}
}
}
}
}
}
