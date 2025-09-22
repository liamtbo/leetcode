
/*
time complextiy = O(n + (m+n)log(m+n)) -> (m+n)log(m+n)
memory complexity = O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=m; i<m+n ; i++) { // n
            nums1[i] = nums2[i - m];
        }
        sort(nums1.begin(), nums1.end()); // (m+n) log (m+n)
    }
};