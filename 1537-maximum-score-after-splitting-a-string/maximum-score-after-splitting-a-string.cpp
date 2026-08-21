class Solution {
public:
    int maxScore(string s) {
        int n = s.length();

        int result = INT_MIN;
        int total_one = count(s.begin(), s.end(), '1');

        int zeros = 0;
        int ones = 0;

        for (int i = 0; i < n - 1; i++) {

            if (s[i] == '0') {
                zeros++;
            } else {
                ones++;
            }

            int right_one = total_one - ones;

            result = max(result, zeros + right_one);
        }

        return result;
    }
};