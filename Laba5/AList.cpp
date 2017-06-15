#pragma once
#include "AList.h"

AList::AList(std::vector<std::vector<int>> list)
{
	this->list = list;
}

void AList::GoToTopologicalSort(int v)
{
	if (this->color[v] == 2 || this->loop == true)
	{
		return;
	}
	else if (this->color[v] == 1)
	{
		this->loop = true;
		return;
	}
	else
	{
		this->color[v] = 1;

		for (int i = 0; i < this->list[v].size(); i++)
		{
			this->GoToTopologicalSort(this->list[v][i]);

		}

		this->color[v] = 2;
		this->topologicalSort.push_back(v);
	}
}

void AList::TopologicalDFS()
{
	this->color.clear();
	this->loop = false;
	this->topologicalSort.clear();

	for (int i = 0; i < this->list.size(); i++)
	{
		this->color.push_back(0);
	}

	for (int i = 0; i < this->list.size(); i++)
	{
		this->GoToTopologicalSort(i);
	}

	if (this->loop == false)
	{
		std::reverse(topologicalSort.begin(), topologicalSort.end());

	}

	std::cout << "Топологическая сортировка:" << std::endl;
	if (this->loop == true)
	{
		std::cout << "Граф содержит циклы! Топологическая сортировка не может выполнится!" << std::endl;
	}
	else
	{
		for (int i = 0; i < this->list.size(); i++)
		{
			std::cout << this->topologicalSort[i] << " ";
		}
		std::cout << std::endl;
	}
}