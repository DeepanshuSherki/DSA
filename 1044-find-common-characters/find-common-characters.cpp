class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        // Pehle word ke characters ki frequency count karo
        vector<int> freq(26, 0);

        for (char ch : words[0]) {
            freq[ch - 'a']++;
        }

        // Baaki har word ko check karo
        for (int i = 1; i < words.size(); i++) {

            // Current word ki frequency store karo
            vector<int> curr(26, 0);

            for (char ch : words[i]) {
                curr[ch - 'a']++;
            }

            // Har character ki common minimum frequency rakho
            for (int j = 0; j < 26; j++) {
                freq[j] = min(freq[j], curr[j]);
            }
        }

        // Common characters ko answer mein store karo
        vector<string> ans;

        for (int i = 0; i < 26; i++) {

            // Jitni baar character common hai, utni baar add karo
            while (freq[i] > 0) {
                ans.push_back(string(1, 'a' + i));
                freq[i]--;
            }
        }

        return ans;
    }
};