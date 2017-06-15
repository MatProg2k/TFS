#include <iostream>

#include "AList.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");

	AList listGraph
	(
	{
		{ 1 },
		{ 2, 4 },
		{ 3 },
		{ 5 },
		{ 6 },
		{},
		{}
	}
	);

	listGraph.TopologicalDFS();
	std::cout << std::endl;
	
	system("pause");
	return 0;
}