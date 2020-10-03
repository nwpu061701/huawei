#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class node
{
public:
    char ch;
    int num;
    
    bool operator==(const node &node1)
    {
        if(ch == node1.ch)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/*
bool compare(const node node1, const node node2)
{
    if(node1.ch==node2.ch)
    {
        return true;
    }
    else
    {
        return false;
    }
}*/

void analysis(const string &str)
{
    vector<node> info;
    
    for(auto ch:str)
    {
        node tempNode = {ch, 1};
        auto it = find(info.begin(), info.end(), tempNode);
        if(info.end()==it)
        {
            info.push_back(tempNode);
        }
        else
        {
            ++it->num;
        }
    }
    
    auto itr = info.begin();
    for(;itr!=info.end();++itr)
    {
        if(1==itr->num)
        {
            break;
        }
    }
    
    if(itr!=info.end())
    {
        cout<<itr->ch<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
}

int main()
{
    string str;
    while(cin>>str)
    {
        analysis(str);
    }
}