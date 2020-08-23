/*
HJ39_判断两个IP是否属于同一个子网
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
将b按位取反后+1。如果此时b为1，则b原来是二进制全1，非法掩码
如果b和b-1做按位与运算后为0，则说明是合法掩码，否则为非法掩码
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