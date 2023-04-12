#pragma once
#include <iostream>
using namespace std;

class Graph
{
public:
	Graph(string);
	Graph& operator<<(string str);
	Graph operator!();
	void setStar();

private:
	string _str;
	string _alphabet[26];
};

