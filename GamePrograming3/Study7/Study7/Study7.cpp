#include <iostream>

using namespace std;
/*
 면접.
 프로그래밍 기초(c# ,c++) , 자료구조, 알고리즘(프로그램 심화) 그래픽스 -> 면접은 기초가 더 많다.
 게임엔진(강의) 포트폴리오 // 서버쪽으로가면 운영체제, 데이터베이스 (책이 별로 없다.)

 it회사면접
 1차 서류 - 자개소개서(이상한거만 없으면 됨, 크게중요 X), 포트폴리오. (중요. 공들여야함.... ㄹㅇ)
 경력기술서.
 -- 떨어지면 포폴문제 --
 
 2차 온라인 코딩테스트, 기술면접(직접), 와서 손코딩
 실력검증, 좋은회사일수록 빡빡하게.. 깐깐하게.. 안보는 회사는 가지말것..^^
 - 백준, 프로그래머스lv-3 (네카라쿠배당토 ㅆㄱㄴ) (다음달 - 4월에 할 내용)
 -- 통과하면 거의 다한 거--
 
 3차 임원면접
 
 신입 좋소 -> 실전에 바로투입ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
 중견이상 신입(별로안바람 ㄹㅇ.) 분석.(1달) 짜잘한거 하나 수정. 잘한다 -> 좀더 중요한거 수정
 경력올라가면 신규프로젝트. 새로만들기.
 */

// 함수 오버로딩 (같은 함수더라도 인자가 다를경우 새로만드는것)
//int getMax(int x, int y)
//{
//	return (x > y) ? x : y;
//}
//double getMax(int x, double y)
//{
//	return (x > y) ? x : y;
//}

// 너무 번거로워서 나온게 template.
template<typename T>  // typename 대신 class를 사용해도됨. 주로 typename을 사용
T getMax(T x, T y)
{
	return x > y ? x : y;
}

template<class T>
class Storage
{
public:
	Storage(T value) : m_value(value)
	{

	}
	void print()
	{
		cout << m_value << endl;
	}

private:
	T m_value;

};

void Storage<double>::print() // double 타입만 다르게 하고싶을 경우 재정의 해주면됨.
{
	cout << "double double" << endl;
}

//  서로다른 인자 2개를 쓰고 싶을경우 t1 ,t2로 정의해서 사용. 이름은 주로 t1, t2로 쓴다.
template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

template<typename T, unsigned int T_SIZE>
class MyArray
{
public:
	MyArray()
	{
		m_data = new T[T_SIZE]; // 새로운 배열 생성
	}
	~MyArray()
	{
		delete[] m_data;
	}

	T& operator[](int index)
	{
		return m_data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}
	void print()
	{
		for (int i = 0; i < T_SIZE; i++)
		{
			cout << m_data[i] << " ";
			cout << "\n";
		}
	}
private:
	T* m_data;
};

template<typename T>
class A
{
public:
	A(const T& input)
	{

	}

	void print()
	{
		cout << typeid(T).name() << endl; // typeid.name 를 하면 무슨 타입인지 찍힌다.
	}

private:

};

template<> // temp을 받은걸 표시해주어야함.
class A<char>
{
public:
	A(const char& input)
	{

	}

	void print()
	{
		cout << "char print" << endl; // typeid.name 를 하면 무슨 타입인지 찍힌다.
	}
};

template<typename T>
T biggest(T x[], int T_SIZE)
{
	T output= x[0];
	for (int i = 1; i < T_SIZE; i++)
	{
		if (output < x[i])
		{
			output = x[i];
		}
	}
	return output;
}

template<typename T>
void reverserArray(T x[], T T_SIZE)
{
	T temp[100];
	for (int i = 0; i < T_SIZE; i++)
	{
		temp[i] = x[T_SIZE - i - 1];
	}
	for (int i = 0; i < T_SIZE; i++)
	{
		x[i] = temp[i];
		cout << x[i] << " ";
	}
}

/*
template<typename T>
void reverserArray(T x[], T T_SIZE)
{
	// 홀수이거나 짝수이거나 상관없이 2로 나눈값 만큼 바꾸면된다.
	// [0] [1] [2] [3] [4] -> 2번
	// [0] [1] [2] [3] -> 2번 
	for (int i = 0; i < T_SIZE / 2; i++)
	{
		T temp = x[i];
		x[i] = x[size - 1 - i];
		x[size - 1 - i] = temp;
	}
}
*/

int main()
{
	// #1.배열을 받아 가장 큰값을 리턴하는 제네릭 biggest() 를 작성.
	int x[] = { 1,5,10 ,20 ,60 };
	cout << biggest(x, 5) << endl;

	double d[] = { 1.5, 5.4, 10.3 ,50.2 ,30.6 };
	cout << biggest(d, 5) << endl;

	// #2. 배열의 원소를 반대로 뒤집는 reverserArray()함수를 템플릿으로 작성
	int y[] = { 1,5,10,20,60 };
	reverserArray(y, 5);

	//A<int>a_int(5);
	//A<double>a_double(5.4);
	//A<char>a_char('a');

	//a_int.print();
	//a_double.print();
	//a_char.print();
	/*
	// 템플릿으로 만들경우 < > 를 써서 어떤타입인지 입력해주어야함.
	MyArray<double, 100> my_array;
	for (int i = 0; i < my_array.getLength(); i++)
	{
		my_array[i] = i * 3;
	}

	my_array.print();
	my_array[5] = 4;

	Print(5, 4.5f);
	*/

	/*
	Storage<int> storvalue(5);
	Storage<double> stordvalue(10.4);
	
	storvalue.print();
	stordvalue.print();
	*/

	/*cout << getMax(1, 3) << endl;
	cout << getMax(1.4 , 3.6) << endl;
	cout << getMax(1.4f, 3.6f) << endl;
	cout << getMax('f', 't') << endl;*/


}

