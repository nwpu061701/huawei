//20201007 15:57-16:07(dfs)
#include<iostream>
#include<cstring>
//本题解法：①dfs ②动态规划  ③排列组合算法
/*
草草看了下其他人的解法，都是使用递归，这样对于大的m和n，肯定时间复杂度是不满足的，这道题的测试用例还是太easy。----来自“华科平凡”
*/
using namespace std;
int count = 0;
int n=0,m=0;

void dfs(int x, int y)
{
    if(x>n || y>m)
    {
        return;
    }
    else if(n==x && m==y)
    {
        ++count;
    }
    else
    {
        dfs(x+1, y);
        dfs(x, y+1);
    }
}

int dp(int n, int m)
{
    int array[n+1][m+1];
    memset(array, 0, sizeof(array));
    
    for(int i=0;i<=n;++i)
    {
        array[i][0]=1;
    }
    
    for(int j=0;j<=m;++j)
    {
        array[0][j]=1;
    }
    
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            array[i][j] = array[i-1][j]+array[i][j-1];
            //cout<<"("<<i<<","<<j<<" "<<array[i][j]<<"|";
        }
    }
    //cout<<array[n][m]<<"|";
    return array[n][m];
}


int main()
{
    while(cin>>n>>m)
    {
        /* dfs
        count = 0;
        dfs(0,0);
        cout<<count<<endl;
        count=0;
        */
        count = dp(n, m);
        cout<<count<<endl;
        
    }
}