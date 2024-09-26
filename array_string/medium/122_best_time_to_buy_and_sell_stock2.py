class Solution:
    def maxProfit(self, prices):
        """
        since order matters, i think we'll need some sort of greedy algo going from left to right
        maybe
        want to find the combination of the largest overlapping distances

        find the best single trade like in best time to buy/sell a stock 1
        within that range, sell the highes, buy the lows until we get to the top
        if last price isn't the end of the list
            repeat this process with range [best single trade range end, end of list]

        more simple then i thought
        buy every low, sell every high
        if flat:
            if next_i is lower then curr_i, don't buy
        if buy position on:
            don't sell if next_i is higher then curr_i
        """
        # TODO implement my sol ^
        profit = 0
        buy_price = prices[0]
        for i in range(1, len(prices) - 1):
            if prices[i-1] > prices[i] <= prices[i+1]:
                buy_price = prices[i]
            if prices[i-1] < prices[i] >= prices[i+1]:
                profit += prices[i] - buy_price
                buy_price = prices[i]
        if prices[-1] > buy_price:
            profit += prices[-1] - buy_price
        return profit

print(Solution().maxProfit([7,1,5,3,6,4]))