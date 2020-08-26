#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
//07:50-08:05
void toLower(char& ch)
{
    if(isupper(ch))
    {
        ch = ch-'A'+'a';
    }
}

void calcBeauty(const string & name)
{
    string temp = name;
    for_each(temp.begin(), temp.end(), toLower);
    
    int count[26];
    memset(count, 0, sizeof(count));
    
    int beauty = 0;
    
    /*
    不要用lamda捕获数组名，因为lamda不会认为这个数组名会退化为指针。
    当然，如果可能的话，尽可能避免捕获引用或指针。
    auto lamda = [count](char ch)mutable{
        if(islower(ch))
        {
            int id = ch-'a';
            ++count[id];
        }
    };*/
    int* countTemp = count;
    auto lamda = [countTemp](char ch)mutable{
        if(islower(ch))
        {
            int id = ch-'a';
            ++(*(countTemp+id));
        }
    };
    
    for_each(temp.begin(), temp.end(), lamda);
    /*
    //这个地方可以用一个lamda表达式
    for(auto ch:temp)
    {
        if(islower(ch))
        {
            ++count[ch-'a'];
        }
    }*/
    
    sort(count, count+26);
    
    
    for(int i=25; i>=0;i--)
    {
        beauty += count[i]*(i+1);
    }
    cout<<beauty<<endl;
    //cout<<temp<<"  "<<beauty<<" | ";//<<endl;
}



int main()
{
    string name;
    int num=0;
    while(cin>>num)
    {
        while(num)
        {
            cin>>name;
            //getline(cin, name);
            calcBeauty(name);
            --num;
        }
    }
}