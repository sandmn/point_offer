#include<iostream>
using namespace std;

//每5个数中产生一个可以生成一个0的数
//所以，用n除5，可以得到各个数
//在各个产生0的数中，还是5的倍数即是25的倍数的数还可以在产生一个0
//在上述的数中，再是5的倍数即是125的倍数的数还可以在产生一个0
//依次类推
//所以，首先对n除5，得到是5的倍数的数的个数
//然后，再次除5得到是25的倍数的数的个数
//以此类推
int CountOfZero_InTail(int n)
{
    long count = 0;
    long temp=n/5;
    while (temp!=0)
    {
        count+=temp;
        temp/=5;

    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int ret = CountOfZero_InTail(n);
    cout<<ret;
    return 0;
}
