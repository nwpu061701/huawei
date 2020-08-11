#include<string>
#include<sstream>
#include<iostream>

using namespace std;

void transferIp(const string & input)
{
    stringstream ss(input);
    char dot;
    long long ip=0;
    int temp=0;
    //stringstream如何将dot识别为分隔符并将数字转换为整形？
    //除了下面这种形式，还有方法 while(getline(ss,string, ',')){} 然后用std::stoi()的返回值得到整型数字（当然用ss>>int也行，注意需要ss.clear以及ss.str("")）
    for(int i=0;i<3;i++)
    {
        ss>>temp>>dot;
        ip = ip*256+temp;
    }
    ss>>temp;
    ip = ip*256+temp;
    cout<<ip<<endl;
}

void transferIp(long long ip)
{
    int temp[4]={0,0,0,0};
    for(int i=3;i>=0;--i)
    {
        temp[i]=ip&(0x00FF);
        ip=ip>>8;
    }
    
    for(int i=0;i<3;i++)
    {
        cout<<temp[i]<<".";
    }
    cout<<temp[3]<<endl;
}

int main()
{
    string input;
    long long num;
    while(cin>>input)
    {
        cin>>num;
        transferIp(input);
        transferIp(num);
    }
}