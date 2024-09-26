class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int

        for each coin
            for each amount
                count = count how many times the coin goes into the amount
                remainder = whats left over after coins gone into amount as much as possible
                min(not using coin, count + count_count[remainder]) 
                
        """
        coins_count = [float('inf')] * (amount)
        coins_count[0] = 0
        for i in range(len(coins)):
            for j in range(1, amount):
                remainder = j
                count_i = 0
                while remainder >= coins[i]:
                    remainder -= coins[i]
                    count_i += 1
                if coins_count[j] > count_i + coins_count[remainder]:
                    coins_count[j] = count_i + coins_count[remainder]
        return coins_count[-1]
