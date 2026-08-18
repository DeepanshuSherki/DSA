class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int cur_max = nums[0];
        int result = 0;
        for(int i = 1; i < n; i++){
            result = max(result, (nums[i]-1) * (cur_max-1));

            cur_max = max(cur_max, nums[i]);
        }
        return result;
    }
};