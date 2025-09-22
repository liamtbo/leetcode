
#include <iostream>
#include <unordered_set>
using namespace std;

// ------------------------------------------
/*
Operation	Time Complexity
Insert an element	O(1) (average)
Delete an element	O(1) (average)
Access element by position  O(n)
Find element by value	O(1) (average)
Traverse the set	O(n)
*/
void unordered_sets_ex() {
    // Creating an unordered_set of integers
    unordered_set<int> us = {1, 2, 3, 4, 5};

    for (auto x : us) 
        cout << x << " ";

    // Create an empty unordered_set
    unordered_set<int> us1;
  
    // Initialize an unordered_set using
    // using intializer list
    unordered_set<int> us2 = {1, 2, 3, 4, 5};

    // Insert elments using insert()
    unordered_set<int> us;
    us.insert(3);
    us.insert(1);
    us.insert(2);

    // Accessing third element
    unordered_set<int> us = {1, 2, 3, 4, 5};
    auto it = next(us.begin(), 2);
    cout << *it;

    // 3. Updating Elements
    // In unordered set, the value of the elements cannot be changed after it 
    // is inserted.

    // Finding 4
    unordered_set<int> us = {1, 2, 3, 4, 5};
    auto it = us.find(4);
    if (it != us.end()) cout << *it;
    else cout << "Element not Found!";

    // Delete element by value
    unordered_set<int> us = {1, 2, 3, 4, 5};
    us.erase(5);
    // Delete element by position
    us.erase(us.begin());
}
