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

  ~DirectorySearchResult() { delete query; }

  //Copy constructor
  DirectorySearchResult(const DirectorySearchResult& other):files(other.files),attributes(other.attributes),query(other.query ? new SearchQuery(*other.query) : nullptr)
  {}
  
  //Move constructor
  DirectorySearchResult(DirectorySearchResult&& other):files(std::move(other.files)),attributes(other.attributes)
  {
    query = other.query;
    other.query = nullptr;
  }
  
  //Copy assignment operator:
  DirectorySearchResult& operator=(const DirectorySearchResult& other)
  {
    if (this == other)
        return *this;
    files = other.files;
    attributes = other.attributes;
    delete query;
    query = new SearchQuery(*other.query);
    return *this
    
  }
  DirectorySearchResult& operator=(DirectorySearchResult&& other)
  {
    files = std::move(other.files);
    attributes = other.attributes;
    std::swap(query,other.query);
    return *this
    
  }
  
Class SearchQuery()
{
    int bullshit;
}
  
private:
  std::vector<std::string> files;
  size_t attributes;
  SearchQuery* query;
};

int main(int argv, char** argc[])
{
    return 0;
}