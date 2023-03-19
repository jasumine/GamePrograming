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
	// 포인터!. pointer point 가리키다. 뭔가를 가리키는 곳. 메모리(주소)

	int a = 5; // 4바이트 메모리를 쓰겠다고 a = 5라는 숫자.

	// [주소] -> [5] 가 담겨있음.

//	int* ptr = &a; // a의 주소를 ptr에 담겠다.

	cout << a << endl; // 5
	cout << &a << endl; // a의 주소
	//	cout << ptr << endl; // a의 주소
	//	cout << *ptr << endl; // 5 , 포인터를 통한 간접 참조 값.(원본) 

		/*
		int num1 = 100, num2 = 100;
		int* ptr;

		ptr = &num1;
		(*ptr) += 30;

		ptr = &num2;
		(*ptr) -= 30;

		cout << num1 << " " << num2 << endl;
		*/

		// 포인터를 통해서 원본값을 건드렸따. 

	int x = 5;
	double d = 1.0f;
	int* ptr_x;
	double* ptr_d;

	// 포인터는 무조건 크기 고정. 64비트. ( 8바이트 고정) // 32비트(4비트)

	cout << sizeof(x) << endl; // 4
	cout << sizeof(d) << endl; // 8
	cout << sizeof(&x) << " " << sizeof(ptr_x) << endl; // 8 8
	cout << sizeof(&d) << " " << sizeof(ptr_d) << endl; // 8 8

	/*
	int num = 10;
	int* ptr2 = &num;
	int* ptr3 = ptr2;

	(*ptr2)++; // 11
	(*ptr3)++; // 12 // ptr3은 ptr2이므로 ptr3은 &num을 넣은것과 같다.

	cout << num << endl;
	*/

	int num1 = 10, num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;

	(*ptr1) += 10;
	(*ptr2) -= 10;

	cout << *ptr1 << " " << *ptr2 << endl;
	//이 포인터를 사용해서 두 숫자를 교체. (swap)

	swap(*ptr1, *ptr2);
	cout << *ptr1 << " " << *ptr2 << endl;

	int number = 1;
	number++;
	++number;
	number += 1;

	int* pointer = &number;
	pointer++; // 포인터주소 . 4칸( int 1의 값 만큼)
	++pointer;
	pointer += 1;

	// Player player;
	// cout << sizeof(player) << endl; // 9가 나와야하는데 10이나옴 바이트 패딩(메모리를 효율적으로)

	pointer--;
	// pointer *  2 // 안됨!

	/*
	int arr1[3] = { 1,2,3 };
	double arr2[3] = { 1.1, 2.2,3.3 };

	cout << arr1[0] << " " << arr1[1] << " " << arr1[2] << endl;
	cout << *arr1 << " " << *(arr1 + 1) << " " << *(arr1 + 2) << endl;
	// *arr1 = &arr1[0] , *(arr1+1)= &arr1[0] + 1 = &arr[1] , *(arr1+2) = &arr[0] + 2 = &arr[2];
	// arr[i] == *(arr+i)

	*arr1 += 100;
	*arr2 += 120;

	cout << *arr1 << " " << *arr2 << endl; // 포인터를 통한 원본값 정의
	cout << arr1[0] << " " << arr2[0] << endl;

	// 배열도 포인터처럼 사용이 가능!
	// 배열의 이름자체가 배열의 시작주소값이라는 놀라운 발견!

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

	// ************************************************************************
	// 전부 값을 2씩증가 시키는데
	// 1번째. ptr 변수에 저장된 값을 증가시키기.
	for (int i = 0; i < 5; i++)
	{
		 *ptr +=2;
		 ptr++;
		 *(ptr++) +=2;
		cout << arr[i] << " ";
	}

	cout << endl;

	// 2번째 방법, ptr에 저장된 값을 변경하지 않고 ptr을 대상으로 덧셈연삼하기.
	for (int i = 0; i < 5; i++)
	{
		*(ptr+i) +=2;
		cout << ptr[i] << " ";
	}
	// ************************************************************************

	
}

