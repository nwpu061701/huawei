//20201007 11:38-12:23  13:05-13:12(50%)-13:19(90%)-13:55(100%)
//              45m          7m         7m
//第一次段错误，原因是，向量定义后，直接访问元素，此时向量中还没有元素呢。
//第二次只有50%通过的原因是，炸弹是4个，写成了3个
//第三次只有90%通过的原因是，Q和K和A和2的大小关系不对

//本题的关键在于，剪切字符串，字符串比较（2比9大，2比10大等等），以及搞清楚炸弹是几个
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

#define two 14
#define joker 15
#define JOKER 16


vector<string> strDict = {"3", "4", "5", "6", "7","8","9","10","J", "Q", "K","A", "2","joker","JOKER"};
vector<int> intDict = {3, 4, 5, 6, 7,8,9,10,11, 12, 13, 14, 15, 16, 17};

void cut(const string str, vector<int> &words)
{
    stringstream ss(str);
    string temp;
    while(ss>>temp)
    {
        auto pos=find(strDict.begin(), strDict.end(), temp);
        if(strDict.end()!=pos)
        {
            words.push_back(intDict[pos-strDict.begin()]);
        }
    }
    return;
}

bool isCamparable(const vector<int> & cards1, const vector<int> & cards2)
{
    if(cards1.size() == cards2.size())
    {
        return true;
    }
    else if(4==cards1.size() || (2==cards1.size() && cards1.end() != find(cards1.begin(),cards1.end(),16))
           || 4==cards2.size() || (2==cards2.size() && cards2.end() != find(cards2.begin(),cards2.end(),16)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool campare(const vector<int> & cards1, const vector<int> & cards2)
{
    if(2==cards1.size() && cards1.end() != find(cards1.begin(),cards1.end(),16))
   {
        return true;
   }
   else if(2==cards2.size() && cards2.end() != find(cards2.begin(),cards2.end(),16))
   {
       return false;
   }
   //cards1是炸弹，card2是非王对子
   else if(4==cards1.size() && (2==cards2.size() && cards2.end() == find(cards2.begin(),cards2.end(),16)))
   {
        return true;
   }
   else if(4==cards1.size() && (2==cards2.size() && cards2.end() != find(cards2.begin(),cards2.end(),16)))
   {
       return false;
   }
   else if(4==cards1.size() && 4!=cards2.size())
   {
       return true;
   }
   //cards1是炸弹，card2是炸弹
   else if(cards1.size()==cards2.size())
   {
       return cards1[0]>cards2[0];
   }
   else
   {
       return false;//多余的
   }
       
}


void analysis(const string &card1, const string &card2)
{
    
    vector<vector<int>> cards_array(2);
    cut(card1, cards_array[0]);//注意，如果cards_array中没有元素，是不能直接使用元素的。由于cards_array一开始没有指定元素数目，这里花了7分钟时间定位错误
    cut(card2, cards_array[1]);

    if(isCamparable(cards_array[0], cards_array[1]))
    {
        sort(cards_array.begin(),cards_array.end(),campare);
        
        cout<<strDict[cards_array[0][0]-intDict[0]];
        for(int i=1;i<cards_array[0].size();++i)
        {
            cout<<" "<<strDict[cards_array[0][i]-intDict[0]];
        }
        cout<<endl;
        
    }
    else
    {
        cout<<"ERROR"<<endl;
    }
    
}

int main()
{
    string input;
    while(getline(cin,input))
    {
        stringstream ss(input);
        string card1, card2;
        getline(ss, card1, '-');
        getline(ss, card2, '-');
        analysis(card1, card2);

    }
}