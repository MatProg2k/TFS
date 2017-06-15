#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF INT_MIN
#define PLM INT_MAX

class AList
{
private:
	
	std::vector<int> color; 
	bool loop = false; 
	std::vector<int> topologicalSort; 
	
	void GoToTopologicalSort(int v); 

	std::vector<std::vector<int>> list;
public:

	AList(std::vector<std::vector<int>> list);
	void TopologicalDFS();
};