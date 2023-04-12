
#1. 템플릿에 대한 설명중 틀린것은 ? // 2 c#임 아니고 4번..^^
1).컴파일러에 따라 템플릿을 지원하지 않을수 있어 포팅에 취약하다
(porting은 어느 운영체제(플랫폼)에서 작성한 프로그램이 다른 운영체제에서도 작동하도록 되는것)​
2) c++에서 일반화를 의미하며 generic 이라고 부른다.
3) 템플릿을 통해 함수뿐만 아니라 클래스도 일반화가 가능하다.
4) 템플릿을 사용하면 디버깅시 자료가 더 많이나와 디버깅하기가 더 좋다.


​

#2)
template<typename T>
void show(T a)
{
	cout << a;
}
void show(int a)
{
	cout << "int" << a;
}​
실행시 잘작동이 되는가 ? 된다면 결과는 ?
a가 int 타입일 경우에는 "int" 가 출력되고
나머지는 a의 값이 나온다.
​


​
#3. 두개의 배열을 비교 같으면 true 아니면 false를 리턴하는 제네릭 함수 equalsArrays()를 작성하여라.
main 예시)
int x[] = { 1,20,30,100,40,30 };
int y[] = { 1,20,30,100,40,30 };
if (equalsArrays(x, y, 5))
	cout << "same";
else
	cout << "not same";

​

#4. 배열에서 데이터를 찾는 search() 함수를 템플릿으로 작성하여라.
main 예시)
int x[] = { 1,20,30,100,40,4 };
if (search(100, x, 5)) // 100 이란 숫자를 x배열에서 찾는다. 5는 배열의 크기.
	cout << " 포함되어 있다";
else
	cout << " 포함되어 있지않다";

​

​


#5.
class Circle
{
public:
	Circle(int radius = 1) : _radius(radius)
	{
	}
	int getRadius()
	{
		return _radius;
	}
private:
	int _radius;
};

template <class T>
T getMax(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}
​
int main()
{
	int a = 10, b = 30, c;
	c = getMax(a, b);
	cout << "큰 값은" << c << endl;
	Circle c1(10), c2(20), c3;
	c3 = getMax(c1, c2);
	cout << c3.getRadius() << endl; // 두 객체의 반지름중 큰값이 나오게 프로그램을 수정하여라. 20이 찍혀야됨.
}

​


# 6. 두 배열를 이어주는 concat 함수를 템플릿을 써서 작성하여라.
ex) int* concat(int a[], int sizea, int b[], int sizeb)
int main()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int* p = concat(a, 5, b, 5);
	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << " "; // 1 2 3 4 5 6 7 8 9 10 이찍히게.
	}
}