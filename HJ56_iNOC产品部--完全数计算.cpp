#include<iostream>
#include<cmath>
#include<vector>
//17:25-17:59
using namespace std;
//本地要注意的一个点，就是算法的复杂度，不要超时
//但是奇怪的是，使用查表的方式，竟然比“不查表的”方式还要慢
//通过查看完美数的分部情况“6, 28, 496, 8128”推测，在排除10000-500000这段，花了过长的时间
//有些是否，添加一句排除冗余情况的代码，可以提高算法速度30%
//另外一种思路，欧拉公式：如果i是质数，2^i-1也是质数，那么（2^i-1）*2^(i-1)就是完全数。
bool isPerfect(int num)
{
    int sum = 0;
    int end = sqrt(num);
    sum += 1;
    for(int i=2;i<=end; ++i)
    {
        if(0==num%i)
        {
            if(end == i && fabs(end-sqrt(num))<0.000001)
            {
                sum +=i;
            }
            else
            {
                sum +=i;
                sum +=num/i;
            }
            
            if(sum>num)//加上这一句，查表法用时从890ms减少到670ms
            {
                return false;
            }
        }
    }
    
    if(sum==num)
    {
        //cout<<"   "<<num<<"  | ";
        return true;
    }
    else
    {
        return false;
    }
}


void analysis(int num)
{
    int count = 0;
    for(int i=2;i<num;++i)
    {
        if(isPerfect(i))
        {
            ++count;
        }
    }
    cout<<count<<endl;
}



int main()
{
    //直接查找，从AC通过的角度看，貌似时间效率也可以接受，用时5ms，占用内存476KB
    /*
    int num;
    
    while(cin>>num)
    {
        analysis(num);
    }
    */
    
    //下面进行查表法，因为n是有限的，所以可以先把所有复合条件的数字找到并存下来；
    //之后查表就好
    //用查表法竟然用了820ms, 376K！！！!还有超时的情况
    //所以推断测试集可能并不全面
    
    int num;
    vector<int> perfectDigits;
    
    for(int i=2;i<=500000;++i)
    {
        if(isPerfect(i))
        {
            perfectDigits.push_back(i);
        }
    }
    
    while(cin>>num)
    {
        if(num<=0 ||num>500000)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            int count = 0;
            for(int i=0;i<perfectDigits.size();++i)
            {
                if(perfectDigits[i]>num)
                {
                    count = i;
                    break;
                }
            }
            cout<<count<<endl;
        }
    }
    
}