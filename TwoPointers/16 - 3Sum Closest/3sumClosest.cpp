class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        // Step 1: Sort the array to enable two-pointer technique
        sort(nums.begin(), nums.end());

        // Step 2: Initialize closest sum with the first 3 elements
        int closest = nums[0] + nums[1] + nums[2];

        // Step 3: Fix the first element, and use two pointers to find the other two
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;       // Second pointer
            int k = n - 1;       // Third pointer

            // Move the two pointers toward each other
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                // If this sum is closer to target, update closest
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                // Adjust pointers based on comparison with target
                if (sum > target) {
                    k--;  // Need a smaller sum
                } else if (sum < target) {
                    j++;  // Need a larger sum
                } else {
                    // Exact match found
                    return target;
                }
            }
        }

        // Step 4: Return the closest sum found
        return closest;
    }
};
