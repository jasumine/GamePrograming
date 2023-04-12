// map 컨테이너를 사용해서, 한글단어를 저장하고, 영어로 찾는 사전만들기.
// insert(love ,사랑) << 이런식으로
// 사전의 크기도 출력해보고
// love 단어를 입력받으면 사랑이 출력되게
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, string> dictionary;
	dictionary.insert(make_pair("love", "사랑"));
	dictionary.insert(make_pair("happy", "행복"));
	dictionary.insert(make_pair("sad", "슬픔"));
	dictionary.insert(make_pair("dead", "죽음"));
	dictionary.insert(make_pair("star", "별"));
	dictionary.insert(make_pair("morning", "아침"));
	dictionary.insert(make_pair("gimbap", "김밥"));
	dictionary.insert(make_pair("cake", "케이크"));
	dictionary["apple"] = "사과";

	cout << "저장된 영단어의 개수 : " << dictionary.size() << endl;

	while (1)
	{
		cout << "찾고자 하는 영어단어를 입력하세요.";
		string word;
		cin >> word;
		// getline(cin, str);

		if (word == "0")
		{
			break;
		}
		// 찾는 영단어가 있으면 dictonary.second를 출력하기
		map<string, string>::iterator findWord = dictionary.find(word); // 결과값은 
		if (findWord != dictionary.end())
		{
			cout << findWord->first << "의 한국어는 '" << findWord->second << "'입니다." << endl;
		}
		else
		{
			cout << findWord->first << "의 한국어는 저장되어 있지 않습니다." << endl;
		}

	/*	if (dictionary.find(word) == dictionary.end())
		{
			cout << "없음" << endl;
		}
		else
		{
			cout << dictionary[word] << endl;
		}*/

	}

	
}