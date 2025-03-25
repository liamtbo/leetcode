class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> indices_stack;
        vector<int> temps_stack;
        vector<int> ans(temperatures.size(), 0);
        int j;

        temps_stack.push_back(temperatures[0]);
        indices_stack.push_back(0);

        for (int i=1; i<temperatures.size(); i++) {
            while (temps_stack.size() > 0 && temperatures[i] > temps_stack.back()) {
                temps_stack.pop_back();
                j = indices_stack.back();
                indices_stack.pop_back();
                ans[j] = i - j;
            }
            if (temps_stack.size() == 0 || temperatures[i] <= temps_stack.back()) {
                temps_stack.push_back(temperatures[i]);
                indices_stack.push_back(i);
            }
        }
        return ans;
    }
};