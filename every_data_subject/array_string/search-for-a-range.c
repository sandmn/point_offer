//Given a sorted array of integers, find the starting and ending position of a given target value.
//Your algorithm's runtime complexity must be in the order of O(log n).
//If the target is not found in the array, return[-1, -1].
//For example,
//    Given[5, 7, 7, 8, 8, 10]and target value 8,
//    return[3, 4].
//
//给一个排序数组，在数组中查找目标值，返回目标值所在的起始和结尾位置坐标
//要求时间复杂度为O(logn)
//如果目标值不存在，返回[-1,-1]

class Solution {
    public:
        vector<int> searchRange(int A[], int n, int target) {
            vector<int> ret;
            //start和end分别用于保存目标起始和结尾的位置
            int start = -1;
            int end = -1;
            //index用于遍历数组
            int index = 0;
            for(index = 0;index < n;index++)
            {
                //目标存在
                if(A[index] == target && start == -1)
                {
                    start = index;
                }
                //目标可能有多个
                else if(A[index] == target && start != -1)
                {
                    end = index;
                }
            }
            //目标只有一个的情形
            if(start != -1 && end == -1)
            {
                end = start;
            }
            //将start和end插入到vector变量中，然后返回
            ret.push_back(start);
            ret.push_back(end);
            return ret;

        }
};

