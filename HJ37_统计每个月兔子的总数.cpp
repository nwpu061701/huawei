#include<iostream>

using namespace std;

int getTotalCount1(int month)
{
    if(1==month)
    {
        return 1;
    }
    else if(2==month)
    {
        return 1;
    }
    else
    {
        
        int rabbits1 = 1;//1个月大的兔子
        int rabbits2 = 0;//2个月大的兔子
        int rabbits3 = 0;//3个月大及以上的兔子
        
        int temp=0;
        for(int i=1;i<month;i++)
        {
            /*
            兔子长满3个月再生产
            temp = rabbits3;
            rabbits3 += rabbits2;//2个月大的兔子又成长了，增加了3个月兔子的数量
            rabbits2 = rabbits1;//1个月大的兔子长成了2个月大的兔子
            rabbits1 = temp;//3个月大的兔子又生了1个月的兔子
            */
            
            //兔子长到第3个月就生产
            rabbits3 += rabbits2;//2个月大的兔子又成长了，增加了3个月兔子的数量
            rabbits2 = rabbits1;//1个月大的兔子长成了2个月大的兔子
            rabbits1 = rabbits3;//3个月大的兔子又生了1个月的兔子
            
            
        }
        return rabbits3+rabbits2+rabbits1;
    }
    
}

//思路：第month个月的成熟兔子M(month)，由第month-1个月的成熟兔子M(month-1)和第month-1个月的2个月兔子T(month-1)组成。
//第month个月的2个月兔子T(month-1) 来自于 第month-2个月的1个月兔子O(month-2)
//第month-2个月的1个月兔子O(month-2) 来自于 第month-2个月的成熟兔子M(month-2)
//于是M(month)=M(month-1)+M(month-2)
//第month个月，兔子的总数量是，O(month)+T(month)+M(month)=M(month)+M(month-1)+M(month)=2*M(month)+M(month-1)

int getTotalCount(int month)
{
    if(1==month)
    {
        return 1;
    }
    else if(2==month)
    {
        return 1;
    }
    else
    {
        
        int matureMonthPre2 = 0;//第month-2个月成熟兔子的数量
        int matureMonthPre1 = 1;//第month-1个月成熟兔子的数量
        
        int temp=0;
        for(int i=3;i<month;i++)
        {
            temp = matureMonthPre2;
            matureMonthPre2 = matureMonthPre1;
            matureMonthPre1 = temp+matureMonthPre2;
        }
        
        int matureCurrent = matureMonthPre1;//当前month成熟兔子的数量
        matureMonthPre1 = matureMonthPre2;
        int total = matureCurrent*2+matureMonthPre1;
        return total;
    }
    
}

int main()
{
    int month=0;
    while(cin>>month)
    {
        
        cout<<getTotalCount1(month)<<endl;
        //cout<<getTotalCount2(month)<<endl;
    }
}