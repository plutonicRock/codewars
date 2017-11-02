// NQueen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

typedef std::vector<std::vector<int>> pointlist;

pointlist nQueen_start(int n = 8)
{
	//Initialize list of queen locations
	pointlist qlist;
	//Intialize valid list
	pointlist validplaces;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			validplaces.push_back({ i, j});
		}
	}


	return nQueen(n, validplaces, qlist);
	//pointlist nQueeen();
};

pointlist nQueen(int nq, pointlist validplaces, pointlist qlist)
{
	if (validplaces.size()>0)
	{
		std::vector<int> temp;
		for (pointlist::iterator point = validplaces.begin(); point<validplaces.end(); point++)
		{
			qlist.push_back(*point);
			validplaces.erase(point);
		}
	}
	return qlist;
};

int main()
{
	nQueen_start();

	char k;
	std::cin >> k;
    return 0;
}

