// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//
//������Щ���࣬���Խ��иĽ�

#include "stdafx.h"
#include "windows.h"
#include "time.h"
#include "iostream"
#include "iomanip"

#define arraysize 5
#define numbersize 5
using namespace std;

//��������������
class RadixSort
{
public:
	RadixSort();
	~RadixSort();
	void traversal();//����
	void iniNumber();//��ʼ������
	void iniQueue();//��ʼ�����У�����Ϊ��ά����
	void firstSort();//��һ������
	void secondSort();//�ڶ�������
	void thirdSort();//����������
	void compare(int input[]);//�Ƚ�������������������������
private:
	//ͨ����ά����Ľ���ģ�¶��е���ӳ���
	int **now;//��������Ķ�ά���飬Ҳ��������Ķ���
	int number[numbersize];//��Ų��������ݣ�Ҳ��Ϊһ������
};

RadixSort::RadixSort()
{
	iniQueue();
	iniNumber();
}

RadixSort::~RadixSort()
{
	delete now;
}

//������ά����
void RadixSort::traversal()
{
	for (size_t i = 0; i < numbersize; i++)
	{
			cout << setw(5) << number[i];
	}
	cout << endl;	
}

void RadixSort::iniNumber()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < numbersize; i++)
	{
		number[i] = rand() % 30 + 1;
	}
}

//����һ���ٶ��У�˼���Ƕ��е�˼��
void RadixSort::iniQueue()
{
	//��ʼ����ά������
	now = new int*[10];
	for (size_t i = 0; i < 10; i++)
	{
		//��ʼ����ά������
		now[i] = new int[arraysize];
		for (size_t j = 0; j < arraysize; j++)
		{
			now[i][j] = -1;
		}
	}

}

//����λ���Ĵ�С��������
void RadixSort::firstSort()
{
	int unit;
	size_t zero, one, two, three, four, five, six, seven, eight, nine;//��ֵ
	zero = one = two = three = four = five = six = seven = eight = nine = 0;
	for (size_t i = 0; i < numbersize; i++)
	{
		//��һ���������ʮȡ�����õ���λ��
		unit = number[i] % 10;//��������ĸ�λ�������е�һ������
		switch (unit)
		{
		case 0:
			now[0][zero] = number[i];
			zero++;
			break;
		case 1:
			now[1][one] = number[i];
			one++;
			break;
		case 2:
			now[2][two] = number[i];
			two++;
			break;
		case 3:
			now[3][three] = number[i];
			three++;
			break;
		case 4:
			now[4][four] = number[i];
			four++;
			break;
		case 5:
			now[5][five] = number[i];
			five++;
			break;
		case 6:
			now[6][six] = number[i];
			six++;
			break;
		case 7:
			now[7][seven] = number[i];
			seven++;
			break;
		case 8:
			now[8][eight] = number[i];
			eight++;
			break;
		case 9:
			now[9][nine] = number[i];
			nine++;
			break;
		default:
			cout << "û�з��ϵ�ֵ��֮ƥ��" << endl;
			break;
		}
	}
	int i = 0;
	//ÿ����һ�ξ����źõ�������ӣ�����Ϊԭ����number
	for (size_t j = 0; j < 10; j++)
	{
		for (size_t k = 0; k < arraysize || i < numbersize; k++)
		{
			//���now[j][k]������Ϊ-1˵���˺������û����ӹ�,��ô�����˴�ѭ��
			if (now[j][k] != -1)
			{
				number[i] = now[j][k];
				now[j][k] = -1;//ÿ�γ����������ֵΪ-1Ϊ��һ�γ����ж���׼��
				i++;
			}
			else {
				break;//���now[j][k]������Ϊ-1˵���˺������û����ӹ�,��ô�����˴�ѭ��
			}
		}
	}
}

