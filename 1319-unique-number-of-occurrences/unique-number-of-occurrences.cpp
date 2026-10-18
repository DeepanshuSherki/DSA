class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        // Har number kitni baar aaya, uska count store karne ke liye map
        unordered_map<int, int> freq;

        // Array ke har number ki frequency count karo
        for (int num : arr) {
            freq[num]++; // Number mila, toh uska count 1 se badha do
        }

        // Jo frequencies pehle dekh chuke hain, unhe store karne ke liye set
        unordered_set<int> seen;

        // Map ke har number aur uski frequency par iterate karo
        for (auto it : freq) {

            // Agar ye frequency pehle se set mein hai,
            // toh do numbers ki frequency same hai
            if (seen.find(it.second) != seen.end()) {
                return false; // Frequencies unique nahi hain
            }

            // Frequency pehli baar mili, toh use set mein add kar do
            seen.insert(it.second);
        }

        // Koi bhi frequency repeat nahi hui, toh answer true hai
        return true;
    }
};