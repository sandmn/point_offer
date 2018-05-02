#include<stdio.h>
#include<stdlib.h>

//在一个长度为n的数组里的所有数字都在0~n-1的范围内，找出数组中的一个重复的数字
void Swap(int* data1,int* data2)
{
    int temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}


/////////////////////////////////////
//方法1：将下标位置与该下标处的值对应
/////////////////////////////////////



int find_replace1(int data[],int size,int* replace_data)
{
    if(data == NULL || size <= 0 || replace_data == NULL)
    {
        //非法输入
        return -1;
    }
    
    
    int index = 0;
    for(;index < size;++index)
    {
        //如果n个数的范围不在0到n-1之间，直接返回错误信息
        if(data[index] >= size || data[index] < 0)
        {
            return -1;//非法输入
        }
    }
    //将下标位置与该下标处的值对应
    for(index = 0;index < size;++index)
    {
        //将下标位置与该下标处的值对应
        //如果没有对应的值，说明该处的值必为重复的值
        while(data[index] != index)
        {
            if(data[data[index]] != data[index])
            {
                Swap(&data[index],&data[data[index]]);
            }
            else
            {
                *replace_data = data[index];
                return 1;
            }
        }
    }
    return 0;//没有重复的值
}


///////////////////////////////
//方法2：先冒泡排序，在找重复元素
///////////////////////////////

void BubbleSort(int data[],int size)
{
    int count = 0;
    for(;count < size - 1;++count)
    {
        int cur = 0;
        int flag = 0;
        for(;cur < size - 1 - count;++cur)
        {
            if(data[cur] > data[cur + 1])
            {
                flag = 1;
                Swap(&data[cur],&data[cur + 1]);
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}


int find_replace2(int data[],int size,int* replace_data)
{
    if(data == NULL || size <= 0 || replace_data == NULL)
    {
        //非法输入
        return -1;
    }
    int index = 0;
    for(;index < size;++index)
    {
        if(data[index] >= size || data[index] < 0)
        {
            return -1;//数组元素非法
        }
    }

    BubbleSort(data,size);
    index = 0;
    for(;index < size - 1;++index)
    {
        if(data[index] == data[index + 1])
        {
            *replace_data = data[index];
            return 1;
        }
    }
    return 0;//没有重复的值
}


///////////////////////////////////
//方法三：不修改数组元素，找重复元素,此时空间复杂度为O(n)
///////////////////////////////////

int find_replace3(int data[],int size,int* replace_data)
{
    if(data == NULL || replace_data == NULL || size <= 0)
    {
        //非法输入
        return -1;
    }

    int index = 0;
    for(;index < size;++index)
    {
        if(data[index] >= size || data[index] < 0)
        {
            return -1;//数组元素非法
        }
    }
    //创建一个有n个元素的数组，分别与其下标对应
    int* new_data = (int*)malloc(size*sizeof(int));
    index = 0;
    for(;index < size;++index)
    {
        new_data[index] = index;
    }


    //根据测试数组中的各元素值在新数组中找对应的下标
    index = 0;
    //根据测试数组中的各元素值在新数组中找对应的下标
    for(;index < size;++index)
    {
        //如果找到的为-1，说明该处的值必为重复的值，直接返回即可
        if(new_data[data[index]] == -1)
        {

            *replace_data = data[index];
            return 1;
        }
        //如果找到了，就将新数组中的该值标记为-1
        else
        {
            new_data[data[index]] = -1;
        }
    }
    //如果整个测试数组找完了都没找到-1，就说明诶有重复的值
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//方法四：不改变数组元素，找重复的元素，此时空间复杂度为O(1)
//n+1个数的范围在1～n之间，所以必定有一个重复的数，找出数组中的一个重复的数字
//////////////////////////////////////////////////////////////////////////////


//int find_replace4(int data[],int size)
//{
//    if(data == NULL || size <= 0)
//    {
//        //非法输入
//        return -1;
//    }
//    int index = 0;
//    for(;index < size;++index)
//    {
//        if(data[index] < 1 || data[index] > size - 1)
//        {
//            //数组中的数不在要求的范围内
//            return -1;
//        }
//    }
//
//    //1.取数组的中间元素，若中间元素值为m
//    int left = 1;
//    int right = size - 1;
//    while(left <= right)
//    {
//        int mid_value = left + (right - left)/2;
//        int count = 0;
//        for(index = 0;index < size;++index)
//        {
//            //2.统计数组元素值在1~m之间的个数，及在m+1~size-1之间的元素个数
//            if(data[index] >= left && data[index] <= mid_value)
//            {
//                count++;
//            }
//        }
//        if(left == right && count > 1)
//        {
//            //printf("%d\n",left);
//            return left;
//        }
//
//        //3.如果在1~m之间的个数大于m，则1~m之间必定有个重复元素，反之m+1~size-1之间必定有个重复元素
//        if(count > (mid_value - left + 1))
//        {
//            right = mid_value;
//        }
//        else
//        {
//            left = mid_value + 1;
//        }
//        //4.再对有重复元素的区间进行二分，回到步骤1，直到找到该重复元素
//    }
//}

//1~n n+1

int find_replace4(int *data,int size)
{
    if(data == NULL && size < 0)
    {
        return 0;
    }

    int left = 1;
    int right = size - 1;
    int mid = 0;
    while(1)
    {
        mid = left + (right - left)/2;
        int count = 0;
        int i = 0;
        for(;i < size;++i)
        {
            if(data[i] >= left && data[i] <= mid)
            {
                count++;
            }
        }
        if(left == right && count > 1)
        {
            return left;
        }
        else if(count > (mid - left + 1))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
}


//////////////////////////////
//测试代码
//////////////////////////////


int main()
{
    int data[] = {5,3,4,1,2,5};
    int size;
    int replace_data;
    int ret = 0;

    size = sizeof(data)/sizeof(data[0]);
//    ret = find_replace1(data,size,&replace_data);
//    printf("expect 1,actually %d\n",ret);
//    printf("expect 5,actually %d\n",replace_data);
//
//    ret = find_replace2(data,size,&replace_data);
//    printf("expect 1,actually %d\n",ret);
//    printf("expect 5,actually %d\n",replace_data);
//
//    ret = find_replace3(data,size,&replace_data);
//    printf("expect 1,actually %d\n",ret);
//    printf("expect 5,actually %d\n",replace_data);
//
    ret = find_replace4(data,size);
    printf("expect 5,actually %d\n",ret);

//    int data1[] = {0,3,4,2,1};
//    size = sizeof(data1)/sizeof(data1[0]);
//    ret = find_replace1(data1,size,&replace_data);
//    printf("expect 0,actually %d\n",ret);
//
//    ret = find_replace2(data1,size,&replace_data);
//    printf("expect 0,actually %d\n",ret);
//    
//    ret = find_replace3(data1,size,&replace_data);
//    printf("expect 0,actually %d\n",ret);
//
    int data2[] = {2,3,4,2,1};
    ret = find_replace4(data2,size);
    printf("expect 2,actually %d\n",ret);
    return 0;
}

