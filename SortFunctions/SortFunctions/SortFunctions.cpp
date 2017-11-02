// SortFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iterator>

class someClass
{
public:
	int gamma;
	someClass():gamma(3)
	{}
};
class otherClass : someClass
{
	int delta;
	otherClass() : delta(2)
	{

	}
};

template <class T>
void somefunc(T& alpha)
{
	std::cout << T << std::endl;
}

void sub_mergeSort(std::vector<int>& unsorted, std::vector<int>::iterator alpha, std::vector<int>::iterator end)// , std::vector<int>& temp)
{
	if (end - alpha == 1)
		return;
	else
	{

		std::vector<int>::iterator beta = alpha + (end - alpha) / 2;
		std::cout << "First half: ";
		for (std::vector<int>::iterator it = alpha; it < beta; it++)
		{
			std::cout << *it << " ";
		}
		std::cout << "Second half: ";
		for (std::vector<int>::iterator it = beta; it < end; it++)
		{
			std::cout << *it << " ";
		}
		if(alpha + 1 != beta)
			sub_mergeSort(unsorted, alpha, beta);// , temp);	
		if (beta + 1 != end)
			sub_mergeSort(unsorted, beta, end);//, temp);


		auto temp = std::vector<int>(alpha, end);

		//temp.clear();
		//int length = end - alpha;
		//int length = alpha - unsorted.begin();
		auto alpha_it = temp.begin();// (alpha - unsorted.begin());
		auto alpha_temp = alpha_it;
		int length = beta - alpha;
		auto beta_it = temp.begin() + (beta - alpha);
		auto beta_temp = beta_it;

		for (auto it = alpha; it < end; it++)
		{
			if ((beta_it == temp.end()) || (alpha_it != beta_temp && *alpha_it < *beta_it) )
			{
				*it = *alpha_it++;
			}

			else if (beta_it != temp.end())
			{
				*it = *beta_it++;
			}

		}
		
	}

}

void mergeSort(std::vector<int>& unsorted)
{
	//vect.begin
	//auto temp = std::vector<int>(unsorted.size(), 0);
	sub_mergeSort(unsorted, unsorted.begin(), unsorted.end());// , temp);
	return;
}



void printvect(const std::vector<int>& vect)
{
	for (auto x : vect)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

int main()
{
	//Test setup
	auto& test = std::vector<int>();
	test.push_back(10);
	test.push_back(9);
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	//std::cout << &test << std::endl;
	
	printvect(test);
	std::cout << std::endl;

	//std::vector<int>::iterator it = test.begin();
	mergeSort(test);
	std::cout << std::endl;
	printvect(test);

	//printvect(test);



	//Pause before end
	char endkey;
	std::cin >> endkey;
    return 0;
}

