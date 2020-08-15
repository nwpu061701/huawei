#include<string>
#include<iostream>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;

char transtoupper(char &ch)
{
    if(ch>='a' && ch<='z')
    {
        ch = ch -'a' +'A';
    }
    return ch;
}

string calc(const string & key)
{
    string keyTemp = key;
    for_each(keyTemp.begin(), keyTemp.end(), transtoupper);
    /*
    for(auto & ch :keyTemp)
    {
        if(islower(ch))//不用判断是否是小写字母，再转大写。
        {
            ch = toupper(ch);//toupper会判断是否是小写字母且有对应的大写字母，如果不是，则不转换
        }
    }*/
    //使用unique，需要和sort一起使用才行，unique的原理要求相同的要先放在一起。
    //这里出错，导致一时无法定位是哪里的问题。
    //auto itr = unique(result.begin(), result.end());
    //result.erase(itr, result.end());
    bool existFlag[26];
    memset(existFlag, 0, 26);
    string result;
    for(auto ch: keyTemp)
    {
        if(!existFlag[ch-'A'])
        {
            result +=ch;
            existFlag[ch-'A']=true;
        }
    }
    
    
    
    
    for(char ch='A'; ch<='Z'; ch++)
    {
        if(string::npos == result.find(ch))
        {
            result +=ch;
        }
    }
    return result;
}

void encrypt(const string & key, const string & data)
{
    string encrypted;
    
    for(auto ch:data)
    {
        //cout<<ch<<"^"<<"islower="<<islower(ch);
        if(islower(ch))
        {
            //cout<<key[ch-'a']<<"#";
            encrypted +=tolower(key[ch-'a']);
        }
        else if(isupper(ch))
        {
            //cout<<key[ch-'A']<<"@";
            encrypted +=key[ch-'A'];
        }
        else
        {
            encrypted += ch;
        }
    }
    //cout<<data<<"|"<<key<<"|";
    cout<<encrypted<<endl;
}

int main()
{
    string key;
    string data;
    while(cin>>key)
    {
        cin>>data;
        key = calc(key);
        
        encrypt(key, data);
    }
}