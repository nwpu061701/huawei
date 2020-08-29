#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>

using namespace std;

//本次深度遍历，提示超时。如果超过60个元素进行排列，那将会是一个很大的数量级！！

void search(int depth, int currentWeight, const vector<int> &famas,
           map<int, int>& weights, bool* flags)
{
    for(unsigned int i=0;i<famas.size();i++)
    {
        if(flags[i]==false)
        {
            flags[i]=true;
            currentWeight += famas[i];
            weights[currentWeight] = 1;
            //weights.push_back(make_pair<int, int>(currentWeight,1));
            search(depth+1, currentWeight, famas, weights, flags);
            currentWeight -=famas[i];
            //flags[i]=false;
        }
    }
}

void fama(int n, int* weight, int* nums)
{
    vector<int> famas;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<nums[i];j++)
        {
            famas.push_back(weight[i]);
        }
    }
    
    map<int, int> weightMap;//重量组合结果
    
    bool flags[famas.size()];
    memset(flags, 0, sizeof(flags));
    
    
    std::sort(famas.begin(), famas.end());
    /*
    for(auto f:famas)
    {
        cout<<f<<" | ";
    }
    cout<<"  ||||  ";
    */
    //do
    //{
        for(int i=0;i<famas.size(); i++)
        {
            //weightMap.push(make_pair<int, int>(famas[i], 1));
            weightMap[famas[i]]=1;
            flags[i]=true;
            search(0, famas[i], famas, weightMap, flags);
            flags[i]=false;
        }
    //}while(next_permutation(famas.begin(), famas.end()));
    
    cout<<weightMap.size()+1<<endl;
    /*
    for(auto w:weightMap)
    {
        cout<<w.first<<" | ";
    }*/
    
}


int main()
{
    int num=0;
    while(cin>>num)
    {
        int weight[num], nums[num];
        for(int i=0;i<num;i++)
        {
            cin>>weight[i];
        }
        for(int i=0;i<num;i++)
        {
            cin>>nums[i];
        }
        
        fama(num, weight, nums);
        
    }
}