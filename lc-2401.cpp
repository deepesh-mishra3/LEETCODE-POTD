
class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            // Binary search for the longest nice subarray length
            int left = 0, right = nums.size();
            int result = 1;  // Minimum answer is 1 (as subarrays of length 1 are
                             // always nice)
    
            while (left <= right) {
                int length = left + (right - left) / 2;
                if (canFormNiceSubarray(length, nums)) {
                    result = length;    // Update the result
                    left = length + 1;  // Try to find a longer subarray
                } else {
                    right = length - 1; 
                }
            }
            return result;
        }
    
    private:
        bool canFormNiceSubarray(int length, vector<int>& nums) {
            if (length <= 1) return true;  
    
          
            for (int start = 0; start <= nums.size() - length; ++start) {
                int bitMask = 0;  
                bool isNice = true;
    
           
                for (int pos = start; pos < start + length; ++pos) {
                  
                    if ((bitMask & nums[pos]) != 0) {
                        isNice = false;
                        break;
                    }
                    bitMask |= nums[pos]; 
                }
    
                if (isNice)
                    return true;  
            }
            return false;  
        }
    };