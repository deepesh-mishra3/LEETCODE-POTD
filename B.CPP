class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            int total=1<<(nums.size());
            total=total-1;
            vector<vector<int>>ans;
            int size=nums.size();
            for(int i=0;i<=total;i++){
                vector<int>temp;
                for(int j=0;j<size;j++){
                    if(i&(1<<j)) temp.push_back(nums[j]);
                }
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            return ans;
        }
    };