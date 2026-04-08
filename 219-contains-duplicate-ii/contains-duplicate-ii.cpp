class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int> dup;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(dup.count(nums[i])){
                if(i - dup[nums[i]] <= k){
                    return true;
                }
            } 
            dup[nums[i]] = i; 
        }
        return false;     
    }
};