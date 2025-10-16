#include <vector>;
#include <unordered_set>
using namespace std;

/*
time complexity: 
    best_case: O(n)
    worst case: O(n^2)
memory compleixty:
    best_case: O(n) // dups holds n elements
*/

class Solution {
public:
    int removeDuplicates(vector<int> nums) {
        unordered_set<int> dups = {};
        int i = 0;
        for (int num : nums) { // O(n)
            if (dups.find(num) == dups.end()) { // ammortized: O(1), worse-case: O(n) (hash collisions)
                dups.insert(num); // ammortized: O(1), worse-case: O(n) (hash collisions)
                nums[i] = num; // O(1)
                i++;
            }
        }
        return i;
    }
};
