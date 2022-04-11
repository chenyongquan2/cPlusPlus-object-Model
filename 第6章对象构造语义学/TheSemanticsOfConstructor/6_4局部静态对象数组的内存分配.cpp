#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>

using namespace std;


//二：6_4局部静态对象数组的内存分配

class A
{
public:
	A()
	{
		//cout << "A::A()" << endl;
	}
	~A()
	{
		//cout << "A::~A()" << endl;
	}
	int m_i;
};

void myfunc()
{	
	static A s_aobj[5];//数组内存应该是连续的,当数组比较小时
	static A s_aobj[1000'0000]; //数组内存应该是连续的,当数组过于大时
	//--数组没有使用，所以没有直接分配内存(写个死循环 查看任务管理器内存)，当使用的时候，才分配内存
	//for (int i = 0; i < 10000000; i++) //让编译器的分配内存优化能力失效
	//{
	//	s_aobj[i].m_i = i;
	//}
	printf("s_aobj数组的首地址是%p\n", s_aobj);

}

void func()
{
	myfunc();
	myfunc();
}


int main()
{
	func();

	while (1)
	{

	}
	system("pause");

	return 1;
}



