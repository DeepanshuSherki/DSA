class Solution {
public:
    string decodeString(string s) {

        stack<int> countStack;
        stack<string> stringStack;

        string curr = "";
        int num = 0;

        for (char ch : s) {

            // Agar digit hai toh repetition number calculate karo
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // Opening bracket: current state stack mein save karo
            else if (ch == '[') {
                countStack.push(num);
                stringStack.push(curr);

                num = 0;
                curr = "";
            }

            // Closing bracket: previous string ke saath decoded string jodo
            else if (ch == ']') {

                int k = countStack.top();
                countStack.pop();

                string prev = stringStack.top();
                stringStack.pop();

                // Current string ko k times repeat karo
                for (int i = 0; i < k; i++) {
                    prev += curr;
                }

                curr = prev;
            }

            // Normal character ko current string mein add karo
            else {
                curr += ch;
            }
        }

        return curr;
    }
};