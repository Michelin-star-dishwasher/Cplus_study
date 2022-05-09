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
	//�������չ�µĹ��ܣ������޸�Դ��
	//�����ǿ������ᳫ����ԭ��
	//����ԭ��:����չ���п��ţ����޸Ľ��йر�

	int m_num1;
	int m_num2;
};
//���ö�̬ʵ�ּ�����
//��̬�ô�:
//1. ��֯�ṹ����
//2�� �ɶ���ǿ
//3�� ����ǰ�ںͺ�����չ�Լ�ά���Ը�

//ʵ�ּ�����������
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
//�ӷ���������
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 + m_num2;
	}
};
//������������
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 - m_num2;
	}
};
//�˷���������
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
	//����ǵ�����
	delete abc;

	abc = new SubCalculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
	//����ǵ�����
	delete abc;

	abc = new MulCalculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
	//����ǵ�����
	delete abc;
}
int main() {
	test01();
	//test02();
	system("pause");
	return 0;
}