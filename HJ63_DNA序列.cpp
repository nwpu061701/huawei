//22:52
#include<iostream>
#include<string>
/*
题目描述
    一个DNA序列由A/C/G/T四个字母的排列组合组成。G和C的比例（定义为GC-Ratio）是序列中G和C两个字母的
    总的出现次数除以总的字母数目（也就是序列长度）。在基因工程中，这个比例非常重要。因为高的GC-Ratio
    可能是基因的起始点。

    给定一个很长的DNA序列，以及要求的最小子序列长度，研究人员经常会需要在其中找出GC-Ratio最高的子序列。

输入描述:
    输入一个string型基因序列，和int型子串的长度

输出描述:
    找出GC比例最高的子串,如果有多个输出第一个的子串


示例1
    输入
    AACTGTGCACGACCTGA
    5

    输出
    GCACG
*/

//nowcoder上通过的代码，固定了子序列的长度，但实际上子序列的长度应该是>=最小子序列长度的，要找的是长度>=最小长度的子序列中GC含量最高的那个子序列
using namespace std;

inline bool isGC(char ch)
{
    if('G'==ch || 'C'==ch)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void calcTopGC(const string & input, int subNum)
{
    if(input.size()<subNum)
    {
        cout<<endl;
    }
    else
    {
        int topPos = 0;//记录GC比例最高的字串的起点
        int topNum = 0;
        for(int i=0; i<subNum; i++)
        {
            if(isGC(input[i]))
            {
                ++topNum;
            }
        }
        
        int tempTopNum = topNum;
        for(int i=subNum; i<input.size(); i++)
        {
            if(isGC(input[i-subNum]))
            {
                --tempTopNum;
            }
            if(isGC(input[i]))
            {
                ++tempTopNum;
            }
               
            if(tempTopNum>topNum)
            {
                topPos = i-subNum+1;//更新起点
                topNum = tempTopNum;
            }
        }
        
        cout<<input.substr(topPos, subNum)<<endl;
    }

}


int main()
{
    string input;
    int num;
    while(getline(cin, input))
    {
        cin>>num;
        
        calcTopGC(input, num);
        
        
    }
}