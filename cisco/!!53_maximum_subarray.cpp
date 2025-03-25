#include <vector>
#include <numeric>
#include <iostream>
// #include <ostream>
using namespace std;



/* DOESNT WORK*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        going next i negative == exploring
            there might be higher ones that pos cancel out
        -2  [-2] -2
        1   [1] 1 // nums[i] > sum of previous sub arr, save
        -3  [1, -3] -2  // explore
        4   [4] 4 // nums[i] > sum of previous sub arr
        -1  [4,-1] 3 // explore
        2   [4,-1,2] 5 // explore, save
        1   [4,-1,2,1] 6 // explore, save
        -5  [4,-1,2,1,-5] 1 // explore, don't save
        4   [4,-1,2,1,-5,4] 5 // explore, don't save
        
        best_sub_nums = []
        exploration_sub = []

        for num in nums:
            if num > best_sub_num.accumulate + num:
                clear best_sub_nums
                best_sub_nums.append(num)
                clear exploration sub
                exploration_sub.append(num)
            else
                explortion_sub.append(num)
                if exploration_sub.accum > best_sub:
                    best_sub = exploration sub
        */
        vector<int> best_sub;
        vector<int> exploration_sub;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > accumulate(best_sub.begin(), best_sub.end(), 0) + nums[i]) {
                best_sub.clear();
                best_sub.push_back(nums[i]);
                exploration_sub = best_sub;
                
            } else {
                exploration_sub.push_back(nums[i]);
                if (accumulate(exploration_sub.begin(), exploration_sub.end(), 0) > accumulate(best_sub.begin(), best_sub.end(), 0)) {
                    best_sub = exploration_sub;
                }
            }
            cout << "iteration " << i << "\n\tbest_sub: ";
            for (const int num : best_sub) {
                cout << num << " ";
            }
            cout << endl;
        }
        return accumulate(best_sub.begin(), best_sub.end(), 0);
    }
};

int main() {
    vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
    int tmp = Solution().maxSubArray(input);
    cout << tmp << endl; 
}