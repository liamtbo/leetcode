/*
time complexity: O(n)
memory complexity: O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump_gas = nums[0];
        for (int i=1; i<nums.size(); i++) {
            jump_gas -= 1;
            if (jump_gas < 0) { return false;}
            if (nums[i] > jump_gas) { jump_gas = nums[i]; }
        }
        return true;
    }
};