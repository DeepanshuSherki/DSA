class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        //2. Define min heap
        priority_queue<P,vector<P>,greater<P>> pq; //min heap
        //3.push elements in min heap
        //maintain size of k only
        for(auto& it : mp){
            int value = it.first;
            int freq = it.second;
            pq.push({freq,value});
            if(pq.size()>k){
                pq.pop();
            }
        }
        //4.Result
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};