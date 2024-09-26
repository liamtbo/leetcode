class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sub = [1] * len(nums)
        for i in range(1, len(nums)):
            for j in range(0, i):
                if nums[j] < nums[i]:
                    if sub[j] + 1 > sub[i]: sub[i] = sub[j] + 1
        return max(sub)
"""
C
int lengthOfLIS(int* nums, int numsSize) {
    int arr[numsSize];
    for (int i=0; i<numsSize; i++) {
        arr[i] = 1;
    }
    for (int i=1; i<numsSize; i++) {
        for (int j=0; j<i; j++) {
            if (nums[j] < nums[i] && arr[j] + 1 > arr[i]) {
                arr[i] = arr[j] + 1;
            }
        }
    }
    int max = 0;
    for (int i=0; i<numsSize; i++) {
        max = (max < arr[i]) ? arr[i] : max;
    }
    return max;
}
"""