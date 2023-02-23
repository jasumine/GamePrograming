#include <iostream>
#include <iomanip>

using namespace std;

/*
 1����Ʈ(byte) = 8 ��Ʈ(bit)
 1024����Ʈ = 1kb // 2^10
 1024kb = 1mb
 1024mb = 1gb
 1024gb = 1tb

 char	1 ����Ʈ. ( 0 0 0 0 , 0 0 0 0) 8��Ʈ = 2^8= 256 ǥ�� , -128 127 ǥ������
 short	2 ����Ʈ. ( 0 0 0 0, 0 0 0 0, 0 0 0 0, 0 0 0 0) 16��Ʈ = 2^16 , -32768~32767 ǥ������
 int	4 ����Ʈ . ( ~) 32��Ʈ = 2^32 = -21��~21��.
 __int64(��ȣ) == long long / 8 ����Ʈ = 36��Ʈ, 2^64 ū ����
 ============(�����)
 unsigned char 0~256
 unsigned short // 0~65535
 unsigned int // 0~42��
 unsigned __int64 == unsigned long long // ū��

 32��Ʈ��ǻ��(2^32) 16��Ʈ��ǻ��(2^16) ���̰�ũ��!

 ============(�� ����) 
 ��ǻ�� �ּ��� ������ 1byte���� 1byte���� ������.
 bool isDead = true;
 bool isPlayer = false;

 =============(�Ҽ���)
 float moveSpeed = 1.0f;  // 4����Ʈ
 double moveSpeed2 = 1.4; // 8����Ʈ

 �ε��Ҽ��� ������� ��� 
 3.141592 = 0.3141592 * 10 = 0.03141592 * 100
 ��ȿ���� 3141592 (���� 1) = 32��Ʈ.
 float ��ȣ(1) ���� (8) ��ȿ����(23) = 32��Ʈ = 4����Ʈ
 double ��ȣ(1) ����(11) ��ȿ����(52) = 64��Ʈ = 8����Ʈ
 �ٻ簪�� ǥ���� ���ټ� �ְ�, ��Ȯ�ϰ� ǥ���� ���� ����.
 ***** �Ҽ��� �ε�ȣ ǥ���� >=, �̳� <= �� �̿��ؼ� ����

 */
char a;
int main()
{
	unsigned short ub;

	short b;
	int c;
	__int64 d;
	long long e;
	bool isPlayer = false;

	ub = 0;
	ub = ub - 1;

	cout << ub << endl;

	b = 32767;
	b = b + 1; // �����÷ο� ���� �� �˾Ƶα� https://m.blog.naver.com/noksek0615/221745224309
	// 0 1 1 1 , 1 1 1 1 �� 1�� ���ϸ�
	// 1 0 0 0 , 0 0 0  �� �Ǽ� -32768�� ���´�.
	cout << b << endl;

	double dd(1.0f);
	double ddd(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

	cout << setprecision(18) << endl; // �ε� �Ҽ��� ���� ��ü �ڸ����� �����մϴ�. (��Ȯ�� ���� ǥ��)
	cout << dd <<" "<< &dd<< endl;
	cout << ddd << " "<< &ddd<<endl;


	if (dd == ddd)
		cout << "same" << endl;
	else cout << "not same, dd : " << dd << ", ddd : "<< ddd << endl;

	b = a++; // b=a�� �ְ� a�� 1 ����
	b = ++a; // a�� 1 ���� ��Ű�� b=a 

	cout << sizeof(d) << endl;
	cout << sizeof(c) << endl;
	cout << sizeof(isPlayer) << endl;

	char ch = 35;
	char ch2 = 'a';
	char ch3 = 'a' + 1; // �ƽ�Ű�ڵ嶧���� ����
	// �����ڵ� -  �߱���, ����, �ѱ���

	// escape sequence �̽������� ������ -  �� Ȱ���غ���!
	cout << ch << "\n" << endl; // ���� ����
	cout << "abc" << "\t" << "def" << endl; // �ٸ���
	cout << "ab" << "\t" << "cdef" << endl;
	cout << ch3 << "\a" << endl; 


	// utf-8  ���ĺ� 1����Ʈ, ���� 2����Ʈ, �ѱ� ���� 3����Ʈ (����θ� ����� ��� �̰ɷ� �����)
	// utf-16 ��κ� 2����Ʈ, �ѱ۵� 2����Ʈ( �ѱ���� ����ҰŸ� �̰ɷ� �����)

	// ���ڿ��� ���ڿ����� \0 �� ����
	char str[] = { 'h','e','l','l','o', '\0'};
	char str2[] = "hello";
	cout << str << endl;
	cout << str2 << endl;
}