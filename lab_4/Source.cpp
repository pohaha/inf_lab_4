# include"Vector.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
	Double_Vector v;
	int swaps_total = 0;
	int checks_total = 0;
	unsigned int size=0;
	int final_size = 500;
	std::cout << "x=[";
	//произвольного порядка
	while (size < final_size)
	{
		//шаг изменения размера вектора
		size += 50;
		//инициализация действительно случайного зерна для функции rand
		srand(time(NULL));
		//заполнение вектора случайными числами
		for (unsigned int i = 0; i < size; i++) v.push_back(double(rand() % 1000) / 10);
		//сортировка пузырьком потому что нет времени делать чтото другое
		swaps_total = 0;
		checks_total = 0;
		for (int i = size - 1; i >= 0; i--)
			for (int j = 0; j < i; j++)
			{
				checks_total++;
				if (v[j] > v[j + 1])
				{
					swaps_total++;
					v.swap(j, j + 1);
				}
			}	
		std::cout << size << " " << swaps_total << " " << checks_total << "; ";
		v.clear();
	}
	std::cout << "]" << std::endl;
	//отсортированный
	std::cout << "y=[";
	size = 0;
	while (size < final_size)
	{
		//шаг изменения размера вектора
		size += 50;
		//инициализация действительно случайного зерна для функции rand
		srand(time(NULL));
		//заполнение вектора случайными числами
		for (unsigned int i = 0; i < size; i++) v.push_back(double(rand() % 1000) / 10);
		//сортировка пузырьком потому что нет времени делать чтото другое
		swaps_total = 0;
		checks_total = 0;
		for (int i = size - 1; i >= 0; i--)
			for (int j = 0; j < i; j++)
			{
				if (v[j] > v[j + 1])
				{
					v.swap(j, j + 1);
				}
			}
		for (int i = size - 1; i >= 0; i--)
			for (int j = 0; j < i; j++)
			{
				checks_total++;
				if (v[j] > v[j + 1])
				{
					swaps_total++;
					v.swap(j, j + 1);
				}
			}
		v.clear();
		std::cout << size << " " << swaps_total << " " << checks_total << "; ";
	}
	std::cout << "]" << std::endl;
	//обратная последовательность
	size = 0;
	std::cout << "z=[";
	while (size < final_size)
	{
		//шаг изменения размера вектора
		size += 50;
		//инициализация действительно случайного зерна для функции rand
		srand(time(NULL));
		//заполнение вектора случайными числами
		for (unsigned int i = 0; i < size; i++) v.push_back(double(rand() % 1000) / 10);
		//сортировка пузырьком потому что нет времени делать чтото другое
		swaps_total = 0;
		checks_total = 0;
		for (int i = size - 1; i >= 0; i--)
			for (int j = 0; j < i; j++)
			{
				if (v[j] < v[j + 1])
				{
					v.swap(j, j + 1);
				}
			}
		for (int i = size - 1; i >= 0; i--)
			for (int j = 0; j < i; j++)
			{
				checks_total++;
				if (v[j] > v[j + 1])
				{
					swaps_total++;
					v.swap(j, j + 1);
				}
			}
		v.clear();
		std::cout << size << " " << swaps_total << " " << checks_total << "; ";
	}
	std::cout << "]" << std::endl;

}