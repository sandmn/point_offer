#include<iostream>
#include<hashtable.h>
using namespace std;

//在查找重复值时，都需要知道数组，字符串元素的范围

//在一个数组中查找一个重复的数字
//该方法只适用于：1. 查找重复的数字，即出现两次的数字
//                2. 查找的重复数字是任意出现的，即不一定是第一次出现的 重复数字


//方法1：通过改变数组元素
class Solution
{
    public:
        int Repeat(int* num,int n)
        {
            if(num == NULL || n <= 1)
            {
                return -1;
            }
            //将数组中的元素移动到该元素数值的下标处
            //遍历数组
            int index = 0;
            for(index = 0;index < n;index++)
            {
                while(num[index] != index)
                {
                    //int data = num[index];
                    //cout<<data<<endl;
                    //cout<<num[data]<<endl;
                    //if(data != num[data])
                    //{
                    //注意此处交换的实际是临时变量data和num[data]的值。而不是num[index]和num[num[index]]的值
                    //    swap(data,num[data]);
                    //}
                    //else
                    //{
                    //    return data;
                    //}
                    if(num[index] == num[num[index]])
                    {
                        cout<<num[index]<<endl;
                        return num[index];
                    }
                    swap(num[index],num[num[index]]);
                }
            }
            return -1;
        }
};

//方法2：通过哈希表
class Solution1
{
    public:
        int Repeat(int* num,int n)
        {
            //定义一个哈希表，哈希表的key为数组各元素值
            //哈希表的value为各元素出现的次数
            //const int n1 = n;
            //int HashTable[7] = {0};
            //遍历一次数组，来填充哈希表
            int* HashTable = new int[n];
            int index = 0;
            for(index = 0;index < n;index++)
            {
                HashTable[num[index]]++;
            }
            //在遍历一次数组，用于查找出现重复的元素
            for(index = 0;index < n;index++)
            {
                if(HashTable[num[index]] >= 2)
                {
                    return num[index];
                }
            }
            return -1;
        }

};


int main()
{
    Solution s;
    Solution1 s1;
    int num[] = {1,2,3,0,4,5,6};
    int ret = s.Repeat(num,7);
    cout<<ret<<endl;

    int ret1 = s1.Repeat(num,7);
    cout<<ret1<<endl;
    return 0;
}
