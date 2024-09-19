"""
take max out of everything in range X

start from back, find the farthest number that reaches you in whole list O(n)
from the number repeat process until you reach start of list O(n^2) X

start from beggining, take all numbers in range, add one point to each based on how 
far it is away from i, take jump thats max, if tied, take farthest
    a = [2,5,4,0,0,0,1] # -> works
    b = [1,3,0,0,3,1,0] # -> works
    c = [3,3,0,2,1] # -> works
    d = [7,0,0,0,6,0,0,1] # -> x
    
"""
class Solution:
    def jump(self, nums) -> int:
        near = far = jumps = 0

        while far < len(nums) - 1:
            farthest = 0
            for i in range(near, far + 1):
                farthest = max(farthest, i + nums[i])
            
            near = far + 1
            far = farthest
            jumps += 1
        
        return jumps
