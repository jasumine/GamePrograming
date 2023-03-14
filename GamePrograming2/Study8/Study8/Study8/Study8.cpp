#include <iostream>

using namespace std;

void swap(int *a, int* b)
{
	int *temp = a;
	a = b;
	b = temp;
}

void swap2(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Function1(int x)
{
	cout << "function: " << x << " " << &x << endl; 
	// 매개변수가 다르지만, 매개변수의 주소가 고정되어 있어서 주소값은 같다.
}

int addOne(int x)
{
	return x + 1;
}

/*
void Function(int *x) // 포인터의 경우
{
	cout << "Function x :" << x << " " << &x << endl;
	// x는 x의 주소값, &x는 &x를의 주소를 담은 매개변수의 주소값.
}
*/

void Function(int& x)
{
	cout << "Function x :" << x << " " << &x << endl;
	// x는 x의값(5)가 들어가고, &x 는 x의 주소값 (매개변수의 주소값이 아니다)
}

// 포인터를 반환한다는 뜻?!
int* Function3(int x)
{
	// 지역변수의 주소값은 넘기는 일이 잘 없어서 쓰이지는 않지만, 
	// 지역변수의 주소값을 넘기는 일은 굉장히 위험하다!!!!!!!!
	int value = x * 2;
	return &value;
	// value의 주소를 반환 , 함수가 끝나면 value는 사라져버려서 주소가 사라지게된다.	
}

// 레퍼런스를 반환한다는 뜻?! 경험이 없어서 헷갈리는 듯?!!!!!
// 언젠가는 쓰일 일이 생긴다?!!
int& Function4(int x)
{
	int value = x * 2;
	return value; // 괜찮습니다. 값을 넘겨서 괜찮다는 뜻.
}

int& referenceOne(int& ref)
{
	ref++;
	return ref; // ref +1
}


int main()
{
	/*const int value = 5;
	const int* ptr = &value; // ptr이 가리키는 주소에 있는 값을 바꾸지 않겠다.
//	*ptr = 6;

	int value = 5;
	int* const ptr = &value; // 주소값 자체를 바꾸지 않겠따.
	int vlaue2 = 6;
	ptr = &value2;

	int value = 5;
	int* ptr = &value; // 포인터
	int& ref = value; // 참조, 레퍼런스

	// ptr
	int* ptr = nullptr; // null 값을 넣어주어도된다.
	int& ref = nullptr; // 안됨! 무조건 값을 받아와야한다.
	// 주소의 두번째 이름을 지어주는 느낌

	cout << &value << endl; // value의 주소
	cout << ref << endl; // value의 값
	cout << &ref << endl; // value의 주소
	cout << ptr << endl; // value의 주소
	cout << &ptr << endl; // ptr의 주소
	// &value, &ref, ptr == value의 주소 // ref, *ptr == value의 값 // &ptr  == ptr의 주소

	// ================================================

	int a = 10;
	int b = 20;
	swap(&a, &b);
	swap2(a, b);
	cout << a << " " << b << endl;

	Function1(5);
	int x = 6;
	cout << "main: " << x << " " << &x << endl;

	Function1(x);
	Function1(x + 1);

	// ==================================================
	

	int x = 6;

	cout << x << " " << &x << endl; // 6, x의 주소

	addOne(x);

	cout << x << " " << &x << endl; // 7, x의 주소 // 값이 바뀌어도 주소값은 같다.

	// =================================================

	int x = 5;
	cout << x << " " << &x << endl; // 5, x의 주소값

	Function(x); // &x(포인터의 경우)
	cout << x << " " << &x << endl; // 포인터보단 참조가 조금 성능좋음.

	// ==================================================
	

	int* value = Function3(2);

	cout << value << endl; // 주소는 넘겼지만, 넘겨진 주소가 날라간다...

	int value = Function4(3); // 값을 넘겨받아서 안전하다.

	// ==============================================
	*/

	int num1 = 1;
	int& num2 = referenceOne(num1); 
	// num2는 num1의 주소를 가리키고있는 상태 
	// num1의 값이 증가해서 num2의 값도 증가하고
	// num2는 num1을 가리키고있어서 num1의 값이 증가한다.

	// 2) int num2 = referenceOne(num1);
	// num2 : 2, num1 : 2인데 
	// ++을 각각해줘서 3 3 이 나온다.

	num1++; 
	num2++;  

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;

	// smartpointer!를 쓴다요~
	
}
