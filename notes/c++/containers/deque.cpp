
#include <iostream>
#include <deque>
using namespace std;

/*
Operation	Time Complexity
Insert at back	O(1) amortized
Insert at front	O(1) amortized
Insert at arbitrary position O(n)
Remove from back	O(1) amortized
Remove from front	O(1) amortized
Remove from arbitrary position O(n)
Access elements at any position using index	O(1)
Update elements at any position using index	O(1)
Iterate the deque	O(n)
*/
void deque_ex() {
    // Creating an empty deque
    deque<int> dq1;
    // Creating a deque with default size and value
    deque<int> dq2(3, 4);
    // Creating a deque from an initializer list
    deque<int> dq3 = {1, 4, 2, 3, 5};

    // looping through
    for (auto x: dq1) {
        cout << x << " ";
    }
    cout << '\n';
    for (int i = 0; i < dq1.size(); i++) 
    cout << dq1[i] << " ";

    // inserting elements
    deque<int> dq = {1, 4, 2};
    // Inserting elements at back and front
    dq.push_back(5);
    dq.push_front(0);
    // Insert element at third position
    auto it = dq.begin() + 2;
    dq.insert(it, 11);

    deque<int> dq = {1, 4, 2, 3, 5};

    // Accessing elements
    cout << dq[2] << endl;
    cout << dq.front() << endl;
    cout << dq.back();

    // Updating Elements
    deque<int> dq = {1, 4, 2, 3, 5};
    dq[2] = 8;

    // deleting elements
    deque<int> dq = {1, 4, 2, 3, 5};
    dq.pop_back();
    dq.pop_front();
    dq.erase(dq.begin());
}