#include <unordered_map>
#include <iostream>
using namespace std;

/*
stores elements using hashing
        Average     Worse-Case
search  O(1)        O(n)
insert  O(1)        O(n)
delete  O(1)        O(n)
travers O(n)        O(n)
*/


void unordered_map_ex() {
    unordered_map<string, int> food1;
    unordered_map<string, int> food2 = {
        {{"chipotle",1}, {"orange chicken",2}}
    };

    // insert
    food2.insert({"pizza", 0});

    // accessing element
    cout << food2["chipotle1"] << endl; // if key doesn't exist, inserts default value for key (0)
    cout << food2.at("chipotle1") << endl; // if key doesn't exist, throws exception (i think)

    // loop through keys and values
    for (auto key_value : food2) {
        cout << "key: " << key_value.first << endl;
        cout << "value: " << key_value.second << endl;
    }
    // Traverse using pointers
    for (auto it=food2.begin(); it != food2.end(); it++) {
        cout << it->first << ": " << it-> second << endl;
    }

    // update elements
    food2["orange_chicken"] = 10;
    food2.at("orange_chicken") = 40;

    // finding elements
    if (food2.find("pizza") == food2.end()) {
        cout << "doesn't exist" << endl;
    }

    // deleting elements
    food2.erase("pizza")


}

int main() {
    unordered_map_ex();
}