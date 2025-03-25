#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == val) {
                nums[i] = 51;
            } else {
                count++;
            }
        }
        sort(nums.begin(), nums.end());
        return count;
    }
};

int main() {
    vector<int> input = {0,1,2,2,3,0,4,2};
    int tmp = Solution().removeElement(input, 2);
    for (const int num : nums) {
        cout << "num: " << num << endl;
    }
    
}