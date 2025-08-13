#include <iostream> // cout cin endl
#include <string> // string type
#include <vector>
#include <algorithm> // distace, min_element
#include <map>
#include <unordered_map>
#include <sstream>
#include <queue>

using namespace std;
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

void string_ex();
void class_ex();
void mem_ex();
void vector_ex();
void queue_ex();

int main() {

    // string_ex();

    // class_ex();

    // mem_ex();

    // vector_ex();

    // int n = 5;
    // increment(n);
    // std::cout << n << std::endl;

    // auto lambda_ex = [&](int x, int y) {
    //     return x + y;
    // };
    // cout << lambda_ex(5,6) << endl;

}

void queue_ex() {
    std::queue<int> q;

    // Adding elements to the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Accessing the front and back elements
    std::cout << "Front: " << q.front() << "\n"; // 10
    std::cout << "Back: " << q.back() << "\n";   // 30

    // Removing elements from the queue
    q.pop();
    std::cout << "Front after pop: " << q.front() << "\n"; // 20

    // Checking if the queue is empty
    if (q.empty()) {
        std::cout << "Queue is empty\n";
    } else {
        std::cout << "Queue is not empty\n";
    }

    // Printing the size of the queue
    std::cout << "Queue size: " << q.size() << "\n";

    // clearing a queue
    queue<int>().swap(q);
}

// dictionaries
/*
Feature	            std::map	    std::unordered_map
Order of elements	Sorted by key	No particular order
Lookup time	        O(log n)	    O(1) (average)
Memory usage	    Less efficient	More efficient
*/
void dictionaries() {
    map<string, int> ages;

    unordered_map<string, int> grades;

    ages["Alice"] = 25;  // Add or update a key-value pair
    ages["Bob"] = 30;

    grades["Alice"] = 90;
    grades["Bob"] = 85;

    std::cout << "Alice's age: " << ages["Alice"] << std::endl;

    
    if (ages.find("Alice") == ages.end()) {
        std::cout << "Alice is not in the map.\n";
    } else {
        std::cout << "Alice is in the map.\n";
    }
    
    // Using at() for safer access
    try {
        std::cout << "Bob's grade: " << grades.at("Bob") << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Key not found: " << e.what() << std::endl;
    }

    // Iterating through std::map
    for (const auto& [key, value] : ages) {
        std::cout << key << ": " << value << std::endl;
    }

    // Iterating through std::unordered_map
    for (const auto& pair : grades) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }


    ages.erase("Bob");

 // 1. Get the size of the dictionary
    std::cout << "Size of ages map: " << ages.size() << std::endl;
    std::cout << "Size of grades unordered_map: " << grades.size() << std::endl;

    // 2. Check if a dictionary is empty
    std::cout << "Is ages map empty? " << (ages.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Is grades unordered_map empty? " << (grades.empty() ? "Yes" : "No") << std::endl;

    // 3. Check if a key exists using count()
    std::cout << "Does 'Alice' exist in ages map? " 
              << (ages.count("Alice") ? "Yes" : "No") << std::endl;
    std::cout << "Does 'Charlie' exist in grades unordered_map? " 
              << (grades.count("Charlie") ? "Yes" : "No") << std::endl;

    // 4. Clear all elements from the dictionary
    ages.clear();
    grades.clear();

}