//��ʮλ���Ĵ�С��������
void RadixSort::secondSort()
{
	int decade;
	size_t zero, one, two, three, four, five, six, seven, eight, nine;//��ֵ
	zero = one = two = three = four = five = six = seven = eight = nine = 0;
	for (size_t i = 0; i < numbersize; i++)
	{
		decade = (number[i] % 100)/10;//��������ĸ�λ�������еڶ�������
		switch (decade)
		{
		case 0:
			now[0][zero] = number[i];
			zero++;
			break;
		case 1:
			now[1][one] = number[i];
			one++;
			break;
		case 2:
			now[2][two] = number[i];
			two++;
			break;
		case 3:
			now[3][three] = number[i];
			three++;
			break;
		case 4:
			now[4][four] = number[i];
			four++;
			break;
		case 5:
			now[5][five] = number[i];
			five++;
			break;
		case 6:
			now[6][six] = number[i];
			six++;
			break;
		case 7:
			now[7][seven] = number[i];
			seven++;
			break;
		case 8:
			now[8][eight] = number[i];
			eight++;
			break;
		case 9:
			now[9][nine] = number[i];
			nine++;
			break;
		default:
			cout << "û�з��ϵ�ֵ��֮ƥ��" << endl;
			break;
		}
	}
	int i = 0;
	//ÿ����һ�ξ����źõ�������ӣ�����Ϊԭ����number
	for (size_t j = 0; j < 10; j++)
	{
		for (size_t k = 0; k < arraysize || i < numbersize; k++)
		{
			//���now[j][k]������Ϊ-1˵���˺������û����ӹ�,��ô�����˴�ѭ��
			if (now[j][k] != -1)
			{
				number[i] = now[j][k];
				now[j][k] = -1;//ÿ�γ����������ֵΪ-1Ϊ��һ�γ����ж���׼��
				i++;
			}
			else {
				break;//���now[j][k]������Ϊ-1˵���˺������û����ӹ�,��ô�����˴�ѭ��
			}
		}
	}
}

//����λ���Ĵ�С��������
void RadixSort::thirdSort()
{
	int hundred;
	size_t zero, one, two, three, four, five, six, seven, eight, nine;//��ֵ
	zero = one = two = three = four = five = six = seven = eight = nine = 0;
	for (size_t i = 0; i < numbersize; i++)
	{
		hundred = number[i] / 100;//��������ĸ�λ�������е���������
		switch (hundred)
		{
		case 0:
			now[0][zero] = number[i];
			zero++;
			break;
		case 1:
			now[1][one] = number[i];
			one++;
			break;
		case 2:
			now[2][two] = number[i];
			two++;
			break;
		case 3:
			now[3][three] = number[i];
			three++;
			break;
		case 4:
			now[4][four] = number[i];
			four++;
			break;
		case 5:
			now[5][five] = number[i];
			five++;
			break;
		case 6:
			now[6][six] = number[i];
			six++;
			break;
		case 7:
			now[7][seven] = number[i];
			seven++;
			break;
		case 8:
			now[8][eight] = number[i];
			eight++;
			break;
		case 9:
			now[9][nine] = number[i];
			nine++;
			break;
		default:
			cout << "û�з��ϵ�ֵ��֮ƥ��" << endl;
			break;
		}
	}
	int i = 0;
	//ÿ����һ�ξ����źõ�������ӣ�����Ϊԭ����number
	for ( size_t j = 0; j < 10; j++)
	{
		for (size_t k = 0; k < arraysize || i < numbersize; k++)
		{
			//���now[j][k]������Ϊ-1˵���˺������û����ӹ�,��ô�����˴�ѭ��
			if (now[j][k] != -1)
			{
				number[i] = now[j][k];
				now[j][k] = -1;//ÿ�γ����������ֵΪ-1Ϊ��һ�γ����ж���׼��
				i++;
			}
			else {
				break;//���now[j][k]������Ϊ-1˵���˺������û����ӹ�,��ô�����˴�ѭ��
			}
		}
	}
}

void RadixSort::compare(int input[])
{
	int count = 0;
	for (size_t i = 0; i < numbersize; i++)
	{
		for (size_t j = 0; j < numbersize; j++)
		{
			if (input[i] == number[j])
			{
				cout << setw(5) << input[i];
				count++;
			}
		}
	}
	cout << endl;
	cout <<"������"<<count<<"����"<< endl;
}

int main()
{
	system("title ʵ���-��������");
	system("color f0");
	RadixSort radix = RadixSort();
	int input[numbersize];
	cout << "������" << numbersize << "��30���ڵ���" << endl;
	for (size_t i = 0; i < numbersize; i++)
	{
		cin >> input[i];
	}
	cout << endl;
	cout << "û������ǰ" << endl;
	radix.traversal();
	cout << endl;
	cout << "��һ�������" << endl;
	radix.firstSort();
	radix.traversal();
	cout << endl;
	cout << "�ڶ��������" << endl;
	radix.secondSort();
	radix.traversal();
	cout << endl;
	cout << "�����������" << endl;
	radix.thirdSort();
	radix.traversal();
	cout << "�����"<<numbersize<<"���������������������ͬ����"<< endl;
	radix.compare(input);
	system("pause");
	return 0;
}