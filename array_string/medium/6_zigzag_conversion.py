class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows <= 1: return s
        d = {}
        for i in range(numRows):
            d[i] = ""
        going_down = 1
        row = 0
        for letter in s:
            d[row] += letter
            if row == numRows-1:
                going_down = 0 # now we're going up so decrement row
            if row == 0:
                going_down = 1 # now we're going to increment row
            row += 1 if going_down else -1
        ret_str = ""
        for value in d.values():
            ret_str += value
        return ret_str

"""
C++
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        int going_down = 1;
        int row = 0;
        std::vector<std::string> word_rows(numRows);
        for (int i=0; i<s.length(); i++) {
            word_rows[row].append(1, s[i]);
            if (row == numRows-1) {
                going_down = 0;
            }
            if (row == 0) {
                going_down = 1;
            }
            if (going_down) {row += 1;} else {row -= 1;}
        }
        for (int i=1; i<numRows; i++) {
            word_rows[0].append(word_rows[i]);
        }
        return word_rows[0];
    """