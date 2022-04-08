#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;
typedef string mytype;

class A
{
public:
	//typedef int mytype;//放到类的最前面
	void myFunction(mytype temvalue);//这里mytype是string类型，因为先看到上面的typedef string mytype;

public:
	typedef int mytype;
	mytype m_value;//先定义类型，这里m_value是int类型
};

void A::myFunction(::mytype temvalue)
//void A::myFunction(mytype temvalue) 这里认为是int类型。
{
	//m_value = temvalue;//error 将string类型转换为int类型0
}


int main(void)
{
	system("pause");
	return 0;
}


/*
* (1)结论：对于成员函数参数：，是在第一次遇见整个mytype类型的时候被决定的。
* 所以第一次遇见mytpye的时候，编译器看到了typedef string mytype;，还没看到类中的typedef int mytype;
* 就把参数当作string类型。
* 结论：为了在类中尽早看到mytype类型，类型定义语句一定要定义到类最开始的位置
* 那后边的成员函数第一次遇到这个类型mytype的时候，它就本着最近碰到的类型的原则来应用最近碰到的类型。
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/
