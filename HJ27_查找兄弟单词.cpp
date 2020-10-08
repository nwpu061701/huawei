//20201008 17:11-17:45(40%)
//只通过40%的原因，输入答案的问题（题意没搞明白）
//题目的意思是，总是要输出查找到的兄弟单词的个数；
//对于索引n，没有超出兄弟单词个数的情况下，才输出该索引对应的兄弟单词
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

bool isBother(string a, string b)
{
    if(a == b)
    {
        return false;
    }
    else
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a==b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    string str;
    int num;
    while(cin>>num)
    {
        vector<string> words;
        vector<string> bothers;
        for(int i=0;i<num;++i)
        {
            cin>>str;
            words.push_back(str);
        }
        
        cin>>str;
        for(auto & i:words)
        {
            if(isBother(i, str))
            {
                bothers.push_back(i);
                //cout<<i<<"| ";
            }
        }
        
        sort(bothers.begin(), bothers.end());
        //auto end = unique(bothers.begin(), bothers.end());
        //bothers.erase(end, bothers.end());
        cout<<bothers.size()<<endl;
        cin>>num;
        
        if((num-1)<bothers.size())
        {
            cout<<bothers[num-1]<<endl;
        }
        /*
        if((num-1)<bothers.size())
        {
            cout<<bothers.size()<<endl<<bothers[num-1]<<endl;
        }
        else
        {
            cout<<endl;
        }
        */
    }
}