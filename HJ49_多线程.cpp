#include<thread>
#include<mutex>
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
/*
本地编译并通过，但是牛客上报编译错误“undefined reference to `pthread_create'”
有哪位同学知道需要怎么处理吗？
*/
char g_write[1032];
int total = INT_MAX;//total表示总字符个数
int current = 0;
mutex mtx;
 
void print(char ch)
{
    mtx.lock();
    if (total != INT_MAX)
    {
        if (current<total)
        {
            if (current % 4 == ch - 'A')
            {
                g_write[current] = ch;
                current++;
            }
        }
    }
    mtx.unlock();
}
 
int writeFinish()
{
    bool finish = false;
    mtx.lock();
    finish = (current == total) ? true : false;
    mtx.unlock();
    return finish;
}
 
unsigned int _ThreadFunc1(int count)
{
    mtx.lock();
    total = (count)* 4;
    current = 0;
    mtx.unlock();
 
    while (!writeFinish())
    {
        print('A');
    }
    return 0;
}
 
unsigned int _ThreadFunc2()
{
    while (!writeFinish())
    {
        print('B');
    }
    return 0;
}
 
unsigned int _ThreadFunc3()
{
    while (!writeFinish())
    {
        print('C');
    }
    return 0;
}
 
unsigned int _ThreadFunc4()
{
    while (!writeFinish())
    {
        print('D');
    }
    return 0;
}
 
int main()
{
    int num;
    while (cin >> num)
    {
        total = INT_MAX;//total表示总字符个数
        current = 0;
        memset(g_write,0, 1032);
        thread thread1(_ThreadFunc1, num);
        thread thread2(_ThreadFunc2);
        thread thread3(_ThreadFunc3);
        thread thread4(_ThreadFunc4);
 
        thread1.join();
        thread2.join();
        thread3.join();
        thread4.join();
 
        for (int i = 0; i<num; i++)
        {
            for (int j = 0; j<4; j++)
            {
                cout << g_write[i*4 + j];
            }
 
        }
        cout << endl;
    }
}