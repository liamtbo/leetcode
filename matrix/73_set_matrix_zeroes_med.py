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
    
"""
c++
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::vector<int> rows;
        std::vector<int> cols;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for (int i=0; i<rows.size(); i++) {
            int row = rows[i];
            for (int j=0; j<matrix[0].size(); j++) {
                matrix[row][j] = 0;
            }
        }
        for (int i=0; i<cols.size(); i++) {
            int col = cols[i];
            for (int j=0; j<matrix.size(); j++) {
                matrix[j][col] = 0;
            }
        }
    }
};
"""