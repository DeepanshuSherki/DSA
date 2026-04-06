class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> majority;
        vector<int> result;
        int n = nums.size();
        for(int num : nums){
            majority[num]++;        
        }
        for(auto &p : majority){
            if(p.second > n / 3){
                result.push_back(p.first);
            }
        }
        return result;
    }
};