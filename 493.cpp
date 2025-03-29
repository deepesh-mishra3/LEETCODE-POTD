class Solution {
    public:
        int cnt = 0;
        
        // Count reverse pairs function
        void count(vector<int>& nums, int low, int mid, int high) {
            int j = mid + 1;
            
            // Iterate over the left half
            for (int q = low; q <= mid; q++) {
                while (j <= high && nums[q] > 2LL * nums[j]) {
                    j++;
                }
                cnt += (j - (mid + 1));  // Add valid pairs count
            }
        }
        
        // Merge two sorted halves
        void merge(vector<int>& nums, int low, int mid, int high) {
            vector<int> temp;
            int i = low, j = mid + 1;
            
            // Merge the two halves
            while (i <= mid && j <= high) {
                if (nums[i] <= nums[j]) {
                    temp.push_back(nums[i++]);
                } else {
                    temp.push_back(nums[j++]);
                }
            }
            
            // Copy remaining elements from the left half
            while (i <= mid) {
                temp.push_back(nums[i++]);
            }
            
            // Copy remaining elements from the right half
            while (j <= high) {
                temp.push_back(nums[j++]);
            }
            
            // Copy merged elements back to the original array
            for (int k = 0; k < temp.size(); k++) {
                nums[low + k] = temp[k];
            }
        }
        
        // Merge sort function
        void mergesort(vector<int>& nums, int low, int high) {
            if (low >= high) return;
            
            int mid = (low + high) / 2;
            
            // Sort left half
            mergesort(nums, low, mid);
            
            // Sort right half
            mergesort(nums, mid + 1, high);
            
            // Count reverse pairs before merging
            count(nums, low, mid, high);
            
            // Merge the two halves
            merge(nums, low, mid, high);
        }
        
        // Main function to return the number of reverse pairs
        int reversePairs(vector<int>& nums) {
         
            mergesort(nums, 0, nums.size() - 1);
            return cnt;
        }
    };
    