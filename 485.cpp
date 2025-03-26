class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
              int ans=0;
              int temp=0;
            for(auto i:nums){
              if(i==1) temp++;
              else temp=0;
              ans=max(temp,ans);
            }
            return ans;
        }
    };