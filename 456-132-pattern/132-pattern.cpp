class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int third = INT_MIN;

        // Right se left traverse
        for (int i = nums.size() - 1; i >= 0; i--) {

            // 1st element < 3rd element mila
            if (nums[i] < third)
                return true;

            // Current element 2nd element ban sakta hai
            while (!st.empty() && st.top() < nums[i]) {
                third = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};