class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> triplet;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            while(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;

            while(j < k){
                long long sum = nums[i] + nums[j];
                sum+=nums[k];
                if(sum == 0){
                    triplet.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                              // Skip duplicates for the second element (nums[j])
                    while (j < k && nums[j] == nums[j - 1]) j++;

                    // Skip duplicates for the third element (nums[k])
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
         vector<vector<int>> ans(triplet.begin(), triplet.end());
         return ans;
    }
};