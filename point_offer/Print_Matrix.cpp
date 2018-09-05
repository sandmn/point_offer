vector<int> MyPrint(vector<vector<int> > matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> v;
    int a = 0,b = row - 1,c = 0,d = col - 1;
    int i;
    while(a <= b && c <= d)
    {
        //特殊情况一：只有一个需要输出
        if(a == b && c == d)
        {
            v.push_back(matrix[a][c]);
        }
        //特殊情况二：需要输出一行
        else if(a == b && c != d)
        {
            for(i = c;i <= d;i++)
            {
                v.push_back(matrix[a][i]);
            }
        }
        //特殊情况三：输出一列
        else if(a != b && c == d)
        {
            for(i = a;i <= b;i++)
            {
                v.push_back(matrix[i][d]);
            }
        }
        else
        {
            for(i = c;i < d;i++)
            {
                v.push_back(matrix[a][i]);
            }
            for(i = a;i < b;i++)
            {
                v.push_back(matrix[i][d]);
            }
            for(i = d;i > c;i--)
            {
                v.push_back(matrix[b][i]);
            }
            for(i = b;i > a;i--)
            {
                v.push_back(matrix[i][c]);
            }
        }
        a++,b--,c++,d--;
    }
    return v;
}

class Solution {
    public:
        vector<int> printMatrix(vector<vector<int> > matrix) {
            vector<int> v;
            if(matrix.empty() == 1)
            {
                return v;
            }
            return MyPrint(matrix);
        }
};
