//�������ݽṹʵ����ҵ
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

int search(numt a[], int key,int m) {//a�����ݱ�key��������ҹؼ��֣�m��¼a��ı�
	//�ڹ�ϣ��a�в��ҹؼ���Ϊkey��Ԫ�أ������ҳɹ������ع�ϣ��ĵ�Ԫ��ţ����򷵻�-1 
	int H0 = H(key);     	                   			//���ݹ�ϣ����H��key�������ϣ��ַ
	int Hi;
	if (a[H0].key == EMPTY) return -1;		//����ԪH0Ϊ�գ�������Ԫ�ز�����
	else if (a[H0].key == key) return H0;		//����ԪH0��Ԫ�صĹؼ���Ϊkey������ҳɹ�
	else {
		for (int i = 1; i < m; ++i) {
			Hi = (H0 + i) % m;     		//��������̽�ⷨ������һ����ϣ��ַHi
			if (a[Hi].key == EMPTY) return -1;	//����ԪHiΪ�գ�������Ԫ�ز�����
			else if (a[Hi].key == key) return Hi; 	//����ԪHi��Ԫ�صĹؼ���Ϊkey������ҳɹ�
		}
		return -1;
	}
}

int main()
{
	int num;
	cout << "���������ݵĸ�����" << endl;
	cin >> num;
	int result;
	
	for (int i = 0; i < num; i++)
	{
		cin >> a[i].key;
	}
	int sub;
	cout << "��������Ҫ���ҵ�����" << endl;
	cin >> sub;
	result = search(a, sub, num);
	if (result != -1)
	{
		printf("�ڵ�%d��λ���ҵ�\n", result + 1);
	}
	else
	{
		printf("δ�ҵ�\n");
	}
}