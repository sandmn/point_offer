#include<stdio.h>
#include<stdlib.h>

void Swap(int* a,int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int duplicate(int numbers[], int length, int* duplication) {

    int index = 0;
    for(;index < length;index++)
    {
        while(numbers[index] != index)
        {
            if(numbers[index] == numbers[numbers[index]])
            {
                *duplication = numbers[index];
                return 1;
            }
            Swap(&numbers[index],&numbers[numbers[index]]);
        }    
    }
    return 0;
}
int main()
{
    int num[] = {4,6,1,0,2,5,3};
    int repeat;
    int ret = duplicate(num,sizeof(num)/sizeof(num[0]),&repeat);
    printf("expect 1,actually %d\n",ret);
    printf("expect 2,actually %d\n",repeat);
    return 0;
}
