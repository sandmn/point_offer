
#include<iostream>
#include<vector>
using namespace std;

bool IsPost(vector<int> v,int begin,int end)
{
    if(v.size() <= 0 || begin > end)
    {
        return false;
    }
    //一棵二叉搜索树的最后一个元素必为根节点，前面一部分元素均小于根节点，后面一部分均大于根节点
    int root = v[end];//保存根节点的值
    int index = begin;
    while(index < end)
    {
        if(v[index] < root)
        {
            index++;
        }
        if(v[index] > root)
        {
            break;//此时的index为右子树的起始坐标
        }
    }
    int rindex = index;
    //判断右子树是否均大于根节点
    while(rindex < end)
    {
        if(v[rindex] > root)
        {
            rindex++;
        }
        else
        {
            return false;
        }
    }
    //此时的右子树中的结点必大于根节点元素
    //判断左右子树是否满足条件
    bool l;
    bool r;
    //如果有左子树,对左子树进行判断
    //没有左子树时，也可能是后序序列
    if(index > begin)
    {
        l = IsPost(v,begin,index - 1);
    }
    //如果有右子树
    if(end  > index)
    {
        r = IsPost(v,index,end - 1);
    }
    return l && r;
}

//判断一个数组是否是一棵二叉搜索树的后序遍历结果
class Solution {
    public:
        bool VerifySquenceOfBST(vector<int> sequence) {
            if(sequence.empty())
            {
                return true;
            }
            if(sequence.size() == 1)
            {
                return true;
            }
            int s = sequence.size();//计算数组中的元素个数
            //将数组的起始坐标作为参数进行判断
            return IsPost(sequence,0,s - 1);
        }
};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(6);
    v.push_back(8);
    v.push_back(7);
    //v.push_back(11);
    //v.push_back(12);
    v.push_back(10);
    bool ret = s.VerifySquenceOfBST(v);
    cout<<ret<<endl;
    return 0;

}

