class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int value = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != i) return i;
        }
        return n; 
    }
};