#include<iostream>
#include<cmath>
using namespace std;

/*
HJ60 查找组成一个偶数最接近的两个素数
如何判断一个数m是不是素数(Prime)？只需要判断m能不能被2-sqrt(m)之间的整数整除即可
reference：http://c.biancheng.net/view/498.html
*/

bool isPrime(int num)
{
    int end = sqrt(num)+0.5;
    
    for(int i=2;i<=end;i++)
    {
        if(0==num%i)
        {
            return false;
        }
    }
    
    return true;
}

void analysis(int num)
{
    if(num<2 || 1== num%2)
    {
        cout<<endl;
    }
    
    int half = num/2;

    for(int i=half; i>1;i--)
    {
        if(isPrime(i) && isPrime(num-i))
        {
            cout<<i<<endl<<num-i<<endl;
            return;
        }
    }
    
    cout<<1<<endl<<num<<endl;
    return;
}


int main()
{
    int num;
    while(cin>>num)
    {
        analysis(num);
    }
}