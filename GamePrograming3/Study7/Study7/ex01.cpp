//#include <iostream>
//using namespace std;
//
//template<typename T>
//T biggest(T x[], T T_SIZE)
//{
//	T output = x[0];
//	for (int i = 0; i < T_SIZE; i++)
//	{
//		if (output < x[i])
//		{
//			output = x[i];
//		}
//	}
//	return output;
//}
//
//template<typename T>
//void reverserArray(T x[], T T_SIZE)
//{
//	T temp[10];
//	for (int i = 0; i < T_SIZE; i++)
//	{
//		temp[i] = x[T_SIZE - i];
//	}
//	for (int i = 0; i < T_SIZE; i++)
//	{
//		x[i] = temp[i];
//		cout << x[i] << " ";
//	}
//}
//
//int main()
//{
//	// #1.배열을 받아 가장 큰값을 리턴하는 제네릭 biggest() 를 작성.
//	int x[] = { 1,5,10 ,20 ,60 };
//	cout << biggest(x, 5) << endl;
//
//	double d[] = { 1.5,5.4,10.3 ,50.2 ,30.6 };
//	cout << biggest(x, 5) << endl;
//
//	// #2. 배열의 원소를 반대로 뒤집는 reverserArray()함수를 템플릿으로 작성
//	int y[] = { 1,5,10,20,60 };
//	reverserArray(y, 5);
//}