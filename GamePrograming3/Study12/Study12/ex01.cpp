// map �����̳ʸ� ����ؼ�, �ѱ۴ܾ �����ϰ�, ����� ã�� ���������.
// insert(love ,���) << �̷�������
// ������ ũ�⵵ ����غ���
// love �ܾ �Է¹����� ����� ��µǰ�
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, string> dictionary;
	dictionary.insert(make_pair("love", "���"));
	dictionary.insert(make_pair("happy", "�ູ"));
	dictionary.insert(make_pair("sad", "����"));
	dictionary.insert(make_pair("dead", "����"));
	dictionary.insert(make_pair("star", "��"));
	dictionary.insert(make_pair("morning", "��ħ"));
	dictionary.insert(make_pair("gimbap", "���"));
	dictionary.insert(make_pair("cake", "����ũ"));
	dictionary["apple"] = "���";

	cout << "����� ���ܾ��� ���� : " << dictionary.size() << endl;

	while (1)
	{
		cout << "ã���� �ϴ� ����ܾ �Է��ϼ���.";
		string word;
		cin >> word;
		// getline(cin, str);

		if (word == "0")
		{
			break;
		}
		// ã�� ���ܾ ������ dictonary.second�� ����ϱ�
		map<string, string>::iterator findWord = dictionary.find(word); // ������� 
		if (findWord != dictionary.end())
		{
			cout << findWord->first << "�� �ѱ���� '" << findWord->second << "'�Դϴ�." << endl;
		}
		else
		{
			cout << findWord->first << "�� �ѱ���� ����Ǿ� ���� �ʽ��ϴ�." << endl;
		}

	/*	if (dictionary.find(word) == dictionary.end())
		{
			cout << "����" << endl;
		}
		else
		{
			cout << dictionary[word] << endl;
		}*/

	}

	
}