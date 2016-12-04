#include "utility.h"
#include "base.h"
//defalt <
template<typename T1, typename T2>
void Utility::doSortByID(T1& t1, T2& t2/*, SortType st*/)
{
  using People::age();
  return t1->age() < t2->age();
}
