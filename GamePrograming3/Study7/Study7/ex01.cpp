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
//	// #1.�迭�� �޾� ���� ū���� �����ϴ� ���׸� biggest() �� �ۼ�.
//	int x[] = { 1,5,10 ,20 ,60 };
//	cout << biggest(x, 5) << endl;
//
//	double d[] = { 1.5,5.4,10.3 ,50.2 ,30.6 };
//	cout << biggest(x, 5) << endl;
//
//	// #2. �迭�� ���Ҹ� �ݴ�� ������ reverserArray()�Լ��� ���ø����� �ۼ�
//	int y[] = { 1,5,10,20,60 };
//	reverserArray(y, 5);
//}