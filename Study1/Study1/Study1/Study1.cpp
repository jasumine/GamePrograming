#include <iostream>
#include <iomanip>

using namespace std;

/*
 1바이트(byte) = 8 비트(bit)
 1024바이트 = 1kb // 2^10
 1024kb = 1mb
 1024mb = 1gb
 1024gb = 1tb

 char	1 바이트. ( 0 0 0 0 , 0 0 0 0) 8비트 = 2^8= 256 표현 , -128 127 표현가능
 short	2 바이트. ( 0 0 0 0, 0 0 0 0, 0 0 0 0, 0 0 0 0) 16비트 = 2^16 , -32768~32767 표현가능
 int	4 바이트 . ( ~) 32비트 = 2^32 = -21억~21억.
 __int64(선호) == long long / 8 바이트 = 36비트, 2^64 큰 숫자
 ============(양수형)
 unsigned char 0~256
 unsigned short // 0~65535
 unsigned int // 0~42억
 unsigned __int64 == unsigned long long // 큰수

 32비트컴퓨터(2^32) 16비트컴퓨터(2^16) 차이가크다!

 ============(참 거짓) 
 컴퓨터 최소의 단위가 1byte여서 1byte값을 가진다.
 bool isDead = true;
 bool isPlayer = false;

 =============(소수형)
 float moveSpeed = 1.0f;  // 4바이트
 double moveSpeed2 = 1.4; // 8바이트

 부동소수점 방법으로 사용 
 3.141592 = 0.3141592 * 10 = 0.03141592 * 100
 유효숫자 3141592 (지수 1) = 32비트.
 float 부호(1) 지수 (8) 유효숫자(23) = 32비트 = 4바이트
 double 부호(1) 지수(11) 유효숫자(52) = 64비트 = 8바이트
 근사값만 표현을 해줄수 있고, 정확하게 표현을 하지 못함.
 ***** 소수의 부등호 표현은 >=, 이나 <= 을 이용해서 하자

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
	b = b + 1; // 오버플로우 현상 꼭 알아두기 https://m.blog.naver.com/noksek0615/221745224309
	// 0 1 1 1 , 1 1 1 1 에 1을 더하면
	// 1 0 0 0 , 0 0 0  이 되서 -32768이 나온다.
	cout << b << endl;

	double dd(1.0f);
	double ddd(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

	cout << setprecision(18) << endl; // 부동 소수점 값의 전체 자릿수를 설정합니다. (정확한 숫자 표현)
	cout << dd <<" "<< &dd<< endl;
	cout << ddd << " "<< &ddd<<endl;


	if (dd == ddd)
		cout << "same" << endl;
	else cout << "not same, dd : " << dd << ", ddd : "<< ddd << endl;

	b = a++; // b=a를 넣고 a를 1 증가
	b = ++a; // a를 1 증가 시키고 b=a 

	cout << sizeof(d) << endl;
	cout << sizeof(c) << endl;
	cout << sizeof(isPlayer) << endl;

	char ch = 35;
	char ch2 = 'a';
	char ch3 = 'a' + 1; // 아스키코드때문에 가능
	// 유니코드 -  중국어, 한자, 한국어

	// escape sequence 이스케이프 시퀀스 -  잘 활용해보기!
	cout << ch << "\n" << endl; // 한줄 띄우기
	cout << "abc" << "\t" << "def" << endl; // 줄맞춤
	cout << "ab" << "\t" << "cdef" << endl;
	cout << ch3 << "\a" << endl; 


	// utf-8  알파벳 1바이트, 유럽 2바이트, 한글 한자 3바이트 (영어로만 출시할 경우 이걸로 만들기)
	// utf-16 대부분 2바이트, 한글도 2바이트( 한국어로 출시할거면 이걸로 만들기)

	// 문자열은 문자열끝에 \0 이 있음
	char str[] = { 'h','e','l','l','o', '\0'};
	char str2[] = "hello";
	cout << str << endl;
	cout << str2 << endl;
}