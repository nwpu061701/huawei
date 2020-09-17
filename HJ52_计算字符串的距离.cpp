#include<iostream>
#include<string>


//典型的动态规划问题
//感觉DP问题初看很复杂，其实熟悉之后无非就是列好状态转移方程和找初始状态，然后循环加比较就完事了
/* 来自nowcoder "蓝天萝卜"的观点
 *字符串之间的距离，编辑距离，将strA编辑成strB所需的最小代价
 * 编辑操作包括插入一个字符、删除一个字符、替换一个字符
 * 分别对应的代价是ic、dc、rc，insert cost、delete cost、replace cost
 * strA[x-1]代表strA的第x个字符，注意下标是从0开始的,strA[y-1]代表strA的第y个字符
 * 定义一个代价矩阵为(N+1)*(M+1)，M N 表示strA strB的长度
 * dp[x][y]表示strA的前x个字符串编辑成 strB的前y个字符所花费的代价
 * dp[x][y]是下面几种值的最小值：
     * 1、dp[x][y] = dp[x-1][y] + dc
     * dp[x-1][y]将strA的前x-1个字符编辑成strB的前y个字符的代价已知，
     * 那么将将strA的前x个字符编辑成strB的前y个字符的代价dp[x][y]就是dp[x-1][y] + dc
     * 相当于strA的前x-1个字符编辑成strB的前y个字符，现在变成了strA的前x个字符，增加了一个字符，要加上删除代价
     * 2、dp[x][y] = dp[x][y-1] + ic
     * dp[x][y-1]将strA的前x个字符编辑成strB的前y-1个字符的代价已知，
     * 现在变为strB的前y个字符，相应的在strA前x个操作代价的基础上插入一个字符
     * 3、dp[x][y] = dp[x-1][y-1]
     * dp[x-1][y-1]将strA的前x-1个字符编辑成strB的前y-1个字符的代价已知，
     * strA的第x个字符和strB的第y个字符相同，strA[x-1] == strB[y-1]，没有引入操作
     * 4、dp[x][y] = dp[x-1][y-1] + rc
     * strA的第x个字符和strB的第y个字符不相同，strA[x-1] ！= strB[y-1]，
     * 在strA的前x-1个字符编辑成strB的前y-1个字符的代价已知的情况下，
     * 计算在strA的前x字符编辑成strB的前y个字符的代价需要加上替换一个字符的代价
* */
using namespace std;

void calStringDistance(const string & str1, const string & str2)
{
    const int size1 = str1.size()+1;
    const int size2 = str2.size()+1;
    
    int dp[size1][size2];//dp[i][j]表示将str1的前i个字符转换成str2的前j个字符
    
    for(int i=0;i<size1;++i)
    {
        dp[i][0] = i;
    }
    
    for(int i=0;i<size2;++i)
    {
        dp[0][i]=i;
    }
    
    int deltai = 0, deltaj = 0, deltaij = 0;
    int deltaMin = 0;
    for(int i=1;i<size1;++i)
        for(int j=1;j<size2;++j)
        {
            if(str1[i-1]!=str2[j-1])
            {
                deltaij = dp[i-1][j-1]+1;
            }
            else
            {
                deltaij =  dp[i-1][j-1];
            }
            
            deltai = dp[i-1][j]+1;
            deltaj = dp[i][j-1]+1;
            
            deltaMin = (deltai>deltaj)?deltaj:deltai;
            deltaMin = (deltaMin>deltaij)?deltaij:deltaMin;
            
            dp[i][j] = deltaMin;
        }
    
    cout<<dp[size1-1][size2-1]<<endl;
}

int main()
{
    string str1, str2;
    
    while(cin>>str1)
    {
        cin>>str2;
        calStringDistance(str1, str2);
    }
    
}