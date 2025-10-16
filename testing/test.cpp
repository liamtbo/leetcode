

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8};
    vector<int> slice1(nums.end()-4, nums.end());
    vector<int> slice2(nums.begin(), nums.end()-4);
    for (int num : slice1) {
        cout << num << endl;
    }
    for (int num : slice2) {
        cout << num << endl;
    }
}