#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) {
            return s;
        }

        auto expand_from_center = [=](int left_pointer, int right_pointer) {
            while(left_pointer >= 0 && right_pointer < s.length() && s[left_pointer] == s[right_pointer]) {
                left_pointer--; right_pointer++;
            }
            // left pointer +1 bc while loop went too far, needs to go back one step
            // right pointe - left_pointer - 1 bc substr needs # of chars to go after first agrument
            // and -1 bc while loop goes to far to break so needs to go back one step
            return s.substr(left_pointer+1, right_pointer - left_pointer - 1);
        };

        string max_pal = "";

        for (int i=0; i<s.length(); i++) {
            string odd_substr = expand_from_center(i, i);
            if (odd_substr.length() > max_pal.length()) {
                max_pal = odd_substr;
            }

            string even_substr = expand_from_center(i, i+1);
            if (even_substr.length() > max_pal.length()) {
                max_pal = even_substr;
            }
        }

        return max_pal;
    }
};