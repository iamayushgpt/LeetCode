//Better soln. I with T.C> O(n) and S.C> O(1)
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        // your code goes here
        int ans = 0;
        for (int i = 0; i <= 31; i++) {
            int count = 0;

            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] & (1 << i)) count++;
            }
            if (count % 3 != 0) ans |= (1 << i);
        }
        return ans;
    }
};


//better soln.II  with T.C> O(nlogn) and S.C> O(1) 
class Solution {
public:
    /* Function to get the single 
    number in the given array */
    int singleNumber(vector<int>& nums) {
        // Variable to store size of array
        int n = nums.size();
        
        // Sorting the array
        sort(nums.begin(), nums.end());
        
        // Traversing the array
        for (int i = 1; i < nums.size(); i += 3) {
            /* Checking the elements 
            in the bucket */
            if (nums[i] != nums[i - 1]) {
                // Return the single number
                return nums[i - 1];
            }
        }
        
        /* If not found till now, then 
        the last number will be single */
        return nums[n - 1];
    }
};



//optimal soln. with T.C> O(n) and S.C> O(1) using bucket method
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};