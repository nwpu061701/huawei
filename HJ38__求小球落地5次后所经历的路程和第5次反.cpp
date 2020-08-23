#include<iostream>
#include<cmath>
//这个判断误差的意思是啥？感觉保留位数题目没说清楚

//2016年有仙人提出了一种神奇答案，按比例缩放
//1米初始高度--经历2.875米--第五次反弹0.03125米
//n米初始高度--经历2.875*n米--第五次反弹0.03125*n米
using namespace std;

void calc(int height)
{
    float total = 0.0;
    float single = height;
    float temp= height;
    
    for(int i=0; i<4;i++)
    {
        temp *=0.5;
        if(fabs(temp-single)>0.000001)
        {
            single = temp;
            total +=single*2;
        }
    }
    
    total += height;
    single *= 0.5;
    cout<<total<<endl<<single<<endl;
}



int main()
{
    int height = 0;
    while(cin>>height)
    {
        calc(height);
    }
}