class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        """
        cant brute force bc O(n^2)
        so some kind of strategy needs to be made so that we don't try every combination
        need a filter

        is there a pre-requisite for a number such that if it added to something else it would be div by 60?

        can i loop through it multiple times, extracting info the first and counting the next?

        since we don't need to ret the pairs, maybe the solution can be derived from some kind of total summ and then subtractions?

        solution:
        create a list with the remainders of each time % 60
        sort the list
        count zeros
        perform (total zeros choose 2) combination equation, add result to pair_count
        same thing needs to be done with 30s
        use pointers
            left pointer starts at first non-zero of remainder list
            right pointer starts on far right of remainder list
        as you work in from both sides with pointers
            for each pair group
                how many on left side, count how many are on right side
                multiply these numbers and add to pair_count

        [1,2,3] = 3 = odd -> 3/2 = 1.5 -.> floor 1

        """
        # creata a parallel list distribution
        time_len = len(time)
        number = [0]
        count = [0]
        for i, num_i in enumerate(range(time_len)):
            remainder = time[num_i] % 60
            if i == 0:
                number[0] = remainder
                count[0] += 1
                continue
            if remainder == number[-1]:
                count[-1] += 1
            else:
                number.append(remainder)
                count.append(1)
                    
        left_pointer = 0
        right_pointer = time_len - 1

        pair_count = 0
        while 1:
            if number[left_pointer] == 0:
                pair_count += math.factorial(count[left_pointer]) \
                / (math.factorial(2) * math.factorial(count[left_pointer] - 2))
                left_pointer += 1
            
            # case 1: left and right are a pair [0,10,20,30,30,40,50]
            if number[left_pointer] + number[right_pointer] == 60:
                left_pointer_i += 1
                right_pointer_i -= 1
                pair_count += count[left_pointer] * count[right_pointer]
            # case2: left and right are not a pair, and [10, 10, 20, 30, 40]
            if number[left_pointer] < (60 - number[right_pointer]):
                left_pointer += 1
            # case3: left and right are not a pair and [20, 30, 40, 50, 50]
            if number[right_pointer] > (60 - number[left_pointer]):
                right_pointer_i -= 1
        return pair_count
    
    # TODO need to deal with 30 exists case, and 30 doesn't exist case