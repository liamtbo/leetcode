
/*
time complexity O(n + (m+n)log(m+n))
space comlexity O(1)*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto nums1_p = nums1.begin() + m;
        int nums2_count = 0;
        while (nums2_count != n) {
            *nums1_p = nums2[nums2_count];
            nums2_count++;
            nums1_p++;
        }
        sort(nums1.begin(), nums1.end());
    }
};