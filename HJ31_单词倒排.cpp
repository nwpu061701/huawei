#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
#include<vector>

using namespace std;

void transfer(string & str)
{
    for(auto & ch:str)
    {
        if(isupper(ch) || islower(ch))
        {
            //nothing to do
        }
        else
        {
            ch = ' ';
        }
    }
}

void reverse(const string & input)
{
    string transferd = input;
    transfer(transferd);
    
    stringstream ss(transferd);
    
    vector<string> vstr;
    string word;
    while(ss>>word)
    {
        vstr.push_back(word);
    }
    



    if(vstr.size())
    {
        /*尾部有空格，格式不符合
        auto endItr = vstr.rend();
        for(auto itr=vstr.rbegin();itr!=endItr;itr++)
        {
            cout<<*itr<<" ";
        }
        cout<<endl;
        */
        /*可以通过
        for(int i= vstr.size()-1; i>0;--i)
        {
            cout<<vstr[i]<<" ";
        }
        cout<<vstr[0]<<endl;
        */
        //用reverse(str.begin(),str.end());实现倒叙也行
        auto endItr = --vstr.rend();
        for(auto itr=vstr.rbegin();itr!=endItr;itr++)
        {
            cout<<*itr<<" ";
        }
        cout<<*endItr<<endl;
    }
    else
    {
        cout<<endl;
    }

}

int main()
{
    string input;
    while(getline(cin, input))
    {
        reverse(input);
    }
}