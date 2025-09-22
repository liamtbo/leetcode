#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;



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
