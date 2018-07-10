

//Given a digit string, return all possible letter combinations that the number could represent.
//A mapping of digit to letters (just like on the telephone buttons) is given below.
//Input:Digit string "23" Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

//Note: 
//Although the above answer is in lexicographical order, your answer could be in any order you want.

#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            //定义字符数组保存最终的结果
            vector<string> ans;
            //如果数字字符串中的字符数小于等于0，直接返回空的数组
            if(digits.size() <= 0)
            {
                return ans;
            }
            //先对除第一个数字之外的其余数字递归调用该函数进行处理，得到一个新的字符串数组
            vector<string> tmp = letterCombinations(digits.substr(1,digits.size() - 1));
            //如果新得到的字符串数组个数小于等于0，就给字符串数组中添加一个只有\0的字符串
            //表示字符串的结束
            if(tmp.size() <= 0)
            {
                tmp.push_back("");
            }

            //定义i用于遍历第一个数字所代表的的字符串
            int i = 0;
            //num表示第一个数字字符表示的数字
            int num = digits[0] - '0';
            //size表示第一个数字所代表字符串中字符的个数
            int size = str[num].size();
            //将第一个字符串中的各数字与新的到的字符串数组中的各字符串进行组合拼接
            for(i = 0;i < size;i++)//遍历第一个字符串
            {
                int j = 0;//遍历新得到的字符串数组
                for(j = 0;j < tmp.size();j++)
                {
                    //拼接起来之后将其添加到最终的字符串数组中
                    ans.push_back(str[num][i] + tmp[j]);
                }
            }
            //返回最终的字符串数组
            return ans;
        }
    //private:
        vector<string> str; 
};

int main()
{
    string digits("23");
    Solution s;
    s.str.push_back("");
    s.str.push_back("");
    s.str.push_back("abc");
    s.str.push_back("def");
    s.str.push_back("ghi");
    s.str.push_back("jkl");
    s.str.push_back("mno");
    s.str.push_back("pqrs");
    s.str.push_back("tuv");
    s.str.push_back("wxyz");
    vector<string> ans = s.letterCombinations(digits);
    int index = 0;
    for(index = 0;index < ans.size();index++)
    {
        cout<<ans[index]<<endl;
    }
    return 0;
}
