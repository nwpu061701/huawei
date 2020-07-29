#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class student{
public:
    string name;
    int score;
};

int compareGreater(const student& stu1, const student& stu2)
{
    if(stu1.score>stu2.score)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int compareSmaller(const student& stu1, const student& stu2)
{
    if(stu1.score<stu2.score)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int num = 0;
    int direct = 0;
    while(cin>>num)
    {
        vector<student> students;
        cin>>direct;
        for(int i=0;i<num;i++)
        {
            student stu;
            cin>>stu.name>>stu.score;
            students.push_back(stu);
        }
        
        if(0==direct)
        {
            stable_sort(students.begin(),students.end(), compareGreater);
        }
        else
        {
            stable_sort(students.begin(),students.end(), compareSmaller);
        }
        
        for(auto & stu:students)
        {
            cout<<stu.name<<" "<<stu.score<<endl;
        }
    }
}