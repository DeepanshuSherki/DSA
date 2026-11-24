
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;

        // 2*n traversal for circular array
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;

            // Smaller or equal elements remove karo
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            // Answer sirf original traversal mein update karo
            if (i < n && !st.empty()) {
                ans[idx] = st.top();
            }

            // Elements ko stack mein push karo
            st.push(nums[idx]);
        }

        return ans;
    }
};
