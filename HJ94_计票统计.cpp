//20201007 23:33-23:52
#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>

//这道题不要用map<string,int>来配对名字和票数，因为map会打乱输入顺序
//map会默认排序，这个解法，对于输出时候的顺序，不一定会和输入的名字顺序一致吧
using namespace std;

class candicate
{
public:
    candicate(const string & str):name(str),tickets(0){}
    
    bool operator==(const candicate& temp){
            return temp.name==this->name;
    }
    
    void vote(){
        ++tickets;
    }
    
    int tickets;
    string name;
};



int main()
{
    int num=0;
    string name;
    while(cin>>num)
    {
        vector<candicate> cands;
        candicate invalid("Invalid");
        for(int i=0;i<num;++i)
        {
            cin>>name;
            candicate cand(name);
            cands.push_back(cand);
        }
        
        cin>>num;
        for(int i=0;i<num;++i)
        {
            cin>>name;
            candicate temp(name);
            auto itr = find(cands.begin(), cands.end(),temp);
            if(cands.end()!=itr)
            {
                itr->vote();
            }
            else
            {
                invalid.vote();
            }
        }
        
        for(auto &temp:cands)
        {
            cout<<temp.name<<" : "<<temp.tickets<<endl;
        }
        cout<<invalid.name<<" : "<<invalid.tickets<<endl;
    }
}