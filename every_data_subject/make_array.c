#include<stdio.h>
#include<stdlib.h>


int* multiply(int* a,int size)
{
    int* b = (int*)malloc(size*sizeof(int));
    int index = 0;
    for(;index < size;index++)
    {
        int mul = 1;
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
