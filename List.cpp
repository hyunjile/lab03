#include <string>
#include <iostream>

using namespace std;

const int defaultSize = 100;

class List {
public: 
  List();
  ~List();
  void push_back(string val);
  string at(int loc) const;
  int size() const;

private:
  string* data_;
  int size_;
};

List::List()
{
  size_ = 0;
  data_ = new string [defaultSize];
}

List::~List()
{
  size_ = 0;
  delete [] data_;
}

void List::push_back(string val)
{
  data_[size_++] = val;
}

string List::at(int loc) const
{
  return data_[loc];
}

int List::size() const
{
  return size_;
}

