#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int totalLength = m + n;
        int low = 0, high = m;

        while (low <= high) {
            int i = (low + high) / 2;         // Partition nums1
            int j = (m + n + 1) / 2 - i;      // Partition nums2

            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];

            // Valid partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Check if total length is odd
                if (totalLength % 2 == 1) {
                    return max(maxLeft1, maxLeft2);
                }
                // Total length is even
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            }
            // Move binary search left
            else if (maxLeft1 > minRight2) {
                high = i - 1;
            }
            // Move binary search right
            else {
                low = i + 1;
            }
        }
        
        // If no valid partition is found
        throw invalid_argument("Input arrays are not valid.");
    }
};
