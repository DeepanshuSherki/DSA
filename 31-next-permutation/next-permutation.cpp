class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int t_index = -1;
        for(int i = n-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                t_index = i-1;
                break;
            }
        }
        if (t_index != -1){
            int s_index = t_index;
            for(int j = n-1;j >= t_index+1; j--){
                if(nums[j] > nums[t_index]){
                    s_index = j;
                    break;
                }
            }
            swap(nums[t_index],nums[s_index]);
        }
        reverse(nums.begin() + t_index+1, nums.end());
    }
};