#include<iostream>
using namespace std;

void MoveZero(int arr[],int n)
{
    //定义两个变量，都是从头开始进行遍历
    //fast从头往后开始遍历，找到第一个0元素
    //fast找到0元素之后，slow从fast之后的后一个位置开始往后遍历寻找该0元素之后的第一个非零元素
    //找到之后，进行交换。
    //交换之后，fast继续往后开始遍历寻找0元素，找到之后,slow与以上相同
    //直到fast或者slow达到数组结尾
    //
    //注意：如果slow到达结尾说明0元素已经全部移到后面了
    //如果fast到达结尾说明数组中没有0元素
    
    int fast = 0;
    int slow = 0;

    while(fast < n || slow < n)
    {
        while(fast < n && arr[fast] != 0)
        {
            fast++;
        }
        if(fast == n)
        {
            return;
        }
        slow = fast + 1;
        while(slow < n && arr[slow] == 0)
        {
            slow++;
        }
        if(slow == n)
        {
            return;
        }
        swap(arr[fast],arr[slow]);
    }
}


int main()
{
    int arr[] = {1,2,0,3,4,0,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    MoveZero(arr,n);
    int index = 0;
    for(index = 0;index < n;index++)
    {
        cout<<arr[index]<<" ";
    }
    cout<<endl;
    return 0;
}
