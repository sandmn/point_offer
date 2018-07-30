
#include<iostream>
using namespace std;

int Sum(int n)
{
    int shang = n;
    int yushu;
    int Sum = 0;
    while(1)
    {
        yushu = shang/10;
        Sum += shang%10;
        shang = shang/10;
        if(shang == 0)
        {
            break;
        }
    }
    return Sum;
}
void _movingCount(int threshold,int rows,int cols,int* count,int row,int col)
{
    //如果函数和列数的位数之和大于指定值，或者超出格子的范围，则进行回溯
    if(Sum(row) + Sum(col) > threshold)
    {
        return;
    }
    if(row >= rows || col >= cols || row < 0 || col < 0)
    {
        return;
    }
    //f否则说明当前位置机器人可以走，所以计数变量值加1
    (*count)++;
    cout<<row<<" "<<col<<endl;
    sleep(2);
    //然后从上，右，下，左开始进行深度遍历
    _movingCount(threshold,rows,cols,count,--row,col);
    _movingCount(threshold,rows,cols,count,row,++col);
    _movingCount(threshold,rows,cols,count,++row,col);
    _movingCount(threshold,rows,cols,count,row,--col);
    return;
}
class Solution {
    public:
        int movingCount(int threshold, int rows, int cols)
        {
            if(threshold < 0)
            {
                return 0;
            }
            int count = 0;
            int row = 0;
            int col = 0;
            _movingCount(threshold,rows,cols,&count,row,col);
            return count;
        }
};

int main()
{
    Solution s;
    int ret = s.movingCount(1,2,2);
    cout<<ret<<endl;
    return 0;
}
