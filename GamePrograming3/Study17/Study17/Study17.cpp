#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // input output manipulaotrs
#include <fstream> 

using namespace std;

typedef int id;
using id2 = int;

typedef void(*Myfunc)();
using Myfunc2 = void(*)(); // void (*)() 
// using 함수이름 = 타입(포인터를 쓰면 붙이기)(); << 우월하다 (템플릿때문.)


//template<typename T>
//typedef vector<T> V1; // 사용할 수 없음.

template <typename T>
using V2 = vector<T>; // 사용가능.  (template과의 차이점!)

// Modrenc++	using, enum class, lamda, smartpointer 

void PrintStates(const ios& stream)
{
	cout << boolalpha;
	cout << "good " << stream.good() << endl; // 상태가 좋으면 true
	cout << "eof() " << stream.eof() << endl; // 파일을 끝까지 읽었는지
	cout << "fail() = " << stream.fail() << endl; // 상태가 안좋은지
	cout << "bad() = " << stream.bad() << endl; //	문제 발생시.
}

void PrintCheck(const char& i) // int로 받을경우 아스키코드로 인식한다.
{
	cout << boolalpha;
	cout << "is alpha or num " << bool(isalnum(i)) << endl; // 알파벳, 또는 숫자니?
	cout << "is blank " << bool(isblank(i)) << endl; // 빈칸이니?
	cout << "is digit " << bool(isdigit(i)) << endl; // 숫자니?
	cout << "is lower " << bool(islower(i)) << endl;	// 소문자니?
	cout << "is upper " << bool(isupper(i)) << endl; // 대문자니?
}


int main()
{
	/*id a = 5;
	id2 b = 10;

	vector<int> v;*/

	//===========================================================

	char buf[100];
	//cin >> setw(5) >> buf; // 딱 5글자만 입력받는다.
	//cout << buf << "\n";

	//cin >> setw(5) >> buf; // 딱 5글자만 입력받는다.
	//cout << buf << "\n";

	//cin >> setw(5) >> buf; // 딱 5글자만 입력받는다.
	//cout << buf << "\n";
	// 여러번 쓸 경우, buf에 남아서 끊어진것처럼 보임.

	//===========================================================

	//cin.get(buf, 5); // 5글자만 받는다.
	//cout << cin.gcount()<<" " << buf << "\n"; // 몇글자 읽어왔는지 알려준다.

	//===========================================================

	////cin.ignore(); 이걸 해주면 두번째 getline도 입력 받을 수 있음.
	//cin.getline(buf, 5);
	//cout << cin.gcount()<< " " << buf << endl; // 4글자

	//cin.getline(buf, 5);
	//cout << cin.gcount() << buf << endl; // 0글자 < buf가 비어있음.

	//===========================================================

	//cin.ignore(2); // 앞에 2글자만 무시한다.
	//cin >> buf;
	//cout << buf << endl;

	//===========================================================

	//cout << (char)cin.peek() << endl; //위에 있는거 구경하기 ?!!

	//cin >> buf;
	//cout << buf << endl;

	//===========================================================

	cout.setf(ios::showpos); // plus 기호를 붙인다.?
	cout << 108 << endl;

	cout.unsetf(ios::showpos);  // plus 기호를 없앤다.?
	cout << 108 << endl;

	//===========================================================

	//cout << hex;	// 16진수로 표현됨.
	//cout << 108 << endl;
	//cout << 90 << endl;

	//cout << dec;	//10진수로 표현된다.
	//cout << 108 << endl; 

	//===========================================================

	//cout << setprecision(3) << 1.2345678 << endl; // 3글자만 가져옴.
	//cout << setprecision(4) << 12.345678 << endl; // 소수점의 경우반올림으로 가져온다.
	//cout << setprecision(5) << 12.345678 << endl;
	//cout << setprecision(6) << 12.345678 << endl;

	//===========================================================

	//cout << 12345 << endl;
	//cout.fill('*'); //빈칸을 별로 채운다는 의미.
	//cout << setw(10) << -12345 << endl; 
	//cout << setw(10) << left << -12345 << endl;
	//cout << setw(10) << right << -12345 << endl;

	//===========================================================

	//while (true)
	//{
	//	char i;
	//	cin >> i;

	//	PrintStates(cin);
	//	PrintCheck(i);

	//	cout << i << endl;

	//	cin.clear();
	//	cin.ignore(1024, '\n'); // 싹 청소 한다.
	//}

	//===========================================================
	// 파일 입출력은 엔진에서 자동으로 해주는 경우가 많다.
	// 파일 입력
	/*ofstream ofs("datas.dat");

	ofs << "Line 0" << endl;
	ofs << "Line 1" << endl;*/

	// 이진수로 넘기는 방법. 파일이 깨진다.!!
	/*ofstream ofs("datas2.dat");

	const unsigned num_size = 10;
	ofs.write((char*)&num_size, sizeof(num_size));

	for (int i = 0; i < num_size; i++)
	{
		ofs.write((char*)&i, sizeof(i));
	}*/

	// 파일 출력
	//ifstream ifs("datas.dat"); // 파일명이 1자라도 다를경우 error

	//if (!ifs)
	//{
	//	cerr << "error" << endl;
	//	exit(1);
	//}
	//while (ifs) // 파일이 있다면 읽어온다
	//{
	//	string str;
	//	getline(ifs, str);
	//	
	//	cout << str << endl;
	//}
	//// 아스키코드를 넘기는 방법. 굉장히 느리다.
}
