//20201009 18:24-18:34 20:03-20:35(未想出来)
//第二次做，还是没弄出来，说明第一次看“讨论"后并没有理解
//该题目较难
#include<iostream>
#include<cstring>
using namespace std;


void analysis(int m, int n)
{
    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i=0;i<=m;++i)
    {
        dp[i][0]=0;//没有盘子时，为0个方法
    }
    
    for(int j=1;j<=n;++j)
    {
        dp[0][j]=1;//没有苹果使，为1种方法
    }
    
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dp[i][j]=dp[i][j-1];//分苹果看成两种分法，①如果有1个盘子中没有苹果；②如果盘子都有苹果，剩下的苹果如何放
            if(i-j>=0)
            {
                dp[i][j] += dp[i-j][j];
            }
        }
         
    }
    cout<<dp[m][n]<<endl; 
}

int main()
{
    int m=0,n=0;
    while(cin>>m)
    {
        cin>>n;
        if(m<=10 && m>0 && n<=10 && n>0)
        {
            analysis(m,n);
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
}