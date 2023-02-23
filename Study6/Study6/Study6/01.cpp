#include <iostream>

using namespace std;

void swap(int* ptr1, int* ptr2)
{
	int swap = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = swap;
}

struct Player
{
	int a;
	int b;
	char c;
};


int main()
{
	// ������!. pointer point ����Ű��. ������ ����Ű�� ��. �޸�(�ּ�)

	int a = 5; // 4����Ʈ �޸𸮸� ���ڴٰ� a = 5��� ����.

	// [�ּ�] -> [5] �� �������.

//	int* ptr = &a; // a�� �ּҸ� ptr�� ��ڴ�.

	cout << a << endl; // 5
	cout << &a << endl; // a�� �ּ�
	//	cout << ptr << endl; // a�� �ּ�
	//	cout << *ptr << endl; // 5 , �����͸� ���� ���� ���� ��.(����) 

		/*
		int num1 = 100, num2 = 100;
		int* ptr;

		ptr = &num1;
		(*ptr) += 30;

		ptr = &num2;
		(*ptr) -= 30;

		cout << num1 << " " << num2 << endl;
		*/

		// �����͸� ���ؼ� �������� �ǵ�ȵ�. 

	int x = 5;
	double d = 1.0f;
	int* ptr_x;
	double* ptr_d;

	// �����ʹ� ������ ũ�� ����. 64��Ʈ. ( 8����Ʈ ����) // 32��Ʈ(4��Ʈ)

	cout << sizeof(x) << endl; // 4
	cout << sizeof(d) << endl; // 8
	cout << sizeof(&x) << " " << sizeof(ptr_x) << endl; // 8 8
	cout << sizeof(&d) << " " << sizeof(ptr_d) << endl; // 8 8

	/*
	int num = 10;
	int* ptr2 = &num;
	int* ptr3 = ptr2;

	(*ptr2)++; // 11
	(*ptr3)++; // 12 // ptr3�� ptr2�̹Ƿ� ptr3�� &num�� �����Ͱ� ����.

	cout << num << endl;
	*/

	int num1 = 10, num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;

	(*ptr1) += 10;
	(*ptr2) -= 10;

	cout << *ptr1 << " " << *ptr2 << endl;
	//�� �����͸� ����ؼ� �� ���ڸ� ��ü. (swap)

	swap(*ptr1, *ptr2);
	cout << *ptr1 << " " << *ptr2 << endl;

	int number = 1;
	number++;
	++number;
	number += 1;

	int* pointer = &number;
	pointer++; // �������ּ� . 4ĭ( int 1�� �� ��ŭ)
	++pointer;
	pointer += 1;

	// Player player;
	// cout << sizeof(player) << endl; // 9�� ���;��ϴµ� 10�̳��� ����Ʈ �е�(�޸𸮸� ȿ��������)

	pointer--;
	// pointer *  2 // �ȵ�!

	/*
	int arr1[3] = { 1,2,3 };
	double arr2[3] = { 1.1, 2.2,3.3 };

	cout << arr1[0] << " " << arr1[1] << " " << arr1[2] << endl;
	cout << *arr1 << " " << *(arr1 + 1) << " " << *(arr1 + 2) << endl;
	// *arr1 = &arr1[0] , *(arr1+1)= &arr1[0] + 1 = &arr[1] , *(arr1+2) = &arr[0] + 2 = &arr[2];
	// arr[i] == *(arr+i) 

	*arr1 += 100;
	*arr2 += 120;

	cout << *arr1 << " " << *arr2 << endl; // �����͸� ���� ������ ����
	cout << arr1[0] << " " << arr2[0] << endl;

	// �迭�� ������ó�� ����� ����!
	// �迭�� �̸���ü�� �迭�� �����ּҰ��̶�� ���� �߰�!

	cout << arr1 << endl;
	cout << &arr1[0] << endl;
	cout << &arr1[1] << endl;

	int* ptr = &arr1[0];
	cout << ptr[0] << endl; // arr1
	cout << ptr[1] << endl; // arr2
	cout << ptr[2] << endl; // arr3
	*/

	int arr[5] = { 1,2,3,4,5 };
	int* ptr = arr;
	
	// ���� ���� 2������ ��Ű�µ�
	// 1��°. ptr ������ ����� ���� ������Ű��.
	for (int i = 0; i < 5; i++)
	{
		arr[i] += 2;
		// *ptr +=2;
		// ptr++;
		// *(ptr++) +=2;
		cout << arr[i] <<" ";
 	}

	cout << endl;

	// 2��° ���, ptr�� ����� ���� �������� �ʰ� ptr�� ������� ���������ϱ�.
	for (int i = 0; i < 5; i++)
	{
		ptr[i] += 2;
		// *(ptr+i) +=2;
		cout << ptr[i] << " ";
	}

}

