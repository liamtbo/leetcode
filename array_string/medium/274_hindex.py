"""
How I thought through the problem:
    since h-index can be any number, we need to test every single number, 
    leading me to update test_val one point at a time.
    had the potential option of ascending or descending test_val, ascending was better
    choice bc you could act greedily and choose the new higher test_val that worked.
    we know for a sure h_val could def not be over max(citations) so for looped over
    the lists
"""

class Solution: 
    def hIndex(self, citations) -> int:
        """sol:
        if len of list from current test val on is >= test value
            update h to test val and increase test val by one
        if test val is now greater then current list[i]
            then take a step down the list
        if test val is still smaller then list[i]
            update h val to test val
        [0,1,3,5,6]
        """
        citations.sort()
        h_val = 0
        test_val = 0
        for i in range(len(citations)):
            while test_val <= citations[i]:# can't jump to next in list bc of if cond below
                if test_val <= len(citations[i:]):
                    h_val = test_val
                test_val += 1
        return h_val