// strings
void string_ex() {
    string myStr = "codeine crazy";
    myStr[7] = '$';
    
    myStr.append("drinking");
    myStr.append(1, 'f'); // need to say how many chars when adding just one
    myStr += " crazy";
    myStr += 'f';

    string str1 = "big checks";
    str1.insert(3, "$");

    int n = str1.size();
    n = str1.length(); // does same thing

    if (str1[0] == 'h') {cout << "True" << endl;}

    // starts at index 7, + len of 5
    string sub = str1.substr(4, 5);

    string str2 = "chunk melon";
    // reversing option 1
    reverse(str2.begin(), str2.end());
    // reversing option 2
    for (int i=0; i<str2.size() / 2; i++) {
        swap(str2[i], str2[str2.size() - 1 - i]);
    }

    // breaking up string based on " "
    string sentence = "hello darkness my old friend";
    istringstream iss(sentence); // allows us to treat string as a stream
    string word;
    vector<string> words;

    while (getline(iss, word, ' ')) {
        if (word.size() == 0) { continue; } // double spaces "  " skipped
        words.push_back(word);
    }

    string word1 = "new ba11sack";
    if (isalpha(word1[0])) {cout << "letter";}
    if (isdigit(word1[6])) {cout << "number";}
    
    char tmp = 'a';
    tmp = toupper(tmp);
    tmp = tolower(tmp);
}

/*
Lists vs Vectors
Operation	                    std::vector	                                    std::list
Insertion/Deletion at Non-End	O(n) (due to shifting elements)	                O(1) (just pointer updates)
Insertion/Deletion at End	    O(1) (amortized, except for reallocation)	    O(1)
Random Access               	O(1) (supports direct indexing)	                O(n) (requires traversal via iterators)
*/

/* 
pointer on stack, memory on heap
    8 bytes for pointer to memory on heap
    8 bytes for current number of elements in the vecotr
    8 bytes for capacity of vector
when vector is destroyed, heap in auto freed
iterator
    generalization of a pointer that allows one to access elements, move to next element, perform ops
*/

void vector_ex() {
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2(5, 10); // 5 elements, all with value of 10
    vector<int> vec3;        // Empty vector, no heap memory allocated yet

    vec3.push_back(1);
    vec3.push_back(2);
    vec3.push_back(3);
    vec3.push_back(4);

    vec3.pop_back(); // Pops the last element (4)

    cout << vec3[0] << endl;    // Access without bounds checking
    cout << vec3.at(0) << endl; // Access with bounds checking

    // Shifts all elements to the right of the insertion index by 1
    vector<int> vec4 = {1,2,3,4};
    
    for (const int &val : vec4) {
        cout << val << " ";
    }
    cout << endl;

    auto middle = vec4.begin() + vec4.size() / 2;    
    vec4.insert(middle, 999); // Insert at the beginning

    vec4.erase(vec4.begin() + vec4.size() / 2);
    for (const int &num : vec4) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> vec5 = {1,2,3,4,5};
    vector<int>::iterator start = vec5.begin();
    vector<int>::iterator end = vec5.end() - 1; // end point to one past last element

    vec4.clear();
    
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};
    
    auto min_elem_iterator = min_element(matrix[1].begin(), matrix[1].end());
    int min_elem_index = distance(matrix[1].begin(), min_elem_iterator);
    cout << min_elem_index << " " << *min_elem_iterator << endl;
     // --------------------------------
    // removing first element
    vector<int> vec6 = {1,2,3,4,5,6};
    vec6.erase(vec6.begin()); // O(1) best time, O(n) worse and average

    if (!vec6.empty()) {
        move(vec6.begin() + 1, vec6.end(), vec6.begin());
        vec6.pop_back();
    }
    // swap back and front, then pop back
    // for unordered vectors
    if (!vec6.empty()) {
        swap(vec6.front(), vec6.back());
        vec6.pop_back();
    }
    // --------------------------------
    // creating a slice
    // not a function!
    vector<int> vec7 = {1,2,3,4,5,6,7};
    vector<int> slice(vec7.begin() + 1, vec7.end() - 1);

    // findng index of a value
    vector<int> vec8 = {1,2,3,4,5};
    auto it = find(vec8.begin(), vec8.end(), 3); // rets an iterator
}


void deque() {
    vector<int> v = {1,2,3,4,5};
    std::deque<int> d(v.begin(), v.end());
}

void mem_ex() {
    int *p = new int(42);
    std::cout << *p << std::endl;
    delete p;
}

void class_ex() {
    Rectangle r;
    r.setDimensions(5, 6);
    std::cout << "Area: " << r.area() << std::endl;
}


