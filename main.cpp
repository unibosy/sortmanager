#include "people.h"
#include "common.h"
#include "utility.h"
#include "algorithm"

#include "string"
#include "iostream"
#include "vector"
#include "memory"
using namespace std;

void addPeople(std::vector<shared_ptr<People>>& pvec)
{
  //smart pointer will delete itself when out region if no one refer to it.
  shared_ptr<People> people(new People);
  people.get()->setName("Jack");
  people.get()->setAge(20);
  people.get()->setGender(0);
  people.get()->setHeight(170);

  shared_ptr<People> people1(new People);
  people1.get()->setName("Tom");
  people1.get()->setAge(10);
  people1.get()->setGender(0);
  people1.get()->setHeight(100);

  shared_ptr<People> people2(new People);
  people2.get()->setName("Mary");
  people2.get()->setAge(18);
  people2.get()->setGender(1);
  people2.get()->setHeight(165);

  pvec.push_back(people);
  pvec.push_back(people1);
  pvec.push_back(people2);
  cout << "end add people" << endl;

}


template<typename T1, typename T2>
bool doSortByID1(T1& t1, T2& t2)
//bool doSortByID1(People*& t1, People*& t2)
{
  return t1->age() < t2->age();
}
template<typename T1>
bool doSortByID2(T1& t1)
//bool doSortByID1(People*& t1, People*& t2)
{
  return true;
  //return t1->age() < t2->age();
}

//sort using a custom function object so sort can determine which template function to use.
struct {
  template<typename T1, typename T2>
  bool operator()(T1& a, T2& b)
  {
    return a->age() < b->age();
  }
} custoLess;

struct {
  template<typename T>
  //void operator()(const shared_ptr<People> const& t)
  void operator()(const T& t)
  {
    cout << "value=" << t.get()->age() << endl;
  }
} print1;

int main()
{
  std::vector<shared_ptr<People>> peopleVec;
  addPeople(peopleVec);
  std::sort(peopleVec.begin(), peopleVec.end(), /*Utility::*/custoLess);

  for_each(std::begin(peopleVec), std::end(peopleVec), print1);

  getchar();
  return 0;
}



