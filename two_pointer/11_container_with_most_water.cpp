class Solution {
    public:
        int maxArea(vector<int>& height) {
            /*
                
                this algorithm is based off a couple facts
                    n^2 is not allowed for sol
                    these two pointer problems often involve starting from opposite sides
                    5x5 != 4x6 != 3x7
                        so no height vs x-axis distance calculation can be used (likely)
                    if the left container side is larger then right container side, and if the next side to the left of the current right side is smaller then current right side, it's impossible for area to be larger if right side were to move in one
                    if the next one in from the right side is larger, the area could be bigger
    
                start pointer_l at begginning of array
                start pointer_r at end of array
                max_area = calculate area
                if p_l > p_r
                    prev_pr_height = store current
                    move p_r left by one until pr height > prev_pr_height
                if pl == pr
                    randomly move one
                else
                    prev_pl_height = store current
                    move p_l right by one until pl height > prev_pl_height
                calc area
                if area > max_area, update max_area
                loop until pr is pl
                return max_area
            */
            auto lp = height.begin();
            auto rp = height.end() - 1;
            int max_area = (rp - lp) * min(*lp, *rp);
            while (lp != rp) {
                if (*lp >= *rp) {
                    rp--;
                } else {
                    lp++;
                }
                int max_explore = (rp - lp) * min(*lp, *rp);
                if (max_explore > max_area) {
                    max_area = max_explore;
                }
            }
            return max_area;
        }
    };