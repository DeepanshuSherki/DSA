class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for(int right = 0 ; right < n ; right++){
            if(nums[right] == 0){
                zeroCount++;
            }
            while(zeroCount > 1){
                if(nums[left] == 0){
                  zeroCount--; 
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen - 1;
    }
};