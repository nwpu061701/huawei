#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int getGCD(int a, int b)
{
    int temp = 0;
    while(0!=a%b)
    {
        temp= b;
        b = a%b;
        a = temp;
    }
    return b;
}

//该方法通过率60% ，没有显示哪些不通过
//当a/b>=1/c时，将1/c输出，a/b-=1/c
void ConvertRealFractToEgpytFract(const string& str)
{
    stringstream ss(str);
    int num = 0, denum = 0;
    char ch;
    ss>>num>>ch>>denum;
    
    string result;
    int denumTemp = 2;
    while( 1<num)
    {
        int  gcd = getGCD(denum, denumTemp);
        int lcm = denum*denumTemp/gcd;
        
        int num1 = num*lcm/denum;
        int num2 = 1*lcm/denumTemp;
        
        if(num1>num2)
        {
            //printf("%d %d 1/%d %d/%d | ", gcd, lcm, denumTemp,num,denum);
            result += "1/"+to_string(denumTemp)+"+";
            num = num1-num2;
            denum = lcm;

        }
        ++denumTemp;
    }
    if(num)
    {
        result += "1/"+to_string(denum);
    }
    cout<<result<<endl;
}



/*
斐波那契提出的一种算法
∵ a/b是一个真分数
∴ b = a*q+r  0<r<a
  b/a = q+r/a
  b/a < (q+1)
  a/b > 1/(q+1)
  则a/b可以分解为1/(1+q) 和 a/b-1/(1+q) = (a-r)/[(q+1)b]=(a-b%a)/[(b/a+1)*b]
*/
void ConvertToEgpytFract(const string& str)
{
    stringstream ss(str);
    int a = 0, b = 0;
    char ch;
    ss>>a>>ch>>b;
    
    string result;
    while(b%a)
    {
        int q = b/a;
        int r = b%a;
        result += "1/"+to_string(q+1)+"+";
        a = a-r;
        b = (q+1)*b;
    }
    

     result +="1/"+to_string(b/a);
    cout<<result<<endl;

}

//ConvertToEgpytFract1是题目答案对应的解法
void ConvertToEgpytFract1(const string& str)
{
    stringstream ss(str);
    int a = 0, b = 0;
    char ch;
    ss>>a>>ch>>b;
    
    string result;
    /*最终要达到的目标是分解式中所有分数的分子都为1，若不是则需要进行处理，故分子是否为1作为循环条件。
                       不要改为b%a,否则虽然原理对但是分解式不是测试用例给出的那个分解结果*/
    while(a!=1)
    {
        if(b%(a-1)==0)/*当一个真分数分子不为1时，首先不是进行贪心算法，而是先判断能否进行一个偷巧的分解，即
                                   若b%(a-1)==0,则a/b=1/[b/(a-1)]+1/b*/
        {
            result += "1/"+to_string(b/(a-1))+"+";
            a=1;
            b=b;
        }
        else
        {
            int q = b/a;
            int r = b%a;
            result += "1/"+to_string(q+1)+"+";
            a = a-r;
            b = (q+1)*b;
        }

    }
    

     result +="1/"+to_string(b/a);
    cout<<result<<endl;

}

int main()
{
    string str;
    while(cin>>str)
    {
        ConvertRealFractToEgpytFract(str);
    }
}