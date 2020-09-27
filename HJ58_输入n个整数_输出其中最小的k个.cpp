#include<iostream>
#include<algorithm>

using namespace std;
//用最大堆/最小堆排序试试
void MaxHeapSort(int num, int out_num)
{
    if(num<out_num || out_num<=0)
    {
        cout<<endl;
        return;
    }
    int heap[out_num];
    for(int i=0;i<out_num;++i)
    {
        cin>>heap[i];
    }
    make_heap(heap, heap+out_num);
    
    int temp;
    for(int i=out_num;i<num;++i)
    {
        cin>>temp;
        if(heap[0]>temp)
        {
            pop_heap(heap, heap+out_num);//将最大值移动到heap末尾
            heap[out_num-1]=temp;
            push_heap(heap, heap+out_num);//将末尾的元素纳入到heap中
        }
    }
    
    sort_heap(heap, heap+out_num);//按照heap的cmp对heap排序，排序后，会失去heap的属性
    
    cout<<heap[0];
    for(int i=1;i<out_num;++i)
    {
        cout<<" "<<heap[i];
    }
    cout<<endl;
}

int main()
{
    int num = 0, out_num = 0;
    while(cin>>num>>out_num)
    {
        MaxHeapSort(num, out_num);
    }
}

//常规方法
/*
int main()
{
    int num = 0, out_num = 0;
    while(cin>>num)
    {
        cin>>out_num;
        int array[num];
        for(int i=0;i<num;i++)
        {
            cin>>array[i];
        }
        
        std::sort(array, array+num);
        
        if(out_num>0 && out_num<=num)
        {
            cout<<array[0];
            for(int i=1; i<out_num; ++i)
            {
                cout<<" "<<array[i];
            }
            cout<<endl;
        }
        else
        {
            cout<<endl;
        }
    }
}
*/