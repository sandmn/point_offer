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
