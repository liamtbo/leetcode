#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


/*
Operation	Time Complexity
Insert at back	O(1)
Insert at front	O(1)
Insert at arbitrary position when the iterator is known. O(1)
Insert at arbitrary position when the iterator is unknown. O(n)
Remove from back	O(1)
Remove from front	O(1)
Remove from arbitrary position when the iterator is known. O(1)
Remove from arbitrary position when the iterator is unknown. O(n)
Access first element.	O(1)
Access last element	O(1)
Access element at any position	O(n)
Find element by value	O(n)
Traversing the list O(n)
*/
void list_ex() {
    // Creating an empty list
    list<int> l1;
    // Creating list from initializer list
    list<int> l2 = {1, 3, 4, 2, 5};
    // Creating list with given size and
    // initial value
    list<int> l3(5, 9);

    // inserting
    list<int> l = {3, 2};
    l.push_back(5);
    l.push_front(1);
    auto it = l.begin();
    advance(it, 2);
    l.insert(it, 4);

    // accessing
    list<int> l = {1, 3, 4, 2, 5};
    // Accessing first and last elements
    cout << l.front() << endl;
    cout << l.back() << endl;
    // Access third element
    cout << *next(l.begin(), 2);

    // updating elements
    list<int> l = {1, 3, 4, 2, 5};
    l.front() = 11;
    // Move iterator to the second element
    auto it = l.begin();
    advance(it, 2);
    // Update the value using iterator
    *it = 10;

    // finding elements
    list<int> l = {1, 3, 4, 2, 5};
    // Finding 4
    auto it = find(l.begin(), l.end(), 4);
    if (it != l.end()) cout << *it;
    else cout << "Element Not Found!";

    // traversing
    list<int> l = {1, 3, 4, 2, 5};
    // Traversing using iterators
    for (auto it = l.begin(); it != l.end(); ++it) 
        cout << *it << " ";

    // Deletng elements
    list<int> l = {1, 3, 4, 2, 5};

    // Deleting last element
    l.pop_back();
    // Deleting first element
    l.pop_front();
    // Deleting third element
    auto it = l.begin();
    advance(it, 2);
    l.erase(it);
}
