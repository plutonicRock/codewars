// MoveCopyTraining.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

class SearchQuery
{
public:
	int bullshit;
};

class DirectorySearchResult {
public:
	DirectorySearchResult(
		std::vector<std::string> const& files,
		size_t attributes,
		SearchQuery const* query)
		: files(files),
		attributes(attributes),
		query(new SearchQuery(*query))
	{ }
	//Copy constructor
	DirectorySearchResult(DirectorySearchResult& other) :files(other.files),attributes(other.attributes),query(other.query ? new SearchQuery(*other.query) : nullptr)
	{}
	//Move constructor
	DirectorySearchResult(DirectorySearchResult&& other)
	{
		files = std::move(other.files);
		attributes = other.attributes;
		query = other.query;
		other.query = nullptr;
	}
	//Copy assignment operator
	DirectorySearchResult& operator=(const DirectorySearchResult& other)
	{
		if (query == other.query)
			return *this;
		files = other.files;
		attributes = other.attributes;
		delete query;
		query = other.query ? new SearchQuery(*other.query) : nullptr;
		return *this;
	}
	//Move assignment operator
	DirectorySearchResult& operator=(DirectorySearchResult&& other)
	{
		files = std::move(other.files);
		attributes = other.attributes;
		std::swap(query, other.query);
		return *this;
		//query = other.query ? new SearchQuery(*other.query) : nullptr;
	}
	~DirectorySearchResult() { delete query; }

private:
	std::vector<std::string> files;
	size_t attributes;
	SearchQuery* query;
};

int main()
{
    return 0;
}

