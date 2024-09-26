class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums) == 0:
            return []
        if len(nums) == 1:
            return [str(nums[0])]
        ret_list = []
        start = nums[0]
        range_tracker = start + 1
        for i in range(1, len(nums)):
            if nums[i] != range_tracker:
                # if no range was created
                if start + 1 == range_tracker:
                    ret_list.append(str(start))
                else:
                    ret_list.append(str(start) + "->" + str(nums[i-1]))
                if i == len(nums) - 1:
                    ret_list.append(str(nums[i]))
                start = nums[i]
                range_tracker = start + 1
                continue

            if nums[i] == range_tracker:
                range_tracker += 1
                if len(nums) - 1 == i:
                    ret_list.append(str(start) + "->" + str(nums[i]))

        return ret_list