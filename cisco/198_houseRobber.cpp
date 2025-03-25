#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> value(nums.size());
        value[0] = nums[0]; // greatest value to left of index 0 is index 0
        value[1] = max(nums[0], nums[1]); // at index one,can only choose between house 0 or 1
        for (int i=2; i<nums.size(); i++) {
            value[i] = max(value[i-2] + nums[i], value[i-1]);
        }
        return value[nums.size() - 1];

    }
};