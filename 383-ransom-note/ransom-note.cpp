
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int freq[26] = {0};

        // Magazine ke har letter ka count store karo
        for (char ch : magazine) {
            freq[ch - 'a']++;
        }

        // Ransom note ke letters available hain ya nahi
        for (char ch : ransomNote) {
            if (freq[ch - 'a'] == 0) {
                return false;
            }

            // Letter use ho gaya, available count kam karo
            freq[ch - 'a']--;
        }

        return true;
    }
};
