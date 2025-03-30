class Solution {
    public:
        vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
    
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }  
        vector<int> ans;
        int start = 0, maxLast = 0;
        for (int i = 0; i < s.size(); i++) {
            maxLast = max(maxLast, last[s[i] - 'a']);
            if (i == maxLast) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
    };