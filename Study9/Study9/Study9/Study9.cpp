#include <iostream>

using namespace std;

struct Person
{
	int age;
	float height;
	float weight;
	// char a 는 1바이트인데 2로나옴??? 
};

void PrintCopy(Person per)
{
	cout << sizeof(per) << endl;
	cout << per.age << endl;
	cout << per.height << endl;
	cout << per.weight << endl; // call by value (값을 넘김)
}

void PrintPtr(Person* per)
{
	cout << sizeof(per) << endl; // 주소값크기만큼
	cout << per->age << endl; // (*per).age와 같음
	cout << per->height << endl;
	cout << per->weight << endl; // call by address (주소를 넘김)
}

void PrintRef(const Person& per) // 값을 수정하지 않기를 원할때
{
	cout << sizeof(&per) << endl;
	cout << per.age << endl;
	cout << per.height << endl;
	cout << per.weight << endl; // call by reference (참조)
}

// inline을 쓰면 속도가 빨라진다. -> 함수의 호출이 빨라진다.
// 요즘엔 컴퓨터가 좋아서 생략해도된다.
inline int min(int x, int y)
{
	return x > y ? x : y;
}

void Test(int a)
{
	cout << "Test" << endl;
}

void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}

int main()
{/*
	Person me{ 20, 160, 70 };
	
	// 비효율적
	me.age = 20;
	me.height = 160;
	me.weight = 70; 

	//	cout << sizeof(Person); // 4 + 4 + 4

	//PrintCopy(me);
	//PrintPtr(&me);
	//PrintRef(me);

	// ===============================================

	int* ptr = nullptr;
	int** ptrptr = nullptr;  // 가끔 보인다.
//	int*** ptrptr = nullptr; // 3중 이상은 쓸 일이 잘 없다.
//	int**** ptr4 = nullptr;

	int value = 5;
	ptr = &value;
	ptrptr = &ptr;

	cout << ptr << " " << *ptr << &ptr <<endl; // value의 주소 , value 값(5) , ptr의 주소
	cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl; // ptr의 주소, value의 주소, ptrptr의 주소
	cout << **ptrptr << endl; // value의 값(5) =  *(*ptrptr) = *(ptr)
	
	int num1 = 10, num2 = 20, num3 = 30;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* ptr3 = &num3;

	int* ptrArr[] = { ptr1,ptr2,ptr3 }; 
	int** dptr = ptrArr;

	// ***********************복습 필수***************************************
	cout << *ptrArr[0] << " " << *ptrArr[1] << " " << *ptrArr[2] << " " << endl; // 10, 20, 30
	cout << ptrArr[0] << " " << ptrArr[1] << " " << ptrArr[2] << " " << endl;
	cout << ptr1 << " " << ptr2 << " " << ptr3 << " " << endl; 
	cout << dptr[0] << " " << dptr[1] << " " << dptr[2] << " " << endl; // ptr
	cout << *(dptr[0]) << " " << *(dptr[1]) << " " << *(dptr[2]) << endl; // &ptr1, &ptr2, &ptr3 이 왜 안나올까?!
	// *(*ptrArr[0])인가 ??


	int arr2d[3][3];

	cout << arr2d <<" " << arr2d[0] << " " << &arr2d[0][0] << endl; // 같은주소가 나온다.
	cout << arr2d[1] << " " << &arr2d[1][0] << endl;
	cout << arr2d[2] << " " << &arr2d[2][0] << endl;

	cout << sizeof(arr2d) << endl; // 36바이트 4바이트 9칸
	cout << sizeof(arr2d[0]) << endl; // 12바이트 [0][0] , [0][1], [0][2]
	cout << sizeof(arr2d[1]) << endl; // 12바이트 [1][0] , [1][1], [1][2]
	cout << sizeof(arr2d[2]) << endl; // 12바이트 [2][0] , [2][1], [2][2]

	// ==================================================
	
	const int row = 3;
	const int col = 5;

	const int array2[row][col]
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};

	int** matrix = new int* [row];
	
	for (int r = 0; r < row; r++)
		matrix[r] = new int[col];


	int* r1 = new int[col] {1, 2, 3, 4, 5}; // 새로운 배열의 주소를 r1에 넣음
	int* r2 = new int[col] {6, 7, 8, 9, 10};
	int* r3 = new int[col] {11, 12, 13, 14, 15};

	int** rows = new int* [row] {r1, r2, r3}; // 이중 포인터의 2차원배열활용


	// =============================================

	int i = 5;
	float f = 3.0f;
	char c = 'a';

	void* ptr = nullptr;

	ptr = &i;
	ptr = &f;
	ptr = &c;

	// ptr++; // 바이트가 얼마나 더해지는지 모호해서 오류가 생긴다.

	cout << &c << " " << ptr << endl;  // c가 어떤 타입인지 모르기 때문에
//	cout << *ptr << endl; // 역참조도 불가능! *ptr 
	cout << *static_cast<char*>(ptr) << endl; // 역참조하고싶으면 강제 캐스팅

	// ============================================

	int* ptr1 = nullptr;

	// null과 nullptr의 차이
	Test(0);
	Test(NULL);
	Test(ptr1);
	Test(nullptr);

	// ============================================

	//foreach문
	int array3[]{ 0,1,2,3,4,5,6,7 };
	for (int& number : array3) // int number과 int& number의 차이 : 원본값 수정할때?
		cout << number << " ";
		*/
	// ============================================

	const int value = 5;
	const int* ptr = &value;
//	*tr = 6; 주소에 저장된 값을 바꾸지 않겠다.

	cout << *ptr << endl; 

	int value2 = 6;
	int* const ptr2= &value2; 

	ptr = &value2; // 주소는 바꿀 수 있다. ?!

	*ptr2 = 10;
	int vlue3 = 5;
// 	ptr2 = &value3; // 주소값 자체를 바꾸지 않겠다. 

}

