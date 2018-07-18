#include<iostream>
using namespace std;

//顺时针从外圈到内圈打印数组

void Print(int arr[][4],int a,int b,int c,int d)
{
    //index用于遍历数组
    int index = 0;
    //如果要输出的只有一个元素时，此时就进不去下面的循环
    //所以要进行单独讨论
    if(a == c && b == d)
    {
        cout<<arr[a][b]<<" ";
    }
    for(index = b;index < d;index++)
    {
        cout<<arr[a][index]<<" ";
    }
    for(index = a;index < c;index++)
    {
        cout<<arr[index][d]<<" ";
    }
    for(index = d;index > b;index--)
    {
        cout<<arr[c][index]<<" ";
    }
    for(index = c;index > a;index--)
    {
        cout<<arr[index][b]<<" ";
    }
    return;
}

void PrintArr(int arr[][4],int row,int col)
{
    int a = 0;
    int b = 0;
    int c = row - 1;
    int d = col - 1;
    //当横纵坐标相同时，也要进行讨论
    //注意这里的两个条件要同时满足
    while(a <= c && b <= d)
    {
        Print(arr,a++,b++,c--,d--);
    }
    return;
}


void Test()
{
    //int arr1[][1] =
    //{
    //    {1},
    //    {2}
    //};
    ////计算行
    //int row1 = sizeof(arr1)/sizeof(arr1[0]);
    ////加算元素个数
    //int num1 = sizeof(arr1)/sizeof(arr1[0][0]);
    ////计算列
    //int col1 = num1/row1;
    //PrintArr(arr1,row1,col1);
    //cout<<endl;

    //int arr2[][2] = 
    //{
    //    {1,2},
    //    {3,4}
    //};
    ////计算行
    //int row2 = sizeof(arr2)/sizeof(arr2[0]);
    ////加算元素个数
    //int num2 = sizeof(arr2)/sizeof(arr2[0][0]);
    ////计算列
    //int col2 = num2/row2;
    //PrintArr(arr2,row2,col2);
    //cout<<endl;

    //int arr3[][3] =
    //{
    //    {1,2,3},
    //    {4,5,6}
    //};
    ////计算行
    //int row3 = sizeof(arr3)/sizeof(arr3[0]);
    ////加算元素个数
    //int num3 = sizeof(arr3)/sizeof(arr3[0][0]);
    ////计算列
    //int col3 = num3/row3;
    //PrintArr(arr3,row3,col3);
    //cout<<endl;

    //int arr4[][3] =
    //{
    //    {1,2,3},
    //    {4,5,6},
    //    {7,8,9},
    //    {10,11,12}

    //};
    ////计算行
    //int row4 = sizeof(arr4)/sizeof(arr4[0]);
    ////加算元素个数
    //int num4 = sizeof(arr4)/sizeof(arr4[0][0]);
    ////计算列
    //int col4 = num4/row4;
    //PrintArr(arr4,row4,col4);
    //cout<<endl;

    //int arr5[][3] =
    //{
    //    {1,2,3},
    //    {4,5,6},
    //    {7,8,9}
    //};
    ////计算行
    //int row5 = sizeof(arr5)/sizeof(arr5[0]);
    ////加算元素个数
    //int num5 = sizeof(arr5)/sizeof(arr5[0][0]);
    ////计算列
    //int col5 = num5/row5;
    //PrintArr(arr5,row5,col5);
    //cout<<endl;

    int arr6[][4] =
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    //计算行
    int row6 = sizeof(arr6)/sizeof(arr6[0]);
    //加算元素个数
    int num6 = sizeof(arr6)/sizeof(arr6[0][0]);
    //计算列
    int col6 = num6/row6;
    PrintArr(arr6,row6,col6);
    cout<<endl;
}


int main()
{
    Test();
    return 0;
}


