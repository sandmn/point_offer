//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Here are few examples.
//[1,3,5,6], 5 → 2
//[1,3,5,6], 2 → 1
//[1,3,5,6], 7 → 4
//[1,3,5,6], 0 → 0

//在有序数组中搜索目标值插入的位置
class Solution {
    public:
        int searchInsert(int A[], int n, int target) {
            //定义index来遍历数组
            int index = 0;
            for(index = 0;index < n;index++)
            {
                //如果目标值小于等于当前的元素
                //则返回当前元素的下标
                if(target <= A[index])
                {
                    return index;
                }
            }
            //当数组遍历完时，还没找到，就返回数组的下一个坐标
            return n;
        }
};
