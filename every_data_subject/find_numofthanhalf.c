
#include<stdio.h>

//有一个数组中有一个次数超过数组一半的数字,找到这个数字
//用数字之间相互抵消的办法
//假设a出现的次数超过了数组的一半长度
//1)出现一次a，使不同的数字将其抵消，最后必只剩余a，即a的次数至少为1
//2)可能a连续出现了多次，再使不同的数字将其一个个抵消，因为a的次数超过过了一半
//  所以，最后a的次数必然不可能减为0，即a的次数至少为1，
//因此，将最后一个次数为1的数字即为出现次数超过一半的数字

//在数组遍历的过程中，保存两个数字，一个是遍历到的数字，一个是该数字出现的次数
//如果下一个元素与保存的数字相同，则次数加1，保存的数字不变
//如果下一个元素与保存的数字不同，则次数减1，
//    1）如果保存的数字的次数减为0，则更新保存的数字为下一个数字
//    2) 如果保存的数字的次数没有减为0，则继续遍历下下一个数字
//最后，一个保存的数字即为出现次数超过一半的数字


int findnum(int arr[],int size)
{
    int num = arr[0];
    int count = 1;
    int i = 1;
    for(;i < size;i++)
    {
        if(arr[i] == num)
        {
            count++;
        }
        else
        {
            count--;
            if(count == 0)
            {
                num = arr[i];
                count = 1;
            }
        }
    }

    //如果有一个出现次数超过数组一般的数字，则此时num保存的数字必为该数字
    //但是如果没有出现次数超过数组一半的数字，则此时num保存的必为数组的最后一个元素
    //所以，此对num进行判断：
    //再次遍历数组，如果num出现的次数超过了数组的一半长度，则此时num即为出现次数超过数组一半的数字
    //如果num的次数没有超过数组的一半，此时，num即为数组的最后一个数字

    count = 0;
    for(i = 0;i < size;i++)
    {
        if(arr[i] == num)
        {
            count++;
        }
    }
    //num为次数超过数组一半的数字
    if(count > size/2)
    {
        return num;
    }
    //num为数组的最后一个数字
    //此时，既不存在次数超过数组一半的数字
    //因此，直接返回0即可。
    return 0;
}


//void  Swap(int* a,int* b)
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//    return;
//}
//
//void BubbleSort(int arr[],int size)
//{
//    if(arr == NULL || size <= 0)
//    {
//        return;
//    }
//    int i = 0;
//    for(;i < size;i++)
//    {
//        int j = 0;
//        for(j = 0;j < size - i -1;j++)
//        {
//            if(arr[j] > arr[j + 1])
//            {
//                Swap(&arr[j],&arr[j+1]);
//            }
//        }
//    }
//    return;
//}
//
//
//int findnum(int arr[],int size)
//{
//    BubbleSort(arr,size);
//    int i = 0;
//    int count = 1;
//    for(;i < size - 1;i++)
//    {
//        if(arr[i] == arr[i + 1])
//        {
//            count++;
//        }
//        else
//        {
//            count = 1;
//        }
//        if(count > size/2)
//        {
//            return arr[i];
//        }
//    }
//    return 0;
//}

int main()
{
    int arr[] = { 1, 2, 2, 2, 2, 2, 5, 4, 2  };
    int ret = findnum(arr, sizeof(arr) / sizeof(arr[0]));
    printf("%d\n", ret);
    return 0;
}
