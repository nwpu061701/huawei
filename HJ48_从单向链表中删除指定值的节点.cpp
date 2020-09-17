//20200830  22:41-23:33
#include<iostream>

using namespace std;

class node{
public:
    node(int i=0, node* p=NULL):value(i), next(p){}
    
    int value;
    node *next;
    
};


int main()
{
    int size=0;
    int first_value =0;
    while(cin>>size)
    {
        node memory[size];
        int memory_id = 0;
        node* first = &memory[memory_id];
        cin>>first_value;
        first->value=first_value;
        first->next = NULL;
        memory_id++;
        
        //cout<<"0  ";
        //构造
        int next_value = 0;
        int curr_value = 0;
        for(int i=1;i<size;i++)
        {
            cin>>next_value>>curr_value;
            //cout<<next_value<<"<-"<<curr_value<<"|";
            node * curr_node = first;
            while(NULL!=curr_node)
            {
                if(curr_node->value == curr_value)
                {
                    break;
                }
                else
                {
                    curr_node = curr_node->next;
                }
            }
            
            if(NULL!=curr_node)
            {
                node  new_node(next_value, curr_node->next);
                //cout<<"n"<<new_node.value;
                //cout<<"np"<<new_node.next<<" ";
                memory[memory_id]=new_node;
                
                //下面两句代码搞反了，导致关联next地址错误，浪费了十几分钟
                curr_node->next = &memory[memory_id];
                memory_id++;
               
                //cout<<"c"<<curr_node->value<<"n"<<next_value<<"   ";
            }
        }
        
        //删除
        int del_value = 0;
        cin>>del_value;
        node* pre = NULL, *cur = first;
        
        //cout<<"1  ";
        /*
        {
            node* debug = first;
            while(NULL != debug)
            {
                cout<<debug->value<<" ";
                debug = debug->next;
            }
            cout<<"|||";
        }*/
        
        
        
        while(NULL != cur)
        {
            if(cur->value==del_value)
            {
                if(NULL != pre)//如果要删除的不是第一个元素
                {
                    pre->next = cur->next;
                }
                else
                {
                    first= cur->next;
                }
                break;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        //cout<<"2  ";
        //输出
        cur = first;
        while(NULL != cur)
        {
            cout<<cur->value<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
}