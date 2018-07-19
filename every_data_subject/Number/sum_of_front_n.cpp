//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
#include<iostream>
using namespace std;
//定义全局变量，用于存放最后求和的值
int sum = 0;
class Solution {
    public:
        int Sum_Solution(int n) {
            
            //利用短路与，如果n不等于0的时候，就进行后续的递归求和操作
            //否则当n=0时，即前面的条件不满足，那后面的条件也就不用计算了
            //此时，直接返回sum即可
            //n != 0 && (sum = n +  Sum_Solution(n - 1));
            
            //利用短路或，只有第一个条件不满足时，才会继续往后计算
            //两种方式均可以
            n == 0 || (sum = n + Sum_Solution(n - 1));

            return sum;
        }
};
int main()
{
    Solution s;
    int sum = s.Sum_Solution(4);
    cout<<sum<<endl;
    return 0;
}
