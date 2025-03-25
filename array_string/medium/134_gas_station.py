class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        gas_tank = 0
        start = 0
        deficit = 0
        for i in range(len(gas)):
            gas_tank += gas[i]
            gas_tank -= cost[i]
            if gas_tank < 0:
                deficit += gas_tank
                gas_tank = 0
                start = i + 1
            if i == len(gas) - 1 and gas_tank + deficit >= 0:
                return start
            if i == len(gas) - 1 and gas_tank + deficit < 0:
                return -1