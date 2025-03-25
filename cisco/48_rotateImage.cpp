#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
        flip diagnol - bottom left corner to upper right corner
        mirror it horizontally
        (0,2) -> (2,0) -> (0,0)
        */
        // flip diagnoally
        int n = matrix.size();
        for (int i=0; i<n; i++) {
            // loop over rows
            for (int j=0; j<i+1; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        // flip horizontally
        for (int i=0; i<n; i++) {
            for (int j=0; j<ceil(n / 2); j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = tmp;
            }
        }
    }
};