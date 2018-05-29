#include<stdio.h>

int find(int (*a)[4],int size,int key)
{
    if(a == NULL && size < 0)
    {
        return 0;
    }

    int row = 0;
    int col = 3;

    int value;
    while(1)
    {
        if(col < 0 && row > size-1)
        {
            return 0;
        }
        value = a[row][col];
        if(value == key)
        {
            printf("(%d,%d)\n",row,col);
            return 1;
        }
        else  if(value < key)
        {
            row++;   
        }
        else
        {
            col--;
        }
    }
}

int main()
{
    int a[4][4] = 
    {
        {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15}
    };

    int size = sizeof(a)/sizeof(a[0]);
    int key = 6;
    int ret = find(a,4,key);
    printf("%d\n",ret);
    return 0;
}


//在数组中查找一个值是否存在
//数组从左到右，从上到下递增
//int Find(int arr[][3], int size, int key)
//{
//    if (arr == NULL || size <= 0)
//    {
//        return 0;
//    }
//    int row = 0;
//    int col = size - 1;
//    while (row < size && col >= 0)
//    {
//        if (arr[row][col] == key)
//        {
//            return 1;
//        }
//        else if (arr[row][col] < key)
//        {
//            row++;
//        }
//        else
//        {
//            col--;
//        }
//    }
//    return 0;
//
//}
//
//int main()
//{
//    int arr[][3] =
//    {
//        { 1, 2, 3  },
//        { 4, 5, 6  },
//        { 7, 8, 9  }
//    };
//    int size = sizeof(arr) / sizeof(arr[0]);
//    int ret = Find(arr, size, 12);
//    printf("expect 1,actually %d\n", ret);
//    return 0;
//}
