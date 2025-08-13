#include <iostream> // cout cin endl
#include <string> // string type
#include <vector>
#include <algorithm> // distace, min_element
#include <map>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <list>
#include <unordered_set>

using namespace std;

/*
** not chatgpt, sourced from geeks4geeks **
Sequence Containers (store elements in order you inserted them):
    These store items in a linear order like arrays or lists.
    Container | Description | Typical Use
    std::vector | Dynamic array | Most common — fast access, resizeable
    std::deque | Double-ended queue | Fast insert/remove at both ends
    std::list | Doubly-linked list | When you need lots of insertions/removals in the middle

Associative Containers (store and auto sort elements with fast lookup (hash))
    Container | Description | Typical Use
    std::set | Unique sorted elements | Keep elements sorted, avoid duplicates
    std::map | Key-value pairs, sorted by key | O(logn) ops, Dictionary with sorted keys

Unordered (Hash-Based) Containers (faster on average):
    Container | Description | Typical Use
    std::unordered_set | Unique elements, no order | O(1) search, insert, delete, no sorting
    std::unordered_map | Key-value pairs, no order | O(1) Most used for hashtable/dictionary

MISC
    std::stack – LIFO container adapter
    std::queue – FIFO container adapter
    std::deque - Double-ended queue
    std::priority_queue – Heap-based, fast max/min lookup

*/

// ------------------------------------------

/*
Operation	Time Complexity
Insert an element at the end	O(1) (amortized)
Insert an element somewhere in the middle	O(n)
Delete an element from the end	O(1)
Delete an element from somewhere in the middle	O(n)
Access an element by index	O(1)
Traverse the vector	O(n)
Find an element by value O(n)
*/
void vector_ex() {
    // Vector Initialization
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2(5, 10);  // 5 elements, all set to 10
    vector<int> vec3;         // Empty vector

    // Adding and removing elements
    vec3.push_back(1);
    vec3.push_back(2);
    vec3.push_back(3);
    vec3.push_back(4);
    vec3.pop_back(); // Removes the last element (4)

    // Accessing elements
    cout << vec3[0] << endl;    // No bounds checking
    cout << vec3.at(0) << endl; // With bounds checking

    // Inserting and erasing in the middle
    vector<int> vec4 = {1, 2, 3, 4};
    for (int val : vec4) cout << val << " ";
    cout << endl;

    auto middle = vec4.begin() + vec4.size() / 2;
    vec4.insert(middle, 999); // Insert in the middle

    vec4.erase(vec4.begin() + vec4.size() / 2); // Erase from the middle
    for (int num : vec4) cout << num << " ";
    cout << endl;

    // concatenating two vector
    vector<int> vecA = {1, 2, 3};
    vector<int> vecB = {4, 5, 6};
    vecA.insert(vecA.end(), vecB.begin(), vecB.end()); // Concatenate vecB to vecA

    // Iterator example
    vector<int> vec5 = {1, 2, 3, 4, 5};
    auto start = vec5.begin();
    auto end = vec5.end() - 1; // Points to last element

    // Clear a vector
    vec4.clear();

    // 2D vector and finding min element
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    auto min_it = min_element(matrix[1].begin(), matrix[1].end());
    int min_index = distance(matrix[1].begin(), min_it);
    cout << min_index << " " << *min_it << endl;

    // Removing first element and other tricks
    vector<int> vec6 = {1, 2, 3, 4, 5, 6};
    vec6.erase(vec6.begin()); // Removes first element (shifts everything left)

    if (!vec6.empty()) {
        // Shift elements left manually (alternative to erase)
        move(vec6.begin() + 1, vec6.end(), vec6.begin());
        vec6.pop_back(); // Remove duplicate at end
    }

    if (!vec6.empty()) {
        // Fast remove from middle or front if order doesn't matter
        swap(vec6.front(), vec6.back());
        vec6.pop_back();
    }

    // Slicing a vector (not built-in, done with iterators)
    vector<int> vec7 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> slice(vec7.begin() + 1, vec7.end() - 1); // {2, 3, 4, 5, 6}

    // Finding the index of a value
    vector<int> vec8 = {1, 2, 3, 4, 5};
    auto it = find(vec8.begin(), vec8.end(), 3);
    if (it != vec8.end()) {
        int index = distance(vec8.begin(), it);
        cout << "Found 3 at index: " << index << endl;
    }

    // sorting a vector
    vector<int> vec9 = {1, 2, 3, 4, 5};
    sort(vec9.begin(), vec9.end()); // O(n log n) time complexity
}

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

// ------------------------------------------------------



// ------------------------------------------------------


/*
Feature	                struct	                        class
Default Access Modifier	public	                        private
Encapsulation	        Generally minimal	            Encouraged
Typical Usage	        Plain Data Structures (PODs)    Encapsulated Objects with Behavior
*/
/* use structs when you primarily need a simple data structure with minimal
encapsulation and no strict enforecment of asbtraction*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};
/* use class when you want strong encapsulation, data hiding, and object oriented
principles such as inheritance and polymorphism*/
class Rectangle {
    private:
        int width, height;
    
    public:
        void setDimensions(int w, int h) {
            width = w;
            height = h;
        }

        int area() {
            return width * height;
        }
};

// ------------------------------------------------------
