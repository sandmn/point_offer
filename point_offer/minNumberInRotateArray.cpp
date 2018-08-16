int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.size() == 0)
    {
        return 0;
    }
    int left = 0;
    int right = rotateArray.size() - 1;
    //如果数组没有旋转，则left处的值必小于right处的值
    if(rotateArray[left] < rotateArray[right])
    {
        return rotateArray[left];
    }
    //否则数组必旋转了
    int mid;
    int min = rotateArray[0];
    //此时需要寻找两个旋转子数组之间交接的点
    while(rotateArray[left] >= rotateArray[right])
    {
        if(right - left == 1)
        {
            min = rotateArray[right];
            break;
        }
        mid = left + (right - left)/2;
        //如果前后的元素与中间的元素相当，就需要遍历查找最小值
        if(rotateArray[left] == rotateArray[mid] && rotateArray[right] == rotateArray[mid])
        {
            //此时进行循环遍历
            int index = 0;
            for(;index < rotateArray.size();index++)
            {
                if(rotateArray[index] < min)
                {
                    min = rotateArray[index];
                }
            }
        }
        //如果左边的元素小于等于中间的元素，则将中间的值赋为左边的元素:2 2 1
        if(rotateArray[left] <= rotateArray[mid])
        {
            left = mid;
        }
        //如果右边的元素大于等于中间的元素，就使中间的元素赋为右边的元素：2 1 1 
        if(rotateArray[right] >= rotateArray[mid])
        {
            right = mid;
        }
        //然后进行下一次的循环
    }
    return min;
}
