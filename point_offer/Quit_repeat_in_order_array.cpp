#include<iostream>
using namespace std;

//有序数组进行去重
int Quit_Repeat(int arr[],int n)
{
    if(arr == NULL || n <= 1)
    {
        return n;
    }
    int i = 0;
    int index = 0;
    for(i = 1;i < n;i++)
    {
        if(arr[index] != arr[i])
        {
            arr[++index] = arr[i];
        }
    }
    return index + 1;

}

int main()
{
    int arr[] = {1,2,2,2,3,4,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ret = Quit_Repeat(arr,n);
    int i = 0;
    for(i = 0;i < ret;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
