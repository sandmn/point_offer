//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//For example,
//    [1,1,2]have the following unique permutations:
//    [1,1,2],[1,2,1], and[2,1,1].


class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int> &num) {
            //首先统计num中的元素个数
            int size = num.size();
            vector<vector<int> > v;
            if(size <= 1)
            {
                v.push_back(num);
                return v;
            }
            //对num进行排序
            int m = 0;
            for(m = 0;m < size;m++)
            {
                int n = 0;
                for(;n <size - m - 1;n++)
                {
                    if(num[n] > num[n + 1])
                    {
                        swap(num[n],num[n + 1]);
                    }
                }
            }
            //sort(&num[0],&num[size - 1]);
            if(num[0] == num[size - 1])
            {
                v.push_back(num);
                return v;
            }
            //定义index用于遍历num
            int index = 0;
            for(index = 0;index < size;index++)
            {
                int i;
                //定义二维数组用于存放除第一个元素之外的其他元素的全排列
                vector<vector<int> > v_tmp;   
                //如果是遍历到第一个元素或者遍历到与之前不相同的数组元素，则递归调用该函数对其余元素进行全排列
                //如果遍历到第一个元素
                if(index == 0)
                {
                    //交换元素
                    swap(num[0],num[index]);
                    //定义一维数组保存除第一个元素之外的其余元素
                    vector<int> tmp;
                    for(i = 1;i < size;i++)
                    {
                        tmp.push_back(num[i]);
                    }
                    //递归调用该函数获取除第一个数组元素之外的其余元素的全排列
                    v_tmp = permuteUnique(tmp);
                    //将第一个数组元素添加到新获取的二维数组的每个一位数组中
                    //然后将该一位数组添加到最终要返回的二维数组中
                    for(i = 0;i < v_tmp.size();i++)
                    {
                        v_tmp[i].push_back(num[0]);
                        v.push_back(v_tmp[i]);
                    }
                    //最后将两个数在交换回来，进行下一轮的循环
                    swap(num[0],num[index]);
                }
                //如果遍历到某个与上一个不相等的元素，则递归调用函数进行全排列
                else if(num[index] != num[index - 1])
                {
                    swap(num[0],num[index]);
                    vector<int> tmp;
                    for(i = 1;i < size;i++)
                    {
                        tmp.push_back(num[i]);
                    }
                    v_tmp = permuteUnique(tmp);
                    //将第一个数组元素添加到新获取的二维数组的每个一位数组中
                    //然后将该一位数组添加到最终要返回的二维数组中
                    for(i = 0;i < v_tmp.size();i++)
                    {
                        v_tmp[i].push_back(num[0]);
                        v.push_back(v_tmp[i]);
                    }                                                                                                                  
                    //最后将两个数在交换回来，进行下一轮的循环
                    swap(num[0],num[index]);
                }
            }
            //最终返回新获得的二维数组
            return v;
        }
};

