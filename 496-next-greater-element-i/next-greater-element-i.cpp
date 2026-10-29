class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // nums2 ke har element ka Next Greater Element find karo
        for (int num : nums2) {

            // Current number greater hai, toh previous elements
            // ka Next Greater Element current number hai
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }

            // Current number ko future comparison ke liye store karo
            st.push(num);
        }

        // Jin elements ka greater element nahi mila, unka answer -1
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // nums1 ke elements ke answers return karo
        vector<int> ans;

        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};