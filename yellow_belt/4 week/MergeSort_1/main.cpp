/*
Write a template function MergeSort that takes two iterators of template type RandomIt and sorts the range specified by them using merge sort. It is guaranteed that:

Iterators of type RandomIt are functionally similar to iterators of vectors and strings, meaning they can be compared using the operators <, <=, >, and >=, as well as be subtracted and added to numbers;
Sortable objects can be compared using the < operator."


Algorithm:
The classical merge sort algorithm looks as follows:

1. If the range contains fewer than 2 elements, exit the function.
2. Create a vector containing all the elements of the current range.
3. Divide the vector into two equal parts. (In this problem, it's guaranteed that the length of the provided range is a power of two, so the vector can always be divided into two equal parts.)
4. Call the MergeSort function for each half of the vector.
5. Use the merge algorithm to merge the sorted halves, replacing the original range with the resulting sorted range.

You must implement this exact algorithm and no other: the testing system will verify that you perform these actions with the elements precisely.

*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;


template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){


  if( distance(range_begin,range_end) < 2){
    return;
  } else{
    vector<typename RandomIt::value_type> v(range_begin, range_end);
    RandomIt mid_it = v.begin() + v.size()/2;

    MergeSort(v.begin(), mid_it);
    MergeSort(mid_it, v.end());

    merge(v.begin(), mid_it, mid_it, v.end(), range_begin);

  }

  

}



 


int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}