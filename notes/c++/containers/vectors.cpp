#include <vector>
#include <iostream> // cout, endl
#include <algorithm> // distace, min_element
using namespace std;

/*
Operation	                                    Average             Worst Case
push_back(x)	Add element to end              Amortized O(1)	    Occasionally O(n) when resizing
pop_back()	Remove last element	                O(1)	            No reallocation
insert(pos, x)	Insert at arbitrary position	O(n)	            Shifts elements after pos
erase(pos)	Remove one element	                O(n)	            Shifts elements after pos
erase(first, last)	Erase range	                O(n)	            Shifts remaining elements
clear()	Remove all elements	                    O(n)	            Calls destructor for each element
*/
void vector_ex() {
    // Vector Initialization
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2(5, 10);  // 5 elements, all set to 10
    vector<int> vec3;         // Empty vector

    // Adding and removing elements to end of vector
    vec3.push_back(1);
    vec3.push_back(2);
    vec3.push_back(3);
    vec3.push_back(4);
    vec3.pop_back(); // Removes the last element (4)

    // Accessing elements
    cout << vec3[0] << endl;    // No bounds checking
    cout << vec3.at(0) << endl; // With bounds checking

    // replacing elemenets
    vec3[0] = 10;

    // Inserting and erasing in the middle
    vector<int> vec4 = {1, 2, 3, 4};
    for (int val : vec4) cout << val << " ";
    cout << endl;

    auto middle = vec4.begin() + vec4.size() / 2;
    vec4.insert(middle, 999); // Insert in the middle, does not replace element!

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