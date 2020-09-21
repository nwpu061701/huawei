#include<iostream>
#include<string>

using namespace std;

bool isConcerned7(int num)
{
    //有一个更简单暴力的判断，来自“忆水寒”的代码
    //if(!(i%7)||i%10==7||(i%100)/10==7||(i%1000)/100==7||(i%10000)/1000==7)
    
    if(0==num%7)
    {
        return true;
    }
    else
    {
        string temp = to_string(num);//注意，是to_string，而不是itostring
        
        if(string::npos != temp.find('7'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}



void count(int N)
{
    int num = 0;
    
    for(int i=6;i<=N;++i)
    {
        if(isConcerned7(i))
        {
            ++num;
        }
    }
    cout<<num<<endl;
}



int main()
{
    int N;
    while(cin>>N)
    {
        count(N);
    }
}