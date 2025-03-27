class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            vector<int> arr1, arr2;
            
           
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < 0) 
                    arr2.push_back(nums[i]);
                else 
                    arr1.push_back(nums[i]);
            }
            
        
            int pos = 0, neg = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (i % 2 == 0) {
                    nums[i] = arr1[pos++];
                } 
                else {
                    nums[i] = arr2[neg++];
                }
            }
            
            return nums;
        }
    };
    