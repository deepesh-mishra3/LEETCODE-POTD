class Solution {
    public:
        void solve(vector<int>& nums, vector<vector<int>>& ans, int index) {
            if (index == nums.size()) {
                ans.push_back(nums);
                return;
            }
            for (int i = index; i < nums.size(); i++) {
                swap(nums[index], nums[i]);  // Swap to place the i-th element at index
                solve(nums, ans, index + 1); // Recur for next index
                swap(nums[index], nums[i]);  // Backtrack to restore the original state
            }
        }
        
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            solve(nums, ans, 0);
            return ans;
        }
    };
    