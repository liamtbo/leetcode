#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> luckyNums;

        for (int i=0; i<matrix.size(); i++) {
            // find index of smallest int in row i
            auto min_iter = min_element(matrix[i].begin(), matrix[i].end());
            int min_index = distance(matrix[i].begin(), min_iter);

            // loop through col of lowest number in row
            int no_lucky_nums_in_row = 0;
            for (int j=0; j<matrix.size(); j++) {
                // if there's a larger number in the col, then *min_iter isn't a lucky number
                if (matrix[j][min_index] > *min_iter) {
                    no_lucky_nums_in_row = 1;
                    break;
                }
            }
            if (no_lucky_nums_in_row == 0) {
                luckyNums.push_back(matrix[i][min_index]);
            }
        }
        return luckyNums;
    }
};