// 基数排序.cpp : 定义控制台应用程序的入口点。
//
//代码有些冗余，可以进行改进

#include "stdafx.h"
#include "windows.h"
#include "time.h"
#include "iostream"
#include "iomanip"

#define arraysize 5
#define numbersize 5
using namespace std;

//声明基数排序类
class RadixSort
{
public:
	RadixSort();
	~RadixSort();
	void traversal();//遍历
	void iniNumber();//初始化数据
	void iniQueue();//初始化队列，队列为二维数组
	void firstSort();//第一轮排序
	void secondSort();//第二轮排序
	void thirdSort();//第三轮排序
	void compare(int input[]);//比较输入的数据与随机产生的数据
private:
	//通过二维数组的交换模仿队列的入队出队
	int **now;//用来排序的二维数组，也就是这里的队列
	int number[numbersize];//存放产生的数据，也作为一个队列
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

//遍历二维数组
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

//这是一个假队列，思想是队列的思想
void RadixSort::iniQueue()
{
	//初始化二维数组行
	now = new int*[10];
	for (size_t i = 0; i < 10; i++)
	{
		//初始化二维数组列
		now[i] = new int[arraysize];
		for (size_t j = 0; j < arraysize; j++)
		{
			now[i][j] = -1;
		}
	}

}

//按个位数的大小进行排序
void RadixSort::firstSort()
{
	int unit;
	size_t zero, one, two, three, four, five, six, seven, eight, nine;//行值
	zero = one = two = three = four = five = six = seven = eight = nine = 0;
	for (size_t i = 0; i < numbersize; i++)
	{
		//第一次排序除以十取余数得到个位数
		unit = number[i] % 10;//求这个数的各位数，进行第一轮排序
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
			cout << "没有符合的值与之匹配" << endl;
			break;
		}
	}
	int i = 0;
	//每排完一次就让排好的数据入队，队列为原来的number
	for (size_t j = 0; j < 10; j++)
	{
		for (size_t k = 0; k < arraysize || i < numbersize; k++)
		{
			//如果now[j][k]的数据为-1说明此后的数据没有入队过,那么跳出此处循环
			if (now[j][k] != -1)
			{
				number[i] = now[j][k];
				now[j][k] = -1;//每次出队让数组的值为-1为下一次出队判断做准备
				i++;
			}
			else {
				break;//如果now[j][k]的数据为-1说明此后的数据没有入队过,那么跳出此处循环
			}
		}
	}
}

//按十位数的大小进行排序
void RadixSort::secondSort()
{
	int decade;
	size_t zero, one, two, three, four, five, six, seven, eight, nine;//行值
	zero = one = two = three = four = five = six = seven = eight = nine = 0;
	for (size_t i = 0; i < numbersize; i++)
	{
		decade = (number[i] % 100)/10;//求这个数的各位数，进行第二轮排序
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
			cout << "没有符合的值与之匹配" << endl;
			break;
		}
	}
	int i = 0;
	//每排完一次就让排好的数据入队，队列为原来的number
	for (size_t j = 0; j < 10; j++)
	{
		for (size_t k = 0; k < arraysize || i < numbersize; k++)
		{
			//如果now[j][k]的数据为-1说明此后的数据没有入队过,那么跳出此处循环
			if (now[j][k] != -1)
			{
				number[i] = now[j][k];
				now[j][k] = -1;//每次出队让数组的值为-1为下一次出队判断做准备
				i++;
			}
			else {
				break;//如果now[j][k]的数据为-1说明此后的数据没有入队过,那么跳出此处循环
			}
		}
	}
}

//按百位数的大小进行排序
void RadixSort::thirdSort()
{
	int hundred;
	size_t zero, one, two, three, four, five, six, seven, eight, nine;//行值
	zero = one = two = three = four = five = six = seven = eight = nine = 0;
	for (size_t i = 0; i < numbersize; i++)
	{
		hundred = number[i] / 100;//求这个数的各位数，进行第三轮排序
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
			cout << "没有符合的值与之匹配" << endl;
			break;
		}
	}
	int i = 0;
	//每排完一次就让排好的数据入队，队列为原来的number
	for ( size_t j = 0; j < 10; j++)
	{
		for (size_t k = 0; k < arraysize || i < numbersize; k++)
		{
			//如果now[j][k]的数据为-1说明此后的数据没有入队过,那么跳出此处循环
			if (now[j][k] != -1)
			{
				number[i] = now[j][k];
				now[j][k] = -1;//每次出队让数组的值为-1为下一次出队判断做准备
				i++;
			}
			else {
				break;//如果now[j][k]的数据为-1说明此后的数据没有入队过,那么跳出此处循环
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
	cout <<"猜中了"<<count<<"个数"<< endl;
}

int main()
{
	system("title 实验八-基数排序");
	system("color f0");
	RadixSort radix = RadixSort();
	int input[numbersize];
	cout << "请输入" << numbersize << "个30以内的数" << endl;
	for (size_t i = 0; i < numbersize; i++)
	{
		cin >> input[i];
	}
	cout << endl;
	cout << "没有排序前" << endl;
	radix.traversal();
	cout << endl;
	cout << "第一轮排序后" << endl;
	radix.firstSort();
	radix.traversal();
	cout << endl;
	cout << "第二轮排序后" << endl;
	radix.secondSort();
	radix.traversal();
	cout << endl;
	cout << "第三轮排序后" << endl;
	radix.thirdSort();
	radix.traversal();
	cout << "输入的"<<numbersize<<"个数中与随机产生的数相同的是"<< endl;
	radix.compare(input);
	system("pause");
	return 0;
}