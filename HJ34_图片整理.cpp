#include<stdio.h>
#include<cstring>

//方法：桶排序

int num[128]={0};

char input[1025];

int main()
{
    char temp ;
    int index = 0;
    //scanf格式为scanf(format, 变量指针/数组名)
    //通过判断scanf的返回值是否是EOF来判断是否与结束
    //可以用gets(input),遇到换行符结束，从缓冲区中取出该换行符并丢弃，并用‘\0’替代换行符放到字符串结尾
    //gets读取成功，则返回读取的字符串，否则返回空指针NULL/0（这一点可以帮助我们用于循环）
    //scanf以Space(' ')、Enter('\n')、Tab('\t')结束一次输入，但是读取时忽略第一个非空白字符前的所有空白字符（这一点可以帮助我们用于循环）
    //scanf读取后，空白字符会留在缓冲区中
    while(scanf("%s",input)!=EOF)//
    {
        int length = strlen(input);
        for(int i=0;i<length;i++)
        {
            temp = input[i];
            num[temp]++;
        }
        
        for(int j='0';j<='z';j++)
        {
           while(num[j])
           {
                printf("%c",(char)j);
                --num[j];
            }
        }
        printf("\n");
        memset(num, 0, sizeof(int)*128);
        memset(input, 0, 1025);
    }
}