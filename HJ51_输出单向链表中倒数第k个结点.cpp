#include<iostream>

using namespace std;

typedef struct ListNode{
    int m_nKey;
    ListNode* pNext;//前置类型生命生效吗？从编译情况来看，应该是可以的
}ListNode;

int main()
{
    int input;
    int num;
    while(cin>>num)
    {
        if(num<1)
        {
            cout<<endl;
            continue;
        }
        
        ListNode* pListHead = new ListNode[num];
        ListNode* pListTemp = pListHead;
        for(int i=0;i<num;++i)
        {
            cin>>pListTemp->m_nKey;
            ListNode* temp = pListTemp;
            ++pListTemp;
            temp->pNext = pListTemp;
        }
        
        if(num)
        {
            pListHead[num-1].pNext = 0;
        }
        
        int rid = 0;
        cin>>rid;
        int dest = num-rid;
        
        if(dest<0 || dest >=num)
        {
            delete[] pListHead;
            cout<<"0"<<endl;//倒数第0个结点比较扯，给出结果为0; 题意并未提示
            continue;
        }
        else
        {
            ListNode* pDest = pListHead;
            for(int i=0;i<dest;i++)
            {
                pDest=pDest->pNext;
            }
            
            cout<<pDest->m_nKey<<endl;
            delete[] pListHead;
        }
    }
}