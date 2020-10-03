#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
//这种解法太长了，很多答案不足80行
//从部分答案来看，可以直接假定输入格式固定的
//

/*
*************************
"划重点：
* 返回值：
0：IP1与IP2属于同一子网络；
1：IP地址或子网掩码格式非法；
2：IP1与IP2不属于同一子网络
-
另外你们真的不知道按位与操作吗...直接scanf读int然后按位与判结果，这题10分钟水过啊。"

惭愧.....

************************
sacnf中，如果格式与变量类型不匹配会怎么样呢？
失效的格式后面，不会再向变量内读入信息，变量会保持原来的值
例如，
unsignde mask[4] = {255, 255, 255, 255};
scanf("%u.%u.%u.%u", &mask);
cout<<mask[0]<<" "<<mask[1]<<" "<<mask[2]<<" "<<mask[3]<<" ";

如果输入10..12.255.239, 程序运行后的输出是10 255 255 255

************************
判断ip地址，可以直接用网络库
#include <arpa/inet.h>
int inet_pton(int family, const char *strptr, void *addrptr);
            返回：若成功则为1,若输入不是有效的表达格式则为0,若出错则为-1
HJ18 "识别有效的IP..." TOP1解题中有使用
            
************************
如何判断一个掩码地址是不是满足前面连续是1，然后全是0？
将掩码地址转换为32位无符号整型，假设这个数为b。如果此时b为0，则为非法掩码
将b按位取反后+1。如果此时b为1，则b原来是二进制全1，非法掩码；或者直接判断b是否为-1（补码为0xFFFFFFFF）
如果b和b-1做按位或运算后为0xFFFFFFFF，则说明是合法掩码，否则为非法掩码
原理是，只筛选出最后一个1和0的交界，然后过滤
b的类型用unsigned int(32bit)，不要用unsigned long(64bit)、std::size_t(64bit)、

unsigned 也是32bit
unsigned char 8bit
unsigned short 16bit


**************************
字符串转整形的方法：
①stringstream
②int = std::stoi(string)
 unsigned long  = std::stoul(string)
*/

void cut(string s, vector<string> & vstr)
{
    stringstream ss(s);
    string temp;
    vstr.clear();
    while(getline(ss, temp, '.'))
    {
        vstr.push_back(temp);
    }
}

bool isdigital(const string & str)
{
    //未看空串
    bool flag = true;
    for(auto ch:str)
    {
        if(ch<'0' || ch>'9')
        {
            flag=false;
            break;
        }
    }
    return true;
}

bool checkCommon(const string & str)
{
    vector<string> cutted;
    cut(str, cutted);
    if(cutted.size()>4 || 0==cutted.size())
    {
        //printf("E");
        return false;
    }
    else
    {
        for(auto str:cutted)
        {
            if(!isdigital(str))
            {
                //printf("R");
                return false;
            }
        }
        
        for(auto str: cutted)
        {
            int temp = std::stoi(str);
            if(temp<0 || temp>255)
            {
                //printf("T");
                return false;
            }
        }
        
        return true;
    }
}

bool checkMask(const string & mask)
{
    if(!checkCommon(mask))
    {
        //printf("W");
        return false;
    }
    else
    {
        vector<string> cutted;
        cut(mask, cutted);
        bool exit0 = false;
        for(auto s:cutted)
        {
            int temp = std::stoi(s);
            //好像有一种算法，专门查看是否存在相邻的bit是否一致
            for(int i=7;i>=0;i--)
            {
                if(temp>>i & 0x0001)
                {
                    if(exit0==false)
                    {
                        //nothing to do
                    }
                    else
                    {
                        //printf("Q");
                        return false;
                    }
                }
                else
                {
                    exit0 = true;
                }
            }
        }
        
        return true;
        
    }
}

bool checkMaskAlternative(const string & mask)
{
    if(!checkCommon(mask))
    {
        //printf("W");
        return false;
    }
    else
    {
        vector<string> cutted;
        cut(mask, cutted);
        unsigned int bits = 0;
        for(auto s:cutted)
        {
            bits = bits<<8;
            std::size_t temp = std::stoul(s);
             //printf("%lXZ",temp);
            bits +=temp;
        }
        //printf("%lXY",bits);
        bits = ~bits +1;
        
        if(bits&(bits-1))
        {
            //printf("%lXV |%d |%d |%d |",bits, sizeof(std::size_t), sizeof(unsigned int), sizeof(unsigned long));
            return false;
        }
        else
        {
            return true;
        }
        
        
    }
}

bool checkIp(const string & ip)
{
    if(checkCommon(ip))
    {
        return true;
    }
    else
    {
        //printf("F");
        return false;
    }
}

long long getSubNetIp(string& mask, string& ip)
{
    vector<string> vmask;
    vector<string> vip;
    
    cut(mask, vmask);
    cut(ip, vip);
    
    long long imask=0, iip=0;
    
    for(auto s:vmask)
    {
        imask *= 256;
        imask +=std::stoi(s);
    }
    
    for(auto s:vip)
    {
        iip *= 256;
        iip +=std::stoi(s);
    }
    
    return iip & imask;
}



void checkNetSegment(string &mask, string &ip1, string &ip2)
{
    if(!checkMaskAlternative(mask) || !checkIp(ip1) || !checkIp(ip2))
    {
        cout<<1<<endl;
        return;
    }
    else
    {
        long subNet1 = getSubNetIp(mask, ip1);
        long subNet2 = getSubNetIp(mask, ip2);
        
        if(subNet1 == subNet2)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<2<<endl;
        }
        return;
    }
}


int main()
{
    string mask, ip1, ip2;
    while(cin>>mask)
    {
        cin>>ip1>>ip2;
        checkNetSegment(mask, ip1, ip2);
    }
}