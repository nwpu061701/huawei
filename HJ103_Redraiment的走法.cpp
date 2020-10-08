//20201008 09:52-10:53(做题，指导用动态规划，但未作出) 10:53-11:15（查看相关答案）
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//尝试用step[height.size()+1][height.size()+1]来实现动态规划，
//未想出step[i][j]的状态转移公式
void analysis(const vector<int> height)
{
    int m = height.size();
    int step[m+1][m+1];
}

void analysis1(const vector<int> height)
{
    int m = height.size();
    vector<int> dp(m,1);
    int maxStep=1;
    
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<i;++j)
        {
            //每一个height[i]，可以由height(j)(j<i)来达到。这里也就是多条路径了
            //对于每一个height[i]，有多个转换路径，那就要把所有的转换路径遍历一遍
            //从而形成状态转移关系
            if(height[j]<height[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        if(maxStep<dp[i])
        {
            maxStep = dp[i];
        }
    }
    
    cout<<maxStep<<endl;
}


int main()
{
    int num;
    int h_temp;
    while(cin>>num)
    {
        vector<int> height;

        for(int i=0;i<num;++i)
        {
            cin>>h_temp;
            height.push_back(h_temp);
        }
        
        analysis1(height);
    }
}