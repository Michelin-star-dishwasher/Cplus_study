#include<iostream>
using namespace std;
#include<string>

class Calculate
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_num1 + m_num2;
		}
		else if (oper == "-")
		{
			return m_num1 - m_num2;
		}
		else if (oper == "*")
		{
			return m_num1 * m_num2;
		}

	}
	//如果想扩展新的功能，需求修改源码
	//在真是开发中提倡开闭原则
	//开闭原则:对扩展进行开放，对修改进行关闭

	int m_num1;
	int m_num2;
};
//利用多态实现计算器
//多态好处:
//1. 组织结构清晰
//2、 可读性强
//3、 对于前期和后期扩展以及维护性高

//实现计算器抽象类
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_num1;
	int m_num2;
};
//加法计算器类
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 + m_num2;
	}
};
//减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 - m_num2;
	}
};
//乘法计算器类
class MulCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 * m_num2;
	}
};
void test01()
{
	Calculate c;
	c.m_num1 = 10;
	c.m_num2 = 10;
	cout << c.m_num1 << "+" << c.m_num2 << " = " << c.getResult("+") << endl;
	cout << c.m_num1 << "-" << c.m_num2 << " = " << c.getResult("-") << endl;
	cout << c.m_num1 << "*" << c.m_num2 << " = " << c.getResult("*") << endl;
}
void test02()
{
	AbstractCalculator* abc = new AddCalculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
	//用完记得销毁
	delete abc;

	abc = new SubCalculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
	//用完记得销毁
	delete abc;

	abc = new MulCalculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
	//用完记得销毁
	delete abc;
}
int main() {
	test01();
	//test02();
	system("pause");
	return 0;
}