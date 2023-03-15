#include "Graph.h"

Graph::Graph(string str) : _str(str)
{
	setStar();
}
Graph& Graph::operator<<(string str)
{
	if (_str[str.length()] != ' ') _str.pop_back();
	_str += str;
	return *this;
}

Graph Graph::operator!()
{
	cout << _str << endl;
	int count = 0;
	for (int i = 0; i < _str.length(); i++)
	{
		if (isalpha(_str[i]) != 0)
			count++;
	}
	cout << "ÃÑ ¾ËÆÄºª ¼ö " << count << endl;

	int countStar = 0;
	for (int i = 0; i < _str.length(); i++)
	{
		_str[i] = tolower(_str[i]);
		if (isalpha(_str[i]) == 2)
		{
			int j;
			j = _str[i] % 97;
			_alphabet[j] += "*";
			countStar++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		cout << _alphabet[i] << endl;
	}

	return *this;
}

void Graph::setStar()
{
	for (int i = 0; i < 26; i++)
	{
		_alphabet[i] = 97 + i;
		_alphabet[i] += ":";
	}
}
