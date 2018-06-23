#include<stdio.h>
#include<stdlib.h>


//将一个数组中的所有数相乘，得到一个新数组
//如数组：{1,2,3,4,5}
//新数组元素：{2*3*4*5,1*3*4*5,1*2*4*5,1*2*3*5,1*2*3*4}

int* multiply(int* a,int size)
{
    int* b = (int*)malloc(size*sizeof(int));
    //记录数组b的下标
    int index = 0;
    for(;index < size;index++)
    {
        int mul = 1;
        //记录数组a的下标
        int i = 0;
        for(;i < size;i++)
        {
            if(index == i)
            {
                continue;

            }
            mul = mul*a[i];

        }
        b[index] = mul;

    }
    return b;

}


int main()
{
    int a[] = {1,2,3,4,5};
    int size = sizeof(a)/sizeof(a[0]);
    int* b = multiply(a,size);
    int index = 0;
    for(;index < size;index++)
    {
        printf("%d ",b[index]);
    }
    printf("\n");
    return 0;

}
