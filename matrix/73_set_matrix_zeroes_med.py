class Solution:
    def setZeroes(self, matrix) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    # turn col into 2's
                    for k in range(len(matrix)):
                        if matrix[k][j] != 0: matrix[k][j] = 2.5
                    # turns row into 2's
                    for k in range(len(matrix[0])):
                        if matrix[i][k] != 0: matrix[i][k] = 2.5
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 2.5: matrix[i][j] = 0
        return matrix