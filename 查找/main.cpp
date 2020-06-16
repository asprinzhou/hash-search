//查找数据结构实验作业
#include <iostream>
#include <cstdlib>
using namespace std;
#define DELETE  0
#define EXIST	1
#define EMPTY	-1
typedef struct numt {
	int key = -99999;
}numt, * numtl;

numt a[100000]; /*{ -1,14,1,68,27,55,19,20,84,79,23,11,10,-1. - 1. - 1 }*/
int H(int a)
{
	return a % 13;
}

int search(numt a[], int key,int m) {//a是数据表，key是所需查找关键字，m记录a表的表长
	//在哈希表a中查找关键字为key的元素，若查找成功，返回哈希表的单元标号，否则返回-1 
	int H0 = H(key);     	                   			//根据哈希函数H（key）计算哈希地址
	int Hi;
	if (a[H0].key == EMPTY) return -1;		//若单元H0为空，则所查元素不存在
	else if (a[H0].key == key) return H0;		//若单元H0中元素的关键字为key，则查找成功
	else {
		for (int i = 1; i < m; ++i) {
			Hi = (H0 + i) % m;     		//按照线性探测法计算下一个哈希地址Hi
			if (a[Hi].key == EMPTY) return -1;	//若单元Hi为空，则所查元素不存在
			else if (a[Hi].key == key) return Hi; 	//若单元Hi中元素的关键字为key，则查找成功
		}
		return -1;
	}
}

int main()
{
	int num;
	cout << "请输入数据的个数：" << endl;
	cin >> num;
	int result;
	
	for (int i = 0; i < num; i++)
	{
		cin >> a[i].key;
	}
	int sub;
	cout << "请输入需要查找的数：" << endl;
	cin >> sub;
	result = search(a, sub, num);
	if (result != -1)
	{
		printf("在第%d个位置找到\n", result + 1);
	}
	else
	{
		printf("未找到\n");
	}
}