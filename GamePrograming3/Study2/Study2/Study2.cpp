#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
	Graph graph("The greratest glory in living lies not in never falling, but in rising every time we fall \n");
	graph << "No sweat, no sweet " << "No pain no gain";
	!graph;
}
