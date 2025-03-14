class Solution {
    public:
        bool istrue(int mid, vector<int>& candies, long long k) {
            long long count = 0;
            for (auto i : candies) {
                count += (i / mid);
            }
            return count >= k;
        }
    
        int maximumCandies(vector<int>& candies, long long k) {
            long long total = accumulate(candies.begin(), candies.end(), 0LL);
            if (total < k) return 0;
    
            int s = 1;
            int end = *max_element(candies.begin(), candies.end());
            int ans = 0;
    
            while (s <= end) {
                int mid = s + (end - s) / 2;
                if (istrue(mid, candies, k)) {
                    ans = mid;
                    s = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            return ans;
        }
    };
    