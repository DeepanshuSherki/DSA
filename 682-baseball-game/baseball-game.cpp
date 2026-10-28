class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;

        for (string op : operations) {
            if (op == "+") {
                // Pichhle do scores ka sum add karo
                int last = st.back();
                int secondLast = st[st.size() - 2];
                st.push_back(last + secondLast);
            }
            else if (op == "D") {
                // Pichhle score ka double add karo
                st.push_back(2 * st.back());
            }
            else if (op == "C") {
                // Pichhla score cancel karo
                st.pop_back();
            }
            else {
                // String score ko integer mein convert karke add karo
                st.push_back(stoi(op));
            }
        }

        // Saare valid scores ka total nikalo
        int sum = 0;
        for (int score : st) {
            sum += score;
        }

        return sum;
    }
};