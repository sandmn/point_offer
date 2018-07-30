#include<iostream>
using namespace std;

//删除数组中的所有指定元素:返回新数组的大小
//方法1：对非指定元素逐个进行移动
int removeElement(int A[], int n, int elem)
{
    if(A == NULL || n <= 1)
    {
        return -1;
    }
    int i = 0;
    int index = 0;
    for(i = 0;i < n;i++)
    {
        if(A[i] != elem)
        {
            A[index++] = A[i];
        }
    }
    return index;
}

//方法2：定义两个指针查找指定元素和非指定元素进行交换
//交换法
int remove_all1(int arr[],int n,int key)
{
    if(arr == NULL || n <= 1)
    {
        return -1;
    }
    int index1 = 0;
    int index2 = 0;
    while(index1 < n && index2 < n)
    {
        while(index1 < n && arr[index1] != key)
        {
            index1++;
        }
        if(index1 < n)
        {
            index2 = index1 + 1;
        }
        while(index2 < n && arr[index2] == key)
        {
            index2++;
        }
        if(index2 < n)
        {
            swap(arr[index1],arr[index2]);
        }
    }
    int i = 0;
    int ret = 0;
    for(;i < n;i++)
    {
        if(arr[i] != key)
        {
            ret++;
        }
        else
        {
            break;
        }
    }
    return ret;
}

int main()
{
    int arr[] = {1,2,3,4,2,4,2,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 2;
    //int ret = remove_all1(arr,n,key);
    //int i = 0;
    //for(;i < ret;i++)
    //{
    //    cout<<arr[i]<<" ";
    //}
    //cout<<endl;

    int ret1 = removeElement(arr,n,key);
    for(int i = 0;i < ret1;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}
