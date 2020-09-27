#include<iostream>
#include<string>
#include<cstring>
using namespace std;
//20200924 09:45-10:10

//一篇有价值的blog https://blog.csdn.net/zzran/article/details/8274735
/******************
nowcoder 木易星的高赞回答
这道题其实简单的理解就是为了求字符串的最小编辑代价，也是一个经典的动态规划题，复杂度O(M*N)
思路：1.求解状态转移矩阵dp[M + 1][N + 1],dp[i][j] 的值代表的是str1[0...i-1]编辑为str2[0...j-1]
的最小代价。
2. 计算过程：
1）dp[0][0] = 0,表示str1空的字串编辑为str2空的字串代价为0。
2）矩阵dp第一列即为dp[0...M-1][0],dp[i][0] 表示str1[0...i-1]编辑为空串的最小代价，所以就是将str1[0..M-1]的字符删掉的代价
所以dp[i][0] = i;
3) 同2），那str2[0...j-1]编辑的代价，dp[0][j] = j;
4) 接下来的位置就按照从左到右，从上到下来计算，dp[i][j]的值来至于下面的几种情况：
（1）str1[0...i-1]可以先编辑为str1[0..i-2],也就是删除字符str1[i-1],然后由str1[0..i-2]编辑为str2[0...j-1]，dp[i-1][j]表示str1[0..i-2]编辑为str2[0...j-1]的最小代价，
那么dp[i][j]可能等于dp[i -1][j] + 1;
(2）str1[0...i-1]可以先编辑为str1[0..i-2],然后将str2[0..j-2]插入字符str2[j-1],编辑成str2[0...j-1]，dp[i][j-1]表示str1[0..i-1]编辑成str2[0...j-2]的最小代价，
那么dp[i][j] 可能等于dp[i][j-1] + 1;
(3) 如果str1[i - 1]!=str2[j-1] ，那么先把str1[0..i-1]中的str1[0..i-2]的部分边长str2[0..j-2]，然后把字符str1[i-1]替换为str2[j-1],这样str1[0..i-1]就编辑成为str2[0...j-1]了，dp[i - 1][j - 1]表示
str1[0..i-2]编辑为str2[0..j-2]的最小代价，那么dp[i ][j]可能等于dp[i - 1][j - 1] + 1;
(4) 如果str1[i - 1]==str2[j-1] ，那么先把str1[0..i-1]中的str1[0..i-2]的部分边长str2[0..j-2]，因为此时   str1[i - 1]==str2[j-1] ，所以str1[0..i-1]已经编辑为str2[0..j-1]了，dp[i - 1][j - 1]表示str1[0..i-2]编辑为str2[0..j-2]的最小代价， 那么dp[i ][j]可能等于dp[i - 1][j - 1]。
 
上述的4中情况取最小值,dp的最右下角就是最终结果，即最小编辑代价。
******************/
void calcStringSimilarity(const string & str1, const string & str2)
{
    int size1 = str1.size()+1;
    int size2 = str2.size()+1;
    
    int dist[size1][size2];
    memset(dist,0, sizeof(dist));
    
    for(int i=0; i<size1;++i)
    {
        dist[i][0]=i;
    }
    for(int j=0;j<size2;++j)
    {
        dist[0][j]=j;
    }
    
    int dist1 = 0, dist2 = 0, dist3=0, distMin = 0;
    for(int i=1;i<size1;++i)
    {
        for(int j=1;j<size2;++j)
        {
            if(str1[i-1]==str2[j-1])
            {
                dist3 = dist[i-1][j-1];
            }
            else
            {
                dist3 = dist[i-1][j-1] + 1;
            }
            
            dist1 = dist[i][j-1]+1;
            dist2 = dist[i-1][j]+1;
            
            distMin = dist1<dist2? dist1:dist2;
            distMin = dist3<distMin? dist3:distMin;
            dist[i][j] = distMin;
        }
    }
    
    string result = "1/" + to_string(dist[size1-1][size2-1]+1);
    cout<<result<<endl;
}

int main()
{
    string str1, str2;
    while(cin>>str1)
    {
        cin>>str2;
        calcStringSimilarity(str1, str2);
    }
}
