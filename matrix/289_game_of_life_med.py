# this works, come back and recode it in C

class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        next_state = []
        row_len = len(board)
        col_len = len(board[0])
        for i in range(row_len): next_state.append([0] * col_len)

        for i in range(row_len):
            for j in range(col_len):
                cell = board[i][j]
                alive = 0
                for k in range(i-1, i+2):
                    for l in range(j-1, j+2):
                        # within range
                        if 0 <= k < row_len and 0 <= l < col_len:
                            # not cell coords
                            if not (k == i and l == j):
                                if board[k][l] == 1: alive += 1
                if cell and alive < 2: next_state[i][j] = 0
                elif cell and 2 <= alive <= 3: next_state[i][j] = 1
                elif cell and alive > 3: next_state[i][j] = 0
                elif not cell and alive == 3: next_state[i][j] = 1
                else: next_state[i][j] = cell
        return next_state
                
input1 = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
input2 = [[1,1],[1,0]]
expected_out = [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
print(Solution().gameOfLife(input2))
# assert Solution().gameOfLife(input) == expected_out