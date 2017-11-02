// SameAsTemplate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"


class Alpha
{};
class Beta
{};



template <class A, class B>
bool isSameAs(A a, B b)
{
	return false;
}

template <class A>
bool isSameAs(A a, A b)
{
	return true;
}



int main()
{
	auto testa = Alpha();
	auto testaa = Alpha();
	auto testb = Beta();
	
	std::cout << "is same:" << isSameAs(testa, testaa) << std::endl;
	std::cout << "is different:" << isSameAs(testa, testb) << std::endl;

	char k;
	std::cin >> k;

    return 0;
}

