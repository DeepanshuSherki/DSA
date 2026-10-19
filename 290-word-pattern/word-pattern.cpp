
class Solution {
public:
    bool wordPattern(string pattern, string s) {

        // String s ko words mein split karne ke liye string stream
        stringstream ss(s);
        string word;

        // Pattern character se word ki mapping store karne ke liye
        unordered_map<char, string> charToWord;

        // Word se pattern character ki reverse mapping ke liye
        unordered_map<string, char> wordToChar;

        int i = 0;

        // Ek-ek karke har word read karo
        while (ss >> word) {

            // Agar words pattern se zyada hain, toh false
            if (i >= pattern.size()) {
                return false;
            }

            char ch = pattern[i];

            // Check karo ki character pehle kisi word se map hua hai
            if (charToWord.count(ch)) {

                // Agar existing mapping alag hai, toh pattern match nahi
                if (charToWord[ch] != word) {
                    return false;
                }
            }

            // Check karo ki word pehle kisi character se map hua hai
            if (wordToChar.count(word)) {

                // Agar existing mapping alag hai, toh false
                if (wordToChar[word] != ch) {
                    return false;
                }
            }

            // Dono directions mein mapping store/update karo
            charToWord[ch] = word;
            wordToChar[word] = ch;

            // Agle pattern character par jao
            i++;
        }

        // Pattern aur words ki total count same honi chahiye
        return i == pattern.size();
    }
};
