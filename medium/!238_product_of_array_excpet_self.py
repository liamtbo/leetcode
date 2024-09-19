class Solution:
    def productExceptSelf(self, nums):
        length = len(nums)
        prefix = 1
        postfix = 1
        result = [0] * length
        for i in range(length):
            result[i] = prefix
            prefix *= nums[i]
        for i in range(length-1, -1, -1):
            result[i] *= postfix
            postfix *= nums[i]
        return result