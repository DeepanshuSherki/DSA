class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";

        for (char ch : s) {
            // Agar last character current character ke same hai
            if (!ans.empty() && ans.back() == ch) {
                ans.pop_back();  // Dono duplicates remove kar do
            }
            else {
                ans.push_back(ch);  // Character ko answer mein add karo
            }
        }

        return ans;
    }
};