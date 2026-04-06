class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> most;
        for(int num : nums){
            if(num%2 == 0){
                most[num]++;
            }
        }
        int maxMost = 0;
        int result = -1;
        for(auto &p : most){
            int num = p.first;
            int count = p.second;
            if(count > maxMost || (count == maxMost && num < result)){
                maxMost = count;
                result = num;
            }
        }
        return result;
    }
};