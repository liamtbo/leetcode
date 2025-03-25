#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> // reverse
#include <map>
#include <unordered_map>

using namespace std;


int main() {
    vector<int> vec = {1,2,3,4,5};
    vector<int> slice(vec.begin() + 1, vec.end() - 1);
    for (int i : slice) {
        cout << i << endl;
    }
}