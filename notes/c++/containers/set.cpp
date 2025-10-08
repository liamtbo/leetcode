/*
implemented with red-black-trees
searching O(log n)
insertion O(log n) + Rebalance
deletion O(log n) + Rebalance
Automatically avoids duplicates

elements always sorted in non-ascending order by default
operations take longer then unordered_set, because values are sorted
*/

#include <iostream>
#include <set>
using namespace std;

void set_ex() {
    // inserting elements
    set<int> s = {2,3};
    s.insert(1);

    // searching elements
    set<int> s = {1,2,3};
    auto it = s.find(1);
    if (it != s.end()) {
        cout << "element found: " << *it << endl;
    }

    // does element exist
    if (s.count(2))
        cout << "2 exists in the set" << endl;

    // traverse set
    for (auto x : s)
        cout << x << " " << endl;
    
    // traverse using iterators
    for (auto it = s.begin(); it != s.end(); it++) 
        cout << *it << endl;

    // erase
    s.erase(2); // delete by value
    s.erase(s.begin()); // erase by iterator
    
}