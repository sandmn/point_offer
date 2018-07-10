//Given a collection of numbers, return all possible permutations.
//For example,
//    [1,2,3]have the following permutations:
//    [1,2,3],[1,3,,[2,1,3],[2,3,1],[3,1,2], and[3,2,1]
// 求一组数的全排列
// 思路：假设数组元素个数为N，如果是打印数组的全排列
// 如果N = 1,则该数组的全排列即为该数组首元素
// 如果N = 2，将a[0]与a[0]进行交换，首先打印数组第一个元素[0]，然后递归调用本函数得到数组其余元素的全排列
//           将a[0]与a[1]进行交换，打印交换后的数组第一个元素[0]，然后递归调用本函数得到数组其余元素的全排列
// 如果N = 3，将a[o]与a[0]交换，打印a[0]，再递归调用本函数得到数组其余元素的全排列
//            将a[0]与a[1]交换，打印a[0]，再递归调用本函数得到数组其余元素的全排列
//            将a[0]与a[2]交换，打印a[0]，再递归调用本函数得到数组其余元素的全排列
// N = 4，5，...以此类推
#include<iostream>
using namespace std;
#include<vector>

class Solution {
    public:
        vector<vector<int> > permute(vector<int> &num) {
        //首先计算原数组中的元素个数，以便进行遍历交换
        int size = num.size();
        //定义一个待返回的二维数组
        vector<vector<int> > v;
        //如果数组中的元素个数小于等于1，则将本数组插入到带返回的二维数组中
        if(size <= 0)
        {
            v.push_back(num);
            return v;
        }
        //如果原数组元素个数大于1，则遍历数组元素分别与第一个元素进行交换
        int index = 0;//定义index来遍历数组
        for(index = 0;index < size;index++)
        {
            //分别将数组其余元素与首元素进行交换，使数组每个元素都有可能出现在首位
            swap(num[0],num[index]);
            //交换完之后，递归调用本数组，对除第一个元素之外的其余所有元素进行全排列，得到一个新的二维数组
            //得到从第二个元素开始的所有数组元素
            vector<int> vv;
            int i = 0;
            for(i = 1;i < size;i++)
            {
                vv.push_back(num[i]);
            }
            vector<vector<int> > tmp = permute(vv);
            //然后将第一个元素插入到新返回的二维数组的各个一维数组中
            for(i = 0;i < tmp.size();i++)
            {
                tmp[i].push_back(num[0]);
                //然后将添加完的各数组再添加到最终的二维数组中
                v.push_back(tmp[i]);
            }
        }
        //最后返回存放好的二维数组
        return v;
        }
};



//class Solution {
//    public:
//        vector<vector<int> > permute(vector<int> &num) {
//           // 首先计算num中的元素个数
//                int size = num.size();
//            //创建一个二维数组
//            vector<vector<int> > v;
//            if(size == 1)
//            {
//                //创建一个一维数组
//                vector<int> tmp;
//                tmp.push_back(num[0]);
//                //因为原数组中只有一个元素，所以将原数组直接放入二维数组中
//                v.push_back(tmp);
//                //然后返回二维数组
//                return v;
//            }
//            //定义index用于遍历原数组
//            int index = 0;
//            for(index = 0;index < size;index++)
//            {
//                //将原数组第一个元素与其余各元素分别进行交换
//                swap(num[0],num[index]);
//                //然后递归调用本函数，得到除第一个数组元素之外的其余元素的全排列
//                vector<int> tmp;
//                int j = 1;
//                for(j = 1;j < size;j++)
//                {
//                    tmp.push_back(num[j]);
//                }
//                vector<vector<int> > v1 = permute(tmp);
//                //计算新返回的二维数组中的元素个数
//                int size1 = v1.size();
//                //遍历新返回的数组，将原数组交换后的第一个元素都存放在新的二维数组的各数组中
//                //然后将添加完的各数组再添加到最终的二维数组中
//                int i = 0;
//                for(i = 0;i < size1;i++)
//                {
//                    v1[i].push_back(num[0]);
//                    v.push_back(v1[i]);
//                }
//                //然后在=再将元素组恢复到交换之前的状态，进行下一次的交换
//                //swap(num[0],num[index]);
//            }
//            //最后返回存放好的二维数组  
//            return v;
//        }
//};

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    Solution s;
    vector<vector<int> > v = s.permute(num);
    int i = 0;
    for(i = 0;i < v.size();i++)
    {
        int j = 0;
        for(j = 0;j < v[i].size();j++)
        {
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return 0;
}
