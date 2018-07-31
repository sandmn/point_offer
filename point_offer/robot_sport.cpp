
#include<iostream>
using namespace std;

//地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
//但是不能进入行坐标和列坐标的数位之和大于k的格子。
//例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
//但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
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
//判断某个位置坐标能否落脚，如果不能，直接回溯出栈
//如果能落脚，将该位置标记为1，然后对上，下，左，右四个方向进行探测
void _movingCount(int threshold,int rows,int cols,int* mycount,int row,int col,int** arr)
{
    //机器人到达某个位置能落脚的条件是下述1,2,3
    //如果下述三点任意一条不满足，则说明该位置不能走，于是就回溯出栈
    //1.该位置在地图的坐标范围内
    if(row >= rows || col >= cols || row < 0 || col < 0)
    {
        cout<<"haha"<<endl;
        return;
    }
    //2.该位置上的额标记为0
    if(arr[row][col] != 0)
    {
        return;
    }
    //3. 该位置的位置坐标位数之和小于等于指定值
    //如果函数和列数的位数之和大于指定值，或者超出格子的范围，则进行回溯
    if(Sum(row) + Sum(col) > threshold)
    {
        cout<<row<<" "<<col<<endl;

        return;
    }
    
    //f否则说明当前位置机器人可以走，所以计数变量值加1
    (*mycount)++;
    //并对该位置进行标记，说明该位置已经被走过，下一次在遍历到该处时，不进行加1
    arr[row][col] = 1;
    //然后从上，右，下，左开始进行深度遍历
    //注意：对对四个方向进行探测时，中心点的坐标值不能变
    //可以在它的基础上进行加加减减
    _movingCount(threshold,rows,cols,mycount,row - 1,col,arr);
    _movingCount(threshold,rows,cols,mycount,row,col + 1,arr);
    _movingCount(threshold,rows,cols,mycount,row + 1,col,arr);
    _movingCount(threshold,rows,cols,mycount,row,col - 1,arr);
    //当四个方向都遍历完时，说明该位置的四周已经探测完毕，则出栈
    return;
}
class Solution {
    public:
        int movingCount(int threshold, int rows, int cols)
        {
            //因为是从(0,0)开始，所以如果指定的值小于0，必然没有格子可以落脚
            if(threshold < 0)
            {
                return 0;
            }
            //记录机器人走过的格子数
            int mycount = 0;
            //记录机器人的坐标
            int row = 0;
            int col = 0;
            //设置一个二维数组用于标记走过的格子
            //初始时所有的格子均为0，当走过一个格子后将该格子的内容标记为1，
            //下一次在遍历到该处时，计数器就不会在进行加1了
            
            //动态开辟二维数组
            //首先开辟一个存放一位数组指针的二维数组
            int** arr = new int*[rows];

            //在对每个一维数组指针进行内存的开辟
            int i = 0;
            for(i = 0;i < rows;i++)
            {
                arr[i] = new int[cols];
            }
            //将二维数组初始化为0
            for(i = 0;i < rows;i++)
            {
                int j = 0;
                for(j = 0;j < cols;j++)
                {
                    arr[i][j] = 0;
                }
            }

            //递归开始走迷宫
            //判断某个位置坐标能不能落脚
            _movingCount(threshold,rows,cols,&mycount,row,col,arr);
            return mycount;
        }
};

int main()
{
    Solution s;
    int ret = s.movingCount(2,2,2);
    cout<<ret<<endl;
    return 0;
}
