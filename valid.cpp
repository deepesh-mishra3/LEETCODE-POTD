class Solution {
    public:
        unordered_map<int, unordered_map<int, bool>> dp; // Memoization table
    
        bool solve(string &s, int i, int count) {
            if (count < 0) return false; // Too many closing brackets
            if (i == s.size()) return count == 0; // Valid only if count == 0
            
            if (dp.count(i) && dp[i].count(count)) return dp[i][count];
    
            if (s[i] == '(') return dp[i][count] = solve(s, i + 1, count + 1);
            else if (s[i] == ')') return dp[i][count] = solve(s, i + 1, count - 1);
            else {
                return dp[i][count] = (
                    solve(s, i + 1, count) ||    // Treat '*' as empty
                    solve(s, i + 1, count + 1) || // Treat '*' as '('
                    solve(s, i + 1, count - 1)    // Treat '*' as ')'
                );
            }
        }
    
        bool checkValidString(string s) {
            return solve(s, 0, 0);
        }
    };