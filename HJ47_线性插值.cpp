//20200829 20:51
//这个题目的用例给的有迷惑性，到底一行是id、一行是值，还是多行（每行一个id、一个值）
//不过题目也说了给m个数据组，m是多个，由此推断是多行（每行一个id、一个值）。
//写的太长，又臭又长，还容易错。看人家简单写法，多简单，还能规避很多错误。
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdio>

using namespace std;

class info{
public:
    info(int i=0, int v=0):id(i),value(v){}
    int id;
    int value;
};

void cleanUpInfo(vector<info> & original)
{
    if(0==original.size())
    {
        cout<<endl;
        return;
    }
    
    //cout<<"1  ";
    //清除相同的编号
    auto pre = original.begin();
    for(auto itr=original.begin()+1; itr<original.end();)//轻易不要用后++，因为肯能并不是你想要的值
    {
        if(pre->id == itr->id)
        {
            itr = original.erase(itr);
        }
        else
        {
            pre = itr;
            ++itr;
        }
    }
    //cout<<"2  ";
    //插值
    vector<info> result;
    if(original.size()>1)
    {
        result.push_back(original[0]);
        for(auto itr=original.begin()+1;itr<original.end();itr++)
        {
            if(itr->id==result.rbegin()->id+1
              || itr->id<result.rbegin()->id)//题目表述的意思是，如果后跟一个小的编号，也不用插值
            {
                result.push_back(*itr);
            }
            else
            {
                int begin_id = result.rbegin()->id;
                int begin_value = result.rbegin()->value;
                int insert_num = itr->id - begin_id;
                int delta_value = itr->value - begin_value;
                
                //插值不要覆盖尾部端点，因为尾部端点的值可能和插出来的结果不同
                for(int i=1;i<insert_num;i++)
                {
                    int value = begin_value + delta_value/insert_num*i;//用迭代器要特别小心，每插入一个元素，rbegin都会变化
                    //int value = result.rbegin()->value + delta_value / insert_num*i;
                    info insert_info(begin_id+i, value);
                    result.push_back(insert_info);
                }
                
                result.push_back(*itr);
            }
        }
    }
    //cout<<"3  ";
    //输出结果是多行，每行一个di，一个值
    //cout<<result[0].id<<" ";
    for(std::size_t i=0;i<result.size();i++)
    {
        cout<<result[i].id<<" "<<result[i].value<<endl;
    }
    
    /*
    cout<<result[0].value;
    for(std::size_t i=1;i<result.size();i++)
    {
        cout<<" "<<result[i].value;
    }
    cout<<endl;
    */
}


int main()
{
    int m=0;
    int n=0;//n没用；出题人也会出bug
    
    while( EOF != scanf("%d %d",&m, &n))
    {
        vector<info> original;
        int id=0, value =0;
        for(int i=0;i<m;i++)
        {
            cin >> id >> value;
            //scanf("%d %d",&id, &value);
            //cout<<id<<" "<<value<<"|";
            info temp(id, value);
            original.push_back(temp);
        }

        cleanUpInfo(original);
        
    }
    
}