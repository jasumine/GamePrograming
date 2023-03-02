#include <iostream>
#include <string>

using namespace std;

string backword(string);

int main()
{
	/*
	string a = "abc";
	string b("def");

	int num = a.compare(b); // a와 b가 같은지 비교

	if (num == 0) cout << "두 문자열이 같습니다." << endl; // 같을 경우 0을 반환
	else if (num < 0) cout << a << " < " << b << endl; // a < b 일 경우 -1
	else cout << b << " < " << a << endl; //  a > b 일경우 +1
	// abc < def 
	
	a.append("def"); // a라는 문자열 뒤에 def를 붙여준다.
	cout << a << endl;

	a += "etf";
//	a -= "f"; // 빼기는 안된다.

	a.insert(2, "ttt"); // 중간 삽입. 
	cout << a << endl; // ab ttt cdef

	a.replace(2, 5, "111"); // 대체  2번째 이후부터 5글자를 111로 대체
	cout << a << endl; // ab111efetf

	int length = a.length();
	int size = a.size();
	cout << length << ", " << size << endl;

	a.erase(0, 4);
	cout << a << endl; // 0부터 4개를 지운다

	a.clear(); // a를 완전 삭제

	string c = "i love love game";
	string d = c.substr(2, 5); // 2부터 5까지 짜르겠다.
	cout << d << endl; // love
	string e = c.substr(2); // 2부터 끝까지 리턴 
	cout << e << endl; // love love game

	int index = c.find("love"); // 2 리턴 
	cout << index << endl; // love 시작위치, 여러개가 있을경우 가장 첫번째
	index = c.find("love", index + 1); // index가 2인데 +1 인 3부터 love를 찾겠다. 7
	cout << index << endl;;
	index = c.find("like"); // 없을 경우 -1을 리턴
	cout << index << endl;

	char ch = c.at(5); // 5번째 단어를 가져오겠다 . 
	cout << ch << endl; // e 
	char ch2 = c[5]; // 같은말이다.
	cout << ch2 << endl; // e
	c[5] = 'X';  // 5번째를 X로 바꾸겠다.
	cout << c << endl; // i lovX love game

	string year = "2014";
	int n = stoi(year); // string to int 
	cout << n << endl; // 2014가 출력된다.

	string f = "hello";

	for (int i = 0; i < f.length(); i++)
	{
		f[i] = toupper(f[i]); // 대문자로 바꿔준다. HELLO
		cout << f[i];
	}

	for (int i = 0; i < f.length(); i++)
	{
		f[i] = tolower(f[i]); // 소문자로 바꿔준다 .hello
		cout << f[i];
	}

	if (isdigit(f[0]))	cout << "숫자"; // f[0]이 숫자일경우
	else if (isalpha(f[0])) cout << "문자"; // f[0]이 문자일 경우
	*/

	/*
	// 1) 문자열을 입력 받고 글자 하나만 랜덤하게 출력하는 프로그램
	// ex) hello world = hello warld
	// i love you = i lotu you

	cout << "문자를 입력하세요.";
	string str;
	getline(cin,str);
	
	// 97 - a, 122 - z (소문자) 35
	srand(time(0));
	int strRandomly = rand() % str.length(); // str의 길이 중 숫자 1개
	int alphaRandomly = rand() % 35 + 97; // 97~ 122 숫자중 1개
	for (int i = 0; i < str.length(); i++)
	{
		if (i == strRandomly)
		{
			str[strRandomly] = alphaRandomly; // str의 랜덤한 위치에 랜덤한 글자를 넣는다.	
		}
	}

	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i];
	}
	*/
	/*
	// 2) 문자열을 입력하세요. i am so happy. i really happy
	// ex) 문자 a는 4개 있습니다.
	
	cout << "문자열을 입력하세요.";
	string str;
	getline(cin, str);

	srand(time(0));
	int alphaChoice = rand() % 35 + 97; // 97~ 122 숫자중 1개
	
	int count =0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == (char) alphaChoice)
			count++; //같은 숫자가 있다면 ++
	}

	cout << "문자" << (char) alphaChoice << "는 " << count << "개 있습니다." << endl;
*/
	/*
	// 3) 문자열을 입력받고 거꾸로 출력하기.
	// ex) i am happy =  yppah ma i

	cout << "문자열을 입력하세요.";
	string str;
	getline(cin, str);

	string str2;
	for (int i = str.length(); i >= 0; i--)
	{
		str2 = str2 + str[i];
	}

	for (int i = 0; i < str2.length(); i++)
	{
		cout<< str2[i];
	}
*/
	/*
	// 4) 문자열을 5개 입력받고 사전에서 뒤에 나오는 문자열 출력하기.
	// Kim Chang Lee Han Hwang 
	// 사전에서 제일 뒤에나오는 문자열은 Lee 입니다.

	cout << "문자열을 5개 입력하세요" << endl;
	string str[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> str[i];
	}

	string latters = str[0];
	for (int i = 1; i < 5; i++)
	{
		if (latters < str[i])
		{
			latters = str[i];
		}
	}

	cout << "사전에서 제일 뒤에 나오는 문자열은 " << latters << "입니다.";
	*/
	/*
	// 5) 문자열을 입력받고 문자열에서 문자를 찾아 다른 문자열로 대체하는 프로그램.
	// dreams come true
	// 찾을 단어 : come
	// 대체할 단어 : never come
	// dreams never come true

	cout << "문자열을 입력하세요. ";
	string str;
	getline(cin, str);
	
	int index = str.find(" ");
	int index2 = str.find(" ", index + 1); // 2번째 띄어쓰기까지

	
	string word = str.substr(index, index2); // 첫번째 띄어쓰기 ~ 두번째 띄어쓰기 || 처음 ~ 첫번째 띄어쓰기
	cout << "찾을 단어 : " << word << endl;
	string newWord = "meet";
	cout << "대체할 단어 : " << newWord << endl;

	// 찾은 단어 앞과 뒤의 단어를 저장하고, 퍼즐을 맞춘다.
	string frontstr = str.substr(0, index+1); // 찾은 단어 앞의 단어 (띄어쓰기 포함 +1 )
	string backstr = str.substr(index2); // 찾은 단어 뒤에 남은 단어를 저장
	str.clear();
	str = frontstr + newWord + backstr;
	cout << str;
*/

	// 6)문자열을 입력받고 한글자씩 뒤로가게.
	// i love you
	// love youi
	// love youi
	// ove youi l
	// ve youi lo
	//....
	// i love you

	cout << "문자열을 입력하세요. ";
	string str;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++)
	{
		cout << str << endl;
		str = backword(str);
	}

}

string backword(string str)
{
	char temp = str[0];
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		str[i] = str[i + 1];
		if (i == length - 1)
		{
			str[i] = temp;
		}
	}

	return str;
}

