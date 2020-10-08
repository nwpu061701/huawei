//20201008 23:13-23:34(50% 未输出较短串中最先出现的那个)-23:48（80%，字符串比较忘了减1）
#include<iostream>
#include<string>

using namespace std;

void analysis(string &a, string &b)
{
    if(a.size()>b.size())
    {
        swap(a, b);
    }
    int sizea = a.size();
    int sizeb = b.size();
    int dp[sizea+1][sizeb+1];
    
    for(int i=0;i<=sizea;++i)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=sizeb;++j)
    {
        dp[0][j]=0;
    }
    
    int lenMax = 0;
    int x = 0, y = 0;
    for(int i=1;i<=sizea;++i)
    {
        for(int j=1;j<=sizeb;++j)
        {
            if(a[i-1]==b[j-1])//这里忘了减1了
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=0;
            }
            
            if(lenMax<dp[i][j])
            {
                lenMax = dp[i][j];
                x = i;
                y = j;
            }
        }
    }

    cout<<a.substr(x-lenMax,lenMax)<<endl;//注意dp矩阵坐标和字符串坐标的对应关系，否则会出错
}


int main()
{
    string a, b;
    while(cin>>a)
    {
        cin>>b;
        analysis(a,b);
    }
}