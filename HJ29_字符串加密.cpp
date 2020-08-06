#include<iostream>
#include<string>
#include<cctype>
//还有查表大法！！！！！！！！！
//关于“负数取余“需要再好好看看
using namespace std;

string Encrypt(const string & aucPassword)
{
    string aucResult;
    for(auto ch:aucPassword)
    {
        if(islower(ch))
        {
            aucResult += (char)((ch-'a'+1)%26+'A');
        }
        else if(isupper(ch))
        {
            aucResult += (char)((ch-'A'+1)%26+'a');
        }
        else if(isdigit(ch))
        {
            aucResult += to_string((ch-'0'+1)%10);
        }
        else
        {
            aucResult += ch;
        }
    }
    return aucResult;
}

string unEncrypt(const string & result)
{
    string password;
    for(auto ch : result)
    {
        if(isupper(ch))
        {
            if('A'==ch)
            {
                password += 'z';
            }
            else if(isupper(ch))
            {
                password += (char)((ch-'A'-1+'a'));
            }
        }
        else if(islower(ch))
        {
            if('a'==ch)
            {
                password += 'Z';
            }
            else
            {
                password += (char)((ch-'a'-1+'A'));
            }
        }
        else if(isdigit(ch))
        {
            if('0'==ch)
            {
                password += '9';
            }
            else
            {
                password += char(ch-1);
            }
        }
        else
        {
            password += ch;
        }
    }
    return password;
}


int main()
{
    string aucPassword, result;
    while(cin>>aucPassword)
    {
        cout<<Encrypt(aucPassword)<<endl;
        cin>>result;
        cout<<unEncrypt(result)<<endl;
    }
}