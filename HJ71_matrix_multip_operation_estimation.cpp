#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

//HJ71 矩阵乘法计算量估计
typedef struct{
	int row;
	int colonm;
}array;

//增加乘法符号
string addMultiSignal(const string & str)
{
	string result;
	for(auto ch:str)
	{
		if(ch>='A'&&ch<='Z')
		{
			result +=ch;
			result +='*';
		}
		else
		{
			result +=ch;
		}
	}
	
	auto lastMultiSignal = result.find_last_of('*');
	result.erase(lastMultiSignal,1);
	return result;
}


//A*(B*C)
string converToPostfix(const string & str)
{
    //cout<<"**"<<str<<endl;
    string strTemp = addMultiSignal(str);
	//cout<<"&&"<<strTemp<<endl;
	stack<char> charStack;
	string postFix;
	for(int i=0;i<strTemp.length();i++)
	{
		if('('==strTemp[i])
		{
			charStack.push(strTemp[i]);
		}
		else if(')'==strTemp[i])
		{
			while(charStack.size() && '('!=charStack.top())
			{
					postFix+=charStack.top();
					charStack.pop();
			}
			if(charStack.size() && '('==charStack.top())
			{
				charStack.pop();
			}
		}
		else if(strTemp[i]>='A'&&strTemp[i]<='Z')
		{
			postFix+=strTemp[i];
		}
		else
		{
			if(charStack.size())
			{
				//比较优先级，新的乘法优先级与charStack中乘法的优先级都一样，
				while(charStack.size() && '*'==charStack.top() && '*'==strTemp[i])
				{
					postFix+=charStack.top();
					charStack.pop();
				}
				charStack.push(strTemp[i]);
			}
			else
			{
				charStack.push(strTemp[i]);
			}
		}
	}
	
	while(charStack.size())
	{
		postFix+=charStack.top();
		charStack.pop();
	}
    
	return postFix;
}

int calcMultipleNum(const vector<array> &arrays, const string & str)
{
	string postStr = converToPostfix(str);
	stack<array> arrayStack;
	int multiNum=0;
	//cout<<"*&*"<<postStr<<" && "<<postStr.length()<<endl;
	for(int i=0; i<postStr.length();i++)
	{
        //cout<<i;
		if(postStr[i]>='A' && postStr[i]<='Z')
		{
			arrayStack.push(arrays[postStr[i]-'A']);
		}
		else
		{
            //cout<<"size = "<<arrayStack.size()<<endl;
			array right= arrayStack.top();
			arrayStack.pop();
			array left = arrayStack.top();
			arrayStack.pop();

			multiNum += left.row*left.colonm*right.colonm;
            
            //left保存乘法完成后，结果矩阵的信息
            left.colonm = right.colonm;
            arrayStack.push(left);
		}
	}

	cout<<multiNum<<endl;
	return multiNum;
}

int main()
{
	int num;
	string express;
	vector<array> arrays;
	while(cin>>num)
	{
		arrays.clear();
		array temp;
		for(int i=0;i<num;i++)
		{
			cin>>temp.row>>temp.colonm;
			arrays.push_back(temp);
		}
		cin>>express;
		calcMultipleNum(arrays, express);
	}
}