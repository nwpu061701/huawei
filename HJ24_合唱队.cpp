//20201008 21:36-22:47(未作出，困惑于如何实现中间最高，未想到反向做一次最大上升子串)
//先求一次左侧最长递增字串，再求一次右侧最长递减字串，然后相加

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

vector<int> getLongestRising(const vector<int> &heights)
{
    vector<int> dpRising(heights.size(), 1);
    
    for(int i=0;i<heights.size();++i)
    {
        for(int j=0;j<i;++j)
        {
            if(heights[j]<heights[i] && dpRising[i]<dpRising[j]+1)
            {
                dpRising[i]=dpRising[j]+1;
            }
        }
    }
    return  dpRising;
}


void analysis(vector<int> heights)
{
    
    vector<int> dpRising = getLongestRising(heights);//获取每个位置左侧的最大上升字串
    reverse(heights.begin(), heights.end());
    vector<int> dpFalling = getLongestRising(heights);//获取反向每个位置左侧的最大上升子串
    reverse(dpFalling.begin(), dpFalling.end());//反向后，为正向每个位置右侧的最大下降子串
    
    vector<int> chorus(dpRising.begin(), dpRising.end());
    int maxChorus = 0;
    for(int i=0;i<chorus.size();++i)
    {
        chorus[i]+=dpFalling[i]-1;//之所以减1，是因为正向左侧最大上升和正向右侧最大下降，把自己算了两遍
        if(chorus[i]>maxChorus)
        {
            maxChorus = chorus[i];
        }
    }
    
    cout<<heights.size()-maxChorus<<endl;
    /*
    for(int i=0;i<heights.size();++i)
    {
        for(int j=0;j<i;++j)
        {
            if(heights[j]>heights[i])//需要下降
            {
                int tempDown1 = dpRising[j]+1;
                int tempDown2 = dpFalling[j]+1;
                int tempDown = max(tempDown1, tempDown2);
                
                if(tempDown>dpFalling[i])
                {
                    dpFalling[i] = tempDown;
                }
            }
            else if(heights[j]<heights[i])
            {
                int tempDown1 = dpRising[j]+1;
                int tempDown2 = dpFalling[j]+1;
                
                
            }
        }
    }
    */
}

int main()
{
    int height=0;
    int num=0;
    while(cin>>num)
    {
        vector<int> heights;
        for(int i=0;i<num;++i)
        {
            cin>>height;
            heights.push_back(height);
        }
        
        analysis(heights);
    }
}