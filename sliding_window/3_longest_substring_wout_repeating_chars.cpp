

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if (s.size() == 0) return 0;
            if (s.size() == 1) return 1;
            int max_len = 1;
            int lp = 0; int rp = 0;
            map<char, int> substring;
            for (char c = 'a'; c <= 'z'; c++) substring[c] = 0;
    
            substring[s[0]] = 1;
            
            // while loop still rp get's to end, this doesn't work come back bbbbabcd
            while (rp != s.size() - 1) {
                // extend right side window by 1
                rp++; 
                // check if new rp char already exists in substring window
                if (substring[s[rp]] > 0) {
                    
                    // add 1 to left pointer until the duplicate char doesn't exist anymore
                    while (substring[s[rp]] > 0) { 
                        substring[s[lp]] -= 1; // should always equal 0 after this op
                        lp++;
                    }
                }
                // we're going to resize window so save current window size
                if (rp - lp + 1 > max_len) max_len = rp - lp + 1; // rp -1 bc rp is now one ahead of the old window and +1 bc the left char is needs to be included in the length
                substring[s[rp]] += 1; // should alwyas equal 1 after this op
            }
            return max_len;
        }
    };