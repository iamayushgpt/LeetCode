class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Step 1: Get the size of the input vector nums
        int n = nums.size();

        // Step 2: Sort the array to simplify finding quadruples
        sort(nums.begin(), nums.end());

        // Step 3: Create a vector to store the result (valid quadruples)
        vector<vector<int>> quads;

        // Step 4: Iterate through the array to select the first number of the
        // quadruple
        for (int i = 0; i < n; i++) {
            // Skip duplicates for the first number (to avoid repeating the same
            // quadruple)
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Step 5: Iterate through the array to select the second number of
            // the quadruple
            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Step 6: Use two pointers to select the third and fourth
                // numbers of the quadruple
                int k = j + 1; // Initialize the third pointer
                int l =
                    n -
                    1; // Initialize the fourth pointer at the end of the array

                // Step 7: Start the while loop to find valid quadruples
                while (k < l) {
                    // Calculate the sum of the four numbers
                    long long sum = nums[i] + nums[j];
                    sum += nums[k] + nums[l];

                    // Step 8: If the sum is less than the target, move the
                    // third pointer to the right
                    if (sum < target) {
                        k++;
                    }
                    // Step 9: If the sum is greater than the target, move the
                    // fourth pointer to the left
                    else if (sum > target) {
                        l--;
                    }
                    // Step 10: If the sum equals the target, we've found a
                    // valid quadruple
                    else {
                        // Add the quadruple to the result
                        quads.push_back({nums[i], nums[j], nums[k], nums[l]});

                        // Move both pointers inward to look for other potential
                        // quadruples
                        k++;
                        l--;

                        // Skip duplicates for the third number (to avoid
                        // repeating the same quadruple)
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        // Skip duplicates for the fourth number (to avoid
                        // repeating the same quadruple)
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                }
            }
        }

        // Step 11: Return the result containing all unique quadruples
        return quads;
    }
};