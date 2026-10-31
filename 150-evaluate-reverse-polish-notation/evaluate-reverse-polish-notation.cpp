class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {

            // Agar token operator hai
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                // Pehle second operand nikalo
                int b = st.top();
                st.pop();

                // Phir first operand nikalo
                int a = st.top();
                st.pop();

                int result = 0;

                // Operation perform karo
                if (token == "+") {
                    result = a + b;
                }
                else if (token == "-") {
                    result = a - b;
                }
                else if (token == "*") {
                    result = a * b;
                }
                else if (token == "/") {
                    result = a / b;
                }

                // Result ko wapas stack mein push karo
                st.push(result);
            }
            else {
                // Number ko integer mein convert karke push karo
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};